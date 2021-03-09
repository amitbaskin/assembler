#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_SWORD_UTILS_H
#define ASSEMBLER_SWORD_UTILS_H
result initSword(sWord **word);
void freeSWord(sWord *word);
void promoteSWord(sWord **word);
#endif
