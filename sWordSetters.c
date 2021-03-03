#include "sWordSetters.h"
#include "wordId.h"
#include "generalUtils.h"
#include "labUtils.h"
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
    sWord->status = NUM_DATA;
}

void setChrStatus(sWord *sWord){
    sWord->status = CHR_DATA;
}

void setRegStatus(sWord *sWord){
    sWord->status = W_REG;
}

void setOpWordStatus(sWord *sWord){
    sWord->status = OP;
}

void setNextSWord(sWord *this, sWord *other){
    this->next = other;
}

void setThisSWord(sWord **this, sWord *other){
    *this = other;
}

void setSUOpWord(sWord *word, opWord *op){
    setUOpWord(getSUWord(word), op);
}

void setSULab(sWord *word, label *lab){
    setULab(getSUWord(word), lab);
}

void setSUReg(sWord *word, reg r){
    setUReg(getSUWord(word), r);
}

void setSUNumData(sWord *word, long num){
    dataCounter++;
    setUNumData(getSUWord(word), num);
}

void setSUChrData(sWord *word, char chr){
    dataCounter++;
    setUChrData(getSUWord(word), chr);
}

void setSUDataLab(sWord *word){
    setUDataLab(getSUWord(word));
}

void setSUCodeLab(sWord *word){
    setUCodeLab(getSUWord(word));
}

void setSURelLab(sWord *word){
    setURelLab(getSUWord(word));
}

void setSULabAddress(sWord *word, int address){
    setULabAddress(getSUWord(word), address);
}

result setSULabName(sWord *word, char *name){
    return setULabName(getSUWord(word), name);
}

void setSULabType(sWord *word, labelType type){
    setULabType(getSUWord(word), type);
}

void setSUNextLab(sWord *word, label *next){
    setUNextLab(getSUWord(word), next);
}
