#include "opWordUtils.h"
#include "uWordUtils.h"
#include "sWordSetters.h"
#include "generalUtils.h"

opWord *getOpWord(int opIndex, ref src, ref dest){
    void *initPtr;
    getAlloc(sizeof(opWord), &initPtr);
    opWord *op = (opWord *) initPtr;
    op->opIndex = opIndex;
    op->src = src;
    op->dest = dest;
    return op;
}
