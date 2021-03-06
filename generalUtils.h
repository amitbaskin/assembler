#include <stdio.h>
#ifndef ASSEMBLER_GENERAL_UTILS_H
#define ASSEMBLER_GENERAL_UTILS_H
enum result {SUCCESS, ERR, TRUE, FALSE, LINE_END, FILE_END, SEP, NOT_REG, LAB_DEC};
typedef enum result result;
result getAlloc(size_t size, void **ptr);
void freeHelper(void *ptr);
result getFixedStrAlloc(char **output);
result getStrAlloc(size_t size, char **fName);
#define MAX_LINE_LEN 81
#define INITIAL_INSTRUCTION_NUM 100
#define MAX_LAB_LEN 31
#define SEPARATOR ','

/* bubble up err if occurred */
#define VALIDATE_VAL(val) { \
    if ((val) == ERR) {     \
        return ERR; /* handled before hand */ \
    }                       \
}

/* general logic for adding an element to a linked list */
#define ADD_TO_LIST(lstTail, item){ \
    if ((lstTail) == NULL){         \
        lst->tail = item;           \
        lst->head = &(lst->tail);   \
    }                               \
    else{                           \
        lst->head = &((*(lst->head))->next); \
        *(lst->head) = item;        \
    }                               \
}

#endif
