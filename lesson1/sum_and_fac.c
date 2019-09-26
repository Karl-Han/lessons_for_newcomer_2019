#include <stdio.h>

int sum(int num) {
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum = sum + i;
    }
    return sum;
}

int factorial(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    } else {
        return factorial(n - 1) * n;
    }
}

int main() {
    int num;

    scanf("%d", &num);

    printf("sum of 1 to %d is %d\n", num, sum(num));
    printf("factorial of %d is %d\n", num, factorial(num));

    return 0;
}
