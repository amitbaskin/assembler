#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "generalUtils.h"
#include "labelUtils.h"
#include "wordIdentifiers.h"
#include "sWordSetters.h"

int isRel(char *word){
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

void addLabel(label **labLst, label *next){
    (*labLst)->next = next;
}

void addDataLabel(label **labLst, char *name){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    label *lab = (label *) ptr;
    lab->name = name;
    lab->address = dataCounter++;
    lab->isData = 1;
    (*labLst)->next = lab;
    *labLst = lab;
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

void setDataLabel(label *lab){
    lab->isData = 1;
}

void setCodeLabel(label *lab){
    lab->isCode = 1;
}

void setRel(label *lab){
    lab->isRel = 1;
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

void setAddress(label *lab, int address){
    lab->address = address;
}

result setName(label *lab, char *name, unsigned long len){
    void *ptr;
    if (getAlloc(len+1, &ptr) == ERR) return ERR;
    lab->name = (char *) ptr;
    strcpy(lab->name, name);
    (lab->name)[len] = '\0';
    return SUCCESS;
}

void setLabelType(label *lab, labelType type){
    lab->type = type;
}

result getLabelAddress(char *name, label *headLab, int *address){
    while (headLab != NULL){
        if (!strcmp(name, headLab->name)) {
            *address = headLab->address;
            return SUCCESS;
        } headLab = headLab->next;
    } return ERR;
}



result getRelLabelAddress(char *name, label *headLab, int address, int *dist){
    while (headLab != NULL){
        if (!strcmp(name, headLab->name)) {
            *dist = (address - headLab->address);
            return SUCCESS;
        } headLab = headLab->next;
    } return ERR;
}

result checkLabelLegality(label *lab, labelType type){
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

result isLabInLst(label *labHead, label **lab, labelType type, char *name){
    while (labHead != NULL){
        if (!strcmp(labHead->name, name)) {
            *lab = labHead;
            if (checkLabelLegality(*lab, type) == ERR) return ERR;
            return TRUE;
        } labHead = labHead->next;
    } return FALSE;
}
