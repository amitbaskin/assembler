#ifndef ASSEMBLER_OP_DEF_H
#define ASSEMBLER_OP_DEF_H
#define OPERATIONS_AMOUNT 16

struct operation{
    unsigned char index;
    char *name;
    unsigned char opAmount;
    int opcode;
    int funct;
    unsigned char isImSrc : 1;
    unsigned char isDirSrc : 1;
    unsigned char isRelSrc : 1;
    unsigned char isRegSrc : 1;
    unsigned char isImDest : 1;
    unsigned char isDirDest : 1;
    unsigned char isRelDest : 1;
    unsigned char isRegDest : 1;
};

typedef struct operation operation;

static const operation opLst[] = {\
{0, "mov", 2, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1},
{1, "cmp", 2, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
{2, "add", 2, 2, 10, 1, 1, 0, 1, 0, 1, 0, 1},
{3, "sub", 2, 2, 11, 1, 1, 0, 1, 0, 1, 0, 1},
{4, "lea", 2, 4, 0, 1, 1, 0, 0, 0, 1, 0, 1},
{5, "clr", 1, 5, 10, 0, 0, 0, 0, 0, 1, 0, 1},
{6, "not", 1, 5, 11, 0, 0, 0, 0, 0, 1, 0, 1},
{7, "inc", 1, 5, 12, 0, 0, 0, 0, 0, 1, 0, 1},
{8, "dec", 1, 5, 13, 0, 0, 0, 0, 0, 1, 0, 1},
{9, "jmp", 1, 9, 10, 0,0, 0, 0, 0, 1, 1, 1},
{10, "bne", 1, 9, 11, 0,0, 0, 0, 0, 1, 1, 1},
{11, "jsr", 1, 9, 12, 0,0, 0, 0, 0, 1, 1, 1},
{12, "red", 1, 12, 0, 0, 0, 0, 0, 0, 1, 0, 1},
{13, "prn", 1, 13, 0, 0, 0, 0, 0, 1, 1, 0, 1},
{14, "rts", 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{15, "stop",0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

#endif
