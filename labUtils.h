#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LABEL_UTILS_H
#define ASSEMBLER_LABEL_UTILS_H
result checkRel(char **word);
result isLegalLabHelper(char *word, unsigned long len);
result getLegalLab(char **word, label **lab, unsigned long len);
result processLabel(char **line, char **word, label **lab, unsigned long len);
result initLab(label **lab);
result getRelLabelAddressFromLst(char *name, labelLst *labLst, int address, int *dist);
result isLabInLst(labelLst *labLst, label **lab, labelType type, char *name);
result getNewLabByName(label **lab, char *name);
result isLabTypeLegal(label *lab, labelType type);
void promoteLab(label **lab);
void freeLab(label *lab);
#endif
