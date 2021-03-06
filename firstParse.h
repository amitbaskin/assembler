#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_PARSE_FILE_H
#define ASSEMBLER_PARSE_FILE_H
result parseFile(FILE *fp, sWordLst *instLst, sWordLst *dataLst, labelLst *labLst);
result isEmptyLine(const char *line);
#endif
