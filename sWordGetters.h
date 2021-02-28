#include "wordIdentifiers.h"
#ifndef ASSEMBLER_S_WORD_GETTERS_H
#define ASSEMBLER_S_WORD_GETTERS_H
uWord *getSUWord(sWord *word);
wordStatus getSWordStatus(sWord *word);
int getSWordAddress(sWord *word);
char getSWordAddressType(sWord *word);
sWord *getNextSWord(sWord *word);
sWord *getNewEmptySword();
opWord *getSUOpWord(sWord *word);
label *getSULab(sWord *word);
reg getSUReg(sWord *word);
long getSUNumData(sWord *word);
char getSUChrData(sWord *word);
char *getSULabelName(sWord *word);
int getSULabelAddress(sWord *word);
labelType getSULabelType(sWord *word);
unsigned char isSUCodeLabel(sWord *word);
unsigned char isSUDataLabel(sWord *word);
unsigned char isSURelLabel(sWord *word);
label *getSUNextLabel(sWord *word);
#endif
