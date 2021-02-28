#include <stdio.h>
#include "wordTrans.h"
#include "wordId.h"
#include "opWordGetters.h"
#include "sWordGetters.h"

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

unsigned int transOp(opWord *op){
    return transDest(getOpDest(op)) + transSrc(getOpSrc(op)) + transFunct(getFunct(getOpIndexByObject(op)))
    + transOpcode(getOpCode(getOpIndexByObject(op)));
}

void printWordToFile(FILE *fp, unsigned int word){
    fprintf(fp, WORD_FORMAT, word);
}

void printAddressToFile(FILE *fp, sWord *word){
    fprintf(fp, ADDRESS_FORMAT, getSWordAddress(word));
}

void printAddressTypeToFile(FILE *fp, sWord *word){
    fprintf(fp, "%c\n", getSWordAddress(word));
}
