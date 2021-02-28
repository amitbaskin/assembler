#ifndef ASSEMBLER_OP_INFO_GETTERS_H
#define ASSEMBLER_OP_INFO_GETTERS_H
#define NOT_OP -1
int getOpIndexByStr(char *word);
char *getOpName(int opIndex);
unsigned char getOperandsAmount(int opIndex);
unsigned char getFunct(int opIndex);
unsigned char getOpCode(int opIndex);
unsigned char getIsImSrc(int opIndex);
unsigned char getIsDirSrc(int opIndex);
unsigned char getIsRelSrc(int opIndex);
unsigned char getIsRegSrc(int opIndex);
unsigned char getIsImDest(int opIndex);
unsigned char getIsDirDest(int opIndex);
unsigned char getIsRelDest(int opIndex);
unsigned char getIsRegDest(int opIndex);
#endif
