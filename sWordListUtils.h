#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_S_WORD_LIST_UTILS_H
#define ASSEMBLER_S_WORD_LIST_UTILS_H
result addOpWord(opWord *opWord, sWordLst *instLst);
result addRegWord(int reg, sWordLst *instLst);
void addNumWord(long num, int address, wordStatus status, sWordLst *lst);
void addChrWord(char chr, sWordLst *dataLst);
sWord *getSWordTail(sWordLst *lst);
result initSWordLst(sWordLst **lst);
void freeSWordLst(sWordLst *lst);
result addLabToInstLst(sWordLst *instLst, char *name, int address, wordStatus status, labelType labType,
                       unsigned char isRel);
#endif
