#include<stdio.h>
#include<conio.h>

void main()
	{
	int c;
	char a;
	clrscr();
	printf("Enter a character :");
	scanf("%c",&a);
	c=a;
	if(c>=65 && c<=122)
		{
		printf("It is a charcter ");
		}
	else
		{
		printf("it is not charcter ");
		}
	getch();
	}
