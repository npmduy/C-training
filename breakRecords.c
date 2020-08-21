#include <stdio.h>

struct arr_int {
    int arr[100];
    int len;
};

struct arr_int countRecords(struct arr_int scores) {
    int highest = scores.arr[0];
    int lowest = scores.arr[0];
    int highest_rec_count = 0;
    int lowest_rec_count = 0;
    int i;
    for (i = 1; i < scores.len; i++) {
        if (scores.arr[i] > highest) {
            highest = scores.arr[i];
            highest_rec_count++;
        }
        if (scores.arr[i] < lowest) {
            lowest = scores.arr[i];
            lowest_rec_count++;
        }
    }
    struct arr_int ans;
    ans.len = 2;
    ans.arr[0] = highest_rec_count;
    ans.arr[1] = lowest_rec_count;
    return ans;
}

int main() {
    struct arr_int scores;
    scanf("%d", &scores.len);
    int i;
    for (i = 0; i < scores.len; i++) {
        scanf("%d", &scores.arr[i]);
    }
    struct arr_int result = countRecords(scores);
    for (i = 0; i < result.len; i++) {
        printf("%d ", result.arr[i]);
    }
    return 0;
}