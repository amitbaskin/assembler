#include "wordIdentifiers.h"
#ifndef ASSEMBLER_LABEL_SETTERS_H
#define ASSEMBLER_LABEL_SETTERS_H
void setLabelName(label *lab, char *name);
void setLabelAddress(label *lab, int address);
void setLabelType(label *lab, labelType);
void setCodeLabel(label *lab);
void setDataLabel(label *lab);
void setRelLabel(label *lab);
#endif
