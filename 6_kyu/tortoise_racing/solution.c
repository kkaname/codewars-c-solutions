#include <stdio.h>
#include <stdlib.h>

int *race(int v1, int v2, int g);

int main(void) {
    int v1, v2, g;
    v1 = 720;   //speed of tortoise A
    v2 = 850;   //speed of tortoise B
    g = 70; //distance gap between them initially

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

int *race(int v1, int v2, int g) {
    int *result = malloc(3 * sizeof(int));

    if (v1 >= v2) {
        for (int i = 0; i < 3; i++) {
          result[i] = -1;
        }
        return result;
    }

    int total_seconds = (g * 3600) / (v2 - v1);

    result[0] = total_seconds / 3600;
    result[1] = (total_seconds % 3600) / 60;
    result[2] = total_seconds % 60;

	return result;
}
