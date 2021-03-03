#include "wordId.h"
#ifndef ASSEMBLER_S_WORD_LIST_UTILS_H
#define ASSEMBLER_S_WORD_LIST_UTILS_H
void addWord(sWord *word, sWord **sWordLst);
sWord *createAndAddWord(void setStatus(), wordStatus status, sWord **sWordLst);
void addOpWord(opWord *opWord, sWord **sWordLst);
void addLabToInstLst(sWord **sWordLst, char *name, labelType type, label *labHead, unsigned char
isRel);
void addRegWord(int reg, sWord **sWordLst);
void addNumWord(long num, wordStatus status, sWord **sWordLst);
void addChrWord(char chr, sWord **sWordLst);
#endif
