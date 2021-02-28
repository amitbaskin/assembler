#include <stdio.h>
#include "wordId.h"
#ifndef ASSEMBLER_OUTPUT_UTILS_H
#define ASSEMBLER_OUTPUT_UTILS_H
#define HEADER_FORMAT "%d %d\n"
void printInst(FILE *fp, sWord **ptr, unsigned int toPrint);
void printIntsLst(FILE *fp, sWord *instHead);
void printDataLst(FILE *fp, sWord *dataHead);
#endif
