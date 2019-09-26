#include <stdio.h>

int main() {
    printf("Enter the amount of student number:");
    int num;
    scanf("%d", &num);
    int arr[num];

    for (int i = 0; i < num; i++) {
        printf("Enter %d th studen's score:", i);
        scanf("%d", &arr[i]);
    }

    // Code below is equivalent to code above
    // int i = 0;
    // while (i < num) {
    //    printf("Enter %d th studen's score:", i);
    //    scanf("%d", &arr[i]);

    //    i++;
    //}

    int i = 0;
    while (i < num) {
        printf("The %d th student's score is %d\n", i, arr[i]);

        i++;
    }

    return 0;
}
