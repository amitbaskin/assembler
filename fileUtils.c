/* this file is used to handle files used in the program */

#include <string.h>
#include "fileUtils.h"
#include "errFuncs.h"


char *getFullFileName(char *name, char *suffix){
    char *fullName;
    unsigned long nameLen = strlen(name);
    unsigned long sufLen = strlen(suffix);
    if (getStrAlloc(nameLen + sufLen + 1, &fullName) == ERR) return NULL;
    strcat(fullName, name);
    strcat(fullName, suffix);
    return fullName;
}

int removeFile(char *fName){
    int res = 0;
    if (fName != NULL){
        res = remove(fName);
        freeHelper(fName);
    }
    return res;
}

result getFile(char *name, FILE **fp, char *mode, char *suffix){
    /* saves a file named 'name' with the given suffix, in the fp variable
     * this is being done after opening the requested file successfully in the requested mode
     * if not successful or if a memory allocation error has occurred returns ERR, else returns SUCCESS */
    char *fullName = getFullFileName(name, suffix);
    if (fullName == NULL) return ERR;
    *fp = fopen(fullName, mode);
    freeHelper(fullName);
    if (*fp == NULL) {
        openFileErr();
        return ERR;
    }
    return SUCCESS;
}

result getReadFile(char *name, FILE **fp){
    /* opens a file in read mode and saves it in fp */
    return getFile(name, fp, "r", INPUT_FILE_SUFFIX);
}

result getMainOutputFile(char *name, FILE **fp){
    /* opens a file for the main output in write mode */
    return getFile(name, fp, "w", MAIN_OUTPUT_SUFFIX);
}

result getEntOutputFile(char *name, FILE **fp){
    /* opens a file for the entry output in write mode */
    return getFile(name, fp, "w", ENT_SUFFIX);
}

result getExtOutputFile(char *name, FILE **fp){
    /* opens a file for the extern output in write mode */
    return getFile(name, fp, "w", EXT_SUFFIX);
}

result closeFile(FILE *fp){
    /* attempts to close the given file returns ERR if failed and SUCCESS otherwise */
    int res = fclose(fp);
    if (res) {
        closeFileErr();
        return ERR;
    }
    else return SUCCESS;
}
