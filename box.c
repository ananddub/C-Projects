#include <conio.h>
#include <stdio.h>
void box(int dx, int dy, int sx, int sy, int col);
int main()
        {
        clrscr();
        box(10, 10, 10, 10, 5);
        getch();
        }
void box(int dx, int dy, int sx, int sy, int col)
        {
        int x = dx, y = dy;
        int i;
        int parx, pary;
        textcolor(col);
        // stand
        for (i = y + 1; i <= y + sy - 1; i++)
                {
                parx = x + sx;
                gotoxy(dx, i);
                printf("\u2502");
                gotoxy(parx, i);
                printf("\u2502");
                }
        // flat
        for (i = x + 1; i <= x + sx - 1; i++)
                {
                pary = y + sy;
                gotoxy(i, dy);
                printf("\u2500");
                gotoxy(i, pary);
                printf("\u2500");
                }
        // up left corner
        gotoxy(dx, dy);
        printf("\u250C");
        // up right corner
        parx = dx + sx;
        gotoxy(parx, dy);
        printf("\u2510");
        // down left corner
        pary = dy + sy;
        gotoxy(dx, pary);
        printf("\u2514");
        // down right corner
        pary = dy + sy;
        parx = dx + sx;
        gotoxy(parx, pary);
        printf("\u2518");
        textcolor(15);
        }
