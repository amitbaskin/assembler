#include <stdlib.h>
#include <string.h>
#include "fileUtils.h"

result getFile(char *name, FILE **fp, char *mode, char *suffix){
    unsigned long nameLen = strlen(name);
    unsigned long sufLen = strlen(suffix);
    char *fullName = malloc(nameLen+sufLen-1);
    strcpy(fullName, name);
    strcat(fullName, suffix);
    *fp = fopen(fullName, mode);
    if (*fp == NULL) {
        return ERR;
    } return SUCCESS;
}

result getReadFile(char *name, FILE **fp){
    return getFile(name, fp, "r", READ_FILE_SUFFIX);
}

result getMainOutputFIle(char *name, FILE **fp){
    return getFile(name, fp, "w", MAIN_OUTPUT_SUFFIX);
}

result getEntOutputFIle(char *name, FILE **fp){
    return getFile(name, fp, "w", ENT_SUFFIX);
}

result getExtOutputFIle(char *name, FILE **fp){
    return getFile(name, fp, "w", EXT_SUFFIX);
}
