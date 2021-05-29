/* this file is used to provide utilities for handling the sWordLst data structure used both for the instruction
 * list and the data image list */

#include "sWordListUtils.h"
#include "labUtils.h"
#include "labSetters.h"
#include "sWordSetters.h"
#include "sWordUtils.h"
#include "globalVars.h"


void addSWord(sWordLst *lst, sWord *word){
    /* adds a given sWord to the given sWordLst list */
    ADD_TO_LIST(getSWordTail(lst), word)
}

result createAndAddSWord(sWord **word, wordStatus status, sWordLst *lst){
    /* creates an sWord object with the given wordStatus and adds it to the given sWordLst */
    VALIDATE_VAL(initSword(word))
    setSWordStatus(*word, status);
    addSWord(lst, *word);
    return SUCCESS;
}

void freeSWordLstHelper(sWord *word){
    /* given the tail of an sWordLst, deallocates the entire memory of this list */
    sWord *tmp;
    while(word != NULL){
        tmp = word;
        promoteSWord(&word);
        freeSWord(tmp);
    }
}

result addOpWord(opWord *opWord, sWordLst *instLst){
    /* adds an operator word to the instruction list */
    sWord *sOpWord;
    VALIDATE_VAL(createAndAddSWord(&sOpWord, OP, instLst))
    setSUOpWord(sOpWord, opWord);
    setSOpWordStatus(sOpWord);
    setSWordAddressType(sOpWord, A_TYPE);
    setSWordAddress(sOpWord, getInstructionCounter());
    updateInstructionCounter();
    return SUCCESS;
}

result addLabToInstLst(sWordLst *instLst, char *name, int address, wordStatus status, labelType labType,
                       unsigned char isRel){
    /* creates a label sWord with the given name and adds it to the instruction list
     * returns ERR if a memory allocation ERR occurred and SUCCESS otherwise */
    label *lab;
    sWord *sWordLab;
    VALIDATE_VAL(initSword(&sWordLab))
    setSWordAddress(sWordLab, address);
    setSLabStatus(sWordLab);
    initLab(&lab);
    VALIDATE_VAL(setLabName(lab, name))
    setLabType(lab, labType);
    if (isRel) setLabRel(lab, 1);
    setSULab(sWordLab, lab);
    setSWordStatus(sWordLab, status);
    addSWord(instLst, sWordLab);
    return SUCCESS;
}

result addRegWord(int reg, sWordLst *instLst){
    /* creates a reg sWord and adds it to the instruction list.
     * returns ERR if a memory allocation ERR occurred and SUCCESS otherwise */
    sWord *sWordReg;
    VALIDATE_VAL(createAndAddSWord(&sWordReg, W_REG, instLst))
    setSUReg(sWordReg, reg);
    setSWordAddressType(sWordReg, A_TYPE);
    setSWordAddress(sWordReg, getInstructionCounter());
    updateInstructionCounter();
    return SUCCESS;
}

void addNumWord(long num, int address, wordStatus status, sWordLst *lst){
    /* creates an integer sWord and adds it to the instruction list.
     * returns ERR if a memory allocation ERR occurred and SUCCESS otherwise */
    sWord *sWordNum;
    createAndAddSWord(&sWordNum, status, lst);
    setSUNum(sWordNum, num);
    setSWordAddressType(sWordNum, A_TYPE);
    setSWordAddress(sWordNum, address);
}

void addChrWord(char chr, sWordLst *dataLst){
    /* creates a char sWord and adds it to the instruction list.
     * returns ERR if a memory allocation ERR occurred and SUCCESS otherwise */
    sWord *sWordChr;
    createAndAddSWord(&sWordChr, CHR_DATA, dataLst);
    setSUChrData(sWordChr, chr);
    setSWordStatus(sWordChr, CHR_DATA);
    setSWordAddressType(sWordChr, A_TYPE);
    setSWordAddress(sWordChr, getDataCounter());
    updateDataCounter();
}

sWord *getSWordTail(sWordLst *lst){
    return lst->tail;
}

result initSWordLst(sWordLst **lst){
    /* allocates memory for a new sWordLst */
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(sWordLst), &ptr))
    *lst = ptr;
    return SUCCESS;
}

void freeSWordLst(sWordLst *lst){
    /* deallocates the entire memory of the given sWordLst */
    freeSWordLstHelper(getSWordTail(lst));
}
