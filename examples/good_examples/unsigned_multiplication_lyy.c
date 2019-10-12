#include <stdio.h>

int multi(int a, int b) {
    int res = 0;
    while (b) {
        if (b & 1) res = res + a;
        a = a << 1;
        b = b >> 1;
    }
    return res;
}

int main() {
    int a = 4;
    int b = 6;
    printf("%d\n", multi(a, b));
    return 0;
}
