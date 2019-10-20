#include "binary_search_tree.h"

int compare(void* a, void* b) { return *(int*)a > *(int*)b; }

void print(Node* node) { printf("%d ", *(int*)node->data); }

int main() {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->root = NULL;
    int num;
    int counter = 0;
    int arr[10];

    while (scanf("%d", &num) != EOF) {
        int* n = (int*)malloc(sizeof(int));
        *n = num;
        if (num & 0x1) {
            arr[counter++] = num;
        }
        insertion(t, (void*)n);
    }

    inorder_walk(t->root, print);

    printf("counter = %d\n", counter);

    for (int i = 0; i < counter; i++) {
        Node* to_delete = search(t->root, &arr[i]);
        deletion(t, to_delete);
        printf("%d is deleted\n", arr[i]);
    }

    inorder_walk(t->root, print);

    return 0;
}
