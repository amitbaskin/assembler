#ifndef ASSEMBLER_OPERATIONS_API_H
#define ASSEMBLER_OPERATIONS_API_H
int isOp(char *word);
unsigned char getFunct(int i);
unsigned char getOpCode(int i);
unsigned char getIsImSrc(int i);
unsigned char getIsDirSrc(int i);
unsigned char getIsRelSrc(int i);
unsigned char getIsRegSrc(int i);
unsigned char getIsImDest(int i);
unsigned char getIsDirDest(int i);
unsigned char getIsRelDest(int i);
unsigned char getIsRegDest(int i);
#endif
