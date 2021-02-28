#include "machineWordIdentifiers.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_MANAGE_MACHINE_WORD_H
#define ASSEMBLER_MANAGE_MACHINE_WORD_H
static result labelFlag = FALSE;
static unsigned char instructionCounter = 100;
static unsigned char dataCounter = 0;
static unsigned char lineCounter = 1;
static unsigned char ICF = 0;
static unsigned char DCF = 0;
void addWord(sWord *word, sWord **sWordLst);
initial *getInitWord(int opIndex, ref src, ref dest);
uWord *getUWord();
void setInit(uWord *word, initial *init);
void setLab(uWord *uWord, label *lab);
void setReg(uWord *uWord, reg r);
void setNumData(uWord *uWord, long num);
void setChrData(uWord *uWord, char chr);
sWord *getSword();
void setUWord(sWord *sWord, uWord *uWord);
void setSWordStatus(sWord *sWord, wordStatus status);
void setSwordAddress(sWord *sWord, int address);
void setSWordAddressType(sWord *sWord, char addressType);
sWord *createAndAddWord(void setStatus(), wordStatus status, sWord **sWordLst);
void addInitWord(initial *init, sWord **sWordLst);
void addLabWord(sWord **sWordLst, unsigned long len, char *name, label *labHead, unsigned char isRel);
void addRegWord(int reg, sWord **sWordLst);
void addNumWord(long num, sWord **sWordLst);
void addChrWord(char chr, sWord **sWordLst);
#endif
