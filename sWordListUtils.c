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
    VALIDATE_VAL(createAndAddWord(&sOpWord, OP, instLst), "");
    setSUOpWord(sOpWord, opWord);
    setSOpWordStatus(sOpWord);
    setSWordAddressType(sOpWord, A_TYPE);
    setSWordAddress(sOpWord, instructionCounter++);
    return SUCCESS;
}

result createAndAddWord(sWord **word, wordStatus status, sWordLst *lst){
    VALIDATE_VAL(initSword(word), "");
    setSWordStatus(*word, status);
    addSWord(lst, *word);
    return SUCCESS;
}

result addLabToInstLst(sWordLst *instLst, char *name, int address, wordStatus status, labelType labType, unsigned char
isRel){
    sWord *sWordLab;
    VALIDATE_VAL(initSword(&sWordLab), "");
    setSWordAddress(sWordLab, address);
    setSLabStatus(sWordLab);
    label *lab;
    initLab(&lab);
    setLabName(lab, name);
    setLabType(lab, labType);
    if (isRel) setLabRel(lab, 1);
    setSULab(sWordLab, lab);
    setSWordStatus(sWordLab, status);
    addSWord(instLst, sWordLab);
    return SUCCESS;
}

result addRegWord(int reg, sWordLst *instLst){
    sWord *sWordReg;
    VALIDATE_VAL(createAndAddWord(&sWordReg, W_REG, instLst), "");
    setSUReg(sWordReg, reg);
    setSWordAddressType(sWordReg, A_TYPE);
    setSWordAddress(sWordReg, instructionCounter++);
    return SUCCESS;
}

void addNumWord(long num, int address, wordStatus status, sWordLst *lst){
    sWord *sWordNum;
    createAndAddWord(&sWordNum, status, lst);
    setSUNum(sWordNum, num);
    setSWordAddressType(sWordNum, A_TYPE);
    setSWordAddress(sWordNum, address);
}

void addChrWord(char chr, sWordLst *dataLst){
    sWord *sWordChr;
    createAndAddWord(&sWordChr, CHR_DATA, dataLst);
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
