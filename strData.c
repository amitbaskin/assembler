/* this file is used to process string statements */

#include <string.h>
#include "parseLineUtils.h"
#include "labLstUtils.h"
#include "labSetters.h"
#include "sWordListUtils.h"
#include "errFuncs.h"
#include "globalVars.h"


void strScenario(char *str, label *lab, labelLst *labLst, sWordLst *instLst){
    /* executes the scenario in case of a string statement
     * adds the string to the data list such that each character acts as an item, including the null terminator */
    unsigned long len = strlen(str);
    int i;
    char chr;
    flagOnScenario(&lab, labLst, getDataCounter(), 1);
    for (i=1; i<len-1; i++){
        chr = str[i];
        addChrWord(chr, instLst);
    }
    addChrWord('\0', instLst);
}

result isStrScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst){
    /* checks whether or not we have a string statement scenario
     * returns ERR if it is a corrupt string statement, FALSE if its not a string statement and TRUE if it is a valid
     * string statement */
    if (isStringOrder(word) == FALSE) return FALSE;
    if (getWord(line, &word, 0) != LINE_END) VALIDATE_VAL(finishLine(line))
    if (isString(word) == FALSE) {
        nonStrDataErr();
        return ERR;
    }
    strScenario(word, lab, labLst, dataLst);
    return TRUE;
}
