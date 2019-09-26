#include <stdio.h>

/*
 * Two ways to declare new function
 * 1. Declare before use, then implement it after. In this case: bar()
 * 2. Define before use. In this case: foo()
 */

void bar();

void foo() {
    printf("Hello ");
    printf("World\n");
}

int main() {
    foo();
    bar();

    return 0;
}

void bar() {
    printf("Hello ");
    printf("Class");
}
