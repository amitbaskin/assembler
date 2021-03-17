#include "generalUtils.h"
#ifndef ASSEMBLER_FILE_UTILS_H
#define ASSEMBLER_FILE_UTILS_H
char *getFullFileName(char *name, char *suffix);
int removeFile(char *fName);
result getReadFile(char *name, FILE **fp);
result closeFile(FILE *fp);
result getMainOutputFile(char *name, FILE **fp);
result getEntOutputFile(char *name, FILE **fp);
result getExtOutputFile(char *name, FILE **fp);
#define INPUT_FILE_SUFFIX ".as"
#define MAIN_OUTPUT_SUFFIX ".ob"
#define ENT_SUFFIX ".ent"
#define EXT_SUFFIX ".ext"
#endif
