#include "queue_linkedlist.h"
#include "linked_list.h"

Queue* init() {
    Queue* s = (Queue*)malloc(sizeof(Queue));
    s->head = NULL;
    return s;
}

bool enqueue(Queue* s, int key) {
    s->head = add_last(s->head, key);
    return true;
}

bool dequeue(Queue* s) {
    if (!is_empty(s)) {
        s->head = s->head->next;
        return true;
    }
    return false;
}

int* get_head(Queue* s) { return &(s->head->num); }

bool is_empty(Queue* s) { return (s->head == NULL); }

bool is_full(Queue* s) { return false; }

void clear_queue(Queue* s) {
    while (!is_empty(s)) {
        Node* temp = s->head;
        dequeue(s);
        free(temp);
    }
}
