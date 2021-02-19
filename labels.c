#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include "labels.h"
#include "wordIdentifiers.h"

int isRel(const char *word){
    if (word[0] == REL_PREFIX) return TRUE;
    return FALSE;
}

unsigned char isLabel(char *word, unsigned long len){
    int i;
    if (!isalpha(word[0])) return ERR;
    for (i=1; i<len-2; i++){
        if(!isalnum(word[i])) return ERR;
    } return TRUE;
}

unsigned char isLabelDeclaration(const char *word, unsigned long len){
    if (word[len-2] != LABEL_SUFFIX) return FALSE;
    return TRUE;
}

void addLabel(label *last, label *next){
    last->next = next;
}

label *getBasicLabel(label **last, char *name, unsigned int address){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    struct label *lab = (label *) ptr;
    lab->name = name;
    lab->address = address;
    (*last)->next = lab;
    *last = lab;
    return lab;
}

void setDataLabel(label *lab){
    lab->isData = 1;
}

void setCodeLabel(label *lab){
    lab->isCode = 1;
}

void setEntLabel(label *lab){
    lab->isEnt = 1;
}

void setExtLabel(label *lab){
    lab->isExt = 1;
}

unsigned char getLabelAddress(char *name, label *lst, unsigned int *address){
    while (lst != NULL){
        if (!strcmp(name, lst->name)) {
            *address = lst->address;
            return SUCCESS;
        } lst = lst->next;
    } return ERR;
}

unsigned char getRelLabelAddress(char *name, label *lst, unsigned int address, int *dist){
    while (lst != NULL){
        if (!strcmp(name, lst->name)) {
            *dist = ((signed) address - (signed) lst->address);
            return SUCCESS;
        } lst = lst->next;
    } return ERR;
}
