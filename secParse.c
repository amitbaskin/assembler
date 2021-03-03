#include "secParse.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "labUtils.h"
#include "labSetters.h"
#include "sWordGetters.h"

result parseInstLst(sWord *sWordLst, label *labHead){
    label *lab;
    result res;
    sWord *ptr = sWordLst;
    while (ptr != NULL){
        switch (getSWordStatus(ptr)) {
            case W_ENT:
                if (isLabInLst(labHead, &lab, L_ENT, getSULabName(ptr)) == FALSE) {
                    res = ERR;
                    printf("");
                    continue;
                } setLabType(lab, L_ENT);
                setThisSWord(&ptr, getNextSWord(ptr));

            case LAB:
                if (isLabInLst(labHead, &lab, NONE, getSULabName(ptr)) == FALSE) {
                    res = ERR;
                    printf("");
                    continue;
                } setSULab(ptr, lab);
                setThisSWord(&ptr, getNextSWord(ptr));
                break;

            default:
                setThisSWord(&ptr, getNextSWord(ptr));
        }
    } return res;
}
