#include "queue_array.h"

Queue* init() {
    Queue* s = (Queue*)malloc(sizeof(Queue));
    s->head = 0;
    s->tail = 0;
    return s;
}

// Wait in the tail
bool enqueue(Queue* s, int key) {
    if (is_full(s)) {
        // It is full
        return false;
    }

    s->array[s->tail] = key;
    s->tail++;
    s->tail %= 10;
    return true;
}

// Discard the one in the head
bool dequeue(Queue* s) {
    if (is_empty(s)) {
        return false;
    }

    s->head = (s->head + 1) % 10;
    return true;
}

// Get the one in the head
int* get_head(Queue* s) {
    if (!is_empty(s)) {
        return &(s->array[s->head]);
    }

    return NULL;
}

bool is_empty(Queue* s) { return (s->head == s->tail); }

// tail is at most head -1
bool is_full(Queue* s) { return (s->head == (s->tail + 1) % 10); }

void clear(Queue* s) { free(s); }
