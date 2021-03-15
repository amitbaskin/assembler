/* setters for the opWord data structure */

#include "opWordSetters.h"


void setOpIndex(opWord *op, int index){
    op->opIndex = index;
}

void setOpSrcRef(opWord *op, ref src){
    op->src = src;
}

void setOpDestRef(opWord *op, ref dest){
    op->dest = dest;
}
