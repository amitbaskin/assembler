#include <string.h>
#include "labSetters.h"
#include "generalUtils.h"

void setDataLab(label *lab){
    lab->isData = 1;
}

void setCodeLab(label *lab){
    lab->isCode = 1;
}

void setRelLab(label *lab){
    lab->isRel = 1;
}

void setLabAddress(label *lab, int address){
    lab->address = address;
}

result setLabName(label *lab, char *name){
    void *ptr;
    unsigned long len = strlen(name) + 1;
    VALIDATE_FUNC_CALL(getAlloc(len, &ptr), "")
    lab->name = (char *) ptr;
    strcpy(lab->name, name);
    return SUCCESS;
}

void setLabType(label *lab, labelType type){
    lab->type = type;
}

void setNextLab(label *lab, label *next){
    lab->next = next;
}

void setThisLab(label **this, label *other){
    *this = other;
}
