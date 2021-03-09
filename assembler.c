#include "assembler.h"
#include "wordId.h"
#include "sWordUtils.h"
#include "labUtils.h"
#include "firstParse.h"
#include "fileUtils.h"
#include "secParse.h"
#include "outputUtils.h"
#include "generalUtils.h"
#include "sWordListUtils.h"
#include "labLstUtils.h"

result assemble(char *fName) {
    labelLst *labLst = NULL;
    sWordLst *instLst = NULL;
    sWordLst *dataLst = NULL;
    FILE *fp;
    VALIDATE_VAL(initSWordLst(&instLst), "")
    VALIDATE_VAL(initSWordLst(&dataLst), "")
    VALIDATE_VAL(initLabLst(&labLst), "")
    VALIDATE_VAL(getReadFile(fName, &fp), "")
    VALIDATE_VAL(parseFile(fp, instLst, dataLst, labLst), "")
    VALIDATE_VAL(parseInstLst(instLst, labLst), "")
    VALIDATE_VAL(getMainOutputFIle(fName, &fp), "")
    printIntsLst(fp, instLst, labLst);
    printDataLst(fp, instLst);
    VALIDATE_VAL(printEntLst(fName, labLst), "")
    VALIDATE_VAL(printExtLst(fName, instLst), "")
    freeLabLst(labLst);
    freeSWordLst(instLst);
    freeSWordLst(dataLst);
    return SUCCESS;
}