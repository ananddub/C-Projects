#include<stdio.h>
#include<conio.h>
void main()
	{
	int arr[10],clarr[10];
	int find,i,max=0,oc=0;
	float avr,sum=0;
	char ch;
	clrscr();
	for(i=0;i<=9;i++)
		{

		printf("Enter your valur off array[%d] :",i);

		scanf("%d",&arr[i]);
		sum +=arr[i];
		}
	avr=sum/10;
	while(1)
		{
		clrscr();
		printf("\n1.Sum of array");
		printf("\n2.Average of array");
		printf("\n3.Maxium number of array");
		printf("\n4.Finding Occurance of Number");
		printf("\n5.Clone of Array");
		printf("\n6.Reverse of Array");
		printf("\n7.Exit");

		printf("\n\nEnter your choice :");
		ch=getche();
		if(ch=='1')
			{
			printf("\n\nSum of array[10] :%f",sum);
			}
		else if(ch=='2')
			{
			printf("\n\nAverage of array[10] :%f",avr);
			}
		else if(ch=='3')
			{
			max=arr[0];
			for(i=0;i<=9;i++)
				{
				if(max<arr[i])
					{
					max=arr[i];
					}
				}
			printf("\n\nMaxium Number of array[10] :%d",max);
			}
		else if(ch=='4')
			{
			up_f:
			oc=0;
			clrscr();
			printf("Enter a finding number :");
			fflush(stdin);
			if(scanf("%d",&find));
			else
				{
				printf("\n\nIt is not a number ");
				printf("\nPress any key to continue....");
				getch();
				goto up_f;
				}
			for(i=0;i<=9;i++)
				{
				if(arr[i]==find)
					{
					oc++;
					}
				}
			printf("\n\nTotal number of Ocurance in array[10] :%d",oc);
			}

		else if(ch=='5')
			{
			printf("\n");
			for(i=0;i<=9;i++)
				{
				clarr[i]=arr[i] ;
				printf("\nclone of array[%d] :%d",i,clarr[i]);

				}
			}
		else if(ch=='6')
			{
			printf("\n");
			for(i=9;i>=0;i--)
				{
				printf("\narr[%d]=%d",i,arr[i]);
				}
			}

		else if(ch=='7')
			{
			goto exit;
			}
		printf("\n\nPress any key to continue...");
		getch();
		}

	exit:
	}
