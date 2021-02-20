#include "machineWordIdentifiers.h"
#ifndef ASSEMBLER_MANAGE_MACHINE_WORD_H
#define ASSEMBLER_MANAGE_MACHINE_WORD_H
void addWord(sWord *word, sWord *last);
initial *getInitial(char *op, ref src, ref dest);
uWord *getUWord();
void setInit(uWord **word, initial *init);
void setLab(uWord **uWord, label *lab);
void setReg(uWord **uWord, reg r);
void setNumData(uWord **uWord, int num);
void setChrData(uWord **uWord, char chr);
sWord *getSword();
void setUWord(sWord **sWord, uWord *uWord);
void setSWordStatus(sWord **sWord, wordStatus status);
void setSwordAddress(sWord **sWord, int address);
void setSWordAddressType(sWord **sWord, char addressType);
#endif
