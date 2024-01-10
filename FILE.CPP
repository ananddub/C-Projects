#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void main()
	{
	clrscr();
	FILE *fp;
	char str[80];
	fp=fopen("POEM.TXT","w");

	if(fp==NULL)
		{
		puts("Cannot open file "); exit(1);
		}
	priintf("\nnEnter a few lines of text:");
	while(strdlen(gets(str))>0)
		{
		fputs(str,fp);fputs("\");
		}


	}