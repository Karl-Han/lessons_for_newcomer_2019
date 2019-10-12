#include <assert.h>
#include <stdio.h>

int count(int num) {
    int count = 0;

    if (num < 0) {
        num &= 0x7fffffff;
        count++;
    }

    while (num) {
        if (num & 0x01) {
            count++;
        }
        num >>= 1;
    }

    return count;
}

int main() {
    assert(count(-1) == 32);
    assert(count(1) == 1);
    assert(count(3) == 2);
    assert(count(-2) == 31);
    printf("Pass count");
    return 0;
}

