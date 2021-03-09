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
                    getRelLabelAddressFromLst(getSULabName(ptr), labLst, getSULabAddress(ptr), &dist);
                    printInst(fp, &ptr, dist);
                }
                else printInst(fp, &ptr, getSULabAddress(ptr));
                break;

            case W_REG:
                printInst(fp, &ptr, transReg(getSUReg(ptr)));
                break;

            case IM_NUM:
                printInst(fp, &ptr, getSUNumData(ptr));
                break;

            default:
                break;
        }
    }
}

void printDataLst(FILE *fp, sWordLst *dataLst){
    sWord *ptr;
    wordStatus status;
    for (ptr = getSWordTail(dataLst); ptr != NULL; setThisSWord(&ptr, getSWordNext(ptr))) {
        status = getSWordStatus(ptr);
        if (status == NUM_DATA) {
            setSWordAddress(ptr, getSWordAddress(ptr) + ICF);
            printInst(fp, &ptr, getSUNumData(ptr));
        }
        if(status == CHR_DATA){
            setSWordAddress(ptr, getSWordAddress(ptr) + ICF);
            printInst(fp, &ptr, getSUChrData(ptr));
        }
    }
}

void getEntLst(label *ent, labelLst *labLst){
    label *ptr;
    for (ptr = getLabTail(labLst); ptr != NULL; promoteLab(&ptr)){
        if (getLabType(ptr) == L_ENT){
            setThisLab(&ent, ptr);
            setThisLab(&ent, getLabNext(ent));
            setThisLab(&ptr, getLabNext(ptr));
        }
    }

}

result printEntLst(char *fName, labelLst *labLst) {
    label *ent = NULL;
    getEntLst(ent, labLst);
    if (ent == NULL) return SUCCESS;
    FILE *fp;
    VALIDATE_VAL(getEntOutputFile(fName, &fp), "")
    label *ptr;
    for (ptr = getLabTail(labLst); ptr != NULL; promoteLab(&ptr)) {
        if (getLabType(ptr) == L_ENT) {
            printLabel(fp, ptr);
        }
        return SUCCESS;
    }
}

void getExtLst(sWord *ext, sWordLst *instLst){
    sWord *ptr;
    label *lab;
    for (ptr = getSWordTail(instLst); ptr != NULL; promoteSWord(&ptr)) {
        switch (getSWordStatus(ptr)) {
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
    getExtLst(ext, instLst);
    if (ext == NULL) return SUCCESS;
    FILE *fp;
    VALIDATE_VAL(getExtOutputFIle(fName, &fp), "");
    sWord *ptr;
    label *lab;
    for (ptr = getSWordTail(instLst); ptr != NULL; promoteSWord(&ptr)){
        if (getSWordStatus(ptr) == LAB) {
            lab = getSULab(ptr);
            if (getLabType(lab) == EXT) printLabel(fp, lab);
        }
    } return SUCCESS;
}

void printInst(FILE *fp, sWord **ptr, unsigned int toPrint){
    printAddressToFile(fp, *ptr);
    printWordToFile(fp, toPrint);
    printAddressTypeToFile(fp, *ptr);
}

void printLabel(FILE *fp, label *lab){
    fprintf(fp, "%s ", getLabName(lab));
    fprintf(fp, "%du\n", getLabAddress(lab));
}
