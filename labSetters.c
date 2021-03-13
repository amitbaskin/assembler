#include <string.h>
#include "labSetters.h"

void setLabData(label *lab, unsigned char toSet){
    lab->isData = toSet;
}

void setLabCode(label *lab, unsigned char toSet){
    lab->isCode = toSet;
}

void setLabRel(label *lab, unsigned char toSet){
    lab->isRel = toSet;
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
    return SUCCESS;
}

void setLabType(label *lab, labelType type){
    lab->type = type;
}
