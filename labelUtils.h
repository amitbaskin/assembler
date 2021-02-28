#include "wordIdentifiers.h"
#ifndef ASSEMBLER_LABEL_API_H
#define ASSEMBLER_LABEL_API_H
result checkRel(char *word);
result isLegalLabel(char *word, unsigned long len);
result isLabelDeclaration(const char *word, unsigned long len);
label *getNewEmptyLabel();
result getRelLabelAddressFromLst(char *name, label *headLab, int address, int *dist);
result isLabInLst(label *headLab, label **lab, labelType type, char *name);
label *getNewLabelByName(char *name);
result isLabelTypeLegal(label *lab, labelType type);
#endif
