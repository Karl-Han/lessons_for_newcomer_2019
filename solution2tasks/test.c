#include <stdio.h>

int Hallo(int num, int count) {
    printf("Hello world! x %d\n", count);
    if (count < num) {
        count++;
        return Hallo(num, count);
    } else
        return 0;
}

int main() {
    int num = 0;
    int count = 1;
    printf("Enter the number:");
    scanf("%d", &num);
    Hallo(num, count);
    return 0;
}
