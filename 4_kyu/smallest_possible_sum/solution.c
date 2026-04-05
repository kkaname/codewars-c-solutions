#include <stdio.h>
#include <stddef.h>

int gcd_two_num(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int smallest_possible_sum(size_t length, const int array[length]) {
    size_t i;
    int gcd = array[0];

    for (i = 0; i < length; i++) {
        gcd = gcd_two_num(gcd, array[i]);
    }

    return gcd * length;
}

int main(void) {
    const int array[] = {6, 9, 21};
    size_t length = *(&array + 1) - array;

    int sum = smallest_possible_sum(length, array);
    printf("The Smalles Possible sum of : ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("--> %d\n", sum);

    return 0;
}
