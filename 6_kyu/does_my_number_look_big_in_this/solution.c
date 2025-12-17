#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool narcissistic(int num) {
    int p = log10(num) + 1;
    printf("%d\n", p);
    int sum = 0;
    int initial = num;
    while(initial != 0) {
        sum += pow(initial % 10, p);
        if (sum > num) return false;

        initial /= 10;
    }
    if (sum == num)
        return true;
    else
        return false;
}

int main(void) {
    int num = 153;
    printf("Is %d narcissistic? %s\n", num, narcissistic(num) ? "Yes" : "No");

    num = 7;
    printf("Is %d narcissistic? %s\n", num, narcissistic(num) ? "Yes" : "No");

    return 0;
}
