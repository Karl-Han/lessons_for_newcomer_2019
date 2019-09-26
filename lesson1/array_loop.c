#include <stdio.h>
#include <stdlib.h>

int main() {
    // We have got one variable `a`
    int a = 1;
    printf("%d", a);
    // We can define many variables at a time
    int a1, a2, a3, a4;
    // What if we need no more than one?
    // Like 100 int variables?
    int arr[10];
    int arr1[] = {1, 2, 3, 4, 5, 6};

    // As we get array now, how do we use it?
    // What we need is loop
    // array could be used from subscript `0`
    // `i++` equivalent to `i = i +1` and `i += 1`
    int n = 0;
    while (n < 10) {
        printf("%d,", arr[n]);
        n += 1;
    }
    printf("\n");

    // Control flow:
    // 1. Initialization: `int i = 0;`
    // 2. Test condition: `i < 6`, go to 6 if predicate does not fulfill
    // 3. {} body
    // 4. Incresment of i: `i++`
    // 5. Go to 2
    // 6. Done
    for (int i = 0; i < 6; i++) {
        printf("%d,", arr1[i]);
    }
    printf("\n");

    // Do-while guarantee it will be do at least one time.
    int i = 0;
    int arr2[4] = {};
    do {
        printf("%d,", arr2[i++]);
    } while (i < 4);
    return 0;
}
