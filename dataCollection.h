#ifndef ASSEMBLER_DATA_COLLECTION_H
#define ASSEMBLER_DATA_COLLECTION_H
#define SEPARATOR ","
struct data{
    int num;
    struct data *next;
};
typedef struct data data;
unsigned char collectData(char **line, data *dat);
#endif
