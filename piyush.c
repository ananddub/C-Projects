#include <conio.h>#include <stdio.h>void main(){char ch;int flag = 1;while (1)    {    if (kbhit())        {        if (flag)        clrscr();        printf("\n[%d]", getch());        flag = 0;        continue;        }    flag = 1;    }}