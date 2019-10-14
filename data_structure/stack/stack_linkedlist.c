#include "stack_linkedlist.h"
#include "linked_list.h"

Stack* init() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->head = NULL;
    return s;
}

void push(Stack* s, int key) { s->head = new_node_next(key, s->head); }

bool pop(Stack* s) {
    if (s->head != NULL) {
        s->head = s->head->next;
        return true;
    }
    return false;
}

int* top(Stack* s) { return &(s->head->num); }

bool is_empty(Stack* s) { return (s->head == NULL); }

void clear_stack(Stack* s) {
    while (!is_empty(s)) {
        Node* temp = s->head;
        free(temp);
        pop(s);
    }
}
