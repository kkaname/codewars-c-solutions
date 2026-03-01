#include <stdio.h>
#include <stdlib.h>


int **matrix_multiplication(int n, const int a[][n], const int b[][n]) {
    int i, j, k;
    int **ptr = malloc(n * sizeof(int *)); // allocate memory for rows

    for (i = 0; i < n; i++) {
      ptr[i] = (int *) malloc(n * sizeof(int)); // allocate memory for columns
    }

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        ptr[i][j] = 0;
        // initialize each element of resultant matrix to zero
      }
    }


    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
          ptr[i][j] += a[i][k] * b[k][j];
        }
      }
    }

    return ptr;
}

int main(void) {
    int n = 3;
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int b[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int **result = matrix_multiplication(n, a, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
