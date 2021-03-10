#include "string.h"
#include "rawWordLstUtils.h"
#include "rawWordUtils.h"

void freeRawWordLstHelper(rawWord *word){
    rawWord *tmp;
    while(word != NULL){
        tmp = word;
        promoteRawWord(&word);
        freeRawWord(tmp);
    }
}

rawWord *getRawWordTail(rawWordLst *lst){
    return lst->tail;
}

void addRawWord(rawWordLst *lst, rawWord *word){
//    ADD_TO_LIST(sWord, getRawWordTail(lst) == NULL, word)
    if (getRawWordTail(lst) == NULL){                         \
        lst->tail = word;              \
        lst->head = (&lst->tail);      \
    } else{                            \
        lst->head = &((*(lst->head))->next); \
        *(lst->head) = word;           \
    }                                  \
}

result initRawWordLst(rawWordLst **lst){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(rawWordLst), &ptr))
    *lst = ptr;
    return SUCCESS;
}

void freeRawWordLst(rawWordLst *lst){
    freeRawWordLstHelper(getRawWordTail(lst));
}

result isRawStrWordInRLst(rawWord *word, rawWordLst *lst){
    rawWord *ptr;
    for (ptr = getRawWordTail(lst); ptr != NULL; promoteRawWord(&ptr)){
        if (strcmp(getRawWordStr(word), getRawWordStr(ptr)) == 0) return TRUE;
    } return FALSE;
}
