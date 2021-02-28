#include "uWordSetters.h"
#include "labelSetters.h"
#include "uWordGetters.h"

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

void setUDataLabel(uWord *word){
    setDataLabel(getULab(word));
}

void setUCodeLabel(uWord *word){
    setCodeLabel(getULab(word));
}

void setURelLabel(uWord *word){
    setRelLabel(getULab(word));
}

void setULabelAddress(uWord *word, int address){
    setLabelAddress(getULab(word), address);
}

result setULabelName(uWord *word, char *name){
    return setLabelName(getULab(word), name);
}

void setULabelType(uWord *word, labelType type){
    setLabelType(getULab(word), type);
}

void setUNextLabel(uWord *word, label *next){
    setNextLabel(getULab(word), next);
}
