#include "wordId.h"
#ifndef ASSEMBLER_LABEL_UTILS_H
#define ASSEMBLER_LABEL_UTILS_H
result isLabel(char **word, label **lab, unsigned long len);
result checkRel(char *word);
result isLegalLabel(char *word, unsigned long len);
result isLabelDeclaration(const char *word, unsigned long len);
result getNewEmptyLabel(label **lab);
result getRelLabelAddressFromLst(char *name, label *headLab, int address, int *dist);
result isLabInLst(label *headLab, label **lab, labelType type, char *name);
label *getNewLabelByName(char *name);
result isLabelTypeLegal(label *lab, labelType type);
#endif
