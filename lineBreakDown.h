#include "generalUtils.h"
#ifndef ASSEMBLER_LINE_BREAK_DOWN_H
#define ASSEMBLER_LINE_BREAK_DOWN_H
#define SEP_STR ","
struct rawWord{
    char *word;
    struct rawWord *next;
};
typedef struct rawWord rawWord;
void helper(rawWord **word, char *str);
result breakDownLine(char **line, rawWord *word);
#endif
