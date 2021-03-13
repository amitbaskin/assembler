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

unsigned char isLabCode(label *lab){
    return lab->isCode;
}

unsigned char isLabData(label *lab){
    return lab->isData;
}

unsigned char isLabRel(label *lab){
    return lab->isRel;
}
