#include "wordId.h"
#ifndef ASSEMBLER_S_WORD_LIST_UTILS_H
#define ASSEMBLER_S_WORD_LIST_UTILS_H
result createAndAddWord(sWord **word, wordStatus status, sWordLst *lst);
result addOpWord(opWord *opWord, sWordLst *instLst);
result addLabToInstLst(sWordLst *instLst, char *name, int address, wordStatus status, labelType labType, unsigned char
isRel);
result addRegWord(int reg, sWordLst *instLst);
void addNumWord(long num, int address, wordStatus status, sWordLst *lst);
void addChrWord(char chr, sWordLst *dataLst);
void freeSWordLstHelper(sWord *word);
sWord *getSWordTail(sWordLst *lst);
void addSWord(sWordLst *lst, sWord *word);
result initSWordLst(sWordLst **lst);
void freeSWordLst(sWordLst *lst);
#endif
