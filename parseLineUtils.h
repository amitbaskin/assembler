#include "wordId.h"
#include "generalUtils.h"
#include "numsData.h"
#ifndef ASSEMBLER_PARSE_LINE_UTILS_H
#define ASSEMBLER_PARSE_LINE_UTILS_H
#define SEP_STR ","
#define COMMENT_CHR ';'
result finishLine(char **line);
void breakDownLineHelper(rawWordLst *lst, char *str);
result breakDownData(char **line, rawWordLst *lst, unsigned char isSep);
result breakDownLineRecur(result res, char *str, char **line, rawWordLst *lst, unsigned char isSep);
int getLineLoopCond(char chr, int i);
result getLine(char **line, FILE *fp);
int getWordLoopCond(char chr, unsigned char isSep);
result getWord(char **line, char **word, unsigned char isSep);
#endif
