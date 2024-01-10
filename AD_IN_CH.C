#include<stdio.h>
#include<conio.h>

void main()
	{
	int a=0;
	clrscr();
	while(1)
		{
		clrscr();
		printf("Enter a number ->");
		fflush(stdin);
		scanf("%d",&a);

		if(a)
			{
			printf("Your entered value is %d",a);
			break;
			}
		else
			{
			printf("\nInvalid number");
			printf("\nRetry Press any key to continue.....");
			getch();
			}
		}


	getch();
	}
