#include "generalUtils.h"
#include "wordIdentifiers.h"
#ifndef ASSEMBLER_PARSE_LINE_H
#define ASSEMBLER_PARSE_LINE_H
result lookForData(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **instLst, sWord
**dataLst);
result lookForOperation(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **sWordLst);
result lookForLabel(char **line, char **word, unsigned long *len);
int getLineLoopCond(char chr, int i);
result getLine(char **line, FILE *fp);
int getWordLoopCond(char chr, unsigned char isSep);
result getWord(char **line, char **word, unsigned char isSep);

#endif
