#include <stdio.h>
#include <stdbool.h>

struct arr_int {
    int arr[200000];
    int len;
};

bool checkExist(int num, struct arr_int arr) {
    int i;
    for (i = 0; i < arr.len; i++) {
        if (num == arr.arr[i]) {
            return true;
        }
    }
    return false;
}

int migratoryBirds(struct arr_int birds) {
    int i;
    struct arr_int types; types.len = 0;
    struct arr_int types_count; types_count.len = 0;
    for (i = 0; i < birds.len; i++) {
        if (! checkExist(birds.arr[i], types)) {
            types.arr[types.len] = birds.arr[i];
            types.len++;
        }
    }
    int num;
    int i2;
    printf("len: %d\n", birds.len);
    for (i = 0; i < types.len; i++) {
        num = types.arr[i];
        types_count.arr[types_count.len] = 0;
        for (i2 = 0; i2 < birds.len; i2++) {
            if (birds.arr[i2] == num) {
                types_count.arr[types_count.len] += 1;
                printf("Considered number: %d; Count: %d\n", num, types_count.arr[types_count.len]);
            }
        }
        types_count.len++;
    }
    int mostCommonIndex = 0;
    for (i = 0; i < types_count.len; i++) {
        if (types_count.arr[i] > types_count.arr[mostCommonIndex]) {
            mostCommonIndex = i;
        }
    }
    int mostCommon = types.arr[mostCommonIndex];
    printf("count: %d\n", types_count.arr[mostCommonIndex]);
    return mostCommon;
}

int main() {
    struct arr_int birds_migration_arr;
    scanf("%d", &birds_migration_arr.len);
    int len = birds_migration_arr.len;
    int i;
    for (i = 0; i < birds_migration_arr.len; i++) {
        scanf("%d", &birds_migration_arr.arr[i]);
    }
    birds_migration_arr.len = len;
    printf("%d\n", birds_migration_arr.len);
    int result = migratoryBirds(birds_migration_arr);
    printf("%d\n", result);
    return 0;
}