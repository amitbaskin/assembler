#include <string.h>
#include "manageMachineWord.h"
#include "machineWordIdentifiers.h"
#include "generalUtils.h"
#include "labelApi.h"

void addWord(sWord *word, sWord **sWordLst){
    (*sWordLst)->next = word;
    *sWordLst = (*sWordLst)->next;
}

initial *getInitial(int opIndex, ref src, ref dest){
    void *initPtr;
    getAlloc(sizeof(initial), &initPtr);
    initial *init = (initial *) initPtr;
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

void setNumData(uWord *uWord, long num){
    dataCounter++;
    uWord->numData = num;
}

void setChrData(uWord *uWord, char chr){
    dataCounter++;
    uWord->chrData = chr;
}

label *getLabel(unsigned long len, char *name){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    label *lab = (label*) ptr;
    getAlloc(len, &ptr);
    lab->name = (char *) ptr;
    strcpy(lab->name, name);
    return lab;
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
    sWord *sWordInit = createAndAddWord(setInitStatus, W_REG, sWordLst);
    setInit(sWordInit->uWord, init);
    setSwordAddress(sWordInit, instructionCounter++);
}

void addLabWord(sWord **sWordLst, unsigned long len, char *name, label *labHead, unsigned char isRel){
    sWord *sWordLab = createAndAddWord(setLabStatus, W_REG, sWordLst);
    label *lab;
    if (isLabelInLst(labHead, &lab, name) == TRUE);
    else lab = getLabel(len, name);
    setLab(sWordLab->uWord, lab);
    setSwordAddress(sWordLab, instructionCounter++);
    if (isRel) setRel(lab);
}

void addRegWord(int reg, sWord **sWordLst){
    sWord *sWordReg = createAndAddWord(setRegStatus, W_REG, sWordLst);
    setReg(sWordReg->uWord, reg);
    setSwordAddress(sWordReg, instructionCounter++);
}

void addNumWord(long num, sWord **sWordLst){
    sWord *sWordNum = createAndAddWord(setNumStatus, W_REG, sWordLst);
    setNumData(sWordNum->uWord, num);
    setSwordAddress(sWordNum, dataCounter++);
}

void addChrWord(char chr, sWord **sWordLst){
    sWord *sWordChr = createAndAddWord(setNumStatus, W_REG, sWordLst);
    setChrData(sWordChr->uWord, chr);
    setSwordAddress(sWordChr, dataCounter++);
}
