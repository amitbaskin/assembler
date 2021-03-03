#include <stdio.h>
#include "wordId.h"
#ifndef ASSEMBLER_OUTPUT_UTILS_H
#define ASSEMBLER_OUTPUT_UTILS_H
#define HEADER_FORMAT "%d %d\n"
void printLabel(FILE *fp, label *lab);
void printInst(FILE *fp, sWord **ptr, unsigned int toPrint);
void printIntsLst(char *fName, sWord *instHead);
void printEntLst(char *fName, label *labHead);
void printExtLst(char *fName, sWord *instHead);
#endif
