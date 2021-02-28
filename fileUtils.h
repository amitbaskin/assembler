#include "generalUtils.h"
#ifndef ASSEMBLER_FILE_UTILS_H
#define ASSEMBLER_FILE_UTILS_H
result getFile(char *name, FILE **fp, char *mode, char *suffix);
result getReadFile(char *name, FILE **fp);
result getWriteFile(char *name, FILE **fp);
#endif
