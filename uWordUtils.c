#include "uWordUtils.h"
#include "generalUtils.h"

uWord *getNewEmptyUWord(){
    void *uPtr;
    getAlloc(sizeof(uWord), &uPtr);
    uWord *word = (uWord*) uPtr;
    return word;
}
