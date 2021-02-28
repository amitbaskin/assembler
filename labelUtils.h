#include "wordIdentifiers.h"
#ifndef ASSEMBLER_LABEL_API_H
#define ASSEMBLER_LABEL_API_H
result checkRel(char *word);
result isLegalLabel(char *word, unsigned long len);
result isLabelDeclaration(const char *word, unsigned long len);
void addDataLabel(label **labLst, char *name);
void addLabel(label **labLst, label *next);
label *getBasicLabel(char *name, int address);
void setDataLabel(label *lab);
void setCodeLabel(label *lab);
void setEntLabel(label *lab);
void setExtLabel(label *lab);
void setRel(label *lab);
void setAddress(label *lab, int address);
result setName(label *lab, char *name, unsigned long len);
void setLabelType(label *lab, labelType type);
label *getEmptyLabel();
result getLabelAddress(char *name, label *headLab, int *address);
result getRelLabelAddress(char *name, label *headLab, int address, int *dist);
result isLabInLst(label *labHead, label **lab, labelType type, char *name);
label *getLabel(unsigned long len, char *name);
result isLabelTypeLegal(label *lab, labelType type);
#endif
