#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define tk textcolor
#define bk textbackground
typedef struct
        {
        char name[100];
        int roll;
        char course[10];
        unsigned long long mob;
        } student;
void move();
int main()
        {
        move();
        return 1;
        }
void move()
        {
        int cn = 0;
        int x = 60, y = 5;
        char data[10][100] = {"Show all record", "Add new record ", "search record ", "Exit"};
        while (1)
                {
                int i;
                int len;
                char ch;
                int flag = 0;
                bk(0);
                tk(15);
                clrscr();
                y = 5;
                for (i = 0; i < 5; i++)
                        {
                        bk(0);
                        tk(15);
                        gotoxy(x, y);
                        if (cn == i)
                                {
                                bk(15);
                                tk(0);
                                }
                        len=printf("%s",data[i]);
                        for(;len<20;len++)printf(" ");
                        y++;
                        }
                ch = getch();
                while (kbhit())
                        ch = getch();
                switch (ch)
                        {
                case 'B':
                        if (cn < 3)
                                {
                                cn += 1;
                                }
                        else cn=0;
                        break;
                case 'A':
                        if (cn > 0)
                                {
                                cn -=1;
                                }
                        else cn=3;
                        break;
                case '\n':
                        switch(cn)
                                {
                                case 1:
                                        allrec(std);
                                        break;
                                case 2:
                                        create(std);
                                        break;
                                case 3:
                                        find(std);
                                        break;
                                case 4:
                                        exit(0);
                                        break;
                                }
                        break;
                        }

                }
        }
