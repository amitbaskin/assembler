#include "secParse.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "labUtils.h"
#include "labSetters.h"
#include "sWordGetters.h"

void handleLabErr(){}

result parseInstLst(sWord *sWordLst, label *labHead){
    label *lab;
    result res;
    sWord *ptr = sWordLst;
    while (ptr != NULL){
        switch (getSWordStatus(ptr)) {
            case W_ENT:
                res = isLabInLst(labHead, &lab, L_ENT, getSULabelName(ptr));
                if (res == FALSE) {
                    handleLabErr();
                    continue;
                }
                setLabType(lab, L_ENT);
                setThisSWord(&ptr, getNextSWord(ptr));

            case LAB:
                res = isLabInLst(labHead, &lab, NONE, getSULabelName(ptr));
                if (res == FALSE) {
                    handleLabErr();
                    continue;
                } setSULab(ptr, lab);
                setThisSWord(&ptr, getNextSWord(ptr));
                break;

            default:
                setThisSWord(&ptr, getNextSWord(ptr));
        }
    } return res;
}
