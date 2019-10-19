#ifndef __linked_list
#define __linked_list

typedef struct Node {
    int num;
    struct Node* next;
} Node;

Node* new_node(int key);

Node* new_node_next(int key, Node* next_node);

void trasversal(Node* head);

void clear(Node* head);

// ----- Key as argument to find position to insert key

Node* add_last(Node* head, int key);

Node* insert_before_key(Node* head, int key, int to_insert);

Node* insert_after_key(Node* head, int key, int to_insert);

Node* delete_key(Node* head, int key);
// First in last out

#endif
