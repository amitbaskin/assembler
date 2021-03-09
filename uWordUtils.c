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
    switch(word->status){
        case OP:
            freeHelper(getSUOpWord(word));
            break;
        case LAB:
            freeLab(getSULab(word));
            break;
        default:
            break;
    } freeHelper(getSUWord(word));
}