/*Day 2 Turing clase 2018.
1. Array.
2. Pointer.
3. Search.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pointer.h"
int factorial(int*, int);
int ite_binarySearch(int* array, int size, int key);
int rec_binarySearch(int* array, int left, int right, int key);
void factorial_example();
void part_int();

int main() {
    factorial_example();
    part_int();

    int key = 8;
    int pos = 0;
    int pos1 = 0;

    int array[] = {1, 3, 4, 6, 7, 8, 10};
    int num = sizeof(array) / 4;
    pos = rec_binarySearch(array, 0, num - 1, key);
    pos1 = ite_binarySearch(array, num, key);
    if (pos == -1)
        printf("Not Found!\n");
    else
        printf("The position is %d.\n", pos);

    if (pos != pos1) {
        printf("ERROR");
        exit(1);
    }

    return 0;
}

void part_int() {
    int num = 0xffeeddcc;
    unsigned char* numptr;
    numptr = (unsigned char*)&num;
    printf("%x\n", num);
    for (int i = 0; i < 4; i++) {
        printf("%x\n", *(numptr + i));
    }
}

void factorial_example() {
    int len = 10;

    /*To alloc a block.*/
    int* array = (int*)malloc(sizeof(int) * len);

    /*Initialize the array; */
    for (int i = 0; i < len; i++) {
        array[i] = i + 1;
    }

    printf("The product is %d.\n", factorial(array, len));
}

int factorial(int* arr, int len) {
    int res = 1;

    for (int i = 0; i < len; i++) {
        res *= arr[i];
    }

    return res;
}

/* A recursive binary search function. It returns location of x in
   given array arr[l..r] is present, otherwise -1
*/
int rec_binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        /* If the element is present at the middle itself */
        if (arr[mid] == x) return mid;
        /* If element is smaller than mid, then it can only be present
         in left subarray */
        if (arr[mid] > x) return rec_binarySearch(arr, l, mid - 1, x);
        /* Else the element can only be present in right subarray */
        return rec_binarySearch(arr, mid + 1, r, x);
    }
    /* We reach here when element is not present in array */
    return -1;
}

int ite_binarySearch(int* array, int size, int key) {
    int left = 0, right = size, mid = -1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (array[mid] == key) return mid;
        if (array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
