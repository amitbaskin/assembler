#include "machineWordIdentifiers.h"
#ifndef ASSEMBLER_LABEL_UTILS_H
#define ASSEMBLER_LABEL_UTILS_H
#define SUCCESS 0
int isRel(const char *word);
unsigned char isLabel(char *word, unsigned long len);
unsigned char isLabelDeclaration(const char *word, unsigned long len);
void addDataLabel(label **last, char *name);
void addLabel(label *last, label *next);
label *getBasicLabel(char *name, int address);
void setDataLabel(label *lab);
void setCodeLabel(label *lab);
void setEntLabel(label *lab);
void setExtLabel(label *lab);
unsigned char getLabelAddress(char *name, label *lst, int *address);
unsigned char getRelLabelAddress(char *name, label *lst, int address, int *dist);
#endif
