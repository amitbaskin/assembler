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
