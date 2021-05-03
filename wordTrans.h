#include "wordId.h"
#ifndef ASSEMBLER_WORD_TRANS_H
#define ASSEMBLER_WORD_TRANS_H
#define WORD_LEN 3
#define INT_WORD_FORMAT "%03X"
#define INST_ADDRESS_FORMAT "%04d "
#define LAB_ADDRESS_FORMAT "%04d\n"
int transDest(int ref);
int transSrc(int ref);
int transFunct(int i);
int transOpcode(int i);
int transReg(int reg);
int transOp(opWord *op);
result printWordToFile(FILE *fp, int word);
result printAddressToFile(FILE *fp, sWord *word);
result printAddressTypeToFile(FILE *fp, sWord *word);
#endif
