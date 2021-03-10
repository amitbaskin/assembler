#include "outputUtils.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "wordTrans.h"
#include "labUtils.h"
#include "sWordGetters.h"
#include "sWordSetters.h"
#include "labGetters.h"
#include "labSetters.h"
#include "fileUtils.h"
#include "labLstUtils.h"
#include "sWordListUtils.h"
#include "sWordUtils.h"

extern int ICF;

extern int instructionCounter;
extern int dataCounter;

void printInstLst(FILE *fp, sWordLst *instLst, labelLst *labLst){
    sWord *ptr;
    fprintf(fp, HEADER_FORMAT, instructionCounter - INITIAL_INSTRUCTION_NUM, dataCounter);
    for (ptr = getSWordTail(instLst); ptr != NULL; promoteSWord(&ptr)){

        switch (getSWordStatus(ptr)){
            case OP:
                printInst(fp, &ptr, transOp(getSUOpWord(ptr)));
                break;

            case LAB:
                if (isSULabRel(ptr)) {
                    int dist;
                    getRelLabelAddressFromLst(getSULabName(ptr), labLst, getSWordAddress(ptr), &dist);
                    printInst(fp, &ptr, dist);
                }
                else printInst(fp, &ptr, getSULabAddress(ptr));
                break;

            case W_REG:
                printInst(fp, &ptr, transReg(getSUReg(ptr)));
                break;

            case IM_NUM:
                printInst(fp, &ptr, (int) getSUNumData(ptr));
                break;

            default:
                break;
        }
    }
}

void printDataLst(FILE *fp, sWordLst *dataLst){
    sWord *ptr;
    wordStatus status;
    for (ptr = getSWordTail(dataLst); ptr != NULL; promoteSWord(&ptr)) {
        status = getSWordStatus(ptr);
        setSWordAddress(ptr, getSWordAddress(ptr) + ICF);
        if (status == NUM_DATA) printInst(fp, &ptr, (int) getSUNumData(ptr));
        if(status == CHR_DATA) printInst(fp, &ptr, getSUChrData(ptr));
    }
}

result printEntFile(labelLst *lst, char *fName) {
    int flag = 0;
    FILE *fp = NULL;
    label *ptr;
    for (ptr = getLabTail(lst); ptr != NULL; promoteLab(&ptr)) {
        if (getLabType(ptr) == L_ENT) {
            if (!flag) {
                flag = 1;
                VALIDATE_VAL(getEntOutputFile(fName, &fp), "");
            }
            printLabel(fp, ptr);
        }
    } return SUCCESS;
}

result printExtLst(char *fName, sWordLst *instLst) {
    FILE *fp;
    sWord *ptr;
    int extFlag = 0;
    for (ptr = getSWordTail(instLst); ptr != NULL; promoteSWord(&ptr)) {
        if (getSWordStatus(ptr) == LAB) {
            if (getSULabType(ptr) == EXT){
                if (!extFlag) {
                    extFlag = 1;
                    VALIDATE_VAL(getExtOutputFile(fName, &fp), "");
                } setSULabAddress(ptr, getSWordAddress(ptr));
                printLabel(fp, getSULab(ptr));
            }
        }
    } return SUCCESS;
}

void printInst(FILE *fp, sWord **ptr, int toPrint){
    printAddressToFile(fp, *ptr);
    printWordToFile(fp, toPrint);
    printAddressTypeToFile(fp, *ptr);
}

void printLabel(FILE *fp, label *lab){
    fprintf(fp, "%s ", getLabName(lab));
    fprintf(fp, "%d\n", getLabAddress(lab));
}
