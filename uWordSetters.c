#include "uWordSetters.h"

void setUOpWord(uWord *uWord, opWord *init){
    uWord->op = init;
}

void setULab(uWord *uWord, label *lab){
    uWord->lab = lab;
}

void setUReg(uWord *uWord, reg r){
    uWord->reg = r;
}

void setUNumData(uWord *uWord, long num){
    dataCounter++;
    uWord->numData = num;
}

void setUChrData(uWord *uWord, char chr){
    dataCounter++;
    uWord->chrData = chr;
}

void setThisUWord(uWord **this, uWord *other){
    *this = other;
}
