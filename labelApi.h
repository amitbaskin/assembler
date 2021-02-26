#include "machineWordIdentifiers.h"
#ifndef ASSEMBLER_LABEL_API_H
#define ASSEMBLER_LABEL_API_H
int isRel(char *word);
enum result isLegalLabel(char *word, unsigned long len);
enum result isLabelDeclaration(const char *word, unsigned long len);
void addDataLabel(label **last, char *name);
void addLabel(label *last, label *next);
label *getBasicLabel(char *name, int address);
void setDataLabel(label *lab);
void setCodeLabel(label *lab);
void setEntLabel(label *lab);
void setExtLabel(label *lab);
void setRel(label *lab);
unsigned char getLabelAddress(char *name, label *headLab, int *address);
unsigned char getRelLabelAddress(char *name, label *headLab, int address, int *dist);
result isLabelInLst(label *labHead, label **lab, char *name);
#endif
