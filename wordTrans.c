#include <stdio.h>
#include "wordTrans.h"
#include "wordId.h"
#include "opWordGetters.h"
#include "sWordGetters.h"

unsigned int transDest(ref ref){
    if (ref == R_NONE) return 0;
    return (ref - 1) << DEST_BITS_PREFIX;
}

unsigned int transSrc(ref ref){
    if (ref == R_NONE) return 0;
    return (ref - 1) << SRC_BITS_PREFIX;
}

unsigned int transFunct(int i){
    return getFunct(i) << FUNCT_BITS_PREFIX;
}

unsigned int transOpcode(int i){
    return getOpCode(i) << OPCODE_BITS_PREFIX;
}

unsigned int transReg(reg reg){
    unsigned int result;
    result = 1 << reg;
    return result;
}

unsigned int transOp(opWord *op){
    unsigned int dest = transDest(getOpDest(op));
    unsigned int src = transSrc(getOpSrc(op));
    unsigned int funct = transFunct(getOpIndexByObject(op));
    unsigned int opCode = transOpcode(getOpIndexByObject(op));
    return dest + src + funct + opCode;
}

void printWordToFile(FILE *fp, unsigned int word){
    fprintf(fp, WORD_FORMAT, word);
}

void printAddressToFile(FILE *fp, sWord *word){
    fprintf(fp, ADDRESS_FORMAT, getSWordAddress(word));
}

void printAddressTypeToFile(FILE *fp, sWord *word){
    fprintf(fp, "%c\n", getSWordAddressType(word));
}
