#include "sWordListUtils.h"
#include "sWordSetters.h"
#include "uWordSetters.h"
#include "labUtils.h"
#include "labSetters.h"
#include "uWordSetters.h"
#include "sWordSetters.h"
#include "sWordGetters.h"
#include "labGetters.h"
#include "sWordUtils.h"

void addWord(sWord *word, sWord **sWordLst){
    if (getSUWord(word) == NULL) {
        setThisSWord(sWordLst, word);
        return;
    } setNextSWord(*sWordLst, word);
    setThisSWord(sWordLst, getSWordNext(*sWordLst));
}

result addOpWord(opWord *opWord, sWord **sWordLst){
    sWord *sOpWord;
    VALIDATE_FUNC_CALL(createAndAddWord(&sOpWord, setSUOpWordStatus, W_REG, sWordLst), "");
    setSUOpWord(sOpWord, opWord);
    setSWordAddress(sOpWord, instructionCounter++);
    return SUCCESS;
}

result createAndAddWord(sWord **word, void setStatus(), wordStatus status, sWord **sWordLst){
    uWord *uWord = getSUWord(*sWordLst);
    VALIDATE_FUNC_CALL(getNewEmptySword(word), "");
    setSUWord(*word, uWord);
    setStatus(status);
    addWord(*word, sWordLst);
    return SUCCESS;
}

result addLabToInstLst(sWord **sWordLst, char *name, labelType type, label *labHead, unsigned char isRel){
    sWord *sWordLab;
    VALIDATE_FUNC_CALL(createAndAddWord(&sWordLab, setSULabStatus, W_REG, sWordLst), "");
    label *lab;
    if (getLabName(labHead) == NULL) {
        getNewLabelByName(&lab, getLabName(labHead));
        setLabName(lab, name);
    } if (isLabInLst(labHead, &lab, type, name) != TRUE) {
        getNewLabelByName(&lab, name);
        setSWordAddress(sWordLab, instructionCounter++);
    } setLabType(lab, type);
    if (isRel) setRelLab(lab);
    setSULab(sWordLab, lab);
    return SUCCESS;
}

result addRegWord(int reg, sWord **sWordLst){
    sWord *sWordReg;
    VALIDATE_FUNC_CALL(createAndAddWord(&sWordReg, setSURegStatus, W_REG, sWordLst), "");
    setSUReg(sWordReg, reg);
    setSWordAddress(sWordReg, instructionCounter++);
    return SUCCESS;
}

void addNumWord(long num, wordStatus status, sWord **sWordLst){
    sWord *sWordNum;
    createAndAddWord(&sWordNum, setSUNumStatus, W_REG, sWordLst);
    setSUNumData(sWordNum, num);
    setSUWordStatus(sWordNum, status);
    setSWordAddressType(sWordNum, R_TYPE);
    setSWordAddress(sWordNum, dataCounter++);
}

void addChrWord(char chr, sWord **sWordLst){
    sWord *sWordChr;
    createAndAddWord(&sWordChr, setSUChrStatus, W_REG, sWordLst);
    setSUChrData(sWordChr, chr);
    setSUWordStatus(sWordChr, CHR_DATA);
    setSWordAddressType(sWordChr, R_TYPE);
    setSWordAddress(sWordChr, dataCounter++);
}

void freeSWordLst(sWord *word){
    sWord *tmp;
    while(getSWordNext(word) != NULL){
        tmp = word;
        setThisSWord(&word, getSWordNext(word));
        freeSWord(tmp);
    } freeSWord(word);
}
