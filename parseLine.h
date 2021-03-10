#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_PARSE_LINE_H
#define ASSEMBLER_PARSE_LINE_H
result entryScenario(char **line, char **word, label **lab, sWordLst *instLst);
result extScenario(char **line, char
**word, label **lab, labelLst *labLst);
result lookForData(char **word, char **line, label **lab, labelLst *labLst, sWordLst *instLst, sWordLst *dataLst);
result lookForOperation(char **firstOp, char **secOp, char **word, char **line, label **lab, labelLst *labLst, sWordLst
*instLst);
result lookForLabel(char **line, char **word, label **lab);
#endif
