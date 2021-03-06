#include <string.h>
#include "labLstUtils.h"
#include "labUtils.h"
#include "labSetters.h"
#include "labGetters.h"

result addLabToLabLst(labelLst *labLst, label **lab, labelType type, int address){
    result res = isLabInLst(labLst, lab, type, getLabName(*lab));
    if (res == ERR) return ERR;
    setLabAddress(*lab, address);
    setLabType(*lab, type);
    addLab(labLst, *lab);
    return SUCCESS;
}

result getRelLabelAddressFromLst(char *name, labelLst *labLst, int address, int *dist){
    label *ptr;
    while ((ptr = getLabIterNext(labLst)) != NULL && getLabType(ptr) != L_NONE){
        if (strcmp(name, getLabName(ptr)) != 0) setThisLab(&ptr, getLabNext(ptr));
        else {
            *dist = (address - getLabAddress(ptr));
            return SUCCESS;
        }
    } resetLabIter(labLst);
    return ERR;
}

result isLabInLst(labelLst *labLst, label **lab, labelType type, char *name){
    label *ptr;
    while ((ptr = getLabIterNext(labLst)) != NULL && getLabType(ptr) != L_NONE){
        if (strcmp(getLabName(ptr), name) != 0) setThisLab(&ptr, getLabNext(ptr));
        else {
            *lab = ptr;
            VALIDATE_VAL(isLabTypeLegal(*lab, type), "")
            return TRUE;
        }
    } resetLabIter(labLst);
    return FALSE;
}

void checkLabFlagOnScenario(label **lab, labelLst *labLst, void labSetter(label *, unsigned char), int address){
    if (labelFlag) {
        labSetter(*lab, 1);
        addLabToLabLst(labLst, lab, L_NONE, address);
    }
}

void freeLabLstHelper(label *lab){
    label *tmp;
    while(lab !=NULL && getLabType(lab) != L_NONE && getLabNext(lab) != NULL){
        tmp = lab;
        setThisLab(&lab, getLabNext(lab));
        freeLab(tmp);
    } freeLab(lab);
}

label *getLabHead(labelLst *lst){
    return lst->head;
}

label *getLabTail(labelLst *lst){
    return lst->tail;
}

label *getLabCur(labelLst *lst){
    return lst->cur;
}

label *getLabIterNext(labelLst *lst){
    if (lst->head == lst->cur){ \
        lst->cur = lst->tail;\
        return NULL;         \
    } label *cur = lst->cur;  \
    label *tmp = cur;         \
    lst->cur = cur->next;    \
    return tmp;              \
}

void resetLabIter(labelLst *lst){
    label *cur = getLabCur(lst);
    setThisLab(&cur, getLabTail(lst));
}

void addLab(labelLst *lst, label *lab){
//    ADD_TO_LIST(label, getLabType(lst->tail) == L_NONE, lab)
    if (getLabType(lst->tail) == L_NONE){                                   \
        lst->tail = lab;              \
        *(lst->tail->next) = lst->head;\
        lst->head = *(lst->tail->next);   \
                                       \
    } else{                            \
        lst->head = lab;        \
        lst->head = *(lst->head->next);              \
    }                                  \
}

result getNewLabLst(labelLst **lst){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(lst), &ptr), "")
    *lst = ptr;
    return SUCCESS;
}

result initializeLabLst(labelLst **lst){
    VALIDATE_VAL(getNewLabLst(lst), "")
    VALIDATE_VAL(getNewEmptyLab(&((*lst)->tail)), "")
    (*lst)->cur = (*lst)->head = (*lst)->tail;
    return SUCCESS;
}

void freeLabLst(labelLst *lst){
    freeLabLstHelper(getLabTail(lst));
}
