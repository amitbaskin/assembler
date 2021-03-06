#include <stdlib.h>
#include <string.h>
#include "generalUtils.h"

result getAlloc(size_t size, void **ptr){
    *ptr = malloc(size);
    if (ptr == NULL) return ERR;
    return SUCCESS;
}

void freeHelper(void *ptr){
    free(ptr);
}

result getWordAlloc(char **output, size_t size){
    void *ptr;
    VALIDATE_FUNC_CALL(getAlloc(MAX_LINE_LEN, &ptr), "")
    *output = ptr;
    return SUCCESS;
}
