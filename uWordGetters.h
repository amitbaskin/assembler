#include "wordIdentifiers.h"
#ifndef ASSEMBLER_U_WORD_GETTERS_H
#define ASSEMBLER_U_WORD_GETTERS_H
opWord *getOpWord(uWord *uWord);
label *getLab(uWord *uWord);
reg getReg(uWord *uWord);
long getNumData(uWord *uWord);
char getChrData(uWord *uWord);
#endif
