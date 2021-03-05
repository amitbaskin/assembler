#include <string.h>
#include "labLstUtils.h"
#include "labUtils.h"
#include "labSetters.h"
#include "labGetters.h"

result addLabToLabLst(label *head, label **lab, label **labLst, labelType type, int address){
    result res = isLabInLst(head, lab, type, getLabName(*lab));
    if (res == TRUE) return ERR;
    setLabType(*lab, type);
    setLabAddress(*lab, address);
    setNextLab(*labLst, *lab);
    return SUCCESS;
}

result getRelLabelAddressFromLst(char *name, label *headLab, int address, int *dist){
    while (headLab != NULL){
        if (strcmp(name, getLabName(headLab)) != 0) setThisLab(&headLab, getLabNext(headLab));
        else {
            *dist = (address - getLabAddress(headLab));
            return SUCCESS;
        }
    } return ERR;
}

result isLabInLst(label *headLab, label **lab, labelType type, char *name){
    while (headLab != NULL){
        if (strcmp(getLabName(headLab), name) != 0) setThisLab(&headLab, getLabNext(headLab));
        else {
            *lab = headLab;
            VALIDATE_FUNC_CALL(isLabelTypeLegal(*lab, type), "")
            return TRUE;
        }
    } return FALSE;
}

void freeLabLst(label *lab){
    label *tmp;
    while(getLabNext(lab) != NULL){
        tmp = lab;
        setThisLab(&lab, getLabNext(lab));
        freeLab(tmp);
    } freeLab(lab);
}
