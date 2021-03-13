#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_OUTPUT_UTILS_H
#define ASSEMBLER_OUTPUT_UTILS_H
void printInstLst(FILE *fp, sWordLst *instLst, labelLst *labLst);
void printDataLst(FILE *fp, sWordLst *dataLst);
result printExtLst(char *fName, sWordLst *instLst);
result printEntFile(labelLst *lst, char *fName);
#endif
