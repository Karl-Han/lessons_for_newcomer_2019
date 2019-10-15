#include <assert.h>
#include <stdio.h>
#include "queue_array.h"

int main() {
    Queue* s = init();

    assert(get_head(s) == NULL);

    enqueue(s, 123);
    assert(*(get_head(s)) == 123);

    for (int i = 0; i < 20 && !is_full(s); i++) {
        enqueue(s, i);
        printf("%d is not full yet\n", i);
    }

    int t;
    while (!is_empty(s)) {
        t = *get_head(s);
        printf("%d\n", t);
        dequeue(s);
    }

    clear(s);
    return 0;
}
