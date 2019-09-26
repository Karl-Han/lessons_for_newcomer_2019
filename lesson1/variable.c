#include <stdio.h>

int main() {
    // Define a variable `a`
    int a;
    // Assign `a` with 1
    a = 1;
    // Initialization variable `b`
    // Which means that declare and assign
    int b = 2;
    printf("a = %d\nb = %d\n", a, b);
    // We can define many variables at a time
    int a1, a2, a3, a4;

    // Integer
    // 2 bytes
    short s = 1;
    int i = 1;
    long int i1 = 1;
    long long i2 = 1;
    unsigned int u3 = -1;
    printf("u3 = %lu\n", u3);

    // Floating point
    float f = 1.0;
    double d = 3.14;
    printf("f = %f, d = %lf\n", f, d);

    // Character in ASCII
    char c = 'a';
    printf("char c = %c\n", c);

    return 0;
}
