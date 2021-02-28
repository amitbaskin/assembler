#include <string.h>
#include "labelLstUtils.h"
#include "labelUtils.h"
#include "labelSetters.h"
#include "labelGetters.h"

void addLabelToLst(label **labLst, label *next){
    setNextLabel(*labLst, next);
}

void addDataLabelToLst(label **labLst, char *name){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    label *lab = (label *) ptr;
    setLabelName(lab, name);
    setLabelAddress(lab, dataCounter++);
    setDataLabel(lab);
    addLabelToLst(labLst, lab);
}

result getLabelAddressFromLst(char *name, label *headLab, int *address){
    while (headLab != NULL){
        if (!strcmp(name, getLabelName(headLab))) {
            *address = getLabelAddress(headLab);
            return SUCCESS;
        } setThisLabel(&headLab, getNextLabel(headLab));
    } return ERR;
}

result getRelLabelAddressFromLst(char *name, label *headLab, int address, int *dist){
    while (headLab != NULL){
        if (!strcmp(name, getLabelName(headLab))) {
            *dist = (address - getLabelAddress(headLab));
            return SUCCESS;
        } setThisLabel(&headLab, getNextLabel(headLab));
    } return ERR;
}

result isLabInLst(label *headLab, label **lab, labelType type, char *name){
    while (headLab != NULL){
        if (!strcmp(getLabelName(headLab), name)) {
            *lab = headLab;
            if (isLabelTypeLegal(*lab, type) == ERR) return ERR;
            return TRUE;
        } setThisLabel(&headLab, getNextLabel(headLab));
    } return FALSE;
}
