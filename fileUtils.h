#include "generalUtils.h"
#ifndef ASSEMBLER_FILE_UTILS_H
#define ASSEMBLER_FILE_UTILS_H
result getNameAlloc(size_t size, char **fName);
result getReadFile(char *name, FILE **fp);
result getMainOutputFile(char *name, FILE **fp);
result getEntOutputFile(char *name, FILE **fp);
result getExtOutputFile(char *name, FILE **fp);
#define READ_FILE_SUFFIX ".as"
#define MAIN_OUTPUT_SUFFIX ".ob"
#define ENT_SUFFIX ".ent"
#define EXT_SUFFIX ".ext"
#endif
