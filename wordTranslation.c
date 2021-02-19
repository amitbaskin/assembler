#include <stdio.h>
#include "wordTranslation.h"
#include "machineWord.h"
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

unsigned int getInitialWord(unsigned int dest, unsigned int src, unsigned int funct, unsigned int opcode){
    return dest + src + funct + opcode;
}

void printWordToFile(FILE *fp, unsigned int word){
    fprintf(fp, "%03X", word);
}
