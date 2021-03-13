#include "wordId.h"
#ifndef ASSEMBLER_U_WORD_SETTERS_H
#define ASSEMBLER_U_WORD_SETTERS_H
void setUOpWord(uWord *uWord, opWord *op);
void setULab(uWord *uWord, label *lab);
void setUReg(uWord *uWord, reg r);
void setUNumData(uWord *word, long num);
void setUChrData(uWord *word, char chr);
void setULabAddress(uWord *word, int address);
void setULabType(uWord *word, labelType type);
#endif
