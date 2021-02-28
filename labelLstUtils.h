#include "wordIdentifiers.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LABEL_LST_UTILS_H
#define ASSEMBLER_LABEL_LST_UTILS_H
void addDataLabel(label **labLst, char *name);
result getLabelAddress(char *name, label *headLab, int *address);
result getRelLabelAddress(char *name, label *headLab, int address, int *dist);
result isLabInLst(label *labHead, label **lab, labelType type, char *name);
#endif
