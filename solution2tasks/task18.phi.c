#include <assert.h>
#include <stdio.h>

int gcd(int a, int b) {
    if (b > a) {
        int temp = b;
        b = a;
        a = temp;
    }
    while (b) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int phi(int n) {
    int counter = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            counter++;
        }
    }
    return counter;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("phi %d = %d\n", n, phi(n));
    return 0;
}
