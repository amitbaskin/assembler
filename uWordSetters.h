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
void setUDataLabel(uWord *word);
void setUCodeLabel(uWord *word);
void setURelLabel(uWord *word);
void setULabelAddress(uWord *word, int address);
result setULabelName(uWord *word, char *name);
void setULabelType(uWord *word, labelType type);
void setUNextLabel(uWord *word, label *next);
#endif
