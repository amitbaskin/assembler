/* general utilities for the uWord data structure */

#include "labUtils.h"
#include "sWordGetters.h"

result initUWord(uWord **word){
    /* allocates memory for a new uWord object */
    void *uPtr;
    VALIDATE_VAL(getAlloc(sizeof(uWord), &uPtr))
    *word = (uWord*) uPtr;
    return SUCCESS;
}

void freeUWord(sWord *word){
    /* frees the memory allocated for this uWord object */
    wordStatus status = getSWordStatus(word);
    if (status == OP) freeHelper(getSUOpWord(word));
    else if (status == LAB || status == W_ENT) freeLab(getSULab(word));
    freeHelper(getSUWord(word));
}
