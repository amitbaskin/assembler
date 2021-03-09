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
    ADD_TO_LIST(sWord, getRawWordTail(lst) == NULL, word)
}

result initRawWordLst(rawWordLst **lst){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(rawWordLst), &ptr), "")
    *lst = ptr;
    return SUCCESS;
}

void freeRawWordLst(rawWordLst *lst){
    freeRawWordLstHelper(getRawWordTail(lst));
}
