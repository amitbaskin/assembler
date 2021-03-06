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
#define REGS_LEN 8
#define A_TYPE 'A'
#define R_TYPE 'R'
#define E_TYPE 'E'
static const char *regs[] = REGS;
enum reg {R0, R1, R2, R3, R4, R5, R6, R7};
typedef enum reg reg;
enum ref {R_NONE, IM, DIR, REL, R_REG};
typedef enum ref ref;
enum wordStatus {W_NONE, OP, LAB, W_ENT, W_REG, DIR_NUM, NUM_DATA, CHR_DATA};
typedef enum wordStatus wordStatus;
enum labelType {L_NONE, L_ENT, EXT};
typedef enum labelType labelType;

struct opWord{
    int opIndex;
    ref src;
    ref dest;
};

typedef struct opWord opWord;

struct label{
    char *name;
    int address;
    struct label *next;
    labelType type;
    unsigned char isNameAlloc : 1;
    unsigned char isCode : 1;
    unsigned char isData : 1;
    unsigned char isRel : 1;
};

typedef struct label label;

struct labelLst{
    label *tail;
    label *head;
    label *cur;
};

typedef struct labelLst labelLst;

union uWord{
  opWord *op;
  label *lab;
  reg reg;
  long numData;
  char chrData;
  wordStatus status;
};

typedef union uWord uWord;

struct sWord{
    uWord *uWord;
    int address;
    char addressType;
    struct sWord *next;
};

typedef struct sWord sWord;

struct sWordLst{
    sWord *head;
    sWord *tail;
    sWord *cur;
};

typedef struct sWordLst sWordLst;

struct rawWord{
    char *word;
    struct rawWord *next;
};
typedef struct rawWord rawWord;


int isReg(char *r);
result isData(char *word);
result isStringOrder(char *word);
result isEntryOrder(char *word);
result isExternOrder(char *word);
result isString(char *word);
result isImmediateNum(long *got, char *word);
result isNumData(long *got, char *word);

#endif
