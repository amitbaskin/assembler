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
enum ref {IM, DIR, REL, R_REG, NOT_REF};
typedef enum ref ref;
enum wordStatus {OP, LAB, W_ENT, W_REG, NUM, CHR};
typedef enum wordStatus wordStatus;
enum labelType {L_ENT, EXT, NONE};
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
    unsigned char isCode : 1;
    unsigned char isData : 1;
    unsigned char isRel : 1;
};

typedef struct label label;

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
    wordStatus status;
    int address;
    char addressType;
    struct sWord *next;
};

typedef struct sWord sWord;

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
