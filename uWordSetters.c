#include "uWordSetters.h"
#include "labSetters.h"
#include "uWordGetters.h"

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
    dataCounter++;
    word->numData = num;
}

void setUChrData(uWord *word, char chr){
    dataCounter++;
    word->chrData = chr;
}

void setThisUWord(uWord **this, uWord *other){
    *this = other;
}

void setUDataLab(uWord *word, unsigned char toSet){
    setLabData(getULab(word), toSet);
}

void setUCodeLab(uWord *word, unsigned char toSet){
    setLabCode(getULab(word), toSet);
}

void setURelLab(uWord *word, unsigned char toSet){
    setLabRel(getULab(word), toSet);
}

void setULabIsNameAlloc(uWord *word, unsigned char toSet){
    setLabIsNameAlloc(getULab(word), toSet);
}

void setULabAddress(uWord *word, int address){
    setLabAddress(getULab(word), address);
}

result setULabName(uWord *word, char *name){
    return setLabName(getULab(word), name);
}

void setULabType(uWord *word, labelType type){
    setLabType(getULab(word), type);
}

void setUNextLab(uWord *word, label *next){
    setLabNext(getULab(word), next);
}
