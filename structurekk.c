#include <conio.h>
#include <stdio.h>
void print();
void key();
void insert();
int a[10] = {7,6,5, 4, 3, 2, 1, -1};
int b[10] = {};
int c[10] = {};
int ai = 7, bi = 0, ci = 0;
int cur = 0;
int flag = 0;
int data = 0;
void main()
        {
        clrscr();
        while (1)
                {
                if (kbhit())
                        {
                        int x, y = 12;
                        key();
                        clrscr();
                        print();
                        if (cur == 0)
                                x = 1;
                        else if (cur == 1)
                                x = 6;
                        else if (cur == 2)
                                x = 12;
                        gotoxy(x, y);
                        }
                }
        getch();
        }
void key()
        {
        char ch;
        while (kbhit() != 0)
                ch = getch();
        switch (ch)
                {
        case 'A':
                if (flag == 0)
                        {
                        if (cur == 0)
                                {
                                if (ai > 0)
                                        {
                                        ai -= 1;
                                        data = a[ai];
                                        a[ai] = -1;
                                        }
                                }
                        else if (cur == 1)
                                {
                                if (bi > 0)
                                        {
                                        bi -= 1;
                                        data = b[bi];
                                        b[bi] = -1;
                                        }
                                }
                        else if (cur == 2)
                                {
                                if (ci > 0)
                                        {
                                        ci -= 1;
                                        data = c[ci];
                                        c[ci] = -1;
                                        }
                                }
                        flag = 1;
                        }
                break;
        case 'B':
                if (flag == 1)
                        {
                        if (cur == 0)
                                {
                                a[ai] = data;
                                ai += 1;
                                a[ai] = -1;
                                }
                        else if (cur == 1)
                                {
                                b[bi] = data;
                                bi += 1;
                                b[bi] = -1;
                                }
                        else if (cur == 2)
                                {
                                c[ci] = data;
                                ci += 1;
                                c[ci] = -1;
                                }
                        flag = 0;
                        }

                break;
        case 'C':
                if (cur < 2)
                        cur++;
                break;
        case 'D':
                if (cur > 0)
                        cur--;
                break;
                }
        }
void print()
        {
        int i;
        int x, y;
        for (i = 10; i >= 0; i--)
                {
                y = 10 - i;
                if (i < ai)
                        {
                        x = 1;
                        gotoxy(x, y);
                        printf("%d", a[i]);
                        }
                if (i < bi)
                        {
                        x = 6;
                        gotoxy(x, y);
                        printf("%d", b[i]);
                        }
                if (i < ci)
                        {
                        x = 12;
                        gotoxy(x, y);
                        printf("%d", c[i]);
                        }
                printf("\n");
                }
        }
