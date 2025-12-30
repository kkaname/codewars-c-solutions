#include <stdio.h>

int digital_root(int n) {
    if (n < 10) {
        return n;
    }

    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    if (sum > 9) {
        return digital_root(sum);
    }
    return sum;
}

int main(void) {
    int n = 16;
    printf("digital root of %d is %d\n", n, digital_root(n));

    return 0;
}
