#ifndef __stack
#define __stack

#include <stdbool.h>
#include <stdlib.h>

/*
 * This is array implemented stack, which is fixed size.
 *
 * Functions to implement:
 * 1. Initial a stack
 * 2. Push elements to stack
 * 3. Get the top element in the stack
 * 4. Pop the top element in the stack
 *
 * How cursor move?
 * cursor = -1 ~ n-1
 * Push:
 * 1. Move to next
 * 2. Push key in the current position
 *
 * Pop:
 * 1. Return the current value
 * 2. Go back
 *
 */

typedef struct _Stack {
    int array[10];
    int cursor;
} Stack;

Stack* init();

bool push(Stack* s, int key);

bool pop(Stack* s);

int* top(Stack* s);

bool is_empty(Stack* s);

bool is_full(Stack* s);

void clear(Stack* s);

#endif
