#include "wordIdentifiers.h"
#include "sWordSetters.h"
#ifndef ASSEMBLER_U_WORD_UTILS_H
#define ASSEMBLER_U_WORD_UTILS_H
void setOpWord(uWord *uWord, opWord *init);
void setLab(uWord *uWord, label *lab);
void setReg(uWord *uWord, reg r);
void setNumData(uWord *uWord, long num);
void setChrData(uWord *uWord, char chr);
#endif
