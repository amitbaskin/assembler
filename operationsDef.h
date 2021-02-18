#ifndef ASSEMBLER_OPERATIONSDEF_H
#define ASSEMBLER_OPERATIONSDEF_H
#define OPERATIONS {"mov", "cmp", "add", "sub", "lea", "clr", "not", "inc", "dec", "jmp", "bne", "jsr", "red", "prn", \
"rts", "stop"}
#define FUNCTS {0, 0, 10, 11, 0, 10, 11, 12, 13, 10, 11, 12, 0, 0, 0, 0}
#define OPCODES {0, 1, 2, 2, 4, 5, 5, 5, 5, 9, 9, 9, 12, 13, 14, 15}
#define IS_IMMEDIATE_SOURCE_LST {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define IS_DIRECT_SOURCE_LST {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define IS_RELATIVE_SOURCE_LST {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define IS_REGISTRY_SOURCE_LST {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define IS_IMMEDIATE_DEST_LST {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
#define IS_DIRECT_DEST_LST {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
#define IS_RELATIVE_DEST_LST {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}
#define IS_REGISTRY_DEST_LST {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0}
#define OPS_AMOUNT 16
struct op{
    char *name;
    unsigned char funct : 5;
    unsigned char opcode : 5;
    unsigned char isImSrc : 1;
    unsigned char isDirSrc : 1;
    unsigned char isRelSrc : 1;
    unsigned char isRegSrc : 1;
    unsigned char isImDest : 1;
    unsigned char isDirDest : 1;
    unsigned char isRelDest : 1;
    unsigned char isRegDest : 1;
};
struct op *ops[OPS_AMOUNT];
void initializeOps();
void printOps();
#endif
