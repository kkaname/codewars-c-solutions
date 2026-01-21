#include <stdio.h>

 int find_even_index(const int *values, int length) {
     int left_side_sum, right_side_sum;
     left_side_sum = right_side_sum = 0;

     for (int i = 0; i < length; i++) {
         right_side_sum += values[i];
     }

     for (int i = 0; i < length; i++)  {
         right_side_sum -= values[i];
         if (left_side_sum == right_side_sum) {
             return i;
         }
         left_side_sum += values[i];
     }
     return -1;
 }

int  main(void) {
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    int expected_index = 3;
    int result = find_even_index(arr, sizeof(arr) / sizeof(arr[0]));
    if (result == -1) {
        printf("No index found.\n");
    }
    else {
        printf("index: %d\n", result);
    }

    int arr1[] = {1, 100, 50, -51, 1, 1};
    int expected_index1 = 1;
    int result1 = find_even_index(arr1, sizeof(arr1) / sizeof(arr1[0]));
    if (result1 == -1) {
        printf("No index found.\n");
    }
    else {
        printf("index: %d\n", result1);
    }

    return 0;
}
