#include "sWordGetters.h"
#include "uWordGetters.h"
#include "generalUtils.h"

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

sWord *getNextSWord(sWord *word){
    return word->next;
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

char *getSULabelName(sWord *word){
    return getULabelName(getSUWord(word));
}

int getSULabelAddress(sWord *word){
    return getULabelAddress(getSUWord(word));
}

labelType getSULabelType(sWord *word){
    return getULabelType(getSUWord(word));
}

unsigned char isSUCodeLabel(sWord *word){
    return isUCodeLabel(getSUWord(word));
}

unsigned char isSUDataLabel(sWord *word){
    return isUDataLabel(getSUWord(word));
}

unsigned char isSURelLabel(sWord *word){
    return isURelLabel(getSUWord(word));
}

label *getSUNextLabel(sWord *word){
    return getUNextLabel(getSUWord(word));
}
