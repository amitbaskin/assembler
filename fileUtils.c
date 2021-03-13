#include <string.h>
#include "fileUtils.h"
#include "errFuncs.h"

result getNameAlloc(size_t size, char **fName){
    void *ptr;
    VALIDATE_VAL(getAlloc(size, &ptr))
    *fName = ptr;
    return SUCCESS;
}

result getFile(char *name, FILE **fp, char *mode, char *suffix){
    char *fullName;
    unsigned long nameLen = strlen(name);
    unsigned long sufLen = strlen(suffix);
    VALIDATE_VAL(getNameAlloc(nameLen + sufLen + 1, &fullName))
    strcat(fullName, name);
    strcat(fullName, suffix);
    *fp = fopen(fullName, mode);
    freeHelper(fullName);
    if (*fp == NULL) {
        openFileErr();
        return ERR;
    } return SUCCESS;
}

result getReadFile(char *name, FILE **fp){
    return getFile(name, fp, "r", READ_FILE_SUFFIX);
}

result getMainOutputFile(char *name, FILE **fp){
    return getFile(name, fp, "w", MAIN_OUTPUT_SUFFIX);
}

result getEntOutputFile(char *name, FILE **fp){
    return getFile(name, fp, "w", ENT_SUFFIX);
}

result getExtOutputFile(char *name, FILE **fp){
    return getFile(name, fp, "w", EXT_SUFFIX);
}

result closeFile(FILE *fp){
    int res = fclose(fp);
    if (res) closeFileErr();
    return ERR;
}
