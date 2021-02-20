#include "generalUtils.h"
#ifndef ASSEMBLER_DATA_COLLECTION_H
#define ASSEMBLER_DATA_COLLECTION_H
struct data{
    int num;
    struct data *next;
};
typedef struct data data;
result collectData(char **line, data *dat);
#endif
