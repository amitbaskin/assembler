#include "wordId.h"
#include "opDefGetters.h"
#ifndef ASSEMBLER_WORD_TRANS_H
#define ASSEMBLER_WORD_TRANS_H
#define STR_WORD_FORMAT "%c%c%c "
#define INT_WORD_FORMAT "%03X "
#define ADDRESS_FORMAT "%04d "
int transDest(int ref);
int transSrc(int ref);
int transFunct(int i);
int transOpcode(int i);
int transReg(int reg);
int transOp(opWord *op);
void printWordToFile(FILE *fp, int word);
void printAddressToFile(FILE *fp, sWord *word);
void printAddressTypeToFile(FILE *fp, sWord *word);
#endif
