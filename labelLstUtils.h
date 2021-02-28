#include "wordIdentifiers.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LABEL_LST_UTILS_H
#define ASSEMBLER_LABEL_LST_UTILS_H
void addLabelToLst(label **labLst, label *next);
void addDataLabelToLst(label **labLst, char *name);
result isLabInLst(label *headLab, label **lab, labelType type, char *name);
result getLabelAddressFromLst(char *name, label *headLab, int *address);
result getRelLabelAddressFromLst(char *name, label *headLab, int address, int *dist);
#endif
