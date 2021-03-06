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
    return isLabCode(getULab(word));
}

unsigned char isUDataLab(uWord *word){
    return isLabData(getULab(word));
}

unsigned char isURelLab(uWord *word){
    return isLabRel(getULab(word));
}

unsigned char isULabNameAlloc(uWord *word) {
    return isLabNameAlloc(getULab(word));
}

label *getUNextLab(uWord *word){
    return getLabNext(getULab(word));
}
