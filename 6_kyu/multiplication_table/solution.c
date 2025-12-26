#include <stdio.h>
#include <stdlib.h>

int **multiplication_table(int n) {
    int **table = (int **)calloc(n, sizeof(int *));     //for rows
    for (int i = 0; i < n; i++) {
        table[i] = (int *)calloc(n, sizeof(int));   //for columns
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            table[i - 1][j - 1] = i * j;
        }
    }

    return table;
}

int main(void) {
    int n;
    n = 3;
    int **table = multiplication_table(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}
