#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
	{
	int i=50,gd=DETECT,gm,x,y,x1,y1;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;
	for(i=0;i<=120;i+=1)
		{
		//-line(x,y,x+1000,y);
		//line(x,y,x-1000,y);
		setcolor(i/10);
		arc(x,y+100,0,360,i);
		setcolor(i/10);
		arc(x,y-100,0,360,i);
		setcolor(i/10);
		arc(x-100,y,0,360,i);
		setcolor(i/10);
		arc(x+100,y,0,360,i);
		delay(100);
		}
	getch();
	}
