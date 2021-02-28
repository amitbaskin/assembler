#include <string.h>
#include "labelSetters.h"
#include "generalUtils.h"

void setDataLabel(label *lab){
    lab->isData = 1;
}

void setCodeLabel(label *lab){
    lab->isCode = 1;
}

void setRel(label *lab){
    lab->isRel = 1;
}

void setLabelAddress(label *lab, int address){
    lab->address = address;
}

result setLabelName(label *lab, char *name){
    void *ptr;
    unsigned long len = strlen(name)+1;
    if (getAlloc(len, &ptr) == ERR) return ERR;
    lab->name = (char *) ptr;
    strcpy(lab->name, name);
    (lab->name)[len] = '\0';
    return SUCCESS;
}

void setLabelType(label *lab, labelType type){
    lab->type = type;
}

void setNextLabel(label *lab, label *next){
    lab->next = next;
}

void setThisLabel(label **this, label *other){
    *this = other;
}