#include <stdio.h>
#include <conio.h>

int main()
{
    char password[100];
    int i = 0;
    char ch;
    printf("Enter password: ");
    while ((ch = getch()) != '\r')
    {
        password[i++] = ch;
        putchar('*');
    }
    password[i] = '\0';
    printf("\nPassword entered: %s\n", password);
    return 0;
}

