#ifndef ASSEMBLER_OP_INFO_GETTERS_H
#define ASSEMBLER_OP_INFO_GETTERS_H
char *getOpName(int index);
unsigned char getOperandsAmount(int opIndex);
int getFunct(int opIndex);
int getOpCode(int opIndex);
unsigned char getIsImSrc(int opIndex);
unsigned char getIsDirSrc(int opIndex);
unsigned char getIsRelSrc(int opIndex);
unsigned char getIsRegSrc(int opIndex);
unsigned char getIsImDest(int opIndex);
unsigned char getIsDirDest(int opIndex);
unsigned char getIsRelDest(int opIndex);
unsigned char getIsRegDest(int opIndex);
int getOpIndexByStr(char *word);
#define NOT_OP (-1)
#endif
