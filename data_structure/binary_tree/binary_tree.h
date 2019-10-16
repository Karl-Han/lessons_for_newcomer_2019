#ifndef __binary_tree
#define __binary_tree

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
    void* data;
    struct _TreeNode* left_child;
    struct _TreeNode* right_child;
} TreeNode;

TreeNode* new_node(void* p);

bool add_left_node(TreeNode* sub_root, TreeNode* left);

bool add_right_node(TreeNode* sub_root, TreeNode* left);

TreeNode* int2void(int key);

void inorder_walk_op(TreeNode* sub_root, void func(TreeNode*));

void inorder_walk(TreeNode* root);

void clear_node(TreeNode* sub_root);

#endif
