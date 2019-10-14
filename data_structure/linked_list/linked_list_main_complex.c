#include <stddef.h>
#include <stdio.h>
#include "linked_list_complex.h"

int main() {
    Node* temp = NULL;

    Node* n = new_node(1);

    temp = add_last_node(temp, n);

    remove_entry(temp, n);

    trasversal(temp);

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

    // Have no affect on head
    printf("456 => 123 => 789\n");
    head = add_last_node(head, NULL);
    trasversal(head);
    printf("\n");

    // 123 => 789
    printf("123 => 789\n");
    head = delete_key(head, 456);
    trasversal(head);
    printf("\n");

    // 123 => 456 => 789
    printf("123 => 456 => 789\n");
    head = insert_node_before_key(head, 789, new_node_next(456, head->next));
    trasversal(head);
    printf("\n");

    // 123 => 456
    printf("123 => 456\n");
    head = delete_key(head, 789);
    trasversal(head);
    printf("\n");

    // 123 => 456
    printf("123 => 456\n");
    head = insert_node_after_key(head, 0, new_node(234));
    trasversal(head);
    printf("\n");

    clear(head);
    return 0;
}
