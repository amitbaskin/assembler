#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_NUMS_DATA_H
#define ASSEMBLER_NUMS_DATA_H
struct data{
    int num;
    struct data *next;
};
typedef struct data data;
result isDataScenario(char *word, char **line, sWord **dataLst, label *head, label *lab, label **labLst) ;
result collectData(rawWord *raw, data *dat);
result addData(sWord **sWordLst, data *dat, label *head, label *lab, label **labLst);
void freeDataLst(data *dat);
#endif
