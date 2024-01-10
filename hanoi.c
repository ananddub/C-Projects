#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bk textbackground
typedef struct
{
        int a[10];
        int b[10];
        int c[10];
} honoi;
void tower(honoi *);
void input(honoi *, int, int);
void print(honoi);
int main()
{
        honoi hon;
        input(&hon, 1, 3);
        print(hon);
        printf("\nEnd");
        return 1;
}
void print(honoi hon)
{
        int i;
        int j;
        int x, y = 10;
        for (i = 0; i < 10; i++)
        {
                if (hon.a[i] != -1)
                {
                        x = 50;
                        if(hon.a[i]=='1')bk(RED);
                        else if(hon.a[i]=='2')bk(WHITE);
                        else if(hon.a[i]=='3')bk(GREEN);
                        gotoxy(x, y);
                        for (j = 0; j < hon.a[i]; j++)
                                printf(" ");
                        printf("%d",hon.c[i]);
                        for (j = 0; j < hon.a[i]; j++)
                                printf(" ");
                        bk(0);
                }
                if (hon.b[i] != -1)
                {
                        x = 60;
                        gotoxy(x, y);
                        if(hon.a[i]=='1')bk(RED);
                        else if(hon.a[i]=='2')bk(WHITE);
                        else if(hon.a[i]=='3')bk(GREEN);
                        for (j = 0; j < hon.b[i]; j++)
                                printf(" ");
                        printf("%d",hon.b[i]);
                        for (j = 0; j < hon.b[i]; j++)
                                printf(" ");
                        bk(0);
                }

                if (hon.c[i] != -1)
                {
                        x = 80;
                        gotoxy(x, y);
                        if(hon.a[i]=='1')bk(RED);
                        else if(hon.a[i]=='2')bk(WHITE);
                        else if(hon.a[i]=='3')bk(GREEN);
                        for (j = 0; j < hon.c[i]; j++)
                                printf(" ");
                        printf("%d",hon.c[i]);
                        for (j = 0; j < hon.b[i]; j++)
                                printf(" ");
                        bk(0);
                }
                y-=1;
        }
}
void input(honoi *hon, int min, int max)
{
        int i = 0;
        for (i = 0; i < 10; i++,min++)
        {
                if (min < max)
                {
                        hon->a[i] = min;
                }
                else
                {
                        hon->a[i] = -1;
                }
                hon->b[i] = -1;
                hon->c[i] = -1;
        }
}
