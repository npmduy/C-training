#include <stdio.h>
#include <stdbool.h>

struct arr_int1 {
    int arr[100];
    int len;
};

long long getGCD(long long a,long long b) {
    while (a != b) {
        if (a>b) { a -= b; }
        else { b -= a; }
    }
    return a;
}

long long getLCM(long long a, long long b) {
    long long gcd = getGCD(a, b);
    long long lcm = (a*b) / gcd;
    return lcm;
}

long long getArrGCD(struct arr_int1 arr) {
    int index = 0;
    int count = 0;
    long long temp_arr[2];
    long long gcd = arr.arr[0];
    while (index != arr.len) {
        temp_arr[count] = arr.arr[index];
        index++;
        count++;
        if (count == 2) {
            gcd = getGCD(temp_arr[0], temp_arr[1]);
            arr.arr[arr.len] = gcd;
            arr.len++;
            count = 0;
        }
    }
    return gcd;
}

long long getArrLCM(struct arr_int1 arr) {
    int index = 0;
    int count = 0;
    long long temp_arr[2];
    long long lcm = arr.arr[0];
    while (index != arr.len) {
        temp_arr[count] = arr.arr[index];
        index++; 
        count++; 
        if (count == 2) {
            lcm = getLCM(temp_arr[0], temp_arr[1]);
            arr.arr[arr.len] = lcm;
            arr.len++;
            count = 0;
        }
    }
    return lcm;
}

int getTotalX(struct arr_int1 a, struct arr_int1 b) {
    long long lcm_a = getArrLCM(a);
    long long gcd_b = getArrGCD(b);
    //printf("hello world\n");
    long long multiplicand = lcm_a;
    int multiplier = 1;
    long long product = lcm_a;
    //struct arr_int1 numbers_between;
    //numbers_between.len = 0;
    //int index = 0;
    int count = 0;
    //printf("hello world\n");
    while (product <= gcd_b) {
        //printf("Hello\n");
        //numbers_between.arr[index] = product; index++; numbers_between.len++;
        if (gcd_b % product == 0) { count++; }
        multiplier++;
        product = multiplicand * multiplier;
    }
    return count;
}

int main() {
    int n,m;
    scanf("%d%d", &n, &m);
    struct arr_int1 a; a.len = n;
    struct arr_int1 b; b.len = m;
    int i;
    for (i = 0; i < a.len; i++) {
        scanf("%d", &a.arr[i]);
    }
    for (i = 0; i < b.len; i++) {
        scanf("%d", &b.arr[i]);
    }
    int total = getTotalX(a, b);
    printf("%d", total);
    return 0;
}