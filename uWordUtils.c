#include <stdlib.h>
#include "uWordUtils.h"
#include "generalUtils.h"
#include "labUtils.h"
#include "uWordGetters.h"

result getNewEmptyUWord(uWord **word){
    void *uPtr;
    VALIDATE_FUNC_CALL(getAlloc(sizeof(uWord), &uPtr), "");
    *word = (uWord*) uPtr;
    return SUCCESS;
}

void freeUWord(uWord *word){
    switch(word->status){
        case OP:
            freeHelper(word->op);
            freeHelper(word);
            break;
        case LAB:
            freeLab(getULab(word));
            freeHelper(word);
            break;
        default:
            break;
    }
}