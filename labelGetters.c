#include "labelGetters.h"

char *getLabelName(label *lab){
    return lab->name;
}

int getLabelAddress(label *lab){
    return lab->address;
}

labelType getLabelType(label *lab){
    return lab->type;
}

unsigned char isCodeLabel(label *lab){
    return lab->isCode;
}

unsigned char isDataLabel(label *lab){
    return lab->isData;
}

unsigned char isRelLabel(label *lab){
    return lab->isRel;
}

label *getNextLabel(label *lab){
    return lab->next;
}
