#include<stdio.h>
#include<conio.h>
void main()
	{
	char arr[8]="ABCDEGH";
	char a1[2]={'D','B'};
	int a2[2]={-1,-1};
	int i,j,lm=1;
	clrscr();
	for(i=0;i<=1;i++)
		{
		for(j=0;j<=7;j++)
			{

			if(a1[i]==arr[j])
				{
				a2[i]=j;
				}
			}

		}
	printf("%d\t\t%d",a2[0],a2[1]);

	getch();
	}
