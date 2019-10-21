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
    Node* c = root;

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

void insertion(Tree* t, void* data) {
    Node* p = NULL;
    Node* temp = t->root;
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
        t->root = insert;
    } else if (compare(data, p->data)) {
        // data > p->data
        p->right_child = insert;
    } else {
        // data < p->data
        p->left_child = insert;
    }
}

// be_replace could not be NULL
void transplant(Tree* t, Node* be_replace, Node* replacer) {
    // if (replacer != NULL && replacer->parent != NULL) {
    //    if (replacer == replacer->parent->left_child) {
    //        replacer->parent->left_child = NULL;
    //    } else {
    //        replacer->parent->right_child = NULL;
    //    }
    //}

    // be_replace is root
    if (be_replace->parent == NULL) {
        // just change be_replace to NULL
        t->root = replacer;
        return;
    }

    if (be_replace == be_replace->parent->left_child) {
        be_replace->parent->left_child = replacer;
    } else {
        be_replace->parent->right_child = replacer;
    }
    if (replacer != NULL) {
        replacer->parent = be_replace->parent;
    }
}

void deletion(Tree* t, Node* z) {
    if (z->left_child == NULL) {
        transplant(t, z, z->right_child);
    }

    // it has left_child
    if (z->right_child == NULL) {
        transplant(t, z, z->left_child);
    }

    else {
        // it has both child
        Node* s = min_node(z->right_child);

        if (s->parent != z) {
            transplant(t, s, s->right_child);
            s->right_child = z->right_child;
            s->right_child->parent = s;
        }
        // common operation
        transplant(t, z, s);
        s->left_child = z->left_child;
        s->left_child->parent = s;
    }
}

void inorder_walk(Node* subroot, void func(Node*)) {
    if (subroot == NULL) {
        return;
    }
    inorder_walk(subroot->left_child, func);
    func(subroot);
    inorder_walk(subroot->right_child, func);
}
