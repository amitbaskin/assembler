#include "wordId.h"
#ifndef ASSEMBLER_S_WORD_LIST_UTILS_H
#define ASSEMBLER_S_WORD_LIST_UTILS_H
result createAndAddWord(sWord **word, void setStatus(), sWordLst *lst);
result addOpWord(opWord *opWord, sWordLst *instLst);
result addLabToInstLst(sWordLst *instLst, char *name, labelType type, unsigned char isRel);
result addRegWord(int reg, sWordLst *instLst);
void addNumWord(long num, wordStatus status, sWordLst *lst);
void addChrWord(char chr, sWordLst *dataLst);
void freeSWordLstHelper(sWord *word);
sWord *getSWordTail(sWordLst *lst);
void addSWord(sWordLst *lst, sWord *word);
result initSWordLst(sWordLst **lst);
void freeSWordLst(sWordLst *lst);
#endif
