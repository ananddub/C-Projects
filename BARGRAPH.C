#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
void main()
	{
	long x,y,gd=DETECT,gm;
	long i,j,flag=1,flag2=0;
	double flag3=0,abar[5],abar2[5];
	double max=0,total=0;
	int per,bar=2,in;
	char str1[5][10]={{"PSPC"},{"ITA"},{"Math"},{"Eng"},{"PMO"}};
	char str2[100],ch;
	textcolor(BLACK);
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	up:
	clrscr();
	i=0;
	printf("\nIt is  navigate \npress 'w' for up and \npress 's' for down");
	printf("\n\nhow much baar you want ?");

	printf("\n\nbar 2 :");
	if(bar==2)
		{
		printf("\t->");
		}
	printf("\nbar 3 :");
	if(bar==3)
		{
		printf("\t->");
		}
	printf("\nbar 4 :");
	if(bar==4)
		{
		printf("\t->");
		}
	printf("\nbar 5 :");
	if(bar==5)
		{
		printf("\t->");
		}
	printf("\nExit  :");
	if(bar==6)
		{
		printf("\t->");
		}
	ch=getche();
	in=ch;
	if(ch=='w')
		{
		if(bar>2)
			bar--;
		else
			bar=6;
		goto up;
		}
	else if(ch=='s')
		{
		if(bar<6)
			bar++;
		else
			bar=2;
		goto up;
		}
	else if(in==13)
		{
		if(bar==2||bar==3||bar==4||bar==5);
		else if(bar==6)exit();
		else
			goto up;
		}
	else
		{
		goto up;
		}
	for(i=0;i<=4;i++)
		abar[i]=-1;
	clrscr();
	printf("Total bar you selected :%d",bar);
	for(i=0;i<bar;i++)
		{
		while(1)
			{
			printf("\nEnter Your Data (%d):",i);
			fflush(stdin);
			if(scanf("%lf",&abar[i]))
				 break;
			else
				{
				printf("\n\nIt is not a number  ");
				printf("\n\nPress any key to continue...");
				getch();
				}

			}
		}

	clrscr();
	for(i=455,j=65;j<=700;i--,j++)
		{
		if(i>=25)
			line(70,450,70,i);
		line(70,450,j,450);
		delay(5);
		}
	for(i=0,j=50;i<=20;i++,j+=20)
			{
			if(i== 20 )
				{outtextxy(55,j-3,"0 ");}
			else if(i== 18 )
				{outtextxy(50,j-2,"10 ");}
			else if(i== 16 )
				{outtextxy(50,j-2,"20 ");}
			else if(i== 14 )
				{outtextxy(50,j-2,"30 ");}
			else if(i== 12 )
				{outtextxy(50,j-2,"40 ");}
			else if(i== 10 )
				{outtextxy(50,j-2,"50 ");}
			else if(i== 8 )
				{outtextxy(50,j-2,"60 ");}
			else if(i== 6 )
				{outtextxy(50,j-2,"70 ");}
			else if(i== 4 )
				{outtextxy(50,j-2,"80 ");}
			else if(i== 2 )
				{outtextxy(50,j-2,"90 ");}
			else if(i== 0 )
				{outtextxy(42,j-2,"100");}

		line(68,j,72,j);
		delay(35);
		}
	j=100;
	for(i=0;i<bar;i++)
		{
		delay(50);

		outtextxy(j,460,str1[i]);
		j+=50;
		}
	for(i=0;i<bar;i++)
		{
		if(max<abar[i])
			max=abar[i];
		}
	for(i=0;i<bar;i++)
		{
		per=(abar[i]/max)*100;
		abar2[i]=per;
		abar[i]=450-(per*4);
		}

	for(i=450;i>=50;i--)
		{
		if(i>=abar[0])
			{
			if(abar2[0]<50) setcolor(RED);
			else if(abar2[0]>=50&&abar2[0]<80)setcolor(YELLOW);
			else if(abar2[0]>=80)setcolor(GREEN);
			rectangle(100,i,125,450);
			}
		if(i>=abar[1]&&bar>=2)
			{
			if(abar2[1]<50) setcolor(RED);
			else if(abar2[1]>=50&&abar2[1]<80)setcolor(YELLOW);
			else if(abar2[1]>=80)setcolor(GREEN);
			rectangle(150,i,175,450);
			}
		if(i>=abar[2]&&bar>=3)
			{
			if(abar2[2]<50) setcolor(RED);
			else if(abar2[2]>=50&&abar2[2]<80)setcolor(YELLOW);
			else if(abar2[2]>=80)setcolor(GREEN);
			rectangle(200,i,225,450);
			}
		if(i>=abar[3]&&bar>=4)
			{
			if(abar2[3]<50) setcolor(RED);
			else if(abar2[3]>=50&&abar2[3]<80)setcolor(YELLOW);
			else if(abar2[3]>=80)setcolor(GREEN);
			rectangle(250,i,275,450);
			}
		if(i>=abar[4]&&bar>=5)
			{
			if(abar2[4]<50) setcolor(RED);
			else if(abar2[4]>=50&&abar2[4]<80)setcolor(YELLOW);
			else if(abar2[4]>=80)setcolor(GREEN);
			rectangle(300,i,325,450);
			}
		delay(15);
		}

	getch();
	}
