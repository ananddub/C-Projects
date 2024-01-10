#include <conio.h>
#include <stdio.h>
void box(int, int, int, int, int);
void main()
        {
        clrscr();
        box(40, 4, 30, 20, 2);
        } 
void box(int dx, int dy, int sx, int sy, int col)
        {
        int x = dx, y = dy;
        int i;
        int parx, pary;
        // down
        for (i = y + 1; i <= y + sy - 1; i++)
                {
                parx = x + sx;
                gotoxy(dx, i);
                printf("\u2502");
                gotoxy(parx, i);
                printf("\u2502");
                }
        for (i = x + 1; i <= x + sx - 1; i++)
                {
                pary = y + sy;
                gotoxy(i, dy);
                printf("\u2500");
                gotoxy(i, pary);
                printf("\u2500");
                }
        gotoxy(dx,dy);
        printf("\u250C");
        parx=dx+sx;
        gotoxy(parx,dy);
        printf("\u2510");
        pary=dy+sy;
        gotoxy(dx,pary);
        printf("\u2514");
        pary=dy+sy;
        parx=dx+sx;
        gotoxy(parx,pary); 
        printf("\u2518"); 
        }
