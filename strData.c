#include <string.h>
#include "strData.h"
#include "firstParseLineUtils.h"
#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#include "manageMachineWord.h"
#include "parseLabel.h"
#include "labelApi.h"

result isStrScenario(char **line, char *word, sWord **lastWord, label *head, label *lab, label **labLst){
    result res;
    if (isStringOrder(word) == FALSE) return FALSE;
    res = getWord(line, &word, 0);
    if (isString(word) == FALSE) return ERR;
    if (res != LINE_END) res = finishLine(line);
    if (res == ERR) return ERR;
    strScenario(word, lastWord, head, lab, labLst);
    return SUCCESS;
}

void strScenario(char *str, sWord **lastWord, label *head, label *lab, label **labLst){
    uWord *unionWord;
    sWord *structWord;
    unsigned long len = strlen(str);
    int i;
    char chr;
    if (labelFlag) addLabelScenario(head, &lab, labLst, setDataLabel, dataCounter++);
    for (i=1; i<len-1; i++){
        dataCounter++;
        chr = str[i];
        unionWord = getUWord();
        setChrData(unionWord, chr);
        structWord->status = CHR;
        structWord = getSword();
        structWord->uWord = unionWord;
        structWord->address = dataCounter;
        structWord->addressType = R_TYPE;
        (*lastWord)->next = structWord;
        *lastWord = structWord;
    }
}

