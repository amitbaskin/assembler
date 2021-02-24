#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#ifndef ASSEMBLER_NUMS_DATA_H
#define ASSEMBLER_NUMS_DATA_H
struct data{
    int num;
    struct data *next;
};
typedef struct data data;
result isDataScenario(char *word, char **line, sWord **words);
result collectData(rawWord *raw, data *dat);
result addData(sWord **lastWord, data *dat);

#endif
