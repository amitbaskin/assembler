#include "wordId.h"
#ifndef ASSEMBLER_S_WORD_LIST_UTILS_H
#define ASSEMBLER_S_WORD_LIST_UTILS_H
void addWord(sWord *word, sWord **sWordLst);
result createAndAddWord(sWord **word, void setStatus(), sWordLst *lst);
result addOpWord(opWord *opWord, sWordLst *instLst);
result addLabToInstLst(sWordLst *instLst, labelLst *labLst, char *name, labelType type, unsigned char isRel);
result addRegWord(int reg, sWordLst *instLst);
void addNumWord(long num, wordStatus status, sWordLst *instLst);
void addChrWord(char chr, sWordLst *dataLst);
void freeSWordLstHelper(sWord *word);
sWord *getSWordHead(sWordLst *lst);
sWord *getSWordTail(sWordLst *lst);
sWord *getSWordCur(sWordLst *lst);
void addSWord(sWordLst *lst, sWord *word);
sWord *getSWordIterNext(sWordLst *lst);
void resetSWordIter(sWordLst *lst);
result initializeSWordLst(sWordLst **lst);
void freeSWordLst(sWordLst *lst);
#endif
