#include <conio.h>
#include <ctype.h>
#include <stdio.h>
void menu();
int start(int *, int *, int *, int *);
int move(int *, int *, int *, int *, int);
int movec(int *, int *);
int slw(int);
void design();
int key(int *, int *, int *, int *);
int display(int, int, int, char ch);
void core(int, int);
void check(int, int);
void fruit();
int found(int *, int *);
void gameover(int, int);
void fcheck();
void end();
void st();
int tail[100][2] = {};
int len = 1;
int f[2][2];
int score = 0;
int dell = 20000;
int main()
        {
        st();
        return 1;
        }
void menu()
        {
        int p = 1;
        printf("New game");
        printf("\nPlay game");
        printf("\nOption");
        printf("\nExit");
        while (1)
                {
                textcolor(15);
                gotoxy(15, p);
                printf("~>");
                gotoxy(50, 40);
                switch (getch())
                        {
                case 'A':
                        gotoxy(15, p);
                        printf("   ");
                        if (p > 1)
                                p -= 1;
                        else
                                p = 4;
                        break;
                case 'B':
                        gotoxy(15, p);
                        printf("   ");
                        if (p < 4)
                                p += 1;
                        else
                                p = 1;
                        break;
                        }
                }
        }
void st()
        {
        int x = 50, y = 15, x1 = 15, y1 = 15;
        int i;
        textbackground(0);
        clrscr();
        len = 2;
        while (1)
                {
                if (kbhit())
                        {
                        getch();
                        continue;
                        }
                break;
                }
        for (i = 0; i <= len; i++)
                {
                tail[i][0] = 50 - i;
                tail[i][1] = 15;
                }
        fruit();
        start(&x, &y, &x1, &y1);
        }
void fruit()
        {
        int upper = 139, lower = 16;
        int i, j;
        srand(time(0));
        f[0][0] = (rand() % (upper - lower + 1)) + lower;
        upper = 39;
        lower = 6;
        srand(time(0));
        f[0][1] = (rand() % (upper - lower + 1)) + lower;
        }
void check(int x, int y)
        {
        int i;
        for (i = 0; i < len; i++)
                {
                if (f[0][0] == tail[i][0] && f[0][1] == tail[i][1])
                        {
                        int j;
                        len++;
                        fruit();
                        for (j = 0; j <= len; j++)
                                {
                                if (f[0][0] == tail[j][0] && f[0][1] == tail[j][1])
                                        {
                                        j = 0;
                                        fruit();
                                        }
                                }
                        score++;
                        }
                }
        }
int display(int x, int y, int bk, char ch)
        {
        textbackground(bk);
        gotoxy(x, y);
        printf("%c", ch);
        textbackground(0);
        return 1;
        }
int start(int *x, int *y, int *x1, int *y1)
        {
        int flag = 3;
        int fl = 3;
        score = 0;
        while (1)
                {
                design();
                if (kbhit())
                        {
                        flag = key(&*x, &*y, &*x1, &*y1);
                        movec(&flag, &fl);
                        }
                move(&*x, &*y, &*x1, &*y1, flag);
                }
        return 1;
        }
int movec(int *flag, int *fl)
        {
        int tl;
        if (*fl == 1)
                tl = 2;
        else if (*fl == 2)
                tl = 1;
        else if (*fl == 3)
                tl = 4;
        else if (*fl == 4)
                tl = 3;
        if (*flag == tl)
                {
                *flag = *fl;
                }
        else if (*flag > 0)
                {
                *fl = *flag;
                }
        else if (*flag == 0)
                *flag = *fl;
        return 1;
        }
int move(int *x, int *y, int *x1, int *y1, int flag)
        {
        static int cl = 1;
        static int fl = 3;
        static int del = 0;
        if (fl == flag)
                {
                for (; del <= dell; del++)
                        if (kbhit())
                                return 1;
                }
        switch (flag)
                {
        case 1:
                if (*y > 5)
                        {
                        *y -= 1;
                        *y1 = *y + 1;
                        *x1 = *x;
                        }
                else
                        {
                        *y = 40;
                        *y1 = 5;
                        *x1 = *x;
                        }
                fl = 1;
                break;
        case 2:
                if (*y < 40)
                        {
                        *y += 1;
                        *y1 = *y - 1;
                        *x1 = *x;
                        }
                else
                        {
                        *y = 5;
                        *y1 = 40;
                        *x1 = *x;
                        }
                fl = 2;
                break;
        case 3:
                if (*x < 160)
                        {
                        *x += 1;
                        *x1 = *x - 1;
                        *y1 = *y;
                        }
                else
                        {
                        *x = 15;
                        *x1 = 160;
                        *y1 = *y;
                        }
                fl = 3;
                break;
        case 4:
                if (*x > 15)
                        {
                        *x -= 1;
                        *x1 = *x + 1;
                        *y1 = *y;
                        }
                else
                        {
                        *x = 160;
                        *x1 = 15;
                        *y1 = *y;
                        }
                fl = 4;
                break;
                }
        core(*x, *y);
        gotoxy(160, 45);
        textcolor(0);
        textbackground(0);
        printf(" ");
        check(*x, *y);
        gameover(*x, *y);
        for (del = 0; del <= dell; del++)
                if (kbhit())
                        break;
        return 1;
        }
