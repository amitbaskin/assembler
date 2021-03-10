#include "wordId.h"
#ifndef ASSEMBLER_RAW_WORD_LST_UTILS_H
#define ASSEMBLER_RAW_WORD_LST_UTILS_H
void freeRawWordLstHelper(rawWord *word);
rawWord *getRawWordTail(rawWordLst *lst);
void addRawWord(rawWordLst *lst, rawWord *word);
result initRawWordLst(rawWordLst **lst);
void freeRawWordLst(rawWordLst *lst);
result isRawStrWordInRLst(rawWord *word, rawWordLst *lst);
#endif
