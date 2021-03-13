/* setters for the sWord data structure */

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

void setSOpWordStatus(sWord *word){
    word->status = OP;
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

void setSUNum(sWord *word, long num){
    setUNumData(getSUWord(word), num);
}

void setSUChrData(sWord *word, char chr){
    setUChrData(getSUWord(word), chr);
}

void setSULabAddress(sWord *word, int address){
    setULabAddress(getSUWord(word), address);
}

void setSULabType(sWord *word, labelType type){
    setULabType(getSUWord(word), type);
}
