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

void printIntsLst(FILE *fp, sWord *instHead, label *labHead){
    sWord *ptr = instHead;
    fprintf(fp, HEADER_FORMAT, instructionCounter, dataCounter);
    while (ptr != NULL){
        switch (getSUWordStatus(ptr)){
            case OP:
                printInst(fp, &ptr, transOp(getSUOpWord(ptr)));
                break;

            case LAB:
                if (isSURelLab(ptr)) {
                    int dist;
                    getRelLabelAddressFromLst(getSULabName(ptr), labHead, getSULabAddress(ptr), &dist);
                    printInst(fp, &ptr, dist);
                }
                else printInst(fp, &ptr, getSULabAddress(ptr));
                break;

            case W_REG:
                printInst(fp, &ptr, transReg(getSUReg(ptr)));
                break;

            case DIR_NUM:
                printInst(fp, &ptr, getSUNumData(ptr));
                break;

            default:
                setThisSWord(&ptr, getSWordNext(ptr));
        }
    }
}

void printDataLst(FILE *fp, sWord *dataHead){
    sWord *ptr = dataHead;
    while (ptr != NULL) {
        switch (getSUWordStatus(ptr)) {
            case NUM_DATA:
                setSWordAddress(ptr, getSWordAddress(ptr) + ICF);
                printInst(fp, &ptr, getSUNumData(ptr));
                break;

            case CHR_DATA:
                setSWordAddress(ptr, getSWordAddress(ptr) + ICF);
                printInst(fp, &ptr, getSUChrData(ptr));
                break;

            default:
                setThisSWord(&ptr, getSWordNext(ptr));
        }
    }
}

result printEntLst(char *fName, label *labHead){
    FILE *fp;
    if (getEntOutputFIle(fName, &fp) == ERR) return ERR;
    label *ptr = labHead;
    while (ptr != NULL){
        switch (getLabType(ptr)){
            case L_ENT:
                printLabel(fp, ptr);
                setNextLab(ptr, getLabNext(ptr));
                break;

            default:
                setThisLab(&ptr, getLabNext(ptr));
        }
    } return SUCCESS;
}

result printExtLst(char *fName, sWord *instHead) {
    FILE *fp;
    if (getExtOutputFIle(fName, &fp) == ERR) return ERR;
    sWord *ptr = instHead;
    label *lab;
    while (ptr != NULL) {
        switch (getSUWordStatus(instHead)) {
            case LAB:
                lab = getSULab(ptr);
                if (getLabType(lab) == EXT) printLabel(fp, lab);
                setNextSWord(ptr, getSWordNext(ptr));
                break;

            default:
                setThisSWord(&ptr, ptr);
        }
    } return SUCCESS;
}

void printInst(FILE *fp, sWord **ptr, unsigned int toPrint){
    printAddressToFile(fp, *ptr);
    printWordToFile(fp, toPrint);
    printAddressTypeToFile(fp, *ptr);
    setNextSWord(*ptr, getSWordNext(*ptr));
}

void printLabel(FILE *fp, label *lab){
    fprintf(fp, "%s ", getLabName(lab));
    fprintf(fp, "%du\n", getLabAddress(lab));
}
