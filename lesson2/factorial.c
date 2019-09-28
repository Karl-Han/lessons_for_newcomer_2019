#include <assert.h>
#include <stdio.h>

// size_t factorial(size_t n) { return n ? n * factorial(n - 1) : 1; }

// void test_factorial() {
//    size_t cases[][2] = {{0, 1}, {1, 1}, {2, 2}, {3, 6}, {4, 24}, {5, 120}};
//    for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
//        size_t arg = cases[i][0];
//        size_t expected = cases[i][1];
//    }
//}

// void run_all_test() {}

int product(int *a, int len) {
    assert(len > 0 && a);
    if (len == 1) {
        return a[0];
    }
    return a[0] * product(a + 1, len - 1);
    // return a[len - 1] * product(a, len - 1);
}

int *max(int *a, size_t len) {
    if (len == 0) {
        return NULL;
    } else if (len == 1) {
        return a;
    }
    int *next_max = max(a + 1, len - 1);
    if (*a > *next_max) {
        return a;
    } else {
        return next_max;
    }
}

int main(void) {
    int cases = { {1}, {1, 2}, {1, 2, 3} }
}
