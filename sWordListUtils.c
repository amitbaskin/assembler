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
    setSWordNext(*sWordLst, &word);
    setThisSWord(sWordLst, getSWordNext(*sWordLst));
}

result addOpWord(opWord *opWord, sWordLst *instLst){
    sWord *sOpWord;
    VALIDATE_VAL(createAndAddWord(&sOpWord, setSOpWordStatus, instLst), "");
    setSUOpWord(sOpWord, opWord);
    setSOpWordStatus(sOpWord);
    setSWordAddress(sOpWord, instructionCounter++);
    return SUCCESS;
}

result createAndAddWord(sWord **word, void setStatus(), sWordLst *lst){
    VALIDATE_VAL(getNewEmptySword(word), "");
    setStatus(*word);
    addSWord(lst, *word);
    return SUCCESS;
}

result addLabToInstLst(sWordLst *instLst, char *name, labelType type, unsigned char isRel){
    sWord *sWordLab;
    VALIDATE_VAL(getNewEmptySword(&sWordLab), "");
    setSLabStatus(sWordLab);
    label *lab;
    getNewEmptyLab(&lab);
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
    setSWordAddress(sWordReg, instructionCounter++);
    return SUCCESS;
}

void addNumWord(long num, wordStatus status, sWordLst *instLst){
    sWord *sWordNum;
    createAndAddWord(&sWordNum, setSNumStatus, instLst);
    setSUNumData(sWordNum, num);
    setSWordStatus(sWordNum, status);
    setSWordAddressType(sWordNum, R_TYPE);
    setSWordAddress(sWordNum, dataCounter++);
}

void addChrWord(char chr, sWordLst *dataLst){
    sWord *sWordChr;
    createAndAddWord(&sWordChr, setSChrStatus, dataLst);
    setSUChrData(sWordChr, chr);
    setSWordStatus(sWordChr, CHR_DATA);
    setSWordAddressType(sWordChr, R_TYPE);
    setSWordAddress(sWordChr, dataCounter++);
}

void freeSWordLstHelper(sWord *word){
    sWord *tmp;
    while(word != NULL && getSWordStatus(word) != W_NONE && getSWordNext(word) != NULL){
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
//    ADD_TO_LIST(sWord, getSWordStatus(getSWordTail(lst)) == W_NONE, word)
    if (getSWordStatus(getSWordTail(lst)) == W_NONE) {                        \
        lst->tail = word;              \
        *(lst->tail->next) = lst->head;\
        lst->head = *(lst->tail->next);   \
                                       \
    } else{                            \
        lst->head = word;        \
        lst->head = *(lst->head->next);              \
    }                                  \
}

sWord *getSWordIterNext(sWordLst *lst){
    if (lst->head == lst->cur){ \
        lst->cur = lst->tail;\
        return NULL;         \
    } sWord *cur = lst->cur;  \
    sWord *tmp = cur;         \
    lst->cur = *(cur->next);    \
    return tmp;              \
}

void resetSWordIter(sWordLst *lst){
    sWord *head = getSWordHead(lst);
    setThisSWord(&head, getSWordTail(lst));
}

result getNewSWordLst(sWordLst **lst){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(sWordLst), &ptr), "")
    *lst = ptr;
    VALIDATE_VAL(getAlloc(sizeof(sWord), &ptr), "")
    (*lst)->head = (*lst)->tail = (*lst)->cur;
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
