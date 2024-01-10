#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
void main()
	{
	char 	str[]={"Higlights of array :\n\n-> Array is collection of variables of same type (homogenous)\n\n-> Square bracket([]) is use to give the size \n\n-> The size must be constant only like number as 1,2,3,etc\n\n-> The size indicates total number of packets starting from zero(0) to (size=1)\n\n-> Array has name called as base address\n\n-> Every pocket inside array has an address\n\n-> The address of first packet[0] is simlar as base address it means array name \t= base address =first packet address.    eg roll = &roll[0]\n\n-> Depending upon the direction(dimension) the array is of 2types\n\t* Single dimensional array(1D)\n\t* Multi-Dimensional array\n\n-> When array has two dimensions called as 2D array\n"};
	int gd=DETECT,gm,arr[10],i,t=0;
	int x,y,count=0,len=0,z=0,l,b;
	int flag=1;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;
	textcolor(BLACK);
	clrscr();
	len=strlen(str);
	for(i=0;i<=len;i++)
		{
		printf("%c",str[i]);
		delay(50);
		}
	delay(5000);
	clrscr();

	printf("-> 1D array is also called as Vector ");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t1D Array\n\n\n  55");
	printf("    46");
	printf("     86");
	printf("    10");
	printf("    71");
	printf("    15");
	printf("     44");
	printf("    33");
	printf("    11");

	printf("\n\n\n  0");
	printf("      1");
	printf("     2");
	printf("     3");
	printf("      4");
	printf("     5");
	printf("     6");
	printf("      7");
	printf("     8");

	rectangle(1,y,50,200);
	rectangle(100,y,50,200);
	for(i=100;i<=450;i+=50)
		{
		 rectangle(i,y,50,200);
		///outtextxy(i,y,"1");
	       //	count++;
		}
		 //239


	delay(5000);
	clrscr();
	printf("-> 2D array is also called as Matrix");
	printf("\n\n\n\n\n\n\n\n\t\t\t2D Array \n\n\n         0");
	printf("     1");
	printf("     2");
	printf("     3");
	printf("      4");
	printf("     5");
	printf("     6");
	printf("      7");
	printf("\n\n    0    55");
	printf("    46");
	printf("    86");
	printf("    10");
	printf("    71");
	printf("    15");
	printf("     44");
	printf("    33");


	printf("\n\n\n    1");
	printf("   11");
	printf("     25");
	printf("    36");
	printf("    46");
	printf("    56");
	printf("     66");
	printf("    75");
	printf("    89");

	printf("\n\n\n    2");
	printf("   51");
	printf("     62");
	printf("    37");
	printf("    14");
	printf("    56");
	printf("     69");
	printf("    78");
	printf("    20");


	x=100;
	l=50;
	rectangle(x,y,l,200);
	rectangle(150,y,l,200);
	for(i=150;i<=450;i+=50)
		{
		 rectangle(i,y,l,200);
		///outtextxy(i,y,"1");
	       //	count++;
		}


	y=280;
	l=50;
	b=200;
	rectangle(x,y,l,b);
	rectangle(150,y,l,b);
	for(i=150;i<=450;i+=50)
		{
		 rectangle(i,y,l,b);
		}
	y=320;
	l=50;
	b=200;
	rectangle(x,y,l,b);
	rectangle(150,y,l,b);
	for(i=150;i<=450;i+=50)
		{
		 rectangle(i,y,l,b);
		}


	getch();
	}
