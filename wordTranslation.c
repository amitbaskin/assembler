#include <stdio.h>
#include "wordTranslation.h"
#include "wordIdentifiers.h"
#include "operationsApi.h"

unsigned int transDest(enum ref ref){
    return ref << DEST_BITS_PREFIX;
}

unsigned int transSrc(enum ref ref){
    return ref << SRC_BITS_PREFIX;
}

unsigned int transFunct(int i){
    return getFunct(i) << FUNCT_BITS_PREFIX;
}

unsigned int transOpcode(int i){
    return getOpCode(i) << OPCODE_BITS_PREFIX;
}

unsigned int transReg(enum reg reg){
    if (reg == 0) return 0;
    else return 1 << reg;
}

unsigned int getInitialWord(unsigned int dest, unsigned int src, unsigned int funct, unsigned int opcode){
    return dest + src + funct + opcode;
}

void printWordToFile(FILE *fp, signed int word){
    fprintf(fp, "%03X", word);
}

void printAddressToFile(FILE *fp, unsigned int address){
    fprintf(fp, "%04u", address);
}

void printAddressTypeToFile(FILE *fp, char type){
    fprintf(fp, "%c", type);
}
