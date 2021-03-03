#include "wordId.h"
#include "sWordSetters.h"
#ifndef ASSEMBLER_U_WORD_SETTERS_H
#define ASSEMBLER_U_WORD_SETTERS_H
void setUOpWord(uWord *uWord, opWord *init);
void setULab(uWord *uWord, label *lab);
void setUReg(uWord *uWord, reg r);
void setUNumData(uWord *word, long num);
void setUChrData(uWord *word, char chr);
void setThisUWord(uWord **this, uWord *other);
void setUDataLab(uWord *word);
void setUCodeLab(uWord *word);
void setURelLab(uWord *word);
void setULabAddress(uWord *word, int address);
result setULabName(uWord *word, char *name);
void setULabType(uWord *word, labelType type);
void setUNextLab(uWord *word, label *next);
#endif