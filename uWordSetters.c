#include "labSetters.h"
#include "uWordGetters.h"

extern int dataCounter;

void setUOpWord(uWord *word, opWord *op){
    word->op = op;
}

void setULab(uWord *word, label *lab){
    word->lab = lab;
}

void setUReg(uWord *word, reg r){
    word->reg = r;
}

void setUNumData(uWord *word, long num){
    word->numData = num;
}

void setUChrData(uWord *word, char chr){
    word->chrData = chr;
}

void setULabAddress(uWord *word, int address){
    setLabAddress(getULab(word), address);
}

void setULabType(uWord *word, labelType type){
    setLabType(getULab(word), type);
}
