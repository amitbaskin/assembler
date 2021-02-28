#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "generalUtils.h"
#include "labelUtils.h"
#include "wordIdentifiers.h"
#include "sWordSetters.h"

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

label *getEmptyLabel(){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    struct label *lab = (label *) ptr;
    return lab;
}

label *getBasicLabel(char *name, int address){
    label *lab = getEmptyLabel();
    lab->name = name;
    lab->address = address;
    return lab;
}

label *getLabel(unsigned long len, char *name){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    label *lab = (label*) ptr;
    getAlloc(len, &ptr);
    lab->name = (char *) ptr;
    strcpy(lab->name, name);
    return lab;
}

void addLabel(label **labLst, label *next){
    (*labLst)->next = next;
}

result isLabelTypeLegal(label *lab, labelType type){
    switch (type) {
        case L_ENT:
            if (lab->type == EXT) return ERR;
            break;

        case EXT:
            if (lab->type == L_ENT) return ERR;
            break;

        default:
            return SUCCESS;
    } return SUCCESS;
}
