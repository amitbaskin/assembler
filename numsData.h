#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_NUMS_DATA_H
#define ASSEMBLER_NUMS_DATA_H
result isNumDataScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst);
result collectData(rawWordLst *lst);
result addNumsData(sWordLst *dataLst, labelLst *labLst, label *lab, rawWordLst *rawLst);
void freeDataLst(rawWord *dataWord);
#endif
