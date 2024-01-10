#include<stdio.h>
#include<conio.h>e
void main()
	{
	int a=10;
	int *ptr=&a;
	clrscr();
	printf("a=%d",*ptr);
	printf("\na=%d",ptr);
	ptr=2000;
	printf("\na=%d",a);
	printf("\na=%d",ptr);
	getch();
	}
