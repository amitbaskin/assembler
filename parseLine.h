#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_PARSE_LINE_H
#define ASSEMBLER_PARSE_LINE_H
result lookForData(char **word, char **line, label **lab, labelLst *labLst, sWordLst *instLst, sWordLst *dataLst);
result lookForOperation(char **firstOp, char **secOp, char **word, char **line, label **lab, labelLst *labLst,
                        sWordLst *instLst);
#endif
