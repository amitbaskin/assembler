#include "uWordGetters.h"

opWord *getOpWord(uWord *uWord){
    return uWord->op;
}

label *getLab(uWord *uWord){
    return uWord->lab;
}

reg getReg(uWord *uWord){
    return uWord->reg;
}

long getNumData(uWord *uWord){
    return uWord->numData;
}

char getChrData(uWord *uWord){
    return uWord->chrData;
}
