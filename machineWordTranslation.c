#include <stdio.h>
#include "machineWordTranslation.h"
#include "machineWordIdentifiers.h"
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

void printWordToFile(FILE *fp, int word){
    fprintf(fp, WORD_FORMAT, word);
}

void printAddressToFile(FILE *fp, int address){
    fprintf(fp, ADDRESS_FORMAT, address);
}

void printAddressTypeToFile(FILE *fp, char type){
    fprintf(fp, "%c", type);
}
