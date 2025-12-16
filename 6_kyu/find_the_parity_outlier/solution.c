#include <stdio.h>

int find_outlier(const int values[], size_t count) {
    int odd_count, even_count;
    int even_index, odd_index;

    odd_count = even_count = 0;
    even_index = odd_index = -1;

    for (int i = 0; i < count; i++) {
        if ((values[i] & 1) == 0) {
            ++even_count;
            even_index = i;
        }
        else {
            ++odd_count;
            odd_index = i;
        }
    }

    return (even_count == 1)? even_index : odd_index;
}

int main(void) {
    int a[] = {2, 4, 0, 100, 4, 11, 2602, 36};

    printf("The outlier is %d\n", a[find_outlier(a, sizeof(a)/sizeof(a[0]))]);

    return 0;
}
