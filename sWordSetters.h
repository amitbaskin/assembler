#include "wordIdentifiers.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_MANAGE_MACHINE_WORD_H
#define ASSEMBLER_MANAGE_MACHINE_WORD_H
uWord *getUWord();
label *getSWordLabel(sWord *word);
sWord *getSword();
void setUWord(sWord *sWord, uWord *uWord);
void setSWordStatus(sWord *sWord, wordStatus status);
void setSWordAddress(sWord *sWord, int address);
void setSWordAddressType(sWord *sWord, char addressType);
void setLabStatus(sWord *sWord);
void setEntStatus(sWord *sWord);
void setNumStatus(sWord *sWord);
void setChrStatus(sWord *sWord);
void setRegStatus(sWord *sWord);
void setOpWordStatus(sWord *sWord);
#endif
