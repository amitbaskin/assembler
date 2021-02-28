#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LAB_SETTERS_H
#define ASSEMBLER_LAB_SETTERS_H
result setLabName(label *lab, char *name);
void setLabAddress(label *lab, int address);
void setLabType(label *lab, labelType type);
void setCodeLab(label *lab);
void setDataLab(label *lab);
void setRelLab(label *lab);
void setNextLab(label *lab, label *next);
void setThisLab(label **this, label *other);
#endif
