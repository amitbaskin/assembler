#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_PARSE_LINE_UTILS_H
#define ASSEMBLER_PARSE_LINE_UTILS_H
result finishLine(char **line);
result isEmptyLine(const char *line);
result getLine(char **line, FILE *fp);
result getWord(char **line, char **word, unsigned char isSep);
#define SEPARATOR ','
#define COMMENT_CHR ';'
#endif
