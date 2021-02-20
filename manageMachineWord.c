#include "manageMachineWord.h"
#include "machineWordIdentifiers.h"
#include "generalUtils.h"

void addWord(sWord *word, sWord *last){
    last->next = word;
}

initial *getInitial(char *op, ref src, ref dest){
    void *initPtr;
    getAlloc(sizeof(initial), &initPtr);
    initial *init = (initial *) initPtr;
    init->op = op;
    init->src = src;
    init->dest = dest;
    return init;
}

uWord *getUWord(){
    void *uPtr;
    getAlloc(sizeof(uWord), &uPtr);
    uWord *word = (uWord*) uPtr;
    return word;
}

void setInit(uWord *word, initial *init){
    word->init = init;
}

void setLab(uWord *uWord, label *lab){
    uWord->lab = lab;
}

void setReg(uWord *uWord, reg r){
    uWord->reg = r;
}

void setNumData(uWord *uWord, int num){
    dataCounter++;
    uWord->numData = num;
}

void setChrData(uWord *uWord, char chr){
    dataCounter++;
    uWord->chrData = chr;
}

sWord *getSword(){
    void *sPtr;
    getAlloc(sizeof(sWord), &sPtr);
    sWord *word = (sWord*) sPtr;
    return word;
}

void setUWord(sWord *sWord, uWord *uWord){
    sWord->uWord = uWord;
}

void setSWordStatus(sWord *sWord, wordStatus status){
    sWord->status = status;
}

void setSwordAddress(sWord *sWord, int address){
    sWord->address = address;
}

void setSWordAddressType(sWord *sWord, char addressType){
    sWord->addressType = addressType;
}
