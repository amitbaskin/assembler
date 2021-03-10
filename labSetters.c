#include <string.h>
#include "labSetters.h"
#include "generalUtils.h"
#include "errFuncs.h"

void setLabData(label *lab, unsigned char toSet){
    lab->isData = toSet;
}

void setLabCode(label *lab, unsigned char toSet){
    lab->isCode = toSet;
}

void setLabRel(label *lab, unsigned char toSet){
    lab->isRel = toSet;
}

void setLabIsNameAlloc(label *lab, unsigned char toSet){
    lab->isNameAlloc = toSet;
}

void setLabAddress(label *lab, int address){
    lab->address = address;
}

result setLabName(label *lab, char *name){
    void *ptr;
    unsigned long len = strlen(name) + 1;
    VALIDATE_VAL(getAlloc(len, &ptr))
    lab->name = (char *) ptr;
    strcpy(lab->name, name);
    setLabIsNameAlloc(lab, 1);
    return SUCCESS;
}

void setLabType(label *lab, labelType type){
    lab->type = type;
}

void setLabNext(label *lab, label *next){
    lab->next = next;
}

void setThisLab(label **this, label *other){
    *this = other;
}
