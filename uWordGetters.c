#include "uWordGetters.h"
#include "labelGetters.h"
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

char *getULabelName(uWord *word){
    return getLabelName(getULab(word));
}

int getULabelAddress(uWord *word){
    return getLabelAddress(getULab(word));
}

labelType getULabelType(uWord *word){
    return getLabelType(getULab(word));
}

unsigned char isUCodeLabel(uWord *word){
    return isCodeLabel(getULab(word));
}

unsigned char isUDataLabel(uWord *word){
    return isDataLabel(getULab(word));
}

unsigned char isURelLabel(uWord *word){
    return isRelLabel(getULab(word));
}

label *getUNextLabel(uWord *word){
    return getNextLabel(getULab(word));
}
