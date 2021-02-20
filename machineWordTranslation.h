#include "machineWordIdentifiers.h"
#include "operationsApi.h"
#ifndef ASSEMBLER_WORD_TRANSLATION_H
#define ASSEMBLER_WORD_TRANSLATION_H
#define WORD_FORMAT "%03X"
#define ADDRESS_FORMAT "%04d"
unsigned int transDest(enum ref ref);
unsigned int transSrc(enum ref ref);
unsigned int transFunct(int i);
unsigned int transOpcode(int i);
unsigned int transReg(enum reg reg);
unsigned int getInitialWord(unsigned int dest, unsigned int src, unsigned int funct, unsigned int opcode);
void printWordToFile(FILE *fp, int word);
void printAddressToFile(FILE *fp, int address);
void printAddressTypeToFile(FILE *fp, char type);
#endif
