#include "wordIdentifiers.h"
#ifndef ASSEMBLER_LABEL_GETTERS_H
#define ASSEMBLER_LABEL_GETTERS_H
char *getLabelName(label *lab);
int getLabelAddress(label *lab);
labelType getLabelType(label *lab);
unsigned char isCodeLabel(label *lab);
unsigned char isDataLabel(label *lab);
unsigned char isRelLabel(label *lab);
#endif
