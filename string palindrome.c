#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 100
bool is_palindrome(const char str[]) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}
int main() {
    char input_string[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input_string, MAX_LENGTH, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    if (is_palindrome(input_string)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

