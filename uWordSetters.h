#include "wordIdentifiers.h"
#include "sWordSetters.h"
#ifndef ASSEMBLER_U_WORD_UTILS_H
#define ASSEMBLER_U_WORD_UTILS_H
void setUOpWord(uWord *uWord, opWord *init);
void setULab(uWord *uWord, label *lab);
void setUReg(uWord *uWord, reg r);
void setUNumData(uWord *uWord, long num);
void setUChrData(uWord *uWord, char chr);
void setThisUWord(uWord **this, uWord *other);
#endif
