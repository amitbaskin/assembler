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

void printIntsLst(FILE *fp, sWordLst *instLst, labelLst *labLst){
    sWord *ptr;
    fprintf(fp, HEADER_FORMAT, instructionCounter - INITIAL_INSTRUCTION_NUM, dataCounter);
    while ((ptr = getSWordIterNext(instLst)) != NULL && getSWordStatus(ptr) != W_NONE){
        switch (getSWordStatus(ptr)){
            case OP:
                printInst(fp, &ptr, transOp(getSUOpWord(ptr)));
                break;

            case LAB:
                if (isSULabRel(ptr)) {
                    int dist;
                    getRelLabelAddressFromLst(getSULabName(ptr), labLst, getSULabAddress(ptr), &dist);
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
                break;
        }
    } resetSWordIter(instLst);
}

void printDataLst(FILE *fp, sWordLst *dataLst){
    sWord *ptr;
    while ((ptr = getSWordIterNext(dataLst)) != NULL && getSWordStatus(ptr)) {
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
                setThisSWord(&ptr, getSWordNext(ptr));
        }
    } resetSWordIter(dataLst);
}

void getEntLst(label *ent, label *labTail){
    label *ptr = labTail;
    while (ptr != NULL && getLabType(ptr) != L_NONE){
        switch (getLabType(ptr)){
            case L_ENT:
                setThisLab(&ent, ptr);
                setThisLab(&ent, getLabNext(ent));
                setThisLab(&ptr, getLabNext(ptr));
                break;

            default:
                setThisLab(&ptr, getLabNext(ptr));
        }
    }

}

result printEntLst(char *fName, labelLst *labLst){
    label *ent = NULL;
    getEntLst(ent, getLabTail(labLst));
    if (ent == NULL) return SUCCESS;
    FILE *fp;
    VALIDATE_VAL(getEntOutputFIle(fName, &fp), "")
    label *ptr = NULL;
    while (ptr != NULL && getLabType(ptr) != L_NONE){
        switch (getLabType(ptr)){
            case L_ENT:
                printLabel(fp, ptr);
                setLabNext(ptr, getLabNext(ptr));
                break;

            default:
                setThisLab(&ptr, getLabNext(ptr));
        }
    } return SUCCESS;
}

void getExtLst(sWord *ext, sWord *instHead){
    sWord *ptr = instHead;
    label *lab;
    while (ptr != NULL && getSWordStatus(ptr) != W_NONE) {
        switch (getSWordStatus(instHead)) {
            case LAB:
                lab = getSULab(ptr);
                if (getLabType(lab) == EXT){
                    setThisSWord(&ext, ptr);
                    setSWordNext(ext, getSWordNext(ext));
                }
                setSWordNext(ptr, getSWordNext(ptr));
                break;

            default:
                setThisSWord(&ptr, ptr);
        }
    }
}

result printExtLst(char *fName, sWordLst *instLst) {
    sWord *ext = NULL;
    getExtLst(ext, getSWordHead(instLst));
    if (ext == NULL) return SUCCESS;
    FILE *fp;
    VALIDATE_VAL(getExtOutputFIle(fName, &fp), "");
    sWord *ptr;
    label *lab;
    while ((ptr = getSWordIterNext(instLst)) != NULL && getSWordStatus(ptr) != W_NONE
    ) {
        switch (getSWordStatus(ptr)) {
            case LAB:
                lab = getSULab(ptr);
                if (getLabType(lab) == EXT) printLabel(fp, lab);
                setSWordNext(ptr, getSWordNext(ptr));
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
    setSWordNext(*ptr, getSWordNext(*ptr));
}

void printLabel(FILE *fp, label *lab){
    fprintf(fp, "%s ", getLabName(lab));
    fprintf(fp, "%du\n", getLabAddress(lab));
}