void end()
        {
        int del;
        long total = 500000;
        gotoxy(50, 20);
        textcolor(15);
        textbackground(0);
        fflush(stdin);
        fflush(stdout);
        len = 5;
        fruit();
        while (1)
                {
                if (kbhit())
                        {
                        int ch;
                        ch = getch();
                        if (ch == ' ')
                                break;
                        }
                gotoxy(75, 20);
                printf("Game Over");
                gotoxy(70, 22);
                printf("Press space to restart game   ");
                display(160, 45, 0, ' ');
                for (del = 0; del <= total; del++)
                        if (kbhit())
                                break;
                gotoxy(75, 20);
                printf("Game Over");
                gotoxy(70, 22);
                printf("Press space to restart game.   ");
                display(160, 45, 0, ' ');
                for (del = 0; del <= total; del++)
                        if (kbhit())
                                break;
                gotoxy(75, 20);
                printf("Game Over");
                gotoxy(70, 22);
                printf("Press space to restart game..  ");
                display(160, 45, 0, ' ');
                for (del = 0; del <= total; del++)
                        if (kbhit())
                                break;
                gotoxy(75, 20);
                printf("Game Over");
                gotoxy(70, 22);
                printf("Press space to restart game...");
                display(160, 45, 0, ' ');
                for (del = 0; del <= total; del++)
                        if (kbhit())
                                break;
                }
        st();
        }
void gameover(int x, int y)
        {
        int i;
        for (i = 1; i <= len; i++)
                {
                if (x == tail[i][0] && y == tail[i][1])
                        end();
                // else if(y==tail[i][1])end();
                }
        if (x >= 160 || x <= 15)
                end();
        else if (y >= 40 || y <= 5)
                end();
        }
void core(int x, int y)
        {
        int st, dt;
        int i, cl = 200;
        st = tail[0][0];
        tail[0][0] = x;
        for (i = 1; i <= len; i++)
                {
                dt = tail[i][0];
                tail[i][0] = st;
                st = dt;
                }
        st = tail[0][1];
        tail[0][1] = y;
        for (i = 1; i <= len; i++)
                {
                dt = tail[i][1];
                tail[i][1] = st;
                st = dt;
                }
        len--;
        for (i = 0; i < len; i++)
                {
                char ch = ' ';
                if (i == 0)
                        display(tail[i][0], tail[i][1], LIGHTGRAY, ' ');
                else
                        display(tail[i][0], tail[i][1], cl, ch);
                if (i % 1 == 0)
                        cl += 1;
                if (cl == 8)
                        cl = 1;
                }
        len++;
        display(tail[len][0], tail[len][1], 0, ' ');
        display(tail[i][0], tail[i][1], 0, ' ');
        gotoxy(80, 2);
        textcolor(15);
        printf("score=%d  speed=%d", score, dell);
        gotoxy(f[0][0], f[0][1]);
        textcolor(RED);
        textbackground(0);
        printf("\u2665\n");
        //  printf("😍 ");
        textbackground(BLACK);
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
                flag = 1;
                break;
        case 'B':
                flag = 2;
                break;
        case 'C':
                flag = 3;
                break;
        case 'D':
                flag = 4;
                break;
        case 'Z':
                dell += 1000;
                return 0;
        case ' ':
                dell += 1000;
                return 0;
        case 'w':
                if (dell > 0)
                        dell -= 1000;
                return 0;
        case 13:
        case 27:
                if (kbhit() == 0)
                        exit(0);
        default:
                return 0;
                }
        return flag;
        }
void design()
        {
        int i;
        int cl = 100;
        for (i = 4; i <= 41; i++)
                {
                textbackground(cl);
                gotoxy(14, i);
                printf(" ");
                gotoxy(161, i);
                printf(" ");
                if (i % 5 == 0)
                        cl++;
                }
        cl == 100;
        for (i = 15; i < 161; i++)
                {
                textbackground(cl);
                gotoxy(i, 4);
                printf(" ");
                gotoxy(i, 41);
                printf(" ");
                if (i % 10 == 0)
                        cl++;
                }
        }
