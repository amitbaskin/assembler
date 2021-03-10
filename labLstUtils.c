#include <string.h>
#include "labLstUtils.h"
#include "labUtils.h"
#include "labSetters.h"
#include "labGetters.h"

extern int labelFlag;
extern int instructionCounter;

result addLabToLabLst(labelLst *labLst, label **lab, labelType type, int address){
    VALIDATE_VAL(isLabInLst(labLst, lab, type, getLabName(*lab)), "")
    setLabAddress(*lab, address);
    setLabType(*lab, type);
    addLab(labLst, *lab);
    return SUCCESS;
}

result getRelLabelAddressFromLst(char *name, labelLst *labLst, int address, int *dist){
    label *ptr;
    for (ptr = labLst->tail; ptr != NULL; ptr = ptr->next){
        if (strcmp(name, getLabName(ptr)) != 0) setThisLab(&ptr, getLabNext(ptr));
        else {
            *dist = (address - getLabAddress(ptr));
            return SUCCESS;
        }
    } return ERR;
}

result isLabInLst(labelLst *labLst, label **lab, labelType type, char *name){
    label *ptr;
    for (ptr = getLabTail(labLst); ptr != NULL; promoteLab(&ptr)){
        if (strcmp(getLabName(ptr), name) == 0) {
            *lab = ptr;
            VALIDATE_VAL(isLabTypeLegal(*lab, type), "")
            return TRUE;
        }
    } return FALSE;
}

result checkLabFlagOnScenario(label **lab, labelLst *labLst, void labSetter(label *, unsigned char), int address){
    if (labelFlag) {
        labSetter(*lab, 1);
        addLabToLabLst(labLst, lab, L_NONE, address);
        return TRUE;
    } return FALSE;
}

void freeLabLstHelper(label *lab){
    label *tmp;
    while(lab != NULL){
        tmp = lab;
        promoteLab(&lab);
        freeLab(tmp);
    }
}

label *getLabTail(labelLst *lst){
    return lst->tail;
}

void addLab(labelLst *lst, label *lab){
    ADD_TO_LIST(label, lst->tail == NULL, lab)
}

result initLabLst(labelLst **lst){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(lst), &ptr), "")
    *lst = ptr;
    return SUCCESS;
}

void freeLabLst(labelLst *lst){
    freeLabLstHelper(getLabTail(lst));
}
