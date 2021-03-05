#include "wordId.h"
#ifndef ASSEMBLER_LAB_GETTERS_H
#define ASSEMBLER_LAB_GETTERS_H
char *getLabName(label *lab);
int getLabAddress(label *lab);
labelType getLabType(label *lab);
unsigned char isCodeLab(label *lab);
unsigned char isDataLab(label *lab);
unsigned char isRelLab(label *lab);
label *getLabNext(label *lab);
#endif
