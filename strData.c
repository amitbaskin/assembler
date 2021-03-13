#include <string.h>
#include "parseLineUtils.h"
#include "labLstUtils.h"
#include "labSetters.h"
#include "sWordListUtils.h"
#include "errFuncs.h"

extern int labelFlag;
extern int dataCounter;

void strScenario(char *str, label *lab, labelLst *labLst, sWordLst *instLst){
    unsigned long len = strlen(str);
    int i;
    char chr;
    flagOnScenario(&lab, labLst, setLabData, dataCounter);
    for (i=1; i<len-1; i++){
        chr = str[i];
        addChrWord(chr, instLst);
    } addChrWord('\0', instLst);
}

result isStrScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst){
    if (isStringOrder(word) == FALSE) return FALSE;
    if (getWord(line, &word, 0) != LINE_END) VALIDATE_VAL(finishLine(line))
    if (isString(word) == FALSE) {
        nonStrDataErr();
        return ERR;
    } strScenario(word, lab, labLst, dataLst);
    return TRUE;
}
