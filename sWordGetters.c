#include "uWordGetters.h"

uWord *getSUWord(sWord *word){
    return word->uWord;
}

wordStatus getSWordStatus(sWord *word){
    return word->status;
}

int getSWordAddress(sWord *word){
    return word->address;
}

char getSWordAddressType(sWord *word){
    return word->addressType;
}

opWord *getSUOpWord(sWord *word){
    return getUOpWord(getSUWord(word));
}

label *getSULab(sWord *word){
    return getULab(getSUWord(word));
}

reg getSUReg(sWord *word){
    return getUReg(getSUWord(word));
}

long getSUNumData(sWord *word){
    return getUNumData(getSUWord(word));
}

char getSUChrData(sWord *word){
    return getUChrData(getSUWord(word));
}

char *getSULabName(sWord *word){
    return getULabName(getSUWord(word));
}

int getSULabAddress(sWord *word){
    return getULabAddress(getSUWord(word));
}

labelType getSULabType(sWord *word){
    return getULabType(getSUWord(word));
}

unsigned char isSULabRel(sWord *word){
    return isURelLab(getSUWord(word));
}
