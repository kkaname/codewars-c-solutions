#include <stdio.h>
#include <stdlib.h>

int power(int num, int n);
float round_float(float num, int n);
int *race(int v1, int v2, int g);

int main(void) {
    int v1, v2, g;
    v1 = 720;
    v2 = 850;
    g = 70;

    int *ptr = race(v1, v2, g);
    printf("For v1 = %d, v2 = %d, gap = %d: T = ", v1, v2, g);

    for (int i = 0; i < 3; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    v1 = 80;
    v2 = 91;
    g = 37;

    int *timing_ptr = race(v1, v2, g);
    printf("For v1 = %d, v2 = %d, gap = %d: T = ", v1, v2, g);
    for (int i = 0; i < 3; i++) {
        printf("%d ", timing_ptr[i]);
    }
    printf("\n");

    free(ptr);

    return 0;
}

int power(int num, int n) {
    int product = 1;
    for (int i = 0; i < n; i++) {
        product = product * num;
    }
    return product;
}

float round_float(float num, int n) {
    num = (int)(num * power(10, 4));
    return (num / power(10, 4));
}

int *race(int v1, int v2, int g) {
    int *return_ptr = malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
      return_ptr[i] = -1;
    }

    if (v1 >= v2) {
      return return_ptr;
    }

    float time = (float)g / (float)(v2 - v1);
    for (int i = 0; i < 3; i++) {
      if (i == 0) {
        return_ptr[i] = time;
        continue;
      }

      time = (float)time - (int)time;
      time = round_float(time, 4) * 60;
      return_ptr[i] = time;
    }

	return return_ptr;
}
