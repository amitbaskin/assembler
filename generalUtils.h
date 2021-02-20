#include <stdio.h>
#ifndef ASSEMBLER_UTILS_H
#define ASSEMBLER_UTILS_H
#define READ_FILE_SUFFIX ".as"
#define WRITE_FILE_SUFFIX ".ob"
#define MAX_LINE_LEN 81
#define SUCCESS 0
#define ERR 1
#define LINE_END 2
#define FILE_END 3
int getFile(char *name, FILE **fp, char *mode, char *suffix);
int getReadFile(char *name, FILE **fp);
int getWriteFile(char *name, FILE **fp);
int getAlloc(size_t size, void **ptr);
int getLineLoopCond(char chr, int i);
int getLine(char **line, FILE *fp);
int getWordLoopCond(char chr, int i);
int getWord(char **line, char **word);
#endif
