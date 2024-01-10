#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
void main()
	{
	clrscr();
	while(1)
		{
		char arr[100];
		int lw=0,lfup=0,lfw=0,upw=0;
		int i;
		clrscr();
		printf("Enter your value :");
		gets(arr);
		for(i=0;arr[i]!='\0';i++)
			{
			if(isupper(arr[i]))
				{
				if(i==0)
					{
					lfup++;
					}
					else
					{
					upw++;
					}
				}
			else if(islower(arr[i]))
				{
				if(i==0)
					{
					lfw++;
					}
				else
					{
					lw++;
					}
				}
			}
		if(strcmp(arr,"exit")==0)break;
		i--;
		if(i==upw||i==lw||lfup==1&&upw==0)printf("TRUE");
		else printf("FALSE");
		getch();
		}
	}
