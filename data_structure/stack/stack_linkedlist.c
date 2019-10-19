#include "stack_linkedlist.h"
#include "linked_list.h"

Stack* init() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->head = NULL;
    return s;
}

void push(Stack* s, int key) { s->head = new_node_next(key, s->head); }

bool pop(Stack* s) {
    if (!is_empty(s)) {
        Node* temp = s->head;
        // s->head = s->head->next;
        s->head = delete_key(s->head, s->head->num);
        free(temp);
        return true;
    }
    return false;
}

int* top(Stack* s) { return &(s->head->num); }

bool is_empty(Stack* s) { return (s->head == NULL); }

bool is_full(Stack* s) { return false; }

void clear_stack(Stack* s) {
    while (!is_empty(s)) {
        Node* temp = s->head;
        free(temp);
        pop(s);
    }
}
