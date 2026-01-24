#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

char *break_camelcase(char *camelCase) {
    int length = strlen(camelCase);
    int i, j;
    i = j = 0;
    char *break_camelcase = (char *)malloc(MAX_LENGTH * sizeof(char));

    while(camelCase[i] != '\0') {
        if (camelCase[i] >= 'A' && camelCase[i] <= 'Z') {
            break_camelcase[j++] = ' ';
        }
        break_camelcase[j++] = camelCase[i++];
    }
    break_camelcase[j] = '\0';

    return break_camelcase;
}

int main(void) {
    char *camelCase_1 = "camelCasing";
    char *solution_1 = break_camelcase(camelCase_1);
    printf("%s\n", solution_1);
    free(solution_1);

    char *camelCase_2 = "camelCasing";
    char *solution_2 = break_camelcase(camelCase_2);
    printf("%s\n", solution_2);
    free(solution_2);

    return 0;
}
