#include "linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Reference:
// https://www.cs.cmu.edu/~adamchik/15-121/lectures/Linked%20Lists/linked%20lists.html

// Two way to make new node
Node* new_node(void* key) { return new_node_next(key, NULL); }

Node* new_node_next(void* key, Node* next_node) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = key;
    temp->next = next_node;
    return temp;
}

Node* head_insert(Node* head, void* key) { return new_node_next(key, head); }

// 1. head == null, just create new node
// 2. head != null, go to the last one
Node* add_last(Node* head, void* key) {
    if (head == NULL) {
        return new_node(key);
    }

    // Leave head unchange to return
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node(key);
    return head;
}

// 1. head->key == key, insert before head node
// 2. other case, go to where temp->next->key == key
Node* insert_before_key(Node* head, void* key, void* to_insert) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == key) {
        return new_node_next(to_insert, head);
    }

    Node* temp = head;
    // Short circuit evaluation
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next->data == key) {
        temp->next = new_node_next(to_insert, temp->next);
    }
    // No found do nothing
    return head;
}

// All case is the same
Node* insert_after_key(Node* head, void* key, void* to_insert) {
    if (head == NULL) {
        return NULL;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp->data == key) {
        temp->next = new_node_next(to_insert, temp->next);
    }
    return head;
}

// It is very like insert_before_key
// 1. Delete head node
// 2. Delete other node
Node* delete_key(Node* head, void* key) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == key) {
        Node* temp = head->next;
        free(head);
        return temp;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next != NULL && temp->next->data == key) {
        temp->next = temp->next->next;
    }
    // temp->next == NULL, no found do nothing
    return head;
}

void trasversal(Node* head, void print(void*)) {
    while (head != NULL) {
        print(head->data);
        head = head->next;
    }
}

void clear(Node* head) {
    Node* temp = head;
    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
}
