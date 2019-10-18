#ifndef __BST
#define __BST

/*
 * Binary-search-tree property:
 * Let x be a node in a binary search tree.
 * * If y is a node in the left subtree of x, then y:key < x:key.
 * * If y is a node in the right subtree of x, then y:key > x:key.
 *
 * Assume there is no same value in the tree
 *
 * Function to implement:
 * 1. Max and Min
 * 2. Successor and Predecessor
 * 3. Insertion and Deletion
 *
 * Prerequisite
 * For Deletion:
 * * Transplant of subroot
 * * Find Successor
 *
 * Structure:
 * * Node* parent
 * * Node* left_child
 * * Node* right_child
 * * void* data
 *
 * Compare of data must implement a funtion and wrap it
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// return a > b
extern int compare(void* a, void* b);

typedef struct _Node {
    struct _Node* parent;
    struct _Node* left_child;
    struct _Node* right_child;
    void* data;
} Node;

Node* new_node_init(Node* parent, Node* left_child, Node* right_child,
                    void* data);

Node* new_node(void* data);

Node* max_node(Node* root);

Node* min_node(Node* root);

Node* successor(Node* subroot);

Node* predecessor(Node* subroot);

Node* search(Node* root, void* data);

Node* insertion(Node* root, void* data);

// be_replace could not be NULL
Node* transplant(Node* be_replace, Node* replacer, Node* root);

Node* deletion(Node* root, Node* z);

void inorder_walk(Node* subroot, void func(Node*));

#endif
