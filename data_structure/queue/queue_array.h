#ifndef __queue
#define __queue

#include <stdbool.h>
#include <stdlib.h>

/*
 * This is array implemented queue, which is fixed size.
 *
 * Functions to implement:
 * 1. Initial a queue
 * 2. Enqueue elements into queue
 * 3. Get the first element in the queue
 * 4. Dequeue
 *
 *
 * Enqueue
 * 1. Enqueue where tail points to
 * 2. Go around the array
 *
 * Dequeue
 * 1. Dequeue where head points to.
 * 2. Move to the previous
 *
 */

typedef struct _Queue {
    int array[10];
    // Points to the first element to dequeue
    int head;
    // Insert the element here
    int tail;
} Queue;

Queue* init();

bool enqueue(Queue* s, int key);

bool dequeue(Queue* s);

int* get_head(Queue* s);

bool is_empty(Queue* s);

bool is_full(Queue* s);

void clear(Queue* s);

#endif
