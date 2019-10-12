#include <stdio.h>

/*
// What is the purpose of return int?
int hello(int x, int i) {
    // What is this predicate?
    // i > 0 && x >= i
    if (x >= i > 0)
        printf("Hello world! x %d\n", i);
    else
        return 0;
    // Why don't you use curly paratheses?
    // What is the control flow?
    hello(x, i + 1);
}
*/

void hello_good_example(int x, int i) {
    if (x >= i) {
        printf("Hello world! x %d\n", i);
        hello_good_example(x, i + 1);
    }
}
int main(void) {
    printf("ENTER:");
    int x;
    scanf("%d", &x);
    int i;
    i = 1;
    hello_good_example(x, i);
    return 0;
}
