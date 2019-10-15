#include "queue_array.h"

Queue* init() {
    Queue* s = (Queue*)malloc(sizeof(Queue));
    s->head = 0;
    s->tail = 0;
    return s;
}

bool enqueue(Queue* s, int key) {
    if (is_full(s)) {
        // It is full
        return false;
    }

    s->array[s->tail++] = key;
    s->tail %= 10;
    return true;
}

bool dequeue(Queue* s) {
    if (is_empty(s)) {
        return false;
    }

    s->head = (s->head + 1) % 10;
    return true;
}

int* get_head(Queue* s) {
    if (!is_empty(s)) {
        return &(s->array[s->head]);
    }

    return NULL;
}

bool is_empty(Queue* s) { return (s->head == s->tail); }

bool is_full(Queue* s) { return (s->head - 1 == s->tail); }

void clear(Queue* s) { free(s); }
