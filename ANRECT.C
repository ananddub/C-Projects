#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int color=1;
int rescolor=1;
void dlboxt(int );
void dlbox(int,int,int,int);
void stcon();
void newl();
void open();
void play();
void help();
void main()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	stcon();
	}
void help()
	{
	char helpmenu[]={"Chess is a two-player board game that is played on a square board with 64 squares, arranged in an 8x8 grid.\n\nEach player starts with 16 pieces: one king, one queen, two rooks, two knights, two bishops, and eight pawns.\n\nThe objective of the game is to checkmate your opponent's king, which means placing their king under attack in such a way that there is no legal move to get out of check.\n\nEach piece has its own unique way of moving across the board. For example, the pawn can move one or two squares forward on its first move, and then one square forward on subsequent moves. The knight moves in an L-shape, while the bishop moves diagonally.\n\n "};
	char helpmenu1[]={"The queen is the most powerful piece on the board, as it can move in any direction (diagonally, horizontally, or vertically) for any number of squares.\n\nPlayers take turns moving their pieces, with white always moving first.\n\nThere are a few special moves in chess, such as castling (where the king moves two squares towards a rook, and the rook moves"};
	char helpmenu2[]={"\nto the square the king crossed) and en passant (where a pawn can capture an opposing pawn that has just moved two squares forward on its first move).\n\nPlayers must also be careful to avoid putting their own king in danger, as this can lead to checkmate.\n\nThe game is won when one player checkmates their opponent's king, or when the opponent resigns."};
	char arr2[10];
	int w=1,in;
	char ch;
	cleardevice();
	setcolor(15);
	while(1)
		{
		if(w==1)
			{
			textcolor(BLACK);
			clrscr();
			setfillstyle(SOLID_FILL,0);
			printf("\n\n%s",helpmenu);
			printf("\n\n%s",helpmenu1);
			while(1)
				{
				if(kbhit())break;
				}
			}
		else if(w==2)
			{
			textcolor(BLACK);
			clrscr();
			setfillstyle(SOLID_FILL,0);
			bar(0,0	,800,800);
			printf("\n\n%s",helpmenu2);
			while(1)
				{
				if(kbhit())break;
				}
			}
		if(kbhit())
			{
			ch=getche();
			in=ch;
			if(w==2)w=1;
			else w=2;
			if(in==27)exit(0);
			if(in==13)
				{
				break;
				}
			delay(50);
			while(1)
				{
				if(kbhit())
					{
					getch();
					continue;
					}
				break;
				}
			}

		}
	}
void stcon()
	{
	int w=3,in;
	char ch;
	newl();
	while(1)
		{
		//cleardevice();
		dlboxt(w);
		if(kbhit())
			{
			newl();
			ch=getche();
			in=ch;
			if(in==27)exit(0);
			if(in==13)
				{
				if(w==1)break;
				else if(w==2)help();
				else if(w==4)exit(0);
				}
			if(kbhit())
				{
				ch=getche();
				if(ch=='H')
					 {
					 if(w==1)w=4;
					 else w--;
					 }
				if(ch=='P')
					 {
					 if(w==4)w=1;
					 else w++;
					 }

				delay(50);
				while(1)
					{
					if(kbhit())
						{
						getch();
						continue;
						}
					break;
					}
				}
			}

		}

	}
void newl()
	{
	setcolor(WHITE);
	settextstyle(1,0,3);
	textcolor(0);
	clrscr();
	printf("\n\n\nNew");
	printf("\n\nOpen");
	printf("\n\nPlay");
	printf("\n\nExit");
	}
void dlboxt(int t)
	{
	int x,y,x1,y1;
	if(t==1)
		{
		x=140;
		x1=140+82;
		y=98;
		y1=130;
		}
	else if(t==2)
		{
		x=140;
		x1=140+82;
		y=148;
		y1=y+32;
		}
	else if(t==3)
		{
		x=140;
		x1=140+82;
		y=198;
		y1=y+32;
		}
	else if(t==4)
		{
		x=140;
		x1=140+82;
		y=248;
		y1=y+32;
		}
	while(1)
		{
	      //	newl();
		dlbox(x,y,x1,y1);
		if(kbhit())break;
		}
	}
void dlbox(int x,int y,int x1,int y1)
	{
	int i,cn;
	int y2,x2,y3;
	if(x1<x)
		{
		x=x1+x;
		x1=x-x1;
		x=x-x1;
		}
	if(y1<y)
		{
		y=y1+y;
		y1=y-y1;
		y=y-y1;
		}
	y2=y;
	x2=x;
	cn=0;
	setcolor(rescolor);
	if(color==15)color=1;
	else color++;
	rectangle(x,y,x1,y1);
	rectangle(x+1,y+1,x1+1,y1+1);
	rectangle(x+2,y+2,x1+2,y1+2);
	rescolor=color;
	while(1)
		{
		if(kbhit())break;
		putpixel(x,y,color);
		putpixel(x+1,y+1,color);
		putpixel(x+2,y+2,color);
		delay(5);
		if(y>y2&&cn==3)
			{
			y--;
			if(y==y2)break;
			}
		else if(y<=y1&&cn==1)
			{
			y++;
			if(y==y1)cn=2;
			}
		else if(x>=x2&&cn==2)
			{
			x--;
			if(x==x2)cn=3;
			}
		else if(x<=x1&&cn==0)
			{
			x++;
			if(x==x1)cn=1;
			}
		}
	if(color==15)color=1;
	else color++;
	}
