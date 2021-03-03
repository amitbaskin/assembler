#include <stdio.h>
#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_OUTPUT_UTILS_H
#define ASSEMBLER_OUTPUT_UTILS_H
#define HEADER_FORMAT "%d %d\n"
void printLabel(FILE *fp, label *lab);
void printInst(FILE *fp, sWord **ptr, unsigned int toPrint);
void printIntsLst(FILE *fp, sWord *instHead, label *labHead);
void printDataLst(FILE *fp, sWord *dataHead);
result printEntLst(char *fName, label *labHead);
result printExtLst(char *fName, sWord *instHead);
#endif
