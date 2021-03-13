/* this file is used to handle the label list of the program */

#include <string.h>
#include "labLstUtils.h"
#include "labUtils.h"
#include "labSetters.h"
#include "labGetters.h"
#include "errFuncs.h"

extern int labelFlag;
extern int instructionCounter;

label *getLabTail(labelLst *lst){
    return lst->tail;
}

result addLabToLabLst(labelLst *labLst, label **lab, labelType type, int address){
    /* adds a given lab to label list if it doesn't clash with a predefined one else return ERR
     * returns ERR if an error has occurred in the process and SUCCESS other wise */
    setLabAddress(*lab, address);
    setLabType(*lab, type);
    VALIDATE_VAL(addLab(labLst, *lab))
    return SUCCESS;
}

result getRelLabelAddressFromLst(char *name, labelLst *labLst, int address, int *dist) {
    /* get the relative address of given label name from the given address
     * returns ERR if the specified label wasn't found and SUCCESS otherwise */
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
    /* used in the second parse to confirm that a used label is defined and that it wasn't defined with clashing
     * types, else returns ERR */
    label *ptr;
    for (ptr = getLabTail(labLst); ptr != NULL; promoteLab(&ptr)){
        if (strcmp(getLabName(ptr), name) == 0) {
            *lab = ptr;
            VALIDATE_VAL(isLabTypeLegal(*lab, type))
            return TRUE;
        }
    } return FALSE;
}

result flagOnScenario(label **lab, labelLst *labLst, int address, unsigned char isData){
    /* if a label was defined, add to it to the label list */
    if (labelFlag) {
        setLabData(*lab, isData);
        addLabToLabLst(labLst, lab, L_NONE, address);
        return TRUE;
    } return FALSE;
}

void freeLabLstHelper(label *lab){
    /* given the tail of a label list, frees the entire list */
    label *tmp;
    while(lab != NULL){
        tmp = lab;
        promoteLab(&lab);
        freeLab(tmp);
    }
}

result addLab(labelLst *lst, label *lab){
    /* adds the lab to the label list if it doesn't clash with a predefined one, else return ERR */
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
    /* allocates memory for a new label list
     * returns ERR if a memory allocation error has occurred and SUCCESS other wise */
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(lst), &ptr))
    *lst = ptr;
    return SUCCESS;
}

void freeLabLst(labelLst *lst){
    /* frees the allocated memory of the given list */
    freeLabLstHelper(getLabTail(lst));
}
