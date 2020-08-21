#include <stdio.h>

struct arr_int {
    int arr[100];
    int len;
};

int divisbleSumPairs(struct arr_int array, int k) {
    int index = 0;
    int i;
    int sum;
    int count = 0;
    while (index < array.len) {
        for (i = index+1; i < array.len; i++) {
            sum = array.arr[index] + array.arr[i];
            if (sum % k == 0) {
                count++;
            }
        }
        index++;
    }
}

int main() {
    struct arr_int ar;
    int k;
    scanf("%d%d", &ar.len, &k);
    int i;
    for (i = 0; i < ar.len; i++) {
        scanf("%d", &ar.arr[i]);
    }
    int result = divisbleSumPairs(ar, k);
    printf("%d\n", result);
    return 0;
}