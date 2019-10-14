#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Reference:
// https://www.cs.cmu.edu/~adamchik/15-121/lectures/Linked%20Lists/linked%20lists.html

// Two way to make new node
Node* new_node(int key) { return new_node_next(key, NULL); }

Node* new_node_next(int key, Node* next_node) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->num = key;
    temp->next = next_node;
    return temp;
}

void trasversal(Node* head) {
    while (head != NULL) {
        printf("num = %d\n", head->num);
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

Node* add_last(Node* head, int key) {
    if (head == NULL) {
        return new_node(key);
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node(key);
    return head;
}

// 1. Insert before head node
// 2. Insert after
Node* insert_before_key(Node* head, int key, int to_insert) {
    if (head == NULL) {
        return NULL;
    }
    if (head->num == key) {
        return new_node_next(to_insert, head);
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->num != key) {
        temp = temp->next;
    }
    if (temp->next->num == key) {
        temp->next = new_node_next(to_insert, temp->next);
    }
    return head;
}

Node* insert_after_key(Node* head, int key, int to_insert) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    while (temp != NULL && temp->num != key) {
        temp = temp->next;
    }
    if (temp->num == key) {
        temp->next = new_node_next(to_insert, temp->next);
    }
    return head;
}

// 1. Delete head node
// 2. Delete other node
Node* delete_key(Node* head, int key) {
    if (head == NULL) {
        return NULL;
    }
    if (head->num == key) {
        Node* temp = head->next;
        free(head);
        return temp;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->num != key) {
        temp = temp->next;
    }
    // temp->next == NULL or temp->next->num == key
    if (temp->next != NULL && temp->next->num == key) {
        temp->next = temp->next->next;
    }
    return head;
}

Node* add_last_node(Node* head, Node* node) {
    if (head == NULL) {
        return node;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

Node* insert_node_before_key(Node* head, int key, Node* to_insert) {
    if (head == NULL) {
        return NULL;
    }
    if (head->num == key) {
        to_insert->next = head;
        return to_insert;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->num != key) {
        temp = temp->next;
    }
    if (temp->next->num == key) {
        // temp->next = new_node_next(to_insert, temp->next);
        to_insert->next = temp->next;
        temp->next = to_insert;
        return head;
    }
    return head;
}

Node* insert_node_after_key(Node* head, int key, Node* to_insert) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    while (temp != NULL && temp->num != key) {
        temp = temp->next;
    }
    // if temp == NULL, then no found
    if (temp != NULL && temp->num == key) {
        to_insert->next = temp->next;
        temp->next = to_insert;
    }
    return head;
}

void remove_entry(Node* head, Node* entry) {
    Node** indirect = &head;

    while ((*indirect) != entry) {
        indirect = &(*indirect)->next;
    }

    *indirect = entry->next;
}
