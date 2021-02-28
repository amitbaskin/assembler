#ifndef ASSEMBLER_OP_DEF_H
#define ASSEMBLER_OP_DEF_H
#define OPERATIONS {"mov", "cmp", "add", "sub", "lea", "clr", "not", "inc", "dec", "jmp", "bne", "jsr", "red", "prn", \
"rts", "stop"}
#define FUNCTS {0, 0, 10, 11, 0, 10, 11, 12, 13, 10, 11, 12, 0, 0, 0, 0}
#define OPCODES {0, 1, 2, 2, 4, 5, 5, 5, 5, 9, 9, 9, 12, 13, 14, 15}
#define OPERANDS_AMOUNT {2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
#define IS_IMMEDIATE_SOURCE_LST {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define IS_DIRECT_SOURCE_LST {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define IS_RELATIVE_SOURCE_LST {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define IS_REGISTRY_SOURCE_LST {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define IS_IMMEDIATE_DEST_LST {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
#define IS_DIRECT_DEST_LST {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
#define IS_RELATIVE_DEST_LST {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}
#define IS_REGISTRY_DEST_LST {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0}
#define OPERATIONS_AMOUNT 16
static char *operations[] = OPERATIONS;
static const unsigned char functs[] = FUNCTS;
static const unsigned char opcodes[] = OPCODES;
static const unsigned char opAmounts[] = OPERANDS_AMOUNT;
static const unsigned char isImSrcLst[] = IS_IMMEDIATE_SOURCE_LST;
static const unsigned char isDirSrcLst[] = IS_DIRECT_SOURCE_LST;
static const unsigned char isRelSrcLst[] = IS_RELATIVE_SOURCE_LST;
static const unsigned char isRegSrcLst[] = IS_REGISTRY_SOURCE_LST;
static const unsigned char isImDestLst[] = IS_IMMEDIATE_DEST_LST;
static const unsigned char isDirDestLst[] = IS_DIRECT_DEST_LST;
static const unsigned char isRelDestLst[] = IS_RELATIVE_DEST_LST;
static const unsigned char isRegDestLst[] = IS_REGISTRY_DEST_LST;
void printOps();
#endif
