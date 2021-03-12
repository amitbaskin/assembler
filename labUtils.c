#include <ctype.h>
#include <string.h>
#include "generalUtils.h"
#include "labUtils.h"
#include "wordId.h"
#include "sWordSetters.h"
#include "labSetters.h"
#include "labGetters.h"
#include "parseLineUtils.h"
#include "opDef.h"
#include "errFuncs.h"

extern unsigned char labelFlag;

result checkRel(char **word){
    if ((*word)[0] != REL_PREFIX) return FALSE;
    (*word)++;
    return isLegalLabel(*word, strlen(*word));
}

result isLegalLabel(char *word, unsigned long len){
    int i;
    if (len == 0) {
        emptyLabelErr();
            return ERR;
    } if (!isalpha(word[0])) {
        illegalChrErr();
        return ERR;
    } if (len == 1) return TRUE;
    for (i=1; i<len; i++) if (!isalnum(word[i])) {
        illegalChrErr();
        return ERR;
    } for (i=0; i < OPERATIONS_AMOUNT; i++){
        if (strcmp(word, operations[i]) == 0) {
            keyWordErr(operations[i]);
            return ERR;
        }
    } for (i=0; i < REGS_AMOUNT; i++){
        if (strcmp(word, regs[i]) == 0) {
            keyWordErr(regs[i]);
            return ERR;
        }
    } return TRUE;
}

result checkLabelLegality(char **word, label **lab, unsigned long len){
    if (len > MAX_LAB_LEN){
        labTooLongErr();
        return ERR;
    } if (isLegalLabel(*word, len) != TRUE) {
        return ERR; /* handled inside */
    } VALIDATE_VAL(getNewLabByName(lab, *word))
    return TRUE;
}

result isLabelDeclaration(char **line, char **word, label **lab, unsigned long len){
    result res;
    res = checkLabelLegality(word, lab, len);
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
    if (lab->isNameAlloc) freeHelper(lab->name);
    freeHelper(lab);
}

void promoteLab(label **lab){
    *lab = (*lab)->next;
}
