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
    } return SUCCESS;
}

void freeHelper(void *ptr){
    /* this function can be modified if something more needs to be done while freeing a pointer */
    free(ptr);
}

result getWordAlloc(char **output){
    /* allocates memory of fixed size for a string which used either for a word parsed or a line from a file */
    void *ptr;
    VALIDATE_VAL(getAlloc(MAX_LINE_LEN, &ptr))
    *output = ptr;
    return SUCCESS;
}
