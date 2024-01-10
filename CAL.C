#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int mul(int a,int b);
int add(int a,int b);
int min(int a,int b);
int div(int a,int b);


void main()
	{
	char arr[1000]={'\0'},ch;
	int a,b,cn,check,in; //45 to 57
       //	clrscr();
	while(1)
		{
		clrscr();
		printf("Enter your operation :");
		ch=getche();
		in=ch;
		if(in==27)break;
		else if(in==8)
			{
			if(cn>0)
				{
				cn--;
				arr[cn]='\0';
				}
			}

		}
	//getch();
	}
