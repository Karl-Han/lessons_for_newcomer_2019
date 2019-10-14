#include <assert.h>
#include <stdio.h>

int fast_power(int a, int b) {
    if (b == 1) {
        return a;
    }
    if (b & 0x01) {
        return a * fast_power(a * a, b / 2);
    } else {
        return fast_power(a * a, b / 2);
    }
}

int fast_power_iter(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 0x01) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    // a ^b
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", fast_power(a, b));
    assert(fast_power(a, b) == fast_power_iter(a, b));
    return 0;
}
