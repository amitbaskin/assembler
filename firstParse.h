#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_PARSE_FILE_H
#define ASSEMBLER_PARSE_FILE_H
result getLineAlloc(char **output);
result parseFile(FILE *fp, sWord *sWordLst, sWord *dataLst, label *labLst);
#endif
