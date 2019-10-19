#include "queue_linkedlist.h"
#include "linked_list.h"

Queue* init() {
    Queue* s = (Queue*)malloc(sizeof(Queue));
    s->head = NULL;
    s->tail = NULL;
    return s;
}

bool enqueue(Queue* s, int key) {
    if (is_empty(s)) {
        s->head = s->tail = new_node(key);
        return true;
    }
    s->tail->next = new_node(key);
    s->tail = s->tail->next;
    return true;
}

bool dequeue(Queue* s) {
    if (!is_empty(s)) {
        if (s->head == s->tail) {
            s->head = s->tail = NULL;
        } else {
            s->head = s->head->next;
        }
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
