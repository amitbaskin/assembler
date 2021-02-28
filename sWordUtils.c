#include "sWordUtils.h"
#include "generalUtils.h"

sWord *getNewEmptySword(){
    void *sPtr;
    getAlloc(sizeof(sWord), &sPtr);
    sWord *word = (sWord*) sPtr;
    return word;
}
