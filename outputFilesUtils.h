#include <stdio.h>
#include "wordIdentifiers.h"
#ifndef ASSEMBLER_PRINT_FILE_H
#define ASSEMBLER_PRINT_FILE_H
void printInst(FILE *fp, sWord **ptr, unsigned int toPrint);
void printIntsLst(FILE *fp, sWord *instHead);
void printDataLst(FILE *fp, sWord *dataHead);
#endif
