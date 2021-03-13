#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LAB_SETTERS_H
#define ASSEMBLER_LAB_SETTERS_H
result setLabName(label *lab, char *name);
void setLabAddress(label *lab, int address);
void setLabType(label *lab, labelType type);
void setLabData(label *lab, unsigned char toSet);
void setLabRel(label *lab, unsigned char toSet);
#endif
