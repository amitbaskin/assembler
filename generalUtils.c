/* this file is used for general utilities used throughout the program from different files */

#include <stdlib.h>
#include "generalUtils.h"
#include "errFuncs.h"


result getAlloc(size_t size, void **ptr){
    /* allocates memory in ptr as requested */
    *ptr = calloc(1, size);
    if (ptr == NULL) {
        allocErr();
        return ERR;
    }
    return SUCCESS;
}

void freeHelper(void *ptr){
    /* this function can be modified if something more needs to be done while freeing a pointer */
    free(ptr);
}

result getStrAlloc(size_t size, char **fName){
    /* get allocation for a character string
     * being used for processing the name of a file
     * returns ERR if an allocation error has occurred, else returns SUCCESS */
    void *ptr;
    VALIDATE_VAL(getAlloc(size, &ptr))
    *fName = ptr;
    return SUCCESS;
}

result getFixedStrAlloc(char **output){
    /* allocates memory of fixed size for a string which is used either for a word parsed or a line from a file */
    return getStrAlloc(MAX_LINE_LEN, output);
}
