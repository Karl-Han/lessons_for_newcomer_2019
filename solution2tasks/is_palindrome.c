#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char* str) {
    char* end = str;
    int count = strlen(str);
    for (int i = 0; i < count / 2; i++) {
        if (str[i] != end[-i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(isPalindrome("20191002") == false);
    assert(isPalindrome("2019102") == false);
    printf("Pass isPalindrome");
    return 0;
}
