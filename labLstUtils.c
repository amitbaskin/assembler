#include <string.h>
#include "labLstUtils.h"
#include "labUtils.h"
#include "labSetters.h"
#include "labGetters.h"
#include "errFuncs.h"

extern int labelFlag;
extern int instructionCounter;

result addLabToLabLst(labelLst *labLst, label **lab, labelType type, int address){
    setLabAddress(*lab, address);
    setLabType(*lab, type);
    VALIDATE_VAL(addLab(labLst, *lab))
    return SUCCESS;
}

result getRelLabelAddressFromLst(char *name, labelLst *labLst, int address, int *dist) {
    label *ptr;
    for (ptr = getLabTail(labLst); ptr != NULL; promoteLab(&ptr)) {
        if (strcmp(name, getLabName(ptr)) == 0) {
            *dist = (getLabAddress(ptr) - address);
            return SUCCESS;
        }
    } relLabErr();
    return ERR;
}

result isLabInLst(labelLst *labLst, label **lab, labelType type, char *name){
    label *ptr;
    for (ptr = getLabTail(labLst); ptr != NULL; promoteLab(&ptr)){
        if (strcmp(getLabName(ptr), name) == 0) {
            *lab = ptr;
            VALIDATE_VAL(isLabTypeLegal(*lab, type))
            return TRUE;
        }
    } return FALSE;
}

result flagOnScenario(label **lab, labelLst *labLst, void labSetter(label *, unsigned char), int address){
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

result addLab(labelLst *lst, label *lab){
    label *ptr;
    labelType type1;
    labelType type2;
    for (ptr = getLabTail(lst); ptr != NULL; promoteLab(&ptr)){
        if (strcmp(getLabName(lab), getLabName(ptr)) != 0) continue;
        type1 = getLabType(ptr);
        type2 = getLabType(lab);
        if ((type1 == EXT) && type2 == EXT) return SUCCESS;
        labClashErr();
        return ERR;
    } ADD_TO_LIST(label, lst->tail == NULL, lab)
    return SUCCESS;
}

result initLabLst(labelLst **lst){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(lst), &ptr))
    *lst = ptr;
    return SUCCESS;
}

void freeLabLst(labelLst *lst){
    freeLabLstHelper(getLabTail(lst));
}
