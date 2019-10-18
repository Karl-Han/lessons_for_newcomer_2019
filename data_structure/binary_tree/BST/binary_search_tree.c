#include "binary_search_tree.h"

Node* new_node_init(Node* parent, Node* left_child, Node* right_child,
                    void* data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->parent = parent;
    temp->left_child = left_child;
    temp->right_child = right_child;
    temp->data = data;
    return temp;
}

Node* new_node(void* data) { return new_node_init(NULL, NULL, NULL, data); }

Node* max_node(Node* root) {
    Node* c = NULL;

    while (root != NULL) {
        c = root;
        root = root->right_child;
    }

    return c;
}

Node* min_node(Node* root) {
    Node* c = NULL;

    while (root != NULL) {
        c = root;
        root = root->left_child;
    }

    return c;
}

Node* successor(Node* subroot) {
    if (subroot->right_child != NULL) {
        // has successor on the right subtree
        return min_node(subroot->right_child);
    }

    // Go upward and right
    Node* p = subroot->parent;
    while (p != NULL && subroot == p->right_child) {
        subroot = p;
        p = p->parent;
    }

    return p;
}

Node* predecessor(Node* subroot) {
    if (subroot->left_child != NULL) {
        return max_node(subroot->left_child);
    }

    // Go upward and left
    Node* p = subroot->parent;
    while (p != NULL && subroot == p->left_child) {
        subroot = p;
        p = p->parent;
    }

    return p;
}

// NULL as no found
Node* search(Node* root, void* data) {
    // No root
    if (root == NULL) {
        return NULL;
    }

    Node* temp = root;
    while (temp != NULL) {
        if (compare(data, temp->data) > 0) {
            // data > temp->data
            temp = temp->right_child;
        } else if (compare(data, temp->data) < 0) {
            // data < temp->data
            temp = temp->left_child;
        } else {
            return temp;
        }
    }

    return NULL;
}

Node* insertion(Node* root, void* data) {
    // No root
    if (root == NULL) {
        return new_node(data);
    }

    Node* p = NULL;
    Node* temp = root;
    while (temp != NULL) {
        if (compare(data, temp->data)) {
            // data > temp->data
            p = temp;
            temp = temp->right_child;
        } else {
            // data < temp->data
            p = temp;
            temp = temp->left_child;
        }
    }

    Node* insert = new_node_init(p, NULL, NULL, data);

    if (p == NULL) {
        // origin root == NULL
        return insert;
    } else if (compare(data, p->data)) {
        // data > p->data
        p->right_child = insert;
    } else {
        // data < p->data
        p->left_child = insert;
    }

    return root;
}

// be_replace could not be NULL
Node* transplant(Node* be_replace, Node* replacer, Node* root) {
    if (be_replace->parent == NULL) {
        return replacer;
    }

    if (be_replace == be_replace->parent->left_child) {
        be_replace->parent->left_child = replacer;
        replacer->parent = be_replace->parent;
    } else {
        be_replace->parent->right_child = replacer;
        replacer->parent = be_replace->parent;
    }

    return root;
}

Node* deletion(Node* root, Node* z) {
    if (z->parent == NULL) {
        return NULL;
    }

    if (z->left_child == NULL) {
        transplant(z, z->right_child, root);
        return root;
    }

    // it has left_child
    if (z->right_child == NULL) {
        transplant(z, z->left_child, root);
        return root;
    }

    // it has both child
    Node* s = min_node(z->right_child);

    if (s->parent != z) {
        transplant(s, s->right_child, root);
        s->right_child = z->right_child;
        s->right_child->parent = s;
    }
    // common operation
    transplant(z, s, root);
    s->left_child = z->left_child;
    s->left_child->parent = s;
    return root;
}

void inorder_walk(Node* subroot, void func(Node*)) {
    if (subroot == NULL) {
        return;
    }
    inorder_walk(subroot->left_child, func);
    func(subroot);
    inorder_walk(subroot->right_child, func);
}
