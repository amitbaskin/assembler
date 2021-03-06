#include <stdio.h>
#ifndef ASSEMBLER_GENERAL_UTILS_H
#define ASSEMBLER_GENERAL_UTILS_H
#define READ_FILE_SUFFIX ".as"
#define MAIN_OUTPUT_SUFFIX ".ob"
#define ENT_SUFFIX ".ent"
#define EXT_SUFFIX ".ext"
#define MAX_LINE_LEN 81
#define INITIAL_INSTRUCTION_NUM 100
#define SEPARATOR ','

#define VALIDATE_FUNC_CALL(funcCall, failMsg) { \
    if (funcCall == ERR) {                      \
        printf(failMsg);                        \
        return ERR;                             \
    }                                           \
}

#define GET_ITER_NEXT(type){ \
    if (&(lst->head) == &(lst->cur)){ \
        lst->cur = lst->tail;\
        return NULL;         \
    } type *cur = lst->cur;  \
    type *tmp = cur;         \
    lst->cur = cur->next;    \
    return tmp;              \
}

#define ADD_TO_LIST(type, cond, item){ \
    if (cond) {                        \
        lst->tail = item;              \
        lst->head = item;               \
    } else{                            \
        lst->head->next = item;        \
        lst->head = item;              \
    }                                  \
}

enum result {SUCCESS, ERR, TRUE, FALSE, LINE_END, FILE_END, SEP, NOT_REG};
typedef enum result result;
static result labelFlag = FALSE;
static unsigned char instructionCounter = INITIAL_INSTRUCTION_NUM;
static unsigned char dataCounter = 0;
static unsigned char lineCounter = 1;
static unsigned char ICF = 0;
static unsigned char DCF = 0;
result getAlloc(size_t size, void **ptr);
void freeHelper(void *ptr);
result getWordAlloc(char **output, size_t size);
#endif
