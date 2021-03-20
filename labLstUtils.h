#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LAB_LST_UTILS_H
#define ASSEMBLER_LAB_LST_UTILS_H
result addLabToLabLst(labelLst *labLst, label **lab, labelType type, int address);
result isLabInLst(labelLst *labLst, label **lab, labelType type, char *name);
result getRelLabelAddressFromLst(char *name, labelLst *labLst, int address, int *dist);
result flagOnScenario(label **lab, labelLst *labLst, int address, unsigned char isData);
label *getLabTail(labelLst *lst);
result addLab(labelLst *lst, label *lab);
result initLabLst(labelLst **lst);
void freeLabLstHelper(label *lab);
void freeLabLst(labelLst *lst);
#endif
