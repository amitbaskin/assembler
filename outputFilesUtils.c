#include "outputFilesUtils.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "wordTrans.h"
#include "labelUtils.h"
#define HEADER_FORMAT "%d %d\n"

void printInst(FILE *fp, sWord **ptr, unsigned int toPrint){
    printAddressToFile(fp, *ptr);
    printWordToFile(fp, toPrint);
    printAddressTypeToFile(fp, *ptr);
    *ptr = (*ptr)->next;
}

void printIntsLst(FILE *fp, sWord *instHead){
    sWord *ptr = instHead;
    fprintf(fp, HEADER_FORMAT, instructionCounter, dataCounter);
    while (ptr != NULL){
        switch (ptr->status){
            case OP:
                printInst(fp, &ptr, transInit(ptr->uWord->op));
                break;

            case LAB:
                printInst(fp, &ptr, ptr->uWord->lab->address);
                break;

            case W_REG:
                printInst(fp, &ptr, transReg(ptr->uWord->reg));
                break;

            case NUM:
                printInst(fp, &ptr, ptr->uWord->numData);
                break;

            default:
                ptr = ptr->next;
        }
    }
}

void printDataLst(FILE *fp, sWord *dataHead){
    sWord *ptr = dataHead;
    while (ptr != NULL) {
        switch (ptr->status) {
            case NUM:
                printInst(fp, &ptr, ptr->uWord->numData);
                break;

            case CHR:
                printInst(fp, &ptr, ptr->uWord->chrData);
                break;

            default:
                ptr = ptr->next;
        }
    }
}

void printLabel(FILE *fp, label *lab){
    fprintf(fp, "%s ", lab->name);
    fprintf(fp, "%du\n", lab->address);
}

void printEntLst(FILE *fp, label *labHead){
    label *ptr = labHead;
    while (ptr != NULL){
        switch (ptr->type){
            case L_ENT:
                printLabel(fp, ptr);
                ptr = ptr->next;
                break;

            default:
                ptr = ptr->next;
        }
    }
}

void printExtLst(FILE *fp, sWord *instHead) {
    sWord *ptr = instHead;
    label *lab;
    while (ptr != NULL) {
        switch (ptr->status) {
            case LAB:
                lab = ptr->uWord->lab;
                if (lab->type == EXT) printLabel(fp, lab);
                ptr = ptr->next;
                break;

            default:
                ptr = ptr->next;
        }
    }
}
