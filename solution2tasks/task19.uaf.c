#include <stdlib.h>

int main() {
    int* a = (int*)malloc(0x18);
    int* b = (int*)malloc(0x18);
    free(a);
    free(b);
    // The position allocate to b has been free, so it can not use it any more
    *b = 0xdeadbeef;
    a = (int*)malloc(0x18);
    b = (int*)malloc(0x18);
    return 0;
}
