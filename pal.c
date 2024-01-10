#include <stdio.h>
#include <string.h>
#include <conio.h>
int pallindrome(char *data);

void main()
{
        printf("%d", pallindrome("mame"));
}
int pallindrome(char *data)
{
        char *ptr = &data[strlen(data) - 1];
        for (; *data != '\0'; ptr--, data++)
        {
                if (*data == *ptr)
                        continue;
                return 0;
        }
        return 1;
}
