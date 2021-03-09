#include "uWordUtils.h"
#include "generalUtils.h"
#include "labUtils.h"
#include "sWordGetters.h"

result initUWord(uWord **word){
    void *uPtr;
    VALIDATE_VAL(getAlloc(sizeof(uWord), &uPtr), "");
    *word = (uWord*) uPtr;
    return SUCCESS;
}

void freeUWord(sWord *word){
    if(getSWordStatus(word) == OP) freeHelper(getSUOpWord(word));
    freeHelper(getSUWord(word));
}
