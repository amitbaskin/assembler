#include "generalUtils.h"
#ifndef ASSEMBLER_FILE_UTILS_H
#define ASSEMBLER_FILE_UTILS_H
result getNameAlloc(size_t size, char **fName);
result getFile(char *name, FILE **fp, char *mode, char *suffix);
result getReadFile(char *name, FILE **fp);
result getMainOutputFile(char *name, FILE **fp);
result getEntOutputFile(char *name, FILE **fp);
result getExtOutputFile(char *name, FILE **fp);
#endif
