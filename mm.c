
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
        FILE *fp;
        char data[10000];
        int a, *ptr = (int *)malloc(5 * sizeof(int));
        *ptr = 24;
        printf("\nBefore :%p", ptr);
        /*ptr = (void *)realloc(ptr, 10* sizeof(int));
        printf("\nAfter  :%d",sizeof(void) );
        */getch();
}
