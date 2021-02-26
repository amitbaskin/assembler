#include "manageMachineWord.h"
#include "machineWordIdentifiers.h"
#include "generalUtils.h"

void addWord(sWord *word, sWord **sWordLst){
    (*sWordLst)->next = word;
    *sWordLst = (*sWordLst)->next;
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

void setInitStatus(sWord *sWord){
    sWord->status = INIT;
}

void setLabStatus(sWord *sWord){
    sWord->status = LAB;
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

sWord *createAndAddWord(void setStatus(), wordStatus status, sWord **sWordLst){
    uWord *uWord = getUWord();
    sWord *sWord = getSword();
    setUWord(sWord, uWord);
    setStatus(status);
    addWord(sWord, sWordLst);
}

void addInitWord(initial *init, sWord **sWordLst){
    sWord *sWordReg = createAndAddWord(setInitStatus, W_REG, sWordLst);
    setInit(sWordReg->uWord, init);
}

void addLabWord(label *lab, sWord **sWordLst){
    sWord *sWordReg = createAndAddWord(setLabStatus, W_REG, sWordLst);
    setLab(sWordReg->uWord, lab);
}

void addRegWord(int reg, sWord **sWordLst){
    sWord *sWordReg = createAndAddWord(setRegStatus, W_REG, sWordLst);
    setReg(sWordReg->uWord, reg);
}

void addNumWord(int num, sWord **sWordLst){
    sWord *sWordReg = createAndAddWord(setNumStatus, W_REG, sWordLst);
    setNumData(sWordReg->uWord, num);
}

void addChrWord(char chr, sWord **sWordLst){
    sWord *sWordReg = createAndAddWord(setNumStatus, W_REG, sWordLst);
    setChrData(sWordReg->uWord, chr);
}
