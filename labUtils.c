/* this file is used to handle the label data structure */

#include <ctype.h>
#include <string.h>
#include "labUtils.h"
#include "labSetters.h"
#include "labGetters.h"
#include "parseLineUtils.h"
#include "errFuncs.h"
#include "opDefGetters.h"
#include "globalVars.h"


result checkRel(char **word){
    /* check if the given string is a relative legal label */
    if ((*word)[0] != REL_PREFIX) return FALSE;
    (*word)++;
    return isLegalLabHelper(*word, strlen(*word));
}

result isLegalLabHelper(char *word, unsigned long len){
    /* helps determine if the given word is in a legal label format
     * returns ERR if not legal and SUCCESS otherwise */
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
    /* gets a new label with the given name and length if it in the right format
     * returns ERR if it is not or if an error has occurred in the process and SUCCESS otherwise */
    VALIDATE_VAL(isLegalLabHelper(*word, len) );
    VALIDATE_VAL(getNewLabByName(lab, *word))
    return TRUE;
}

result processLabel(char **line, char **word, label **lab, unsigned long len){
    /* gets a new label with the given name and length if it in the right format
     * further more turn on the label flag if the name of the label is legal
     * returns ERR if it is not or if an error has occurred in the process and SUCCESS otherwise */
    result res;
    res = getLegalLab(word, lab, len);
    if (res == TRUE) {
        raiseLabelFlag();
        getWord(line, word, 0);
    } return res;
}

result initLab(label **lab){
    /* allocates memory for a new label */
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(label), &ptr))
    *lab = (label *) ptr;
    return SUCCESS;
}

result getNewLabByName(label **lab, char *name){
    /* gets a new label with given name
     * returns ERR if a memory allocation error has occurred in the process and SUCCESS otherwise */
    VALIDATE_VAL(initLab(lab))
    VALIDATE_VAL(setLabName(*lab, name))
    return SUCCESS;
}

result isLabTypeLegal(label *lab, labelType type){
    /* used in the second parse to determine if a label was declared both entry and extern
     * if so returns ERR and else returns SUCCESS */
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
    /* frees the memory allocated for the given lab */
    freeHelper(lab->name);
    freeHelper(lab);
}

void promoteLab(label **lab){
    /* sets the given label to point to its successor */
    *lab = (*lab)->next;
}
