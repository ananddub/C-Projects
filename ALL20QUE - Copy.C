#include<stdio.h>
#include<conio.h>



void factorial()
	{
	int fact,data=1;
	clrscr();
	printf("\nenter a no. for factorial ");
	scanf("%d",&fact);
	while(fact>=1)
		{
		data = data*fact;
		fact--;
		}
	printf("\nfactorial %d",data);
	}

void main()
	{
	char choice;
	clrscr();
	printf("1. factorial \n");
	printf("2. total even or odd in range \n");
	printf("3. prime no. \n");
	printf("4. armstorng no. \n");
	printf("5. exit ");
	scanf("%c",&choice);
	if(choice=="1")
		{
		factorial();
		}

	getch();
	}
