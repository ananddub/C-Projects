#include<stdio.h>
#include<conio.h>

void main()
	{
	int min,max,find;
	clrscr();
	printf("Enter minuim number :");
	scanf("%d",&min);

	printf("Enter maxuim number :");
	scanf("%d",&max);

	printf("Enter finding number :");
	scanf("%d",&find);

	if(min<max);
	else
		{
		min=max+min;
		max=min-max;
		min=min-max;
		}

	while(min<=max)
		{
		if(min==find)
			{
			printf("Found %d",find);
			break;
			}
		else if(min<max)
			{
			min++;
			continue;
			}
		min++;
		printf("Not Found %d",find);
		}

	getch();
	}
