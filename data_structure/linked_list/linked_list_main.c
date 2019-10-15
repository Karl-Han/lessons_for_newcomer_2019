#include <stddef.h>
#include <stdio.h>
#include "linked_list.h"

void func() {
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
}

// Base case: next one is NULL, so this one is the last one, return 1
//

int find_last_nth(Node* head, Node** target, int n) {
    if (head == NULL) {
        return 0;
    }

    int count = find_last_nth(head->next, target, n);

    if (count == n) {
        target = &head;
    }
    return count + 1;
}

// Test case:
// 1. Linked list is NULL
// 2. Linked list has less than n element, return NULL
// 3. Linked list has n elements, return head
// 4. Linked list has more than n elements, return the last nth

int main() {
    Node* head = NULL;
    Node** target = &head;

    int n = find_last_nth(head, target, 3);
    if (n > 3) {
        printf("%d\n", (*target)->num);
    } else {
        printf("NULL\n");
    }

    // 456 => 123 => 789
    head = add_last(head, 123);
    head = insert_before_key(head, 123, 456);

    n = find_last_nth(head, target, 3);
    if (n >= 3) {
        printf("%d\n", (*target)->num);
    } else {
        printf("NULL\n");
    }

    head = insert_after_key(head, 123, 789);
    n = find_last_nth(head, target, 3);
    if (n >= 3) {
        printf("%d\n", (*target)->num);
    } else {
        printf("NULL\n");
    }

    return 0;
}
