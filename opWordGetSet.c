/* getters for the opWord data structure */

#include "opWordGetSet.h"


int getOpIndexByObject(opWord *op){
    return op->opIndex;
}

ref getOpSrc(opWord *op){
    return op->src;
}

ref getOpDest(opWord *op){
    return op->dest;
}

void setOpIndex(opWord *op, int index){
    op->opIndex = index;
}

void setOpSrcRef(opWord *op, ref src){
    op->src = src;
}

void setOpDestRef(opWord *op, ref dest){
    op->dest = dest;
}
