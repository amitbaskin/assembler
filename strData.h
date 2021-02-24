#include "machineWordIdentifiers.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_STR_DATA_H
#define ASSEMBLER_STR_DATA_H
result isStrScenario(char **line, char *word, sWord **lastWord, label *head, label *lab, label **labLst);
void strScenario(char *str, sWord **lastWord, label *head, label *lab, label **labLst);
#endif
