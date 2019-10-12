#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(char* str) {
    char* end = str;
    int count = 0;
    while (*end != 0) {
        count++;
        end++;
    }
    printf("count = %d\n", count);
    for (int i = 0; i < count / 2; i++) {
        if (str[i] != end[-i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char* str = "20191002";
    if (isPalindrome(str)) {
        printf("%s is Palindrome\n", str);
    } else {
        printf("%s is not Palindrome\n", str);
    }
    return 0;
}
