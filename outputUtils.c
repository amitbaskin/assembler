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

void printIntsLst(FILE *fp, sWord *instHead){
    sWord *ptr = instHead;
    fprintf(fp, HEADER_FORMAT, instructionCounter, dataCounter);
    while (ptr != NULL){
        switch (getSWordStatus(ptr)){
            case OP:
                printInst(fp, &ptr, transOp(getSUOpWord(ptr)));
                break;

            case LAB:
                printInst(fp, &ptr, getSULabelAddress(ptr));
                break;

            case W_REG:
                printInst(fp, &ptr, transReg(getSUReg(ptr)));
                break;

            case DIR_NUM:
                printInst(fp, &ptr, getSUNumData(ptr));
                break;

            default:
                setThisSWord(&ptr, getNextSWord(ptr));
        }
    }
}

void printDataLst(FILE *fp, sWord *dataHead){
    sWord *ptr = dataHead;
    while (ptr != NULL) {
        switch (getSWordStatus(ptr)) {
            case NUM_DATA:
                setSWordAddress(ptr, getSWordAddress(ptr) + ICF);
                printInst(fp, &ptr, getSUNumData(ptr));
                break;

            case CHR_DATA:
                setSWordAddress(ptr, getSWordAddress(ptr) + ICF);
                printInst(fp, &ptr, getSUChrData(ptr));
                break;

            default:
                setThisSWord(&ptr, getNextSWord(ptr));
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
                setNextLab(ptr, getNextLab(ptr));
                break;

            default:
                setThisLab(&ptr, getNextLab(ptr));
        }
    } return SUCCESS;
}

result printExtLst(char *fName, sWord *instHead) {
    FILE *fp;
    if (getEntOutputFIle(fName, &fp) == ERR) return ERR;
    sWord *ptr = instHead;
    label *lab;
    while (ptr != NULL) {
        switch (getSWordStatus(instHead)) {
            case LAB:
                lab = getSULab(ptr);
                if (getLabType(lab) == EXT) printLabel(fp, lab);
                setNextSWord(ptr, getNextSWord(ptr));
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
    setNextSWord(*ptr, getNextSWord(*ptr));
}

void printLabel(FILE *fp, label *lab){
    fprintf(fp, "%s ", getLabName(lab));
    fprintf(fp, "%du\n", getLabAddress(lab));
}
