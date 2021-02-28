#include <stdio.h>
#include "wordTrans.h"
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

unsigned int transReg(reg reg){
    if (reg == 0) return 0;
    else return 1 << reg;
}

unsigned int transInit(opWord *init){
    return transDest(init->dest) + transSrc(init->src) +transFunct(getFunct(init->opIndex)) + transOpcode(getOpCode
    (init->opIndex));
}

void printWordToFile(FILE *fp, unsigned int word){
    fprintf(fp, WORD_FORMAT, word);
}

void printAddressToFile(FILE *fp, sWord *word){
    fprintf(fp, ADDRESS_FORMAT, word->address);
}

void printAddressTypeToFile(FILE *fp, sWord *word){
    fprintf(fp, "%c\n", word->addressType);
}
