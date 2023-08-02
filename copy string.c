#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
int main() {
    char a[MAX_LENGTH];
    char b[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(source, MAX_LENGTH, stdin);
    source[strcspn(source, "\n")] = '\0';
    strcpy(destination, source);
    printf("Source string: %s\n",a);
    printf("Copied string: %s\n",b);
    return 0;
}

