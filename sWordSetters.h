#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_S_WORD_SETTERS_H
#define ASSEMBLER_S_WORD_SETTERS_H
void setSUWord(sWord *sWord, uWord *uWord);
void setSWordStatus(sWord *sWord, wordStatus status);
void setSWordAddress(sWord *sWord, int address);
void setSWordAddressType(sWord *sWord, char addressType);
void setLabStatus(sWord *sWord);
void setEntStatus(sWord *sWord);
void setNumStatus(sWord *sWord);
void setChrStatus(sWord *sWord);
void setRegStatus(sWord *sWord);
void setOpWordStatus(sWord *sWord);
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
