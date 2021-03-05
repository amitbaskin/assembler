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
#endif
