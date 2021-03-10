#include <stdio.h>
#include "string.h"
#include "wordTrans.h"
#include "wordId.h"
#include "opWordGetters.h"
#include "sWordGetters.h"

int transDest(int ref){
    if (ref == R_NONE) return 0;
    return (ref - 1) << DEST_BITS_PREFIX;
}

int transSrc(int ref){
    if (ref == R_NONE) return 0;
    return (ref - 1) << SRC_BITS_PREFIX;
}

int transFunct(int i){
    return getFunct(i) << FUNCT_BITS_PREFIX;
}

int transOpcode(int i){
    return getOpCode(i) << OPCODE_BITS_PREFIX;
}

int transReg(int reg){
    return 1 << reg;
}

int transOp(opWord *op){
    int dest = transDest(getOpDest(op));
    int src = transSrc(getOpSrc(op));
    int funct = transFunct(getOpIndexByObject(op));
    int opCode = transOpcode(getOpIndexByObject(op));
    return dest + src + funct + opCode;
}

void printWordToFile(FILE *fp, int word){
    void *ptr = NULL;
    char *str = NULL;
    unsigned long len;
    if (word < 0){
        getAlloc(sizeof(int), &ptr);
        str = (char *) ptr;
        sprintf(str, "%X", word);
        len = strlen(str);
        fprintf(fp, STR_WORD_FORMAT, str[len-3], str[len-2], str[len-1]);
        freeHelper(str);
    } else fprintf(fp, INT_WORD_FORMAT, word);
}

void printAddressToFile(FILE *fp, sWord *word){
    fprintf(fp, ADDRESS_FORMAT, getSWordAddress(word));
}

void printAddressTypeToFile(FILE *fp, sWord *word){
    fprintf(fp, "%c\n", getSWordAddressType(word));
}
