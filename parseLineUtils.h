#include "generalUtils.h"
#ifndef ASSEMBLER_FIRST_PARSE_H
#define ASSEMBLER_FIRST_PARSE_H
#define SEP_STR ","
struct rawWord{
    char *word;
    struct rawWord *next;
};
typedef struct rawWord rawWord;
struct data{
    int num;
    struct data *next;
};
typedef struct data data;
result collectData(char **line, data *dat);
void breakDownLineHelper(rawWord **word, char *str);
result breakDownLine(char **line, rawWord *word);

#endif
