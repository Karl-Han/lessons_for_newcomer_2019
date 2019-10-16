#include <assert.h>
#include <stdio.h>
#include "queue_linkedlist.h"

int main() {
    Queue* s = init();

    assert(get_head(s) == NULL);

    enqueue(s, 123);
    assert(*(get_head(s)) == 123);

    for (int i = 0; i < 20; i++) {
        enqueue(s, i);
    }

    int t;
    while (!is_empty(s)) {
        t = *get_head(s);
        printf("%d\n", t);
        dequeue(s);
    }

    clear_queue(s);
    return 0;
}
