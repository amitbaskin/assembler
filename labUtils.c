#include <ctype.h>
#include <string.h>
#include "generalUtils.h"
#include "labUtils.h"
#include "wordId.h"
#include "sWordSetters.h"
#include "labSetters.h"
#include "labGetters.h"

result checkRel(char *word){
    if (word[0] != REL_PREFIX) return FALSE;
    word++;
    return isLegalLabel(word, strlen(word));
}

result isLegalLabel(char *word, unsigned long len){
    int i;
    if (!isalpha(word[0])) return ERR;
    if (len == 1) return TRUE;
    for (i=1; i<len-2; i++) if (!isalnum(word[i])) return ERR;
    return TRUE;
}

result checkLabelLegality(char **word, label **lab, unsigned long len){
    if (isLegalLabel(*word, len) != TRUE) return ERR;
    return getNewLabByName(lab, *word);
}

result isLabelDeclaration(char *word, label **lab, unsigned long len){
    if (word[len-1] != LABEL_SUFFIX) return FALSE;
    word[len-1] = '\0';
    return checkLabelLegality(&word, lab, len-1);
}

result getNewEmptyLab(label **lab){
    void *ptr;
    VALIDATE_FUNC_CALL(getAlloc(sizeof(label), &ptr), "")
    *lab = (label *) ptr;
    return SUCCESS;
}

result getNewLabByName(label **lab, char *name){
    void *ptr;
    VALIDATE_FUNC_CALL(getAlloc(sizeof(label), &ptr), "");
    *lab = (label*) ptr;
    setLabName(*lab, name);
    return SUCCESS;
}

result isLabTypeLegal(label *lab, labelType type){
    switch (type) {
        case L_ENT:
            if (getLabType(lab) == EXT) return ERR;
            break;

        case EXT:
            if (getLabType(lab) == L_ENT) return ERR;
            break;

        default:
            return SUCCESS;
    } return SUCCESS;
}

void copyLab(label *input, label *output){
    char *outputName = getLabName(output);
    getWordAlloc(&outputName, strlen(getLabName(input)));
    strcpy(getLabName(output), getLabName(input));
    setLabAddress(output, getLabAddress(input));
    setLabType(output, getLabType(input));
    setLabIsNameAlloc(output, isLabNameAlloc(input));
    setLabCode(output, isLabCode(input));
    setLabData(output, isLabData(input));
    setLabRel(output, isLabRel(input));
}

void freeLab(label *lab){
    if (lab->isNameAlloc) freeHelper(lab->name);
    freeHelper(lab);
}
