#include <ctype.h>
#include <string.h>
#include "labUtils.h"
#include "labSetters.h"
#include "labGetters.h"
#include "parseLineUtils.h"
#include "opDef.h"
#include "errFuncs.h"
#include "opDefGetters.h"

extern unsigned char labelFlag;

result checkRel(char **word){
    if ((*word)[0] != REL_PREFIX) return FALSE;
    (*word)++;
    return isLegalLabHelper(*word, strlen(*word));
}

result isLegalLabHelper(char *word, unsigned long len){
    int i;
    char *opName;
    char *regName;
    if (len == 0) {
        emptyLabelErr();
        return ERR;
    } if (len > MAX_LAB_LEN){
        labTooLongErr();
        return ERR;
    } if (!isalpha(word[0])) {
        illegalChrErr();
        return ERR;
    } if (len == 1) return TRUE;
    for (i=1; i<len; i++) {
        if (!isalnum(word[i])) {
            illegalChrErr();
            return ERR;
        }
    } for (i=0; i < OPERATIONS_AMOUNT; i++){
        opName = getOpName(i);
        if (strcmp(word, opName) == 0) {
            keyWordErr(opName);
            return ERR;
        }
    } for (i=0; i < REGS_AMOUNT; i++){
        regName = getReg(i);
        if (strcmp(word, regName) == 0) {
            keyWordErr(regName);
            return ERR;
        }
    } return TRUE;
}

result getLegalLab(char **word, label **lab, unsigned long len){
    VALIDATE_VAL(isLegalLabHelper(*word, len) );
    VALIDATE_VAL(getNewLabByName(lab, *word))
    return TRUE;
}

result processLabel(char **line, char **word, label **lab, unsigned long len){
    result res;
    res = getLegalLab(word, lab, len);
    if (res == TRUE) {
        labelFlag = 1;
        getWord(line, word, 0);
    } return res;
}

result initLab(label **lab){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(label), &ptr))
    *lab = (label *) ptr;
    return SUCCESS;
}

result getNewLabByName(label **lab, char *name){
    VALIDATE_VAL(initLab(lab))
    VALIDATE_VAL(setLabName(*lab, name))
    return SUCCESS;
}

result isLabTypeLegal(label *lab, labelType type){
    switch (type) {
        case L_ENT:
            if (getLabType(lab) == EXT) {
                illegalLabTypeErr(getLabName(lab));
                return ERR;
            } break;

        case EXT:
            if (getLabType(lab) == L_ENT) {
                illegalLabTypeErr(getLabName(lab));
                return ERR;
            } break;

        default:
            return SUCCESS;
    } return SUCCESS;
}

void freeLab(label *lab){
    freeHelper(lab->name);
    freeHelper(lab);
}

void promoteLab(label **lab){
    *lab = (*lab)->next;
}
