#include <string.h>
#include "sWordSetters.h"
#include "wordIdentifiers.h"
#include "generalUtils.h"
#include "labelUtils.h"
#include "uWordSetters.h"
#include "sWordGetters.h"

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

void setSUDataLabel(sWord *word){
    setUDataLabel(getSUWord(word));
}

void setSUCodeLabel(sWord *word){
    setUCodeLabel(getSUWord(word));
}

void setSURelLabel(sWord *word){
    setURelLabel(getSUWord(word));
}

void setSULabelAddress(sWord *word, int address){
    setULabelAddress(getSUWord(word), address);
}

result setSULabelName(sWord *word, char *name){
    return setULabelName(getSUWord(word), name);
}

void setSULabelType(sWord *word, labelType type){
    setULabelType(getSUWord(word), type);
}

void setSUNextLabel(sWord *word, label *next){
    setUNextLabel(getSUWord(word), next);
}
