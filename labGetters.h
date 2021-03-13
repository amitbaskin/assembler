#include "wordId.h"
#ifndef ASSEMBLER_LAB_GETTERS_H
#define ASSEMBLER_LAB_GETTERS_H
char *getLabName(label *lab);
int getLabAddress(label *lab);
labelType getLabType(label *lab);
unsigned char isLabData(label *lab);
unsigned char isLabRel(label *lab);
#endif
