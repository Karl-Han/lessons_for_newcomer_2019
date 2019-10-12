#include <assert.h>
#include <stdio.h>

unsigned long multiply(unsigned int x, unsigned int y) {
    unsigned long res = 0;
    unsigned long l = x;
    // Guarantee x > y
    if (y > x) {
        unsigned int temp = x;
        x = y;
        y = temp;
    }

    while (y) {
        if (y & 0x01) {
            res += l;
        }
        y >>= 1;
        l <<= 1;
    }

    return res;
}

int main() {
    unsigned int x, y;
    scanf("%u%u", &x, &y);
    unsigned long res = (unsigned long)x * y;
    printf("%lu\n", res);
    unsigned long mul_res = multiply(x, y);
    printf("%lu\n", mul_res);
    assert(mul_res == res);
    return 0;
}
