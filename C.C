#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
void C(int,int,int);
void anim();
void main()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	anim();
	getch();
	}
void anim()
	{
	char str2[10]="hess";
	char arr[10];
	int del=120;
	settextstyle(1,0,5);
	outtextxy(100,50,"First game made by me");
	settextstyle(1,0,4);
	delay(2500);
	cleardevice();
	setcolor(14);
	outtextxy(10,100,"NAME    : ANAND KUMAR DUBEY");
	outtextxy(10,200,"ROLL NO : 822108");
	delay(4000);
	//exit(0);
	cleardevice();
	C(250,100,1);
	cleardevice();
	setcolor(RED);
	C(100,100,2);
	delay(del);
	arr[0]=str2[0];
	arr[1]='\0';
	setcolor(15);
	settextstyle(1,0,50);
	outtextxy(135,22,arr);
	delay(del);
	arr[0]=str2[1];
	arr[1]='\0';
	setcolor(15);
	settextstyle(1,0,50);
	outtextxy(215,22,arr);
	delay(del);
	arr[0]=str2[2];
	arr[1]='\0';
	setcolor(15);
	settextstyle(1,0,50);
	outtextxy(280,22,arr);
	delay(del+100);
	arr[0]=str2[3];
	arr[1]='\0';
	setcolor(15);
	settextstyle(1,0,50);
	outtextxy(340,22,arr);
	outtextxy(280,150,"in");
	C(450,350,0);
	}
void C(int x,int y,int flag)
	{
	int i,j=0,cl=1,coun=0;
	if(flag==0)
		{
		setcolor(0);
		settextstyle(1,0,2);
	    //	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tPress any key to continue...");
		}
	while(1)
		{
		cl++;
		if(cl==15)cl=1;
		if(flag!=2)
			setcolor(cl);
		for(i=110;i<=300;i++)
			{
			arc(x,y,70,i,50);
			arc(x+1,y+1,70,i,50);
			arc(x+2,y+2,70,i,50-1);
			arc(x+1,y+2,70,i,50);
			if(flag!=2)
				delay(10);
			}
		if(flag==1)
			{
			coun++;
			if(coun==3
			)break;
			}
		else if(flag==2)break;
		if(kbhit())break;
		}
	//for(i=0;i
	}
