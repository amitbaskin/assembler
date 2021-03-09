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
#include "labLstUtils.h"

extern int dataCounter;

extern int instructionCounter;

result addOpWord(opWord *opWord, sWordLst *instLst){
    sWord *sOpWord;
    VALIDATE_VAL(createAndAddWord(&sOpWord, setSOpWordStatus, instLst), "");
    setSUOpWord(sOpWord, opWord);
    setSOpWordStatus(sOpWord);
    setSWordAddressType(sOpWord, A_TYPE);
    setSWordAddress(sOpWord, instructionCounter++);
    return SUCCESS;
}

result createAndAddWord(sWord **word, void setStatus(), sWordLst *lst){
    VALIDATE_VAL(initSword(word), "");
    setStatus(*word);
    addSWord(lst, *word);
    return SUCCESS;
}

result addLabToInstLst(sWordLst *instLst, char *name, labelType type, unsigned char isRel){
    sWord *sWordLab;
    VALIDATE_VAL(initSword(&sWordLab), "");
    setSWordAddress(sWordLab, instructionCounter++);
    setSLabStatus(sWordLab);
    label *lab;
    initLab(&lab);
    setLabName(lab, name);
    setLabType(lab, type);
    if (isRel) setLabRel(lab, 1);
    setSULab(sWordLab, lab);
    setSLabStatus(sWordLab);
    addSWord(instLst, sWordLab);
    return SUCCESS;
}

result addRegWord(int reg, sWordLst *instLst){
    sWord *sWordReg;
    VALIDATE_VAL(createAndAddWord(&sWordReg, setSRegStatus, instLst), "");
    setSUReg(sWordReg, reg);
    setSWordAddressType(sWordReg, A_TYPE);
    setSWordAddress(sWordReg, instructionCounter++);
    return SUCCESS;
}

void addNumWord(long num, wordStatus status, sWordLst *lst){
    sWord *sWordNum;
    createAndAddWord(&sWordNum, setSNumStatus, lst);
    setSUNumData(sWordNum, num);
    setSWordStatus(sWordNum, status);
    setSWordAddressType(sWordNum, A_TYPE);
    setSWordAddress(sWordNum, dataCounter++);
}

void addChrWord(char chr, sWordLst *dataLst){
    sWord *sWordChr;
    createAndAddWord(&sWordChr, setSChrStatus, dataLst);
    setSUChrData(sWordChr, chr);
    setSWordStatus(sWordChr, CHR_DATA);
    setSWordAddressType(sWordChr, A_TYPE);
    setSWordAddress(sWordChr, dataCounter++);
}

void freeSWordLstHelper(sWord *word){
    sWord *tmp;
    while(word != NULL){
        tmp = word;
        promoteSWord(&word);
        freeSWord(tmp);
    }
}

sWord *getSWordTail(sWordLst *lst){
    return lst->tail;
}

void addSWord(sWordLst *lst, sWord *word){
    ADD_TO_LIST(sWord, getSWordTail(lst) == NULL, word)
}

result initSWordLst(sWordLst **lst){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(sWordLst), &ptr), "")
    *lst = ptr;
    return SUCCESS;
}

void freeSWordLst(sWordLst *lst){
    freeSWordLstHelper(getSWordTail(lst));
}
