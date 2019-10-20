#include "binary_search_tree.h"

int compare(void* a, void* b) { return *(int*)a > *(int*)b; }

void print(Node* node) { printf("%d ", *(int*)node->data); }

int main() {
    Node* root = NULL;
    int num;
    int counter = 0;
    int arr[10];

    while (scanf("%d", &num) != EOF) {
        int* n = (int*)malloc(sizeof(int));
        *n = num;
        if (num & 0x1) {
            arr[counter++] = num;
        }
        root = insertion(root, (void*)n);
    }

    inorder_walk(root, print);

    printf("counter = %d\n", counter);

    for (int i = 0; i < counter; i++) {
        Node* to_delete = search(root, &arr[i]);
        deletion(&root, to_delete);
        printf("%d is deleted\n", arr[i]);

        if (i < counter - 2) {
            inorder_walk(root, print);
        }
    }

    inorder_walk(root, print);

    return 0;
}
