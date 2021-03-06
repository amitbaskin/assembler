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

void addWord(sWord *word, sWord **sWordLst){
    if (getSUWord(word) == NULL) {
        setThisSWord(sWordLst, word);
        return;
    }
    setSWordNext(*sWordLst, word);
    setThisSWord(sWordLst, getSWordNext(*sWordLst));
}

result addOpWord(opWord *opWord, sWordLst *instLst){
    sWord *sOpWord;
    VALIDATE_VAL(createAndAddWord(&sOpWord, setSUOpWordStatus, instLst), "");
    setSUOpWord(sOpWord, opWord);
    setSWordAddress(sOpWord, instructionCounter++);
    return SUCCESS;
}

result createAndAddWord(sWord **word, void setStatus(), sWordLst *lst){
    VALIDATE_VAL(getNewEmptySword(word), "");
    setStatus(*word);
    addSWord(lst, *word);
    return SUCCESS;
}

result addLabToInstLst(sWordLst *instLst, labelLst *labLst, char *name, labelType type, unsigned char isRel){
    sWord *sWordLab;
    VALIDATE_VAL(createAndAddWord(&sWordLab, setSULabStatus, instLst), "");
    label *lab;
    label *head = getLabHead(labLst);
    char *headName = getLabName(head);
    if (headName == NULL) {
        getNewLabByName(&lab, headName);
        setLabName(lab, name);
    } if (isLabInLst(labLst, &lab, type, name) != TRUE) {
        getNewLabByName(&lab, name);
        setSWordAddress(sWordLab, instructionCounter++);
    } setLabType(lab, type);
    if (isRel) setLabRel(lab, 1);
    setSULab(sWordLab, lab);
    return SUCCESS;
}

result addRegWord(int reg, sWordLst *instLst){
    sWord *sWordReg;
    VALIDATE_VAL(createAndAddWord(&sWordReg, setSURegStatus, instLst), "");
    setSUReg(sWordReg, reg);
    setSWordAddress(sWordReg, instructionCounter++);
    return SUCCESS;
}

void addNumWord(long num, wordStatus status, sWordLst *instLst){
    sWord *sWordNum;
    createAndAddWord(&sWordNum, setSUNumStatus, instLst);
    setSUNumData(sWordNum, num);
    setSUWordStatus(sWordNum, status);
    setSWordAddressType(sWordNum, R_TYPE);
    setSWordAddress(sWordNum, dataCounter++);
}

void addChrWord(char chr, sWordLst *dataLst){
    sWord *sWordChr;
    createAndAddWord(&sWordChr, setSUChrStatus, dataLst);
    setSUChrData(sWordChr, chr);
    setSUWordStatus(sWordChr, CHR_DATA);
    setSWordAddressType(sWordChr, R_TYPE);
    setSWordAddress(sWordChr, dataCounter++);
}

void freeSWordLstHelper(sWord *word){
    sWord *tmp;
    while(word != NULL && getSUWordStatus(word) != W_NONE && getSWordNext(word) != NULL){
        tmp = word;
        setThisSWord(&word, getSWordNext(word));
        freeSWord(tmp);
    } freeSWord(word);
}

sWord *getSWordHead(sWordLst *lst){
    return lst->head;
}

sWord *getSWordTail(sWordLst *lst){
    return lst->tail;
}

sWord *getSWordCur(sWordLst *lst){
    return lst->cur;
}

void addSWord(sWordLst *lst, sWord *word){
    ADD_TO_LIST(sWord, getSUWordStatus(getSWordTail(lst)) == W_NONE, word)
}

sWord *getSWordIterNext(sWordLst *lst){
    GET_ITER_NEXT(sWord)
}

void resetSWordIter(sWordLst *lst){
    sWord *head = getSWordHead(lst);
    setThisSWord(&head, getSWordTail(lst));
}

result getNewSWordLst(sWordLst **lst){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(sWordLst), &ptr), "")
    *lst = ptr;
    return SUCCESS;
}

result initializeSWordLst(sWordLst **lst){
    VALIDATE_VAL(getNewSWordLst(lst), "");
    VALIDATE_VAL(getNewEmptySword(&((*lst)->tail)), "")
    (*lst)->cur = (*lst)->head = (*lst)->tail;
    return SUCCESS;
}

void freeSWordLst(sWordLst *lst){
    freeSWordLstHelper(getSWordTail(lst));
}
