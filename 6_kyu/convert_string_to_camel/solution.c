#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_camel_case(const char *text, char *camel) {
    int i, j;
    j = 0;
    camel[j] = '\0';    //if text is a empty string

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] != '-' && text[i] != '_') {
            camel[j++] = text[i];
        }
        else {
            ++i;
            if (text[i] >= 97 && text[i] <= 122) {
                camel[j++] = text[i] - 32;
            }
            else {
                camel[j++] = text[i];
            }
        }
    }
    camel[j] = '\0';
}

int main(void) {
   const char text[] = "the-stealth-warrior";
   char *camel = (char *)malloc(strlen(text) + 1);
   to_camel_case(text, camel);
   printf("%s\n", camel);
   free(camel);

   const char text1[] = "The_Stealth_Warriors";
   char *camel1 = (char *)malloc(strlen(text1) + 1);
   to_camel_case(text1, camel1);
   printf("%s\n", camel1);
   free(camel1);

   return 0;
}
