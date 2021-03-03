#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_OP_WORD_GETTERS_H
#define ASSEMBLER_OP_WORD_GETTERS_H
int getOpIndexByObject(opWord *op);
ref getOpSrc(opWord *op);
ref getOpDest(opWord *op);
result getOpWord(int opIndex, ref src, ref dest, opWord **op);
#endif
