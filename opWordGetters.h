#include "wordIdentifiers.h"
#ifndef ASSEMBLER_OP_WORD_GETTERS_H
#define ASSEMBLER_OP_WORD_GETTERS_H
int getOpIndex(opWord *op);
ref getOpSrcRef(opWord *op);
ref getOpDestRef(opWord *op);
opWord *getOpWord(int opIndex, ref src, ref dest);
#endif
