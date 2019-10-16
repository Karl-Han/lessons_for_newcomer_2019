#include "binary_tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

TreeNode* new_node(void* p) {
    TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
    n->data = p;
    n->left_child = NULL;
    n->right_child = NULL;
    return n;
}

bool add_left_node(TreeNode* sub_root, TreeNode* left) {
    if (sub_root != NULL) {
        sub_root->left_child = left;
        return true;
    }
    return false;
}

bool add_right_node(TreeNode* sub_root, TreeNode* left) {
    if (sub_root != NULL) {
        sub_root->right_child = left;
        return true;
    }
    return false;
}

TreeNode* int2void(int key) {
    int* k = (int*)malloc(sizeof(int));
    *k = key;
    TreeNode* n = new_node(k);
    return n;
}

/* Old version of clear_node
void clear_node(TreeNode* sub_root) {
    if (sub_root != NULL) {
        // clean left
        clear_node(sub_root->left_child);
        clear_node(sub_root->right_child);
        free(sub_root->data);
        free(sub_root);
    }
}
*/

void free_node(TreeNode* node) {
    free(node->data);
    free(node);
}

void clear_node(TreeNode* root) { inorder_walk_op(root, free_node); }

/* Old version of inorder_walk
void inorder_walk(TreeNode* sub_root) {
    if (sub_root != NULL) {
        inorder_walk(sub_root->left_child);
        inorder_walk(sub_root->right_child);
        printf("%d ", *((int*)sub_root->data));
    }
}
*/

void print_node(TreeNode* node) { printf("%d ", *(int*)node->data); }

void inorder_walk(TreeNode* root) {
    inorder_walk_op(root, print_node);
    printf("\n");
}

void inorder_walk_op(TreeNode* sub_root, void func(TreeNode*)) {
    if (sub_root != NULL) {
        inorder_walk_op(sub_root->left_child, func);
        inorder_walk_op(sub_root->right_child, func);
        func(sub_root);
    }
}
