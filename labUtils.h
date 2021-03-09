#include "wordId.h"
#ifndef ASSEMBLER_LABEL_UTILS_H
#define ASSEMBLER_LABEL_UTILS_H
result checkRel(char *word);
result isLegalLabel(char *word, unsigned long len);
result checkLabelLegality(char **word, label **lab, unsigned long len);
result isLabelDeclaration(char *word, label **lab, unsigned long len);
result getNewEmptyLab(label **lab);
result getRelLabelAddressFromLst(char *name, labelLst *labLst, int address, int *dist);
result isLabInLst(labelLst
*labLst, label **lab, labelType type, char *name);
result getNewLabByName(label **lab, char
*name);
result isLabTypeLegal(label *lab, labelType type);
void promoteLab(label **lab);
void freeLab(label *lab);
#endif
