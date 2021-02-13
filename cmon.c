/**
 * Copyright (c) 2021, TANG SHIQIANG <https://github.com/tsq>
 * All rights reserved.
 */

#define VERSION = "1.0.0"

#include <stdio.h>

char version[] = "1.0.0";

char cFile[] = "";

void printInfo() {
    printf("\x1b[33m[cmon] %s\x1b[0m\n", version);
    printf("\x1b[33m[cmon] watching file: cmon.c\x1b[0m\n");
    printf("\x1b[32m[cmon] starting `gcc cmon.c -o cmon && ./cmon`\x1b[0m\n");
    printf("1\n");
    printf("\x1b[32m[cmon] waiting for changes before restart\x1b[0m\n");
    printf("1\n");
}

void compileAndRunCFile() {
}

void findCFileOnCurrentDirectory() {

}

void watchCFile() {

}

int main() {
    findCFileOnCurrentDirectory();
    compileAndRunCFile();
    watchCFile();
    printInfo();
    return 0;
}
