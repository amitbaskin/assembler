#include "wordId.h"
#include "opDefGetters.h"
#ifndef ASSEMBLER_WORD_TRANS_H
#define ASSEMBLER_WORD_TRANS_H
#define WORD_FORMAT "%03X "
#define ADDRESS_FORMAT "%04d "
unsigned int transDest(enum ref ref);
unsigned int transSrc(enum ref ref);
unsigned int transFunct(int i);
unsigned int transOpcode(int i);
unsigned int transReg(enum reg reg);
unsigned int transOp(opWord *op);
void printWordToFile(FILE *fp, unsigned int word);
void printAddressToFile(FILE *fp, sWord *word);
void printAddressTypeToFile(FILE *fp, sWord *word);
#endif