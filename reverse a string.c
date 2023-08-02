#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int length, i;
    printf("Enter a string: ");
    scanf("%[^\n]", str); 
    length = strlen(str);
    printf("The reverse of the string is: ");
    for (i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}

