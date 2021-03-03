#include "sWordUtils.h"
#include "generalUtils.h"

result getNewEmptySword(sWord **word){
    void *sPtr;
    if (getAlloc(sizeof(sWord), &sPtr) == ERR) return ERR;
    *word = (sWord*) sPtr;
    return SUCCESS;
}
