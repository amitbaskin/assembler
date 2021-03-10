#include "uWordUtils.h"
#include "generalUtils.h"
#include "labUtils.h"
#include "sWordGetters.h"

result initUWord(uWord **word){
    void *uPtr;
    VALIDATE_VAL(getAlloc(sizeof(uWord), &uPtr))
    *word = (uWord*) uPtr;
    return SUCCESS;
}

void freeUWord(sWord *word){
    wordStatus status = getSWordStatus(word);
    if (status == OP) freeHelper(getSUOpWord(word));
    else if (status == LAB || status == W_ENT) freeLab(getSULab(word));
    freeHelper(getSUWord(word));
}
