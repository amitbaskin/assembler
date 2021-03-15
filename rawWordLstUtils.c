/* this file is used to provide utilities to handle a linked list of integer data content */

#include "string.h"
#include "rawWordUtils.h"


void freeRawWordLstHelper(rawWord *word){
    /* frees an entire rawWordLst given its tail */
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
    ADD_TO_LIST(sWord, getRawWordTail(lst) == NULL, word)
}

result initRawWordLst(rawWordLst **lst){
    /* allocates memory for a rawWordLst
     * returns ERR if a memory allocation error has occurred and SUCCESS otherwise */
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(rawWordLst), &ptr))
    *lst = ptr;
    return SUCCESS;
}

void freeRawWordLst(rawWordLst *lst){
    freeRawWordLstHelper(getRawWordTail(lst));
}

result isRawStrWordInRLst(rawWord *word, rawWordLst *lst){
    /* looks for the given rawWord in the given rawWordLst, returns TRUE if found and FALSE otherwise */
    rawWord *ptr;
    for (ptr = getRawWordTail(lst); ptr != NULL; promoteRawWord(&ptr)){
        if (strcmp(getRawWordStr(word), getRawWordStr(ptr)) == 0) return TRUE;
    } return FALSE;
}
