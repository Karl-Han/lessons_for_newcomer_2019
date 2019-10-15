#include <stddef.h>
#include <stdio.h>
#include "linked_list.h"

void print(void* p) { printf("%d\n", *(int*)p); }

void op() {
    printf("head = NULL\n");
    Node* head = NULL;
    trasversal(head, print);
    printf("\n");

    printf("123\n");
    int a = 123;
    head = add_last(head, &a);
    trasversal(head, print);
    printf("\n");

    // 456 => 123
    printf("456 => 123\n");
    int b = 456;
    head = insert_before_key(head, &a, &b);
    trasversal(head, print);
    printf("\n");

    // 456 => 123 => 789
    printf("456 => 123 => 789\n");
    int c = 789;
    head = insert_after_key(head, &a, &c);
    trasversal(head, print);
    printf("\n");

    // 123 => 789
    printf("123 => 789\n");
    head = delete_key(head, &b);
    trasversal(head, print);
    printf("\n");

    // 123
    printf("123\n");
    head = delete_key(head, &c);
    trasversal(head, print);
    printf("\n");

    clear(head);
}

int main() {
    Node* head = NULL;
    Node** target = &head;

    return 0;
}
