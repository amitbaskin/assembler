#include "machineWordIdentifiers.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_MANAGE_MACHINE_WORD_H
#define ASSEMBLER_MANAGE_MACHINE_WORD_H
static result labelFlag = FALSE;
static unsigned char instructionCounter = 100;
static unsigned char dataCounter = 0;
void addWord(sWord *word, sWord **sWordLst);
initial *getInitial(char *op, ref src, ref dest);
uWord *getUWord();
void setInit(uWord *word, initial *init);
void setLab(uWord *uWord, label *lab);
void setReg(uWord *uWord, reg r);
void setNumData(uWord *uWord, int num);
void setChrData(uWord *uWord, char chr);
sWord *getSword();
void setUWord(sWord *sWord, uWord *uWord);
void setSWordStatus(sWord *sWord, wordStatus status);
void setSwordAddress(sWord *sWord, int address);
void setSWordAddressType(sWord *sWord, char addressType);
void addInitWord(initial *init, sWord **sWordLst);
void addLabWord(label *lab, sWord **sWordLst);
void addRegWord(int reg, sWord **sWordLst);
void addNumWord(int num, sWord **sWordLst);
void addChrWord(char chr, sWord **sWordLst);
#endif
