#include "assembler.h"
#include "fileUtils.h"

extern char *inputFileName;

int main(int argc, char **args) {
    FILE *fp;
    while (--argc){
        inputFileName = *++args;
        if (getReadFile(inputFileName, &fp) == ERR) continue;
        assemble(inputFileName, fp);
        closeFile(fp); /* err handled inside if one occurs */
    } return 0;
}
