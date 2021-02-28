#include <stdlib.h>
#include <string.h>
#include "generalUtils.h"

result getAlloc(size_t size, void **ptr){
    *ptr = malloc(size);
    if (ptr == NULL){
        return ERR;
    } return SUCCESS;
}
