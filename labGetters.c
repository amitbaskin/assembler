#include "labGetters.h"

char *getLabName(label *lab){
    return lab->name;
}

int getLabAddress(label *lab){
    return lab->address;
}

labelType getLabType(label *lab){
    return lab->type;
}

unsigned char isCodeLab(label *lab){
    return lab->isCode;
}

unsigned char isDataLab(label *lab){
    return lab->isData;
}

unsigned char isRelLab(label *lab){
    return lab->isRel;
}

label *getNextLab(label *lab){
    return lab->next;
}
