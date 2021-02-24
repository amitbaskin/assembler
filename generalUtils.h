#include <stdio.h>
#ifndef ASSEMBLER_UTILS_H
#define ASSEMBLER_UTILS_H
#define READ_FILE_SUFFIX ".as"
#define WRITE_FILE_SUFFIX ".ob"
#define MAX_LINE_LEN 81
#define SEPARATOR ','
enum result {SUCCESS, ERR, TRUE, FALSE, LINE_END, FILE_END, SEP, NOT_REG};
typedef enum result result;
result getFile(char *name, FILE **fp, char *mode, char *suffix);
int getReadFile(char *name, FILE **fp);
int getWriteFile(char *name, FILE **fp);
result getAlloc(size_t size, void **ptr);
int getLineLoopCond(char chr, int i);
result getLine(char **line, FILE *fp);
int getWordLoopCond(char chr, unsigned char isSep);
result getWord(char **line, char **word, unsigned char isSep);
#endif
