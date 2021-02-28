#include "uWordUtils.h"

void setOpWord(uWord *word, opWord *init){
    word->init = init;
}

void setLab(uWord *uWord, label *lab){
    uWord->lab = lab;
}

void setReg(uWord *uWord, reg r){
    uWord->reg = r;
}

void setNumData(uWord *uWord, long num){
    dataCounter++;
    uWord->numData = num;
}

void setChrData(uWord *uWord, char chr){
    dataCounter++;
    uWord->chrData = chr;
}
