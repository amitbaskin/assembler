#include "wordId.h"
#include "generalUtils.h"
#include "numsData.h"
#ifndef ASSEMBLER_PARSE_LINE_UTILS_H
#define ASSEMBLER_PARSE_LINE_UTILS_H
#define SEP_STR ","
result finishLine(char **line);
void breakDownLineHelper(rawWord **raw, char *str);
result breakDownLine(char **line, rawWord **raw, unsigned char isSep);
int getLineLoopCond(char chr, int i);
result getLine(char **line, FILE *fp);
int getWordLoopCond(char chr, unsigned char isSep);
result getWord(char **line, char **word, unsigned char isSep);
#endif
