#include "wordIdentifiers.h"
#include "operationsApi.h"
#ifndef ASSEMBLER_WORD_TRANSLATION_H
#define ASSEMBLER_WORD_TRANSLATION_H
unsigned int transDest(enum ref ref);
unsigned int transSrc(enum ref ref);
unsigned int transFunct(int i);
unsigned int transOpcode(int i);
#endif
