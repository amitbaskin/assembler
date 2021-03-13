#include "wordId.h"
#ifndef ASSEMBLER_U_WORD_GETTERS_H
#define ASSEMBLER_U_WORD_GETTERS_H
opWord *getUOpWord(uWord *word);
label *getULab(uWord *word);
reg getUReg(uWord *word);
long getUNumData(uWord *word);
char getUChrData(uWord *v);
char *getULabName(uWord *word);
int getULabAddress(uWord *word);
labelType getULabType(uWord *word);
unsigned char isURelLab(uWord *word);
#endif
