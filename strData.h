#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_STR_DATA_H
#define ASSEMBLER_STR_DATA_H
result isStrScenario(char **line, char *word, sWord **sWordLst, label *head, label *lab, label **labLst);
void strScenario(char *str, sWord **sWordLst, label *head, label *lab, label **labLst);
#endif
