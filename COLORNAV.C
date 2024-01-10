#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
	{
	int gd=DETECT,gm;
	int w=1,in;
	char ch;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	up:
	cleardevice();
      //	printf("\nIt is trail of cursor navigate with 'w'and 's'");
	if(w==1)
		{
		settextstyle(8,0,4);
		setcolor(GREEN);
		}
	else
		{
		settextstyle(8,0,2);
		setcolor(WHITE);
		}
	outtextxy(100,50,"\n\n1.New");

	if(w==2)
		{
		settextstyle(8,0,4);
		setcolor(GREEN);
		}
	else
		{
		settextstyle(8,0,2);
		setcolor(WHITE);
		}
	outtextxy(100,100,"\n2.old");
	if(w==3)
		{
		settextstyle(8,0,4);
		setcolor(GREEN);
		}
	else
		{
		settextstyle(8,0,2);
		setcolor(WHITE);
		}

	outtextxy(100,150,"\n3.Doc");
	if(w==4)
		{
		settextstyle(8,0,4);
		setcolor(GREEN);
		}
	else
		{
		settextstyle(8,0,2);
		setcolor(WHITE);
		}
	outtextxy(100,200,"\n4.Help");
	if(w==5)
		{
		settextstyle(8,0,4);
		setcolor(GREEN);
		}
	else
		{
		settextstyle(8,0,2);
		setcolor(WHITE);
		}
	outtextxy(100,250,"\n5.Exit");

	ch=getche();
	in=ch;
	switch(ch)
		{
		case '1':
			w=1;
			goto up;
		case '2':
			w=2;
			goto up;
		case '3':
			w=3;
			goto up;
		case '4':
			w=4;
			goto up;
		case '5':
			w=5;
			goto up;





		}
	if(ch=='w'||in==72)
		{
		if(w>1)
			w--;
		else
			w=5;
		goto up;
		}
	else if(ch=='s'||in==80)
		{
		if(w<5)
			w++;
		else
			w=1;
		goto up;
		}
	else if(in==13)
		{
		if(w==5)goto exit;
		else if(w==1)
			{
			clrscr();
			printf("\nYou are under New ");
			}
		else if(w==2)
			{
			clrscr();
			printf("\nYou are under old ");
			}
		else if(w==3)
			{
			clrscr();
			printf("\nYou are under Doc");
			}
		else if(w==4)
			{
			clrscr();
			printf("\nYou are under help");
			}
		getch();
		goto up;
		}
	else
		{
		goto up;
		}
	exit:

	}
