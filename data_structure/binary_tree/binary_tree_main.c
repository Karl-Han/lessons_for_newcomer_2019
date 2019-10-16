#include "binary_tree.h"

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

    inorder_walk(root);

    clear_node(root);
    return 0;
}
