/* this file is used to handle the output of the program */

#include "wordTrans.h"
#include "labUtils.h"
#include "sWordGetters.h"
#include "sWordSetters.h"
#include "labGetters.h"
#include "fileUtils.h"
#include "labLstUtils.h"
#include "sWordListUtils.h"
#include "sWordUtils.h"
#include "rawWordLstUtils.h"
#include "rawWordUtils.h"
#include "globalVars.h"


#define HEADER_FORMAT "%d %d\n"


void printInst(FILE *fp, sWord **ptr, int toPrint){
    printAddressToFile(fp, *ptr);
    printWordToFile(fp, toPrint);
    printAddressTypeToFile(fp, *ptr);
}

void printLabel(FILE *fp, label *lab){
    fprintf(fp, "%s ", getLabName(lab));
    fprintf(fp, LAB_ADDRESS_FORMAT, getLabAddress(lab));
}

void printInstLst(FILE *fp, sWordLst *instLst, labelLst *labLst){
    /* outputs the main output file containing the translation of the instructions and data to machine code */
    sWord *ptr;
    fprintf(fp, HEADER_FORMAT, getInstructionCounter() - INITIAL_INSTRUCTION_NUM, getDataCounter());
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
                break; /* the switch statement is used here for readability but it should not be possible to
            * get to this default statement because this function should always get a type of one of the mentioned
            types above */
        }
    }
}

void printDataLst(FILE *fp, sWordLst *dataLst){
    sWord *ptr;
    wordStatus status;
    for (ptr = getSWordTail(dataLst); ptr != NULL; promoteSWord(&ptr)) {
        status = getSWordStatus(ptr);
        setSWordAddress(ptr, getSWordAddress(ptr) + getIcf());
        if (status == NUM_DATA) printInst(fp, &ptr, (int) getSUNumData(ptr));
        if(status == CHR_DATA) printInst(fp, &ptr, getSUChrData(ptr));
    }
}

result printEntFile(labelLst *lst, char *fName) {
    /* outputs the entry file if any entry statement exists, making sure the entry statements refer to actual labels */
    int isEntExists = 0;
    FILE *fp = NULL;
    label *ptr;
    rawWordLst *rawLst;
    rawWord *rWord;
    initRawWordLst(&rawLst);
    for (ptr = getLabLstTail(lst); ptr != NULL; promoteLab(&ptr)) {
        if (getLabType(ptr) == L_ENT) {
            if (!isEntExists) {
                isEntExists = 1;
                VALIDATE_VAL(getEntOutputFile(fName, &fp))
            }
            initRawWord(&rWord);
            setRawWordStr(rWord, getLabName(ptr));
            if (isRawStrWordInRLst(rWord, rawLst) == FALSE){
                addRawWord(rawLst, rWord);
                printLabel(fp, ptr);
            }
            else freeRawWord(rWord);
        }
    }
    freeRawWordLst(rawLst);
    return SUCCESS;
}

result printExtLst(char *fName, sWordLst *instLst) {
    /* outputs the extern file if any extern statement exists */
    FILE *fp;
    sWord *ptr;
    int isExtExists = 0;
    for (ptr = getSWordTail(instLst); ptr != NULL; promoteSWord(&ptr)) {
        if (getSWordStatus(ptr) == LAB) {
            if (getSULabType(ptr) == EXT){
                if (!isExtExists) {
                    isExtExists = 1;
                    VALIDATE_VAL(getExtOutputFile(fName, &fp))
                }
                setSULabAddress(ptr, getSWordAddress(ptr));
                printLabel(fp, getSULab(ptr));
            }
        }
    }
    return SUCCESS;
}
