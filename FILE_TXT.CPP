#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int main()
	{
	FILE *fp;
	char str[80];
	clrscr();
	fp = fopen("POEM.TXT","w");
	if(fp==NULL)
		{
		puts("Cannot open file"); exit(1);
		}
	printf("\nEnter a few lines of text:\n");
	while(strlen(gets(str))>0)
		{
		fputs(str,fp);fputs("\n",fp);
		}
	fclose(fp);

	/*read the file back*/
	printf("\nFile contents are being read now ...\n",str);
	fp = fopen("POEM.TXT","r");
	if(fp==NULL)
		{
		puts("Cannot open file ");exit(2);
		}
	while(fgets(str,79,fp)!=NULL)
		{
		printf("%s",str);
		}
	fclose(fp);
	getch();
	return 0;
	}