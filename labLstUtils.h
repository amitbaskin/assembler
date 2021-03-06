#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LAB_LST_UTILS_H
#define ASSEMBLER_LAB_LST_UTILS_H
void addLabelToLst(label **labLst, label *next);
result addLabToLabLst(labelLst *labLst, label **lab, labelType type, int address);
void addDataLabelToLst(label
**labLst, char *name);
result isLabInLst(labelLst *labLst, label **lab, labelType type, char *name);
result getLabelAddressFromLst(char *name, label *headLab, int *address);
result getRelLabelAddressFromLst(char *name, labelLst *labLst, int address, int *dist);
void checkLabFlagOnScenario(label **lab, labelLst *labLst, void labSetter(label *, unsigned char), int address);
label *getLabHead(labelLst *lst);
label *getLabTail(labelLst *lst);
label *getLabCur(labelLst *lst);
label *getLabIterNext(labelLst *lst);
void resetLabIter(labelLst *lst);
void addLab(labelLst *lst, label *lab);
result initializeLabLst(labelLst *lst);
void freeLabLstHelper(label *lab);
void freeLabLst(labelLst *lst);
#endif
