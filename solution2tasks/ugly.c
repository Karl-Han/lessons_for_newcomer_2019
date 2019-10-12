#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool isUgly(int num) {
    if (num == 0) {
        return false;
    }
    while ((num & 0x01) == 0) {
        num >>= 1;
    }
    while (num % 3 == 0) {
        num /= 3;
    }
    while (num % 5 == 0) {
        num /= 5;
    }
    return num == 1;
}

int main() {
    assert(isUgly(6) == true);
    return 0;
}
