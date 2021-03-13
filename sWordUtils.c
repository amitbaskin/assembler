/* general utilities for the sWord data structure */

#include "uWordUtils.h"
#include "sWordSetters.h"

result initSword(sWord **word){
    /* allocates memory for a new sWord object */
    void *ptr;
    uWord *unionWord;
    VALIDATE_VAL(getAlloc(sizeof(sWord), &ptr))
    *word = (sWord*) ptr;
    initUWord(&unionWord);
    setSUWord(*word, unionWord);
    return SUCCESS;
}

void freeSWord(sWord *word){
    /* frees the memory allocated for this sWord object */
    freeUWord(word);
    freeHelper(word);
}

void promoteSWord(sWord **word){
    /* sets the given sWord object to point to its successor */
    *word = (*word)->next;
}
