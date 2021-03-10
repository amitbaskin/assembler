#include <stdio.h>
#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_OUTPUT_UTILS_H
#define ASSEMBLER_OUTPUT_UTILS_H
#define HEADER_FORMAT "%d %d\n"
void printLabel(FILE *fp, label *lab);
void printInst(FILE *fp, sWord **ptr, int toPrint);
void printInstLst(FILE *fp, sWordLst *instLst, labelLst *labLst);
void printDataLst(FILE *fp, sWordLst *dataLst);
result printExtLst(char *fName, sWordLst *instLst);
result printEntFile(labelLst *labLst, char *fName);
#endif
