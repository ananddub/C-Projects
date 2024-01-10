#include <conio.h>
#include <stdio.h>

void initch(char arr[])
        {
        printf("Enter your name :");
        fflush(stdin);
        gets(arr);
        }
void main()
        {
        char name[100];
        clrscr();
        initch(name);
        printf("\nyour entered name :%s",name);
        getch();
        }
