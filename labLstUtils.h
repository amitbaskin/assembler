#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LAB_LST_UTILS_H
#define ASSEMBLER_LAB_LST_UTILS_H
void addLabelToLst(label **labLst, label *next);
result addLabToLabLst(label *head, label **lab, label **labLst, labelType type, int address);
void addDataLabelToLst(label **labLst, char *name);
result isLabInLst(label *headLab, label **lab, labelType type, char *name);
result getLabelAddressFromLst(char *name, label *headLab, int *address);
result getRelLabelAddressFromLst(char *name, label *headLab, int address, int *dist);
void freeLabLst(label *lab);
#endif
