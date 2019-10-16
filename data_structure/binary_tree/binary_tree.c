#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
    void* data;
    struct _TreeNode* left_child;
    struct _TreeNode* right_child;
} TreeNode;

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

void clear_node(TreeNode* sub_root) {
    if (sub_root != NULL) {
        // clean left
        clear_node(sub_root->left_child);
        clear_node(sub_root->right_child);
        free(sub_root->data);
        free(sub_root);
    }
}

void inorder_walk(TreeNode* sub_root) {
    if (sub_root != NULL) {
        inorder_walk(sub_root->left_child);
        inorder_walk(sub_root->right_child);
        printf("%d ", *((int*)sub_root->data));
    }
}

void inorder_walk_op(TreeNode* sub_root, void func(TreeNode*)) {
    if (sub_root != NULL) {
        inorder_walk(sub_root->left_child);
        inorder_walk(sub_root->right_child);
        func(sub_root);
    }
}

void print_node(TreeNode* n) { printf("%d ", *(int*)n->data); }

int main() {
    /* Let us create following BST
          50
       /     \
      30      70
     /  \    /  \
   20   40  60   80 */
    TreeNode* root = NULL;
    root = int2void(50);

    TreeNode* left_sub = int2void(30);
    add_left_node(left_sub, int2void(20));
    add_right_node(left_sub, int2void(40));

    TreeNode* right_sub = int2void(70);
    add_left_node(right_sub, int2void(60));
    add_right_node(right_sub, int2void(80));

    add_left_node(root, left_sub);
    add_right_node(root, right_sub);

    // inorder_walk(root);
    inorder_walk_op(root, print_node);

    clear_node(root);
    return 0;
}
