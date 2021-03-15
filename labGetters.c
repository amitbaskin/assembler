/* getters for the label data structure */

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

unsigned char isLabData(label *lab){
    return lab->isData;
}

unsigned char isLabRel(label *lab){
    return lab->isRel;
}
