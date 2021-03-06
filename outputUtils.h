#include <stdio.h>
#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_OUTPUT_UTILS_H
#define ASSEMBLER_OUTPUT_UTILS_H
#define HEADER_FORMAT "%d %d\n"
void printLabel(FILE *fp, label *lab);
void printInst(FILE *fp, sWord **ptr, unsigned int toPrint);
void printIntsLst(FILE *fp, sWordLst *instLst, labelLst *labLst);
void printDataLst(FILE *fp, sWordLst *dataLst);
result printEntLst(char *fName, labelLst *labLst);
result printExtLst(char *fName, sWordLst *instLst);
void getEntLst(label *ent, label *labTail);
void getExtLst(sWord *ext, sWord *instHead);
#endif
