#include "secondParse.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "labelUtils.h"

void handleLabErr(){}

result parseInstLst(sWord *sWordLst, label *labHead){
    label *lab;
    result res;
    sWord *ptr = sWordLst;
    while (ptr != NULL){
        switch (sWordLst->status) {
            case W_ENT:
                res = isLabInLst(labHead, &lab, L_ENT, sWordLst->uWord->lab->name);
                if (res == FALSE) {
                    handleLabErr();
                    continue;
                } setEntLabel(lab);
                ptr = ptr->next;

            case LAB:
                res = isLabInLst(labHead, &lab, NONE, ptr->uWord->lab->name);
                if (res == FALSE) {
                    handleLabErr();
                    continue;
                } (*sWordLst).uWord->lab = lab;
                ptr = ptr->next;
                break;

            default:
                ptr = ptr->next;
        }
    } return res;
}
