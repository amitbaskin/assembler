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
    for (i=1; i<len-2; i++) if (!isalnum(word[i])) return ERR;
    return TRUE;
}

result isLabelDeclaration(const char *word, unsigned long len){
    if (word[len-2] != LABEL_SUFFIX) return FALSE;
    return TRUE;
}

result isLabel(char **word, label **lab, unsigned long len){
    if (isLabelDeclaration(*word, len) == TRUE){
        if (isLegalLabel(*word, len) != TRUE) return ERR;
        setLabName(*lab, *word);
    } return FALSE;
}

result getNewEmptyLabel(label **lab){
    void *ptr;
    VALIDATE_FUNC_CALL(getAlloc(sizeof(label), &ptr), "")
    *lab = (label *) ptr;
    return SUCCESS;
}

label *getNewLabelByName(char *name){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    label *lab = (label*) ptr;
    setLabName(lab, name);
    return lab;
}

result isLabelTypeLegal(label *lab, labelType type){
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
