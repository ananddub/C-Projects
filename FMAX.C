#include<stdio.h>
#include<conio.h>
#include<string.h>

int arr[10];
void arrin()
	{
	int i;
	for(i=0;i<=10;i++)
		{
		printf("Enter a number arr[%d] :",i);
		scanf("%d",&arr[i]);
		}
	}
void arrout()
	{
	int i;
	for(i=0;i<=10;i++)
		{
		printf("\narr[%d] :%d",i,arr[i]);
		}
	}
void arrmax()
	{
	int i,max=arr[0],min=arr[0];
	for(i=0;i<=10;i++)
		{
		if(max<arr[i])
			max=arr[i];
		if(min>arr[i])
			min=arr[i];
		}
	printf("\n\nmax :%d\tmin :%d",max,min);
	}
void arrsum()
	{
	int sum=0,i=0;
	for(i=0;i<=10;i++)
		{
		sum+=arr[i];
		}
	printf("\nsum of all arr :%d",sum);
	}
void main()
	{
	clrscr();
	arrin();
	clrscr();
	arrout();
	arrmax();
	arrsum();
	getch();
	}
