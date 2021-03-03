#include "assembler.h"
#include "wordId.h"
#include "sWordUtils.h"
#include "labUtils.h"
#include "firstParse.h"
#include "fileUtils.h"
#include "secParse.h"
#include "outputUtils.h"

result assemble(char *fName){
    label *labLst;
    sWord *sWordLst;
    sWord *dataLst;
    FILE *fp;
    if (getNewEmptySword(&sWordLst) == ERR) return ERR;
    if (getNewEmptySword(&dataLst) == ERR) return ERR;
    if (getNewEmptyLabel(&labLst) == ERR) return ERR;
    if (getReadFile(fName, &fp) == ERR) return ERR;
    if (parseFile(fp, sWordLst, dataLst, labLst) == ERR) return ERR;
    if (parseInstLst(sWordLst, labLst) == ERR) return ERR;
    if (getMainOutputFIle(fName, &fp) == ERR) return ERR;
    printIntsLst(fp, sWordLst, labLst);
    printDataLst(fp, sWordLst);
    if (printEntLst(fName, labLst) == ERR) return ERR;
    if (printExtLst(fName, sWordLst) == ERR) return ERR;
    return SUCCESS;
}
