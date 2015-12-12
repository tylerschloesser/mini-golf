#include <cstdio>

#include "window.h"

int main(int argc, char* argv[]) {
    printf("hello world!\n");

    Window window;
    window.init(argc, argv);

    getchar();

    return 0;
}
