#include <stdio.h>

// For more placeholder, please consult
// https://en.cppreference.com/w/c/io/fprintf

int main() {
    // Sometimes we need to know a number/string/... from user

    // Put a `&` before variable `a`
    // `%d` in `""` is a place holder for variables
    int d, a;
    scanf("%d%d", &d, &a);
    printf("%d %d\n", a, d);

    char c = 'a';
    printf("char = %c, f = %f, d = %lf", c, 3.14, 1.0);
    return 0;
}
