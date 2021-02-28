#include "sWordListUtils.h"
#include "sWordSetters.h"
#include "uWordSetters.h"
#include "labelUtils.h"
#include "labelSetters.h"
#include "uWordSetters.h"
#include "sWordSetters.h"
#include "sWordGetters.h"

void addWord(sWord *word, sWord **sWordLst){
    if ((*sWordLst)->uWord == NULL) {
        (*sWordLst) = word;
        return;
    } (*sWordLst)->next = word;
    *sWordLst = (*sWordLst)->next;
}

void addOpWord(opWord *opWord, sWord **sWordLst){
    sWord *sOpWord = createAndAddWord(setOpWordStatus, W_REG, sWordLst);
    setUOpWord(sOpWord->uWord, opWord);
    setSWordAddress(sOpWord, instructionCounter++);
}

sWord *createAndAddWord(void setStatus(), wordStatus status, sWord **sWordLst){
    uWord *uWord = getSUWord();
    sWord *sWord = getNewEmptySword();
    setSUWord(sWord, uWord);
    setStatus(status);
    addWord(sWord, sWordLst);
}

void addLabToInstLst(sWord **sWordLst, char *name, labelType type, label *labHead, unsigned char
isRel){
    sWord *sWordLab = createAndAddWord(setLabStatus, W_REG, sWordLst);
    label *lab;
    if (labHead->name == NULL) setLabelName(lab, name);
    if (isLabInLst(labHead, &lab, type, name) != TRUE) lab = getNewLabelByName(name);
    setLabelType(lab, type);
    setULab(sWordLab->uWord, lab);
    setSWordAddress(sWordLab, instructionCounter++);
    if (isRel) setRelLabel(lab);
}

void addRegWord(int reg, sWord **sWordLst){
    sWord *sWordReg = createAndAddWord(setRegStatus, W_REG, sWordLst);
    setUReg(sWordReg->uWord, reg);
    setSWordAddress(sWordReg, instructionCounter++);
}

void addNumWord(long num, sWord **sWordLst){
    sWord *sWordNum = createAndAddWord(setNumStatus, W_REG, sWordLst);
    setUNumData(sWordNum->uWord, num);
    setSWordStatus(sWordNum, NUM);
    setSWordAddressType(sWordNum, R_TYPE);
    setSWordAddress(sWordNum, dataCounter++);
}

void addChrWord(char chr, sWord **sWordLst){
    sWord *sWordChr = createAndAddWord(setChrStatus, W_REG, sWordLst);
    setUChrData(sWordChr->uWord, chr);
    setSWordStatus(sWordChr, CHR);
    setSWordAddressType(sWordChr, R_TYPE);
    setSWordAddress(sWordChr, dataCounter++);
}
