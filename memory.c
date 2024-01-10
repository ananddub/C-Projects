#include <conio.h>
#include <stdio.h>
int main()
        {
        int i = 20;
        int *ptr = &i;
        clrscr();
        for (i = 0; i <= 4096; i++)
                {
                ptr += 1;
                printf("%d\t", *ptr);
                }
        return 1;
        }
