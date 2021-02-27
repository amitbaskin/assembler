#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#ifndef ASSEMBLER_PARSE_LINE_H
#define ASSEMBLER_PARSE_LINE_H
result lookForData(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **words);
result lookForOperation(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **sWordLst);
#endif
