#include "generalUtils.h"
#ifndef ASSEMBLER_WORD_ID_H
#define ASSEMBLER_WORD_ID_H
#define LABEL_SUFFIX ':'
#define NUM_PREFIX '#'
#define REL_PREFIX '%'
#define DATA_ORDER ".data"
#define STRING_ORDER ".string"
#define ENTRY_ORDER ".entry"
#define EXTERN_ORDER ".extern"
#define DEST_BITS_PREFIX 0
#define SRC_BITS_PREFIX 2
#define FUNCT_BITS_PREFIX 4
#define OPCODE_BITS_PREFIX 8
#define REGS {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7"}
#define REGS_AMOUNT 8
#define OPERATIONS_AMOUNT 16
#define A_TYPE 'A'
#define R_TYPE 'R'
#define E_TYPE 'E'
typedef unsigned char reg; /* type for registers */
typedef enum {R_NONE, IM, DIR, REL, R_REG} ref; /* operands' references */
typedef enum {OP, LAB, W_ENT, W_REG, IM_NUM, NUM_DATA, CHR_DATA} wordStatus; /* status of parsed words to later translate to
 * machine code for the output */
typedef enum {L_NONE, L_ENT, EXT} labelType; /* type for the declared labels in the assembly file */

/* an instruction word which represents an operator */
typedef struct {
    int opIndex;
    ref src;
    ref dest;
} opWord;

/* label data structure */
typedef struct label {
    char *name;
    int address;
    struct label *next;
    labelType type;
    unsigned char isData;
    unsigned char isRel;
} label;

typedef struct {
    label *tail;
    label **head;
} labelLst;

typedef union {
  opWord *op;
  label *lab;
  reg reg;
  long numData;
  char chrData;
} uWord;

typedef struct sWord{
    uWord *uWord;
    int address;
    char addressType;
    wordStatus status;
    struct sWord *next;
} sWord;

typedef struct {
    sWord **head;
    sWord *tail;
} sWordLst;

typedef union {
    char *word;
    int num;
} rawData;

typedef struct rawWord {
    rawData *data;
    struct rawWord *next;
} rawWord;

typedef struct {
    rawWord **head;
    rawWord *tail;
} rawWordLst;

/* operation data structure */
typedef struct {
    unsigned char index;
    char *name;
    unsigned char opAmount;
    int opcode;
    int funct;
    unsigned char isImSrc;
    unsigned char isDirSrc;
    unsigned char isRelSrc;
    unsigned char isRegSrc;
    unsigned char isImDest;
    unsigned char isDirDest;
    unsigned char isRelDest;
    unsigned char isRegDest;
} operation; /* index specified just for convenience so it is easy to see what is the index of each operation, as this is used
 * throughout the code in order to identify operators */

int isReg(char *r);
const char *getReg(int i);
result isDataOrder(char *word);
result isStringOrder(char *word);
result isEntryOrder(char *word);
result isExternOrder(char *word);
result isString(char *word);
result isImmediateNum(long *got, char *word);
result isNum(long *got, char *word);

#endif
