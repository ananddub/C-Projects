#include <conio.h>
#include <stdio.h>

void main()
        {
        int res = 1;
        int fact = 5;
        clrscr();
        for (; fact >= 1;fact--)res *= fact;

        printf("%d", res);
        getch();
        }
