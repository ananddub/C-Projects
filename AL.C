#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
void main()
	{
	int gd=DETECT,gm;
	int x,y,flag=1,i,loop,cl=1;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;
	loop=y-20;
	while(1)
		{
		if(cl==15)cl=1;
		cl++;
		for(i=190;i<=240;i++)
			{
			setcolor(cl);
			circle(x,y,i);
			if(flag==0)
				{
				setcolor(i/10);
				settextstyle(6,0,4);
				outtextxy(x-140,y-20,"Name :Anand Dubey");
				outtextxy(x-140,y+10,"Roll No :822110");
				}
			delay(50);
			}
		cl++;
		for(i=190;i<=240;i++)
			{
			setcolor(cl);
			circle(x,y,i);
			if(flag==0)
				{
				setcolor(i/10);
				settextstyle(6,0,4);
				outtextxy(x-140,y-20,"Name :Anand Dubey");
				outtextxy(x-140,y+10,"Roll No :822110");
				}
			delay(50);
			}
		if(flag)
			{
			setcolor(WHITE);
			settextstyle(7,0,5);
			outtextxy(x-130,y-20,"EXCEL IN 'C'");
			for(i=0;i<=90;i++)
				{
				setcolor(WHITE);
				settextstyle(7,0,5);
				outtextxy(x-130,loop,"EXCEL IN 'C'");
				delay(20);
				if(i!=90)
					{
					setcolor(BLACK);
					settextstyle(7,0,5);
					outtextxy(x-130,loop,"EXCEL IN 'C'");
					}
				loop--;

				if(kbhit())break;
				}
			setcolor(WHITE);
			settextstyle(6,0,4);
			outtextxy(x-140,y-20,"Name :Anand Dubey");
			outtextxy(x-140,y+10,"Roll No :822110");
			flag=0;
			}
		if(kbhit())break;
		}

	getch();
	}
