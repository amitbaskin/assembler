#ifndef ASSEMBLER_MACHINE_WORD_H
#define ASSEMBLER_MACHINE_WORD_H
#define ERR 2
#define TRUE 1
#define FALSE 0
#define NOT_REG -1
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
enum ref {IM, DIR, REL, R_REG};
typedef enum ref ref;
enum wordStatus {INIT, LAB, W_REG, NUM, CHR};
typedef enum wordStatus wordStatus;
enum labelType {COD, DAT, ENT, EXT};
typedef enum labelType labelType;

struct initial{
    char *op;
    enum ref src;
    enum ref dest;
};

typedef struct initial initial;

struct label{
    char *name;
    int address;
    struct label *next;
    unsigned char isCode : 1;
    unsigned char isData : 1;
    unsigned char isEnt : 1;
    unsigned char isExt : 1;
};

typedef struct label label;

union uWord{
  initial *init;
  label *lab;
  reg reg;
  int numData;
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

int isReg(char *r);
unsigned char isData(char *word);
unsigned char isStringOrder(char *word);
unsigned char isEntryOrder(char *word);
unsigned char isExternOrder(char *word);
unsigned char isString(char *word);
unsigned char isImmediateNum(long *got, char *word);
unsigned char isNumData(long *got, char *word);

#endif
