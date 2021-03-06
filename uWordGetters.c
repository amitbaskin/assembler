/* getters for the uWord data structure */

#include "labGetters.h"


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

unsigned char isURelLab(uWord *word){
    return isLabRel(getULab(word));
}
