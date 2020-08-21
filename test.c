#include <stdio.h>

struct arr_int {
    int len;
};

void testFunc(struct arr_int arr) {
    printf("%d", arr.len);
}

int main() {
    struct arr_int test;
    scanf("%d", &test.len);
    testFunc(test);
    return 0;
}