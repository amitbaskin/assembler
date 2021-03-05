#include "wordId.h"
#ifndef ASSEMBLER_S_WORD_LIST_UTILS_H
#define ASSEMBLER_S_WORD_LIST_UTILS_H
void addWord(sWord *word, sWord **sWordLst);
result createAndAddWord(sWord **word, void setStatus(), wordStatus status, sWord **sWordLst);
result addOpWord(opWord *opWord, sWord **sWordLst);
result addLabToInstLst(sWord **sWordLst, char *name, labelType
type, label *labHead, unsigned char isRel);
result addRegWord(int reg, sWord **sWordLst);
void addNumWord(long num, wordStatus status, sWord **sWordLst);
void addChrWord(char chr, sWord **sWordLst);
void freeSWordLst(sWord *word);
#endif
