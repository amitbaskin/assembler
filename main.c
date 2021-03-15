#include "assembler.h"
#include "errFuncs.h"


int main(int argc, char **args) {
    /* assemble the given file names given as arguments */
    if (argc == 1) usageErr();
    while (--argc){
        assemble(*++args);
    } return 0;
}
