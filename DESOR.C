#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
	{
	int i,j,arr[5]={5,4,378,25,66};
	int max=0,id[5],min=0,k,flag=0;
	clrscr();
	for(i=0;i<=4;i++)
		{
		max=0;
		flag=0;
		for(j=0;j<=4;j++)
			{
			for(k=0;k<=4;k++)
				{
				if(id[k]!=arr[i])
					{
					flag++;
					}
				}
			else if(max<arr[j]&&flag==i)
				{
				max=arr[j];
				id[i]=j;
				}
			}
		printf("id=%d\n",id[i]);
		}
	for(i=0;i<=4;i++)
		{
		printf("max=%d\n",arr[i]);
		}
	printf("--------------------------------\n");
	for(i=0;i<=4;i++)
		{
		printf("dmax=%d\n",id[i]);
		}
	printf("--------------------------------\n");
	printf("max value in array :%d",max);
	getch();
	}
