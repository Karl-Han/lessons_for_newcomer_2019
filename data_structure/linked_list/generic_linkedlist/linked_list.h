#ifndef __linked_list
#define __linked_list

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

Node* new_node(void* key);

Node* new_node_next(void* key, Node* next_node);

void trasversal(Node* head, void print(void*));

void clear(Node* head);

// ----- Key as argument to find position to insert key

Node* add_last(Node* head, void* key);

Node* insert_before_key(Node* head, void* key, void* to_insert);

Node* insert_after_key(Node* head, void* key, void* to_insert);

Node* delete_key(Node* head, void* key);

#endif
