/* this file is used to translate the instructions and data collected into machine code to output */

#include <string.h>
#include "wordTrans.h"
#include "opDef.h"
#include "opWordGetSet.h"
#include "sWordGetters.h"
#include "errFuncs.h"


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

result printWordToFile(FILE *fp, int word){
    void *ptr = NULL;
    char *str = NULL;
    char *orgStr = NULL;
    unsigned long len;
    VALIDATE_VAL(getAlloc(sizeof(int)+1, &ptr));
    str = (char *) ptr;
    orgStr = str;
    sprintf(str, INT_WORD_FORMAT, word);
    len = strlen(str);
    str[len] = ' ';
    str += (len - WORD_LEN);
    fprintf(fp, "%s", str);
    freeHelper(orgStr);
    return SUCCESS;
}

result printAddressToFile(FILE *fp, sWord *word){
    if (fprintf(fp, ADDRESS_FORMAT, getSWordAddress(word)) < 0) {
        printErr();
        return ERR;
    }
    return SUCCESS;
}

result printAddressTypeToFile(FILE *fp, sWord *word){
    if (fprintf(fp, "%c\n", getSWordAddressType(word)) < 0){
        printErr();
        return ERR;
    }
    return SUCCESS;
}
