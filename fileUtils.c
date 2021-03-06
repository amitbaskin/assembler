#include <string.h>
#include "fileUtils.h"
#include "generalUtils.h"

result getNameAlloc(size_t size, char **fName){
    void *ptr;
    VALIDATE_VAL(getAlloc(size, &ptr), "")
    *fName = ptr;
    return SUCCESS;
}

result getFile(char *name, FILE **fp, char *mode, char *suffix){
    unsigned long nameLen = strlen(name);
    unsigned long sufLen = strlen(suffix);
    char *fullName;
    VALIDATE_VAL(getNameAlloc(nameLen + sufLen + 1, &fullName), "")
    strcpy(fullName, name);
    strcat(fullName, suffix);
    *fp = fopen(fullName, mode);
    freeHelper(fullName);
    if (*fp == NULL) return ERR;
    return SUCCESS;
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
