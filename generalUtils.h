#include <stdio.h>
#ifndef ASSEMBLER_UTILS_H
#define ASSEMBLER_UTILS_H
#define READ_FILE_SUFFIX ".as"
#define WRITE_FILE_SUFFIX ".ob"
#define MAX_LINE_LEN 81
#define INITIAL_INSTRUCTION_NUM 100
#define SEPARATOR ','
enum result {SUCCESS, ERR, TRUE, FALSE, LINE_END, FILE_END, SEP, NOT_REG};
typedef enum result result;
static result labelFlag = FALSE;
static unsigned char instructionCounter = INITIAL_INSTRUCTION_NUM;
static unsigned char dataCounter = 0;
static unsigned char lineCounter = 1;
static unsigned char ICF = 0;
static unsigned char DCF = 0;
result getFile(char *name, FILE **fp, char *mode, char *suffix);
result getReadFile(char *name, FILE **fp);
result getWriteFile(char *name, FILE **fp);
result getAlloc(size_t size, void **ptr);
int getLineLoopCond(char chr, int i);
result getLine(char **line, FILE *fp);
int getWordLoopCond(char chr, unsigned char isSep);
result getWord(char **line, char **word, unsigned char isSep);
#endif
