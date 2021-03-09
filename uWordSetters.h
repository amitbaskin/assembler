#include "wordId.h"
#include "sWordSetters.h"
#ifndef ASSEMBLER_U_WORD_SETTERS_H
#define ASSEMBLER_U_WORD_SETTERS_H
void setUOpWord(uWord *uWord, opWord *op);
void setULab(uWord *uWord, label *lab);
void setUReg(uWord *uWord, reg r);
void setUNumData(uWord *word, long num);
void setUChrData(uWord *word, char chr);
void setThisUWord(uWord **this, uWord *other);
void setUDataLab(uWord *word, unsigned char toSet);
void setUCodeLab(uWord *word, unsigned char toSet);
void setURelLab(uWord *word, unsigned char toSet);
void setULabIsNameAlloc(uWord *word, unsigned char toSet);
void setULabAddress(uWord *word, int address);
result setULabName(uWord *word, char *name);
void setULabType(uWord *word, labelType type);
void setUNextLab(uWord *word, label *next);
void setUOpIndex(uWord *word, int index);
void setUOpSrcRef(uWord *word, ref src);
void setUOpDestRef(uWord *word, ref dest);
#endif
