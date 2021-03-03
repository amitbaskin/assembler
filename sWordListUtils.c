#include "sWordListUtils.h"
#include "sWordSetters.h"
#include "uWordSetters.h"
#include "labUtils.h"
#include "labSetters.h"
#include "uWordSetters.h"
#include "sWordSetters.h"
#include "sWordGetters.h"
#include "labGetters.h"

void addWord(sWord *word, sWord **sWordLst){
    if (getSUWord(word) == NULL) {
        setThisSWord(sWordLst, word);
        return;
    } setNextSWord(*sWordLst, word);
    setThisSWord(sWordLst, getNextSWord(*sWordLst));
}

void addOpWord(opWord *opWord, sWord **sWordLst){
    sWord *sOpWord = createAndAddWord(setOpWordStatus, W_REG, sWordLst);
    setSUOpWord(sOpWord, opWord);
    setSWordAddress(sOpWord, instructionCounter++);
}

sWord *createAndAddWord(void setStatus(), wordStatus status, sWord **sWordLst){
    uWord *uWord = getSUWord(*sWordLst);
    sWord *sWord = getNewEmptySword();
    setSUWord(sWord, uWord);
    setStatus(status);
    addWord(sWord, sWordLst);
}

void addLabToInstLst(sWord **sWordLst, char *name, labelType type, label *labHead, unsigned char
isRel){
    sWord *sWordLab = createAndAddWord(setLabStatus, W_REG, sWordLst);
    label *lab;
    if (getLabName(labHead) == NULL) setLabName(lab, name);
    if (isLabInLst(labHead, &lab, type, name) != TRUE) lab = getNewLabelByName(name);
    setLabType(lab, type);
    setSULab(sWordLab, lab);
    setSWordAddress(sWordLab, instructionCounter++);
    if (isRel) setRelLab(lab);
}

void addRegWord(int reg, sWord **sWordLst){
    sWord *sWordReg = createAndAddWord(setRegStatus, W_REG, sWordLst);
    setSUReg(sWordReg, reg);
    setSWordAddress(sWordReg, instructionCounter++);
}

void addNumWord(long num, wordStatus status, sWord **sWordLst){
    sWord *sWordNum = createAndAddWord(setNumStatus, W_REG, sWordLst);
    setSUNumData(sWordNum, num);
    setSWordStatus(sWordNum, status);
    setSWordAddressType(sWordNum, R_TYPE);
    setSWordAddress(sWordNum, dataCounter++);
}

void addChrWord(char chr, sWord **sWordLst){
    sWord *sWordChr = createAndAddWord(setChrStatus, W_REG, sWordLst);
    setSUChrData(sWordChr, chr);
    setSWordStatus(sWordChr, CHR_DATA);
    setSWordAddressType(sWordChr, R_TYPE);
    setSWordAddress(sWordChr, dataCounter++);
}
