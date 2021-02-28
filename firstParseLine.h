#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#ifndef ASSEMBLER_FIRST_PARSE_LINE_H
#define ASSEMBLER_FIRST_PARSE_LINE_H
result lookForData(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **sWordLst);
result lookForOperation(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **sWordLst);
result lookForLabel(char **line, char **word, unsigned long *len);
#endif
