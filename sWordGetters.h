#include "wordId.h"
#ifndef ASSEMBLER_S_WORD_GETTERS_H
#define ASSEMBLER_S_WORD_GETTERS_H
uWord *getSUWord(sWord *word);
wordStatus getSUWordStatus(sWord *word);
int getSWordAddress(sWord *word);
char getSWordAddressType(sWord *word);
sWord *getSWordNext(sWord *word);
sWord *getNewEmptySword();
opWord *getSUOpWord(sWord *word);
label *getSULab(sWord *word);
reg getSUReg(sWord *word);
long getSUNumData(sWord *word);
char getSUChrData(sWord *word);
char *getSULabName(sWord *word);
int getSULabAddress(sWord *word);
labelType getSULabType(sWord *word);
unsigned char isSUCodeLab(sWord *word);
unsigned char isSUDataLab(sWord *word);
unsigned char isSURelLab(sWord *word);
label *getSUNextLab(sWord *word);
#endif
