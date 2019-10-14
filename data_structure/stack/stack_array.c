#include "stack.h"

Stack* init() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->cursor = -1;
    return s;
}

bool push(Stack* s, int key) {
    if (s->cursor == 9) {
        // It is full
        return false;
    }

    s->cursor++;
    s->array[s->cursor] = key;
    return true;
}

bool pop(Stack* s) {
    if (s->cursor == -1) {
        return false;
    }

    s->cursor--;
    return true;
}

int* top(Stack* s) {
    if (s->cursor != -1) {
        return &(s->array[s->cursor]);
    }

    return NULL;
}

void clear(Stack* s) { free(s); }

bool is_empty(Stack* s) { return (s->cursor == -1); }
