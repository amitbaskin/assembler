#include <stdlib.h>
#include "generalUtils.h"
#include "errFuncs.h"

result getAlloc(size_t size, void **ptr){
    *ptr = calloc(1, size);
    if (ptr == NULL) {
        allocErr();
        return ERR;
    } return SUCCESS;
}

void freeHelper(void *ptr){
    free(ptr);
}

result getWordAlloc(char **output){
    void *ptr;
    VALIDATE_VAL(getAlloc(MAX_LINE_LEN, &ptr))
    *output = ptr;
    return SUCCESS;
}
