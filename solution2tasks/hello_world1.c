#include <stdio.h>

// 现在需求变了，要求函数输入一个n，按顺序输出n个hello world (同样要用递归做法)
// 按顺序指的是1,2,...,n 这样。
void halo(int i) {
    if (i == 0) {
        return;
    }
    // The difference lie on the call of halo
    printf("Hello World x %d\n", i);
    halo(i - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    halo(n);
    return 0;
}
