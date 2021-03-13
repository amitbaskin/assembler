#include "uWordUtils.h"
#include "sWordSetters.h"

result initSword(sWord **word){
    void *ptr;
    uWord *unionWord;
    VALIDATE_VAL(getAlloc(sizeof(sWord), &ptr))
    *word = (sWord*) ptr;
    initUWord(&unionWord);
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
