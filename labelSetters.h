#include "wordIdentifiers.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_LABEL_SETTERS_H
#define ASSEMBLER_LABEL_SETTERS_H
result setLabelName(label *lab, char *name);
void setLabelAddress(label *lab, int address);
void setLabelType(label *lab, labelType);
void setCodeLabel(label *lab);
void setDataLabel(label *lab);
void setRelLabel(label *lab);
void setNextLabel(label *lab, label *next);
void setThisLabel(label **this, label *other);
#endif
