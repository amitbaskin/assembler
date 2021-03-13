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
#define A_TYPE 'A'
#define R_TYPE 'R'
#define E_TYPE 'E'
typedef unsigned char reg;
enum ref {R_NONE, IM, DIR, REL, R_REG};
typedef enum ref ref;
enum wordStatus {OP, LAB, W_ENT, W_REG, IM_NUM, NUM_DATA, CHR_DATA};
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
    unsigned char isCode;
    unsigned char isData;
    unsigned char isRel;
};

typedef struct label label;

struct labelLst{
    label *tail;
    label **head;
};

typedef struct labelLst labelLst;

union uWord{
  opWord *op;
  label *lab;
  reg reg;
  long numData;
  char chrData;
};

typedef union uWord uWord;

struct sWord{
    uWord *uWord;
    int address;
    char addressType;
    wordStatus status;
    struct sWord *next;
};

typedef struct sWord sWord;

struct sWordLst{
    sWord **head;
    sWord *tail;
};

typedef struct sWordLst sWordLst;

union rawData{
    char *word;
    int num;
};

typedef union rawData rawData;

struct rawWord{
    rawData *data;
    struct rawWord *next;
};

typedef struct rawWord rawWord;

struct rawWordLst{
    rawWord **head;
    rawWord *tail;
};

typedef struct rawWordLst rawWordLst;


int isReg(char *r);
char *getReg(int i);
result isData(char *word);
result isStringOrder(char *word);
result isEntryOrder(char *word);
result isExternOrder(char *word);
result isString(char *word);
result isImmediateNum(long *got, char *word);
result isNum(long *got, char *word);

#endif
