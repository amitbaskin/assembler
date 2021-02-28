#include "opWordGetters.h"
#include "uWordSetters.h"
#include "sWordSetters.h"
#include "generalUtils.h"

int getOpIndex(opWord *op){
    return op->opIndex;
}

ref getOpSrcRef(opWord *op){
    return op->src;
}

ref getOpDestRef(opWord *op){
    return op->dest;
}

opWord *getOpWord(int opIndex, ref src, ref dest){
    void *initPtr;
    getAlloc(sizeof(opWord), &initPtr);
    opWord *op = (opWord *) initPtr;
    op->opIndex = opIndex;
    op->src = src;
    op->dest = dest;
    return op;
}
