// write a program to copy and array of size 10 into anohter
//  and print it using pointer
#include <conio.h>
#include <stdio.h>
int lenstr(char *);
void anim(int, int, char *);
void load(int, int, int);
int main()
        {
        int farr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        int *fptr = farr;
        int sarr[10];
        int *sptr = sarr;
        int i;
        clrscr();
        for (i = 0; i < 10; i++)
                {
                printf("farr[%d]=%d\n", i, *fptr);
                fptr++;
                }
        load(1, 14, 18);
        anim(1, 11, "Press any key to continue");
        getch();
        for (i = 0; i < 10; i++)
                {
                fptr--;
                *sptr = *fptr;
                sptr++;
                }
        sptr = sarr;
        printf("\ndata has been copied");
        anim(1, 14, "Press aniy key to see");
        getch();
        for (i = 0; i < 10; i++)
                {
                printf("\nsarr[%d]=%d", i, *sptr);
                sptr++;
                }
        getch();
        return 1;
        }
void load(int x, int y, int size)
        {
        int dx = x + size + 1;
        int i;
        long del;
        int ctr = 0;
        gotoxy(x, y);
        x += 1;
        gotoxy(x, y);
        for (i = 0; i < size; i++)
                {
                printf("o");
                }
        for (ctr = x; ctr < x + size; ctr++)
                {
                gotoxy(x, y);
                for (i = x; i < ctr; i++)
                        {
                        printf(".");
                        }
                gotoxy(ctr, y);
                printf("c");
                for (del = 0; del <= 30000000; del++)
                        ;
                gotoxy(ctr, y);
                printf("C");
                for (del = 0; del <= 30000000; del++)
                        ;
                }
        }
void anim(int x, int y, char *token)
        {
        long delay = 0;
        int i, max = 0;
        int len = lenstr(token);
        int dx = x + len;
        while (!kbhit())
                {
                gotoxy(x, y);
                printf("%s", token);
                for (i = 0; i < max; i++)
                        {
                        printf(".");
                        }
                printf("   ");
                gotoxy(100, 50);
                for (delay = 0; delay <= 300000 && !kbhit(); delay++)
                        ;
                max++;
                if (max == 4)
                        max = 0;
                }
        gotoxy(x, y + 1);
        }
int lenstr(char *token)
        {
        int len = 0;
        for (; *token != '\0'; token++)
                len++;
        return len;
        }
