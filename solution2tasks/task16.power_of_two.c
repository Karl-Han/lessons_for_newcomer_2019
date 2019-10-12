#include <stdbool.h>
#include <stdio.h>

bool isPowerOfTwo(int n) {
    if (n == 0) {
        return false;
    }
    while (!(n & 0x01)) {
        n >>= 1;
    }
    return n == 1;
}
