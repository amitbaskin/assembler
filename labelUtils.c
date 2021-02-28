#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "generalUtils.h"
#include "labelUtils.h"
#include "wordIdentifiers.h"
#include "sWordSetters.h"
#include "labelSetters.h"
#include "labelGetters.h"

result checkRel(char *word){
    if (word[0] != REL_PREFIX) return FALSE;
    word++;
    return isLegalLabel(word, strlen(word));
}

result isLegalLabel(char *word, unsigned long len){
    int i;
    if (!isalpha(word[0])) return ERR;
    for (i=1; i<len-2; i++){
        if(!isalnum(word[i])) return ERR;
    } return TRUE;
}

result isLabelDeclaration(const char *word, unsigned long len){
    if (word[len-2] != LABEL_SUFFIX) return FALSE;
    return TRUE;
}

label *getNewEmptyLabel(){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    label *lab = (label *) ptr;
    return lab;
}

label *getNewLabelByName(char *name){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    label *lab = (label*) ptr;
    setLabelName(lab, name);
    return lab;
}

result isLabelTypeLegal(label *lab, labelType type){
    switch (type) {
        case L_ENT:
            if (getLabelType(lab) == EXT) return ERR;
            break;

        case EXT:
            if (getLabelType(lab) == L_ENT) return ERR;
            break;

        default:
            return SUCCESS;
    } return SUCCESS;
}
