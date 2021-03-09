#include "wordId.h"
#ifndef ASSEMBLER_RAW_WORD_UTILS_H
#define ASSEMBLER_RAW_WORD_UTILS_H
result initRawWord(rawWord **word);
void freeRawWord(rawWord *word);
void promoteRawWord(rawWord **word);
rawWord *getRawWordNext(rawWord *word);
char *getRawWordStr(rawWord *raw);
int getRawWordNum(rawWord *raw);
void setRawWordNext(rawWord *this, rawWord *other);
void setRawWordStr(rawWord *raw, char *str);
void setRawWordNum(rawWord *raw, int num);
#endif
