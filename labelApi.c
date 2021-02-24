#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "generalUtils.h"
#include "labelApi.h"
#include "machineWordIdentifiers.h"
#include "manageMachineWord.h"

int isRel(const char *word){
    if (word[0] == REL_PREFIX) return TRUE;
    return FALSE;
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

void addLabel(label *last, label *next){
    last->next = next;
}

void addDataLabel(label **last, char *name){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    label *lab = (label *) ptr;
    lab->name = name;
    lab->address = dataCounter;
    lab->isData = 1;
    (*last)->next = lab;
    *last = lab;
}

label *getBasicLabel(char *name, int address){
    void *ptr;
    getAlloc(sizeof(label), &ptr);
    struct label *lab = (label *) ptr;
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

void setEntLabel(label *lab){
    lab->isEnt = 1;
}

void setExtLabel(label *lab){
    lab->isExt = 1;
}

unsigned char getLabelAddress(char *name, label *lst, int *address){
    while (lst != NULL){
        if (!strcmp(name, lst->name)) {
            *address = lst->address;
            return SUCCESS;
        } lst = lst->next;
    } return ERR;
}

unsigned char getRelLabelAddress(char *name, label *lst, int address, int *dist){
    while (lst != NULL){
        if (!strcmp(name, lst->name)) {
            *dist = (address - lst->address);
            return SUCCESS;
        } lst = lst->next;
    } return ERR;
}

result isLabelInLst(label *lst, char *name){
    while (lst != NULL){
        if (!strcmp(lst->name, name)) return TRUE;
        lst = lst->next;
    } return FALSE;

}
