#include "machineWordIdentifiers.h"
#include "generalUtils.h"
#include "numsData.h"

#ifndef ASSEMBLER_FIRST_PARSE_LINE_UTILS_H
#define ASSEMBLER_FIRST_PARSE_LINE_UTILS_H
#define SEP_STR ","
result finishLine(char **line);
void breakDownLineHelper(rawWord **raw, char *str);
result breakDownLine(char **line, rawWord **raw, unsigned char isSep);
#endif
