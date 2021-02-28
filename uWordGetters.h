#include "wordIdentifiers.h"
#ifndef ASSEMBLER_U_WORD_GETTERS_H
#define ASSEMBLER_U_WORD_GETTERS_H
opWord *getUOpWord(uWord *word);
label *getULab(uWord *word);
reg getUReg(uWord *word);
long getUNumData(uWord *word);
char getUChrData(uWord *v);
char *getULabelName(uWord *word);
int getULabelAddress(uWord *word);
labelType getULabelType(uWord *word);
unsigned char isUCodeLabel(uWord *word);
unsigned char isUDataLabel(uWord *word);
unsigned char isURelLabel(uWord *word);
label *getUNextLabel(uWord *word);
#endif
