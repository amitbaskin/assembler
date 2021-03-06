#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_NUMS_DATA_H
#define ASSEMBLER_NUMS_DATA_H
struct data{
    int num;
    struct data *next;
};
typedef struct data data;
result isDataScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst);
result collectData
(rawWord *raw, data *dat);
result addData(sWordLst *dataLst, labelLst *labLst, label *lab, data *dat);
void freeDataLst(data *dat);
#endif
