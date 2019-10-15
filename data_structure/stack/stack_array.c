#include "stack_array.h"

Stack* init() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->cursor = -1;
    return s;
}

bool push(Stack* s, int key) {
    if (is_full(s)) {
        // It is full
        return false;
    }

    s->cursor++;
    s->array[s->cursor] = key;
    return true;
}

bool pop(Stack* s) {
    if (is_empty(s)) {
        return false;
    }

    s->cursor--;
    return true;
}

int* top(Stack* s) {
    if (!is_empty(s)) {
        return &(s->array[s->cursor]);
    }

    return NULL;
}

bool is_empty(Stack* s) { return (s->cursor == -1); }

bool is_full(Stack* s) { return (s->cursor == 9); }

void clear(Stack* s) { free(s); }
