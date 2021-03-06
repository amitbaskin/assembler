#include "sWordSetters.h"
#include "wordId.h"
#include "generalUtils.h"
#include "labUtils.h"
#include "uWordSetters.h"
#include "sWordGetters.h"

void setSUWord(sWord *sWord, uWord *uWord){
    sWord->uWord = uWord;
}

void setSUWordStatus(sWord *sWord, wordStatus status){
    setUStatus(getSUWord(sWord), status);
}

void setSWordAddress(sWord *sWord, int address){
    sWord->address = address;
}

void setSWordAddressType(sWord *sWord, char addressType){
    sWord->addressType = addressType;
}

void setSULabStatus(sWord *word){
    setULabStatus(getSUWord(word));
}

void setSUEntStatus(sWord *word){
    setUEntStatus(getSUWord(word));
}

void setSUNumStatus(sWord *word){
    setUNumStatus(getSUWord(word));
}

void setSUChrStatus(sWord *word){
    setUChrStatus(getSUWord(word));
}

void setSURegStatus(sWord *word){
    setURegStatus(getSUWord(word));
}

void setSUOpWordStatus(sWord *word){
    setUOpStatus(getSUWord(word));
}

void setSWordNext(sWord *this, sWord *other){
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

void setSUDataLab(sWord *word, unsigned char toSet){
    setUDataLab(getSUWord(word), toSet);
}

void setSUCodeLab(sWord *word, unsigned char toSet){
    setUCodeLab(getSUWord(word), toSet);
}

void setSURelLab(sWord *word, unsigned char toSet){
    setURelLab(getSUWord(word), toSet);
}

void setSULabIsNameAlloc(sWord *word, unsigned char toSet){
    setULabIsNameAlloc(getSUWord(word), toSet);
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
