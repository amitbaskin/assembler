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
    sWordLst = getNewEmptySword();
    dataLst = getNewEmptySword();
    labLst = getNewEmptyLabel();
    getReadFile(fName, &fp);
    parseFile(fp, sWordLst, dataLst, labLst);
    parseInstLst(sWordLst, labLst);
    getMainOutputFIle(fName, &fp);
    printIntsLst(fp, sWordLst, labLst);
    printDataLst(fp, sWordLst);
    if (printEntLst(fName, labLst) == ERR) return ERR;
    if (printExtLst(fName, sWordLst) == ERR) return ERR;
    return ERR;
}
