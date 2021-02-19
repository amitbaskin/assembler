#ifndef ASSEMBLER_MACHINE_WORD_H
#define ASSEMBLER_MACHINE_WORD_H
#define ERR 2
#define TRUE 1
#define FALSE 0
#define NOT_REG -1
#define LABEL_SUFFIX ':'
#define NUM_PREFIX '#'
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
static const char *regs[] = REGS;
enum reg {R0, R1, R2, R3, R4, R5, R6, R7};
enum ref {IM, DIR, REL, R_REG};
enum addressType {A, R, E};
enum wordStatus {INIT, LAB, W_REG, NUM, CHR};
enum labelType {COD, DAT, ENT, EXT};

struct initial{
    char *op;
    enum ref src;
    enum ref dest;
};

struct label{
    char *name;
    unsigned int address;
    enum labelType type;
    struct label *next;
};

union uWord{
  struct initial init;
  struct label lab;
  enum reg reg;
  int num;
  char chr;
};

struct sWord{
    union uWord word;
    enum wordStatus status;
    unsigned int address;
    enum addressType type;
    struct sWord *next;
};


#endif
