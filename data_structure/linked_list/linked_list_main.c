#include <stddef.h>
#include <stdio.h>
#include "linked_list.h"

int main() {
    printf("head = NULL\n");
    Node* head = NULL;
    trasversal(head);
    printf("\n");

    printf("123\n");
    head = add_last(head, 123);
    trasversal(head);
    printf("\n");

    // 456 => 123
    printf("456 => 123\n");
    head = insert_before_key(head, 123, 456);
    trasversal(head);
    printf("\n");

    // 456 => 123 => 789
    printf("456 => 123 => 789\n");
    head = insert_after_key(head, 123, 789);
    trasversal(head);
    printf("\n");

    // 123 => 789
    printf("123 => 789\n");
    head = delete_key(head, 456);
    trasversal(head);
    printf("\n");

    // 123 => 456
    printf("123 => 456\n");
    head = delete_key(head, 789);
    trasversal(head);
    printf("\n");

    clear(head);
    return 0;
}
