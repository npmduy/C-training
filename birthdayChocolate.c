#include <stdio.h>

struct arr_int {
    int arr[100];
    int len;
};

int arrSum(struct arr_int arr) {
    int i;
    int sum = 0;
    for (i = 0; i < arr.len; i++) {
        sum += arr.arr[i];
    }
    return sum;
}

int birthday(struct arr_int squares, int d, int m) {
    int index = 0;
    int temp_index;
    struct arr_int temp_squares;
    int i;
    int count;
    temp_squares.len = 0;
    while (index <= squares.len-m) {
        // Gather squares' numbers
        temp_index = index;
        for (i = 1; i <= m; i++) {
            temp_squares.arr[temp_squares.len] = squares.arr[temp_index]; temp_squares.len++;
            temp_index++;
        }
        int sum = arrSum(temp_squares);
        if (sum == d) {
            count++;
        }
        index++;
        temp_squares.len = 0;
    }
    return count;
}

int main() {
    struct arr_int squares;
    scanf("%d", &squares.len);
    int i;
    for (i = 0; i < squares.len; i++) {
        scanf("%d", &squares.arr[i]);
    }
    int d, m;
    scanf("%d%d", &d, &m);
    int result = birthday(squares, d, m);
    printf("%d\n", result);
    return 0;
}