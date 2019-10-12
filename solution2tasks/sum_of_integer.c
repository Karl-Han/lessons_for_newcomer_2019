#include <stdio.h>

int add(int a, int b) {
    int temp;
    while (b) {
        // Other than the first time, b is the carrier
        // a is the sum
        temp = a;
        a ^= b;
        b = (temp & b) << 1;
    }
    return a;
}

int main() {
    // printf("%d\n", add(2, 3));
    // printf("%d\n", add(-2, 3));
    // printf("%d\n", add(-3, 2));
    // printf("%d\n", add(-1, 1));
    int a = 1073741824;
    printf("a = %d, a<<1 = %d", a, a << 1);
    return 0;
}
