#include <stdio.h>

int main() {
    unsigned char c = 255;
    // printf("Size of char: %lu\n", sizeof(c));
    c += 1;
    printf("%d", c);
    return 0;
}
