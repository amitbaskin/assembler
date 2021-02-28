#include <string.h>
#include "labLstUtils.h"
#include "labUtils.h"
#include "labSetters.h"
#include "labGetters.h"

void addLabelToLst(label **labLst, label *next){
    setNextLab(*labLst, next);
}

result addLabToLabLst(label *head, label **lab, label **labLst, labelType type, int address){
    result res = isLabInLst(head, lab, type, getLabName(*lab));
    if (res == FALSE){
        setNextLab(*labLst, *lab);
        setLabType(*lab, type);
        setLabAddress(*lab, address);
        return SUCCESS;
    } else return ERR;
}

void addDataLabelToLst(label **labLst, char *name){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    label *lab = (label *) ptr;
    setLabName(lab, name);
    setLabAddress(lab, dataCounter++);
    setDataLab(lab);
    addLabelToLst(labLst, lab);
}

result getLabelAddressFromLst(char *name, label *headLab, int *address){
    while (headLab != NULL){
        if (!strcmp(name, getLabName(headLab))) {
            *address = getLabAddress(headLab);
            return SUCCESS;
        }
        setThisLab(&headLab, getNextLab(headLab));
    } return ERR;
}

result getRelLabelAddressFromLst(char *name, label *headLab, int address, int *dist){
    while (headLab != NULL){
        if (!strcmp(name, getLabName(headLab))) {
            *dist = (address - getLabAddress(headLab));
            return SUCCESS;
        }
        setThisLab(&headLab, getNextLab(headLab));
    } return ERR;
}

result isLabInLst(label *headLab, label **lab, labelType type, char *name){
    while (headLab != NULL){
        if (!strcmp(getLabName(headLab), name)) {
            *lab = headLab;
            if (isLabelTypeLegal(*lab, type) == ERR) return ERR;
            return TRUE;
        }
        setThisLab(&headLab, getNextLab(headLab));
    } return FALSE;
}
