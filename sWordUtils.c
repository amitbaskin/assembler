#include "sWordUtils.h"
#include "generalUtils.h"
#include "uWordUtils.h"
#include "sWordGetters.h"

result getNewEmptySword(sWord **word){
    void *sPtr;
    VALIDATE_FUNC_CALL(getAlloc(sizeof(sWord), &sPtr), "");
    *word = (sWord*) sPtr;
    return SUCCESS;
}

void freeSWord(sWord *word){
    freeUWord(getSUWord(word));
    freeHelper(word);
}