#include <stdio.h>
#include <stdlib.h>

int *delete_nth(const int order[], size_t n, size_t size, size_t *output_size) {
    int j = 0;

    int max_num = 0;
    for (size_t i = 0; i < size; i++) {
        if (order[i] > max_num) {
            max_num = order[i];
        }
    }
    int count[max_num];
    for (size_t i = 0; i < max_num; i++) {
        count[i] = 0;
    }


    int *num = calloc(size, sizeof(int));
    if (!num) return NULL;

    for (size_t i = 0; i < size; i++) {
        count[order[i]]++;
        if (count[order[i]] <= n) {
            ++(*output_size);
            num[j++] = order[i];
        }
    }

    return num;
}

int main(void) {
    int arr[] = {1, 2, 3, 1, 2, 1, 2, 3};
    size_t n = 2; //each number should appear at most n times
    size_t output_size = 0;

   int *result = delete_nth(arr, n, sizeof(arr)/sizeof(arr[0]), &output_size);

   if (result == NULL) {
       printf("Memory allocation failed.\n");
       return 1;
   }
   else {
       for (size_t i = 0; i < output_size; i++) {
           printf("%d ", result[i]);
       }
       printf("\n");
       free(result);
   }

   return 0;
}
