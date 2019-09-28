#include "pointer.h"
#include <stdio.h>
#include <stdlib.h>

void newline() { printf("\n"); }

// Give me a length, then I will generate a sequence of random
// numbers to you.
// Side effect: You need to free it yourself
// Input: num
// Output: Pointer to array with length of num
int* gen_rand_arr(int num) {
    int* arr;
    arr = (int*)malloc(sizeof(int) * num);
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        arr[i] = rand();
    }
    return arr;
}

int max_rec(int* arr, int pos, int length) {
    // Trival situation
    if (pos == length - 1) {
        return arr[pos];
    }
    int max_rest = max_rec(arr, pos + 1, length);
    return (arr[pos] > max_rest) ? arr[pos] : max_rest;
}

// Find max recursively
int max(int* arr, int length) { return max_rec(arr, 0, length); }

// Definition:
// f(0) = 0, f(1) = 1
// f(n) = f(n-1) + f(n-2)
// Reference: https://en.wikipedia.org/wiki/Fibonacci_number
int fibonacci(int num) {
    // Two base case
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}

void pointer_alone() {
    int num = 123;
    int* a;

    // Store the address of variable num
    a = &num;
    // Use `*` to dereference pointer
    printf("%d\n", *a);
    int abc;

    long* l;
    char* c;
    double* d;
    // Pointer store an address
    printf("Size of int* is %lu\n", sizeof(a));
    printf("Size of long* is %lu\n", sizeof(l));
    printf("Size of double* is %lu\n", sizeof(d));
    printf("Size of char* is %lu\n", sizeof(c));

    // I have not seen it before
    char* str =
        "Hello"
        "World";
    printf("%s\n", str);
    printf("The address stored in str is %p\n", str);
    printf("%p\n", &str);
    // Automatically add \0 at the end of char*
    for (int i = 0; i < 11; i++) {
        printf("%u ", str[i]);
        printf("%c ", str[i]);
    }
    newline();
    // Remember to add \0 if use array

    // Double pointer(pointer on pointer)
    // Explain later
    char** ptr2 = &str;
    printf("Derefer doule pointer : %s\n", *ptr2);
}

void pointer_and_array() {
    // We have seen array
    int arr[10];
    printf("%lu\n", sizeof(arr));

    // Variable length array(Since C99)
    int length;
    scanf("%d", &length);
    int arr1[length];
    printf("%lu\n", sizeof(arr1));

    // Another way to get array, that's with pointer
    // As we know all pointer store the address of the element it pointes to, so
    // its size is 8 bytes (In 64bits machine)
    // Reserve space for it
    // 50 int elements for example
    int* arr2;
    arr2 = (int*)malloc(sizeof(int) * 50);
    for (int i = 0; i < 50; i++) {
        arr2[i] = i + 32;
    }
    for (int i = 0; i < 50; i++) {
        printf("%d ", arr2[i]);
    }
    free(arr2);
    newline();

    // Two dimension array
    int matrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", matrix[i][j]);
        }
        newline();
    }
    printf("%p\n", matrix);
    for (int i = 0; i < 3; i++) {
        printf("%p\n", matrix[i]);
    }
    void* ptr = matrix;
    // In fact matrix allocate a series of space for int
    for (int i = 0; i < 9; i++) {
        printf("%d ", *(int*)(ptr + 4 * i));
    }
    newline();

    // What if we want a matrix that with different element each row
    // array[0][] = {1, 2, 3, 4, 5}
    // array[1][] = {1, 2, 3, 4, 5, 6, 7}
    // array[2][] = {1, 2}
    // It will be very wasteful when we have a long array in it
    // Use Double Pointer
    int** matrix1;
    // Manually allocate memory for each array
    matrix1 = (int**)malloc(sizeof(int*) * 3);
    matrix1[0] = (int*)malloc(sizeof(int) * 5);
    matrix1[1] = (int*)malloc(sizeof(int) * 7);
    matrix1[2] = (int*)malloc(sizeof(int) * 2);
    printf("%p\n", matrix1);
    // Continuous memory
    printf("Address at %p\n", &matrix1[0]);
    printf("Address at %p\n", &matrix1[1]);
    printf("Address at %p\n", &matrix1[2]);
    // Not continuous
    printf("matrix1[0] starts at %p\n", matrix1[0]);
    printf("matrix1[0] ends at %p\n", &matrix1[0][4]);
    printf("matrix1[1] starts at %p\n", matrix1[1]);
    printf("matrix1[1] ends at %p\n", &matrix1[1][6]);
    printf("matrix1[2] starts at %p\n", matrix1[2]);
    printf("matrix1[2] ends at %p\n", &matrix1[2][1]);
    // Remember to free it manually
    // free(matrix);
    free(matrix1[0]);
    free(matrix1[1]);
    free(matrix1[2]);
    // If free it first we can not find elements in it anymore
    free(matrix1);
}

void random_int_arr() {
    int num;
    printf("Enter the number of random numbers:");
    scanf("%d", &num);
    int* arr = gen_rand_arr(num);
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    newline();
    printf("Max in arr is %d", max(arr, num));
}

