#include "sWordUtils.h"
#include "generalUtils.h"
#include "uWordUtils.h"
#include "sWordGetters.h"
#include "sWordSetters.h"

result getNewEmptySword(sWord **word){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(sWord), &ptr), "");
    *word = (sWord*) ptr;
    uWord *unionWord;
    getNewEmptyUWord(&unionWord);
    setSUWord(*word, unionWord);
    return SUCCESS;
}

void freeSWord(sWord *word){
    freeUWord(word);
    freeHelper(word);
}

void promoteSWord(sWord **word){
    *word = (*word)->next;
}