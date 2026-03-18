#include <stdio.h>
#include <stdbool.h>

bool is_valid_ISBN_10 (const char *ISBN) {
    int sum = 0;
    int i;

    for (i = 0; i < 10; i++) {
        if (i < 9) {
            if ((ISBN[i] - '0') >= 0 && (ISBN[i] - '0') <= 9) {
                sum += (ISBN[i] - '0') * (i + 1);
            }
            else {
                return false;
            }
        }
        // for the last 10th character
        else {
            if ((ISBN[i] - '0' >= 0) && (ISBN[i] - '0' <= 9)) {
                sum += (ISBN[i] - '0') * (i + 1);
            }
            else if (ISBN[i] == 'x' || ISBN[i] == 'X') {
                sum += 10 * (i + 1);
            }
            else {
                return false;
            }

            if (ISBN[i + 1]) {
                return false;
            }
        }
    }
    return sum % 11 == 0;
}

int main(void) {
    // case 1: valid ISBN-10
    const char *ISBN = "1112223339";
    printf("%s is %s\n", ISBN, is_valid_ISBN_10(ISBN) ? "valid" : "invalid");

    // case 2: invalid ISBN-10 (sum not divisible by 11)
    ISBN = "1234512345";
    printf("%s is %s\n", ISBN, is_valid_ISBN_10(ISBN) ? "valid" : "invalid");

    // case 3: valid ISBN-10 with 'X'
    ISBN = "048665088X";
    printf("%s is %s\n", ISBN, is_valid_ISBN_10(ISBN) ? "valid" : "invalid");

    // case 4: invalid ISBN-10 (too short)
    ISBN = "1293";
    printf("%s is %s\n", ISBN, is_valid_ISBN_10(ISBN) ? "valid" : "invalid");

    // case 5: invalid ISBN-10 (invalid character)
    ISBN = "X123456788";
    printf("%s is %s\n", ISBN, is_valid_ISBN_10(ISBN) ? "valid" : "invalid");

    // case 6: invalid ISBN-10 (invalid character)
    ISBN = "ABCDEFGHIJ";
    printf("%s is %s\n", ISBN, is_valid_ISBN_10(ISBN) ? "valid" : "invalid");

    // case 7: invalid ISBN-10 (invalid character)
    ISBN = "XXXXXXXXXX";
    printf("%s is %s\n", ISBN, is_valid_ISBN_10(ISBN) ? "valid" : "invalid");

    // case 8: invalid ISBN-10 (invalid character)
    ISBN = "048665088XZ";
    printf("%s is %s\n", ISBN, is_valid_ISBN_10(ISBN) ? "valid" : "invalid");


    return 0;
}
