#include <string.h>
#include "labelLstUtils.h"
#include "labelUtils.h"

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

result isLabInLst(label *labHead, label **lab, labelType type, char *name){
    while (labHead != NULL){
        if (!strcmp(labHead->name, name)) {
            *lab = labHead;
            if (isLabelTypeLegal(*lab, type) == ERR) return ERR;
            return TRUE;
        } labHead = labHead->next;
    } return FALSE;
}
