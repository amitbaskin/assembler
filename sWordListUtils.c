#include "sWordListUtils.h"
#include "sWordSetters.h"
#include "uWordUtils.h"
#include "labelUtils.h"

void addWord(sWord *word, sWord **sWordLst){
    if ((*sWordLst)->uWord == NULL) {
        (*sWordLst) = word;
        return;
    } (*sWordLst)->next = word;
    *sWordLst = (*sWordLst)->next;
}

void addOpWord(opWord *opWord, sWord **sWordLst){
    sWord *sOpWord = createAndAddWord(setOpWordStatus, W_REG, sWordLst);
    setOpWord(sOpWord->uWord, opWord);
    setSWordAddress(sOpWord, instructionCounter++);
}

sWord *createAndAddWord(void setStatus(), wordStatus status, sWord **sWordLst){
    uWord *uWord = getUWord();
    sWord *sWord = getSword();
    setUWord(sWord, uWord);
    setStatus(status);
    addWord(sWord, sWordLst);
}

void addLabToInstLst(sWord **sWordLst, unsigned long len, char *name, labelType type, label *labHead, unsigned char
isRel){
    sWord *sWordLab = createAndAddWord(setLabStatus, W_REG, sWordLst);
    label *lab;
    if (labHead->name == NULL) setName(lab, name, len);
    if (isLabInLst(labHead, &lab, type, name) != TRUE) lab = getLabel(len, name);
    setLabelType(lab, type);
    setLab(sWordLab->uWord, lab);
    setSWordAddress(sWordLab, instructionCounter++);
    if (isRel) setRel(lab);
}

void addRegWord(int reg, sWord **sWordLst){
    sWord *sWordReg = createAndAddWord(setRegStatus, W_REG, sWordLst);
    setReg(sWordReg->uWord, reg);
    setSWordAddress(sWordReg, instructionCounter++);
}

void addNumWord(long num, sWord **sWordLst){
    sWord *sWordNum = createAndAddWord(setNumStatus, W_REG, sWordLst);
    setNumData(sWordNum->uWord, num);
    setSWordStatus(sWordNum, NUM);
    setSWordAddressType(sWordNum, R_TYPE);
    setSWordAddress(sWordNum, dataCounter++);
}

void addChrWord(char chr, sWord **sWordLst){
    sWord *sWordChr = createAndAddWord(setChrStatus, W_REG, sWordLst);
    setChrData(sWordChr->uWord, chr);
    setSWordStatus(sWordChr, CHR);
    setSWordAddressType(sWordChr, R_TYPE);
    setSWordAddress(sWordChr, dataCounter++);
}
