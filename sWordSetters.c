#include "sWordSetters.h"
#include "wordId.h"
#include "generalUtils.h"
#include "labUtils.h"
#include "uWordSetters.h"
#include "sWordGetters.h"

extern int dataCounter;

void setSUWord(sWord *sWord, uWord *uWord){
    sWord->uWord = uWord;
}

void setSWordStatus(sWord *word, wordStatus status){
    word->status = status;
}

void setSWordAddress(sWord *sWord, int address){
    sWord->address = address;
}

void setSWordAddressType(sWord *sWord, char addressType){
    sWord->addressType = addressType;
}

void setSLabStatus(sWord *word){
    word->status = LAB;
}

void setSEntStatus(sWord *word){
    word->status = W_ENT;
}

void setSNumStatus(sWord *word){
    word->status = NUM_DATA;
}

void setSChrStatus(sWord *word){
    word->status = CHR_DATA;
}

void setSRegStatus(sWord *word){
    word->status = W_REG;
}

void setSOpWordStatus(sWord *word){
    word->status = OP;
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
    setUNumData(getSUWord(word), num);
}

void setSUChrData(sWord *word, char chr){
    setUChrData(getSUWord(word), chr);
}

void setSWordStatusDataLab(sWord *word, unsigned char toSet){
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
