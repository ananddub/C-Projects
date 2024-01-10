#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void main()
	{
	char data[10][2][100]={{"fan","100"},{"fan","200"},{"bulb","300"},{"fan","600"},{"tv","100"},{"fan","100"},{"watch","150"},{"lap","500"},{"fan","100"}};
	int i,j,cmp,sum[2]={0,0};
	clrscr();
	printf("Calculating the total fan applinces stock \n\n");
	for(i=0;i<=9;i++)
		{
		printf("%s  \t\t%s\n",data[i][0],data[i][1]);
		cmp=strcmp(data[i][0],"fan");
		if(cmp==0)
			{
			sum[0]=atoi(data[i][1]);
			sum[1]+=sum[0];
			}
		}

	printf("\ntotal fan stock :%d",sum[1]);
	getch();
	}