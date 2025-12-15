#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

char *disemvowel(const char *str) {
    int i, j;
    int n;
    j = n = 0;

    for (i = 0; str[i] != '\0'; i++) {
      ++n;
    }

    char *s = calloc(n, sizeof(char));

    for (i = 0; i < n; i++) {
      if (str[i] == 'a' || str[i] == 'A') {
        continue;
      }
      else if (str[i] == 'i' || str[i] == 'I') {
        continue;
      }
      else if (str[i] == 'e' || str[i] == 'E') {
        continue;
      }
      else if (str[i] == 'o' || str[i] == 'O') {
        continue;
      }
      else if (str[i] == 'u' || str[i] == 'U') {
        continue;
      }
      else {
        s[j++] = str[i];
      }
    }
    s[j] = '\0';

    return s;
}

int main(void) {
    char str[MAXLEN];
    printf("Enter a string: ");
    fgets(str, MAXLEN, stdin);

    char *p = disemvowel(str);
    printf("%s\n", p);
    free(p);

    return 0;
}
