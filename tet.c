#include <conio.h>
#include<string.h>
#include <stdio.h>
typedef struct mainv
        {
        char str[100];
        int ten;
        } mainv;

void test(mainv *);
void tests(int *);

void main()
        {
        char *ptr = 0;
        mainv tt[100];
        clrscr();
        tt[0].ten=10;
        strcpy(tt[0].str, "hello world");
        test(tt);
        getch();
        }
void test(mainv *val)
        {
        tests(&val[0].ten);
        }
void tests(int *val)
        {
        printf("%d",*val);
        }
