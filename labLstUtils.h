#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LAB_LST_UTILS_H
#define ASSEMBLER_LAB_LST_UTILS_H
result addLabToLabLst(labelLst *labLst, label **lab, labelType type, int address);
result isLabInLst(labelLst *labLst, label **lab, labelType type, char *name);
result getRelLabelAddressFromLst(char *name, labelLst *labLst, int address, int *dist);
void checkLabFlagOnScenario(label **lab, labelLst *labLst, void labSetter(label *, unsigned char), int address);
label *getLabTail(labelLst *lst);
void addLab(labelLst *lst, label *lab);
result initializeLabLst(labelLst **lst);
void freeLabLstHelper(label *lab);
void freeLabLst(labelLst *lst);
#endif
