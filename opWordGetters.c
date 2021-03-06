#include "opWordGetters.h"
#include "uWordSetters.h"
#include "sWordSetters.h"

int getOpIndexByObject(opWord *op){
    return op->opIndex;
}

ref getOpSrc(opWord *op){
    return op->src;
}

ref getOpDest(opWord *op){
    return op->dest;
}

result getOpWord(int opIndex, ref src, ref dest, opWord **op){
    void *initPtr;
    VALIDATE_VAL(getAlloc(sizeof(opWord), &initPtr), "");
    *op = (opWord *) initPtr;
    (*op)->opIndex = opIndex;
    (*op)->src = src;
    (*op)->dest = dest;
    return SUCCESS;
}
