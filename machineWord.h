#ifndef ASSEMBLER_MACHINE_WORD_H
#define ASSEMBLER_MACHINE_WORD_H
#define LABEL_SUFFIX ':'
#define NUM_PREFIX '#'
#define DATA_ORDER ".data"
#define STRING_ORDER ".string"
#define ENTRY_ORDER ".entry"
#define EXTERN_ORDER ".extern"

enum reg {r0, r1, r2, r3, r4, r5, r6, r7};
enum ref {IM, DIR, REL, R_REG};
enum addressType {A, R, E};
enum wordStatus {INIT, LAB, W_REG, NUM};
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
};

struct sWord{
    union uWord word;
    enum wordStatus status;
    unsigned int address;
    enum addressType type;
    struct sWord *next;
};


#endif
