#include <stdio.h>
#include <string.h>

int main() {
    char name[30];
    int length;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    length = strlen(name);

    printf("Length of your name = %d characters\n", length);

    return 0;
}
