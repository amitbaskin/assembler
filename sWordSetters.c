#include <string.h>
#include "sWordSetters.h"
#include "wordIdentifiers.h"
#include "generalUtils.h"
#include "labelUtils.h"
#include "uWordSetters.h"

void setSUWord(sWord *sWord, uWord *uWord){
    sWord->uWord = uWord;
}

void setSWordStatus(sWord *sWord, wordStatus status){
    sWord->status = status;
}

void setSWordAddress(sWord *sWord, int address){
    sWord->address = address;
}

void setSWordAddressType(sWord *sWord, char addressType){
    sWord->addressType = addressType;
}

void setLabStatus(sWord *sWord){
    sWord->status = LAB;
}

void setEntStatus(sWord *sWord){
    sWord->status = W_ENT;
}

void setNumStatus(sWord *sWord){
    sWord->status = NUM;
}

void setChrStatus(sWord *sWord){
    sWord->status = CHR;
}

void setRegStatus(sWord *sWord){
    sWord->status = W_REG;
}

void setOpWordStatus(sWord *sWord){
    sWord->status = OP;
}

void setThisSWord(sWord **this, sWord *other){
    *this = other;
}
