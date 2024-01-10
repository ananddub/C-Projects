#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
	{
	int even[12],odd[12],arr[3][4];
	int r,c,temp[12],i;
	int ev=0,od=0,min=0,count=0;
	clrscr();
	for(i=0;i<=11;i++)
		{
		even[i]=-30000;
		temp[i]=-30000;
		odd[i]=-30000;
		}
	for(r=0;r<=2;r++)
		{
		for(c=0;c<=3;c++)
			{
			printf("Enter a data in arr[%d][%d] :",r,c);
			fflush(stdin);
			scanf("%ld",&arr[r][c]);
			}
		}
	while(1)
		{
		clrscr();
		for(r=0;r<=2;r++)
			{
			for(c=0;c<=3;c++)
				{
				printf("Enter a data in arr[%d][%d] :%d\n",r,c,arr[r][c]);
				}
			}


		printf("\n\nPress any key to continue");
		for(i=0;i<=3;i++)
			{
			delay(1000);
			printf(".");
			if(kbhit())break;
			}
		printf("\n\n");
		if(kbhit())break;
		}
	getch();
	od=0;
	ev=0;
	for(r=0;r<=2;r++)
		{
		for(c=0;c<=3;c++)
			{
			if(arr[r][c]%2==0)
				{
				even[ev]=arr[r][c];
				ev++;
				}
			else
				{
				odd[od]=arr[r][c];
				od++;
				}
			}
		}
	c=0;
	min=30000;
	for(r=0;r<=11&&even[r]!=-30000;r++)
		{
		temp[r]=even[r];
		even[r]=-30000;
		}
	for(i=0;i<=11;i++)
		{
		min=30000;
		for(r=0;r<=11;r++)
			{
			if(min>temp[r]&&temp[r]!=-30000)
				{
				min=temp[r];
				c=r;
				}
			}
		if(min!=30000)
			{
			even[i]=min;
			temp[c]=-30000;
			}
		if(kbhit())
			{
			break;
			}
		}
	for(r=0;r<=11;r++)
		{
		temp[r]=-30000;
		}

	for(r=0;r<=11&&odd[r]!=-30000;r++)
		{
		temp[r]=odd[r];
		odd[r]=-30000;
		}
	for(i=0;i<=11;i++)
		{
		min=30000;
		for(r=0;r<=11;r++)
			{
			if(min>temp[r]&&temp[r]!=-30000)
				{
				min=temp[r];
				c=r;
				}
			}
		if(min!=30000)
			{
			odd[i]=min;
			temp[c]=-30000;
			}
		if(kbhit())
			{
			break;
			}
		}


	printf("\nEven :");
	for(i=0;i<=11;i++)
		{
		if(even[i]!=-30000)
			printf(" %d",even[i]);
		}
	printf("\nOdd  :");
	for(i=0;i<=11;i++)
		{
		if(odd[i]!=-30000)
			printf(" %d",odd[i]);
		}

	getch();
	}