#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_PARSE_FILE_H
#define ASSEMBLER_PARSE_FILE_H
result parseFile(FILE *fp, sWordLst *instLst, sWordLst *dataLst, labelLst *labLst);
#endif
