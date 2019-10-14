#include <assert.h>
#include <stdio.h>
#include "stack_array.h"

int main() {
    Stack* s = init();

    assert(top(s) == NULL);

    push(s, 123);
    assert(*(top(s)) == 123);

    for (int i = 0; i < 20; i++) {
        push(s, i);
    }

    int t;
    while (!is_empty(s)) {
        t = *top(s);
        printf("%d\n", t);
        pop(s);
    }

    clear(s);
    return 0;
}
