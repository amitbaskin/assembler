#include "wordId.h"
#ifndef ASSEMBLER_S_WORD_SETTERS_H
#define ASSEMBLER_S_WORD_SETTERS_H
void setSUWord(sWord *sWord, uWord *uWord);
void setSWordStatus(sWord *word, wordStatus status);
void setSWordAddress(sWord *word, int address);
void setSWordAddressType(sWord *sWord, char addressType);
void setSLabStatus(sWord *word);
void setSOpWordStatus(sWord *word);
void setSUOpWord(sWord *word, opWord *op);
void setSULab(sWord *word, label *lab);
void setSUReg(sWord *word, reg r);
void setSUNum(sWord *word, long num);
void setSUChrData(sWord *word, char chr);
void setSULabAddress(sWord *word, int address);
void setSULabType(sWord *word, labelType type);
#endif
