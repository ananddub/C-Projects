#include <conio.h>
#include <ctype.h>
int start(int *, int *, int *, int *);
int move(int *, int *, int *, int *);
int slw(int *, int *, int *, int *);
int key(int *, int *, int *, int *);
int display(int, int);
#define bkc textbackground
#define tc textcolor
int bk = 15;
int main()
        {
        int x = 10, y = 10, x1 = 10, y1 = 10;
        bkc(0);
        clrscr();
        display(x, y);
        start(&x, &y, &x1, &y1);
        return 1;
        }
int display(int x, int y)
        {
        gotoxy(x, y);
        textbackground(bk);
        textcolor(15);
        printf(" ");
        gotoxy(160, 80);
        bkc(bk);
        printf(" \b");
        return 1;
        }
int start(int *x, int *y, int *x1, int *y1)
        {
        while (1)
                {
                if (kbhit())
                        {
                        key(&*x, &*y, &*x1, &*y1);
                        display(*x, *y);
                        }
                }
        return 1;
        }
int key(int *x, int *y, int *x1, int *y1)
        {
        char ch;
        int flag = 0;
        ch = getch();
        toupper(ch);
        switch (ch)
                {
        case 'A':
                if (*y > 5)
                        *y -= 1;
                else
                        *y = 40;
                flag = 1;
                break;
        case 'B':
                if (*y < 40)
                        *y += 1;
                else
                        *y = 5;
                flag = 1;
                break;
        case 'C':
                if (*x < 150)
                        *x += 1;
                else
                        *x = 5;
                flag = 1;
                break;
        case 'D':
                if (*x > 5)
                        *x -= 1;
                else
                        *x = 150;
                flag = 1;
                break;
        case ' ':
                bk += 1;
                if (bk == 16)
                        bk = 1;
                gotoxy(160, 10);
                printf("color=%d", bk);
                break;
        case 13:
        case 27:
                if (kbhit() == 0)
                        exit(0);
                }
        return 1;
        }
