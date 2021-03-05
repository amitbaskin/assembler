#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_S_WORD_SETTERS_H
#define ASSEMBLER_S_WORD_SETTERS_H
void setSUWord(sWord *sWord, uWord *uWord);
void setSUWordStatus(sWord *word, wordStatus status);
void setSWordAddress(sWord *word, int address);
void setSWordAddressType(sWord *sWord, char addressType);
void setSULabStatus(sWord *word);
void setSUEntStatus(sWord *word);
void setSUNumStatus(sWord *word);
void setSUChrStatus(sWord *word);
void setSURegStatus(sWord *word);
void setSUOpWordStatus(sWord *word);
void setNextSWord(sWord *this, sWord *other);
void setThisSWord(sWord **this, sWord *other);
void setSUOpWord(sWord *word, opWord *op);
void setSULab(sWord *word, label *lab);
void setSUReg(sWord *word, reg r);
void setSUNumData(sWord *word, long num);
void setSUChrData(sWord *word, char chr);
void setSUDataLab(sWord *word);
void setSUCodeLab(sWord *word);
void setSURelLab(sWord *word);
void setSULabAddress(sWord *word, int address);
result setSULabName(sWord *word, char *name);
void setSULabType(sWord *word, labelType type);
void setSUNextLab(sWord *word, label *next);
#endif
