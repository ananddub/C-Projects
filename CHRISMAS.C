#include<stdio.h>
#include<conio.h>
void main()
	{
	int i,j,k,l,cl=1;
	long delay=0;
	textbackground(BLACK);
	clrscr();
	for(i=0;i<=200;i++)
		{
		printf("\033[2;1;%dH");
		textcolor(cl);
		if(cl==15)cl=1;
		cl++;
		printf("\n\n\t\t\t     ");
		cprintf("Happy Christmas Day");
		printf("\n\n");
		for(j=0;j<=10;j++)
			{
			printf("    ");
			textcolor(cl);
			if(cl==15)cl=1;
			cl++;
			for(k=10;k>=j;k--)
				{
				printf(" ");
				}
			for(l=0;l<=j;l++)
				{
				textcolor(cl);
				if(cl==15)cl=1;
				cl++;
				cprintf("*");
				}
			for(l=0;l<j;l++)
				{
				textcolor(cl);
				if(cl==15)cl=1;
				cl++;
				cprintf("*");
				}
			for(k=10;k>=j;k--)
				{
				printf(" ");
				}
			for(l=0;l<=j;l++)
				{
				textcolor(cl);
				if(cl==15)cl=1;
				cl++;
				cprintf(" ");
				}
			for(l=0;l<j;l++)
				{
				textcolor(cl);
				if(cl==15)cl=1;
				cl++;
				cprintf(" ");
				}

			for(k=10;k>=j;k--)
				{
				printf("   ");
				}
			for(l=0;l<=j;l++)
				{
				textcolor(cl);
				if(cl==15)cl=1;
				cl++;
				cprintf("*");
				}
			for(l=0;l<j;l++)
				{
				textcolor(cl);
				if(cl==15)cl=1;
				cl++;
				cprintf("*");
				}
			printf("\n");
			}
		for(j=0;j<=5;j++)
			{
			textcolor(BROWN);
			printf("\t      ");
			for(l=0;l<=2;l++)
				{
				cprintf("|");
				}
			printf("\t\t\t\t\t    ");
			for(l=0;l<=2;l++)
				{
				cprintf("|");
				}
			printf("\n");

			}
		textcolor(GREEN);
		for(j=0;j<=79;j++)cprintf("_-");
		for(delay=0;delay<=5000000;delay++);
		}
	getch();
	}