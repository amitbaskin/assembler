#include "uWordGetters.h"
#include "labGetters.h"
#include "generalUtils.h"

opWord *getUOpWord(uWord *word){
    return word->op;
}

label *getULab(uWord *word){
    return word->lab;
}

reg getUReg(uWord *word){
    return word->reg;
}

long getUNumData(uWord *word){
    return word->numData;
}

char getUChrData(uWord *word){
    return word->chrData;
}

char getUStatus(uWord *word){
    return word->status;
}

char *getULabName(uWord *word){
    return getLabName(getULab(word));
}

int getULabAddress(uWord *word){
    return getLabAddress(getULab(word));
}

labelType getULabType(uWord *word){
    return getLabType(getULab(word));
}

unsigned char isUCodeLab(uWord *word){
    return isCodeLab(getULab(word));
}

unsigned char isUDataLab(uWord *word){
    return isDataLab(getULab(word));
}

unsigned char isURelLab(uWord *word){
    return isRelLab(getULab(word));
}

label *getUNextLab(uWord *word){
    return getLabNext(getULab(word));
}
