#include "wordIdentifiers.h"
#ifndef ASSEMBLER_OP_WORD_SETTERS_H
#define ASSEMBLER_OP_WORD_SETTERS_H
void setOpIndex(opWord *op, int index);
void setOpSrcRef(opWord *op, ref src);
void setOpDestRef(opWord *op, ref dest);
#endif
