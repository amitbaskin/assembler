#include "assembler.h"

int main(int argc, char **args) {
    while (--argc){
        assemble(*++args);
    }
}
