#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
int pr=1,pc=1;
int p1=0,p2=0;
int k1=0,k2=0;
int chekmate=0;
int q1=0,q2=0;
int r1=0,r2=0;
int n1=0,n2=0;
int b1=0,b2=0;
int sx,sy,sx2,sy2,sx1,scolor,sy1,sflag=0,scn=0;
int color=1,color65=0;
char name[35];
int loc[35][3],gflag=0,colcd[35];
///////////////////// ////////////////////
void board();
void help();
void C(int,int,int);
void anim();
void dlboxt(int );
void dlbox(int,int,int,int);
void dlboxup(int,int,int,int,int);
void stcon();
void newl();
int nav(int,int);
void control();
void boxp(int,int,int,int);
void barxp(int,int);
void chpl(int,int,int,char);
void reset();
void check(int,int);
void rule(int,int,char,int);
void prin();
int comp(int,int,int);
int cmp(int,int,int);
int rep(int,int,int);
int infr(int,int);
void gameover(int);
////////////////////////chess pieces ///////////////////////////
void P(int,int,int);
void R(int,int,int);
void N(int,int,int);
void B(int,int,int);
void Q(int,int,int);
void K(int,int,int);
//////////////////////////////////////////
void main()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
       // anim();
	reset();
	stcon();
	}
void control()
	{
	int hol;
	int rml=2,rcl=4,rmd=7,rcd=4;
	int r=1,c=1,chan,clflag=0;
	char arr[10];
	cleardevice();
     //	cleardevice();

	chan=gflag;
       //	gameover(2);//--------------------------------------------------
	setfillstyle(SOLID_FILL,0);
	bar(0,0,100,600);
	settextstyle(0,0,1);
	sprintf(arr,"P=%d",p1);
	outtextxy(50,120,arr);
	sprintf(arr,"R=%d",r1);
	outtextxy(50,140,arr);
	sprintf(arr,"N=%d",n1);
	outtextxy(50,160,arr);
	sprintf(arr,"B=%d",b1);
	outtextxy(50,180,arr);
	sprintf(arr,"Q=%d",q1);
	outtextxy(50,200,arr);
      //  ------------------------
	setcolor(6);
	setfillstyle(SOLID_FILL,0);
	bar(570,0,800,600);
	settextstyle(0,0,1);
	sprintf(arr,"P=%d",p2);
	outtextxy(600,120,arr);
	sprintf(arr,"R=%d",r2);
	outtextxy(600,140,arr);
	sprintf(arr,"N=%d",n2);
	outtextxy(600,160,arr);
	sprintf(arr,"B=%d",b2);
	outtextxy(600,180,arr);
	sprintf(arr,"Q=%d",q2);
	outtextxy(600,200,arr);
     //-------------------------------
	settextstyle(1,0,1);
	setcolor(15);
       //	rectangle(40,110,80,210);
       //	retagle(590,110,630,210);
	if(gflag)
		outtextxy(300,5,"BLACK TURN");
	else
		outtextxy(300,5,"WHITE TURN");
	board();
	prin();
       //
	board();
	boxp(r,c,1,1);
	while(1)
		{
		dlboxup(149-4,29-4,600-47,430+3,1);
		if(kbhit())
			{
			hol=nav(r,c);
			if(hol==1)
				{
				barxp(r,c);
				r=pr;
				c=pc;
				boxp(r,c,1,0);
				prin();
				delay(60);
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
			else if(hol==13)
				{
				check(r,c);
				r=pr;
				c=pc;
				boxp(r,c,1,0);
				if(k1)
					{
					gameover(1);
					reset();
					r=2;
					c=4;
					}
				else if(k2)
					{
					gameover(2);
					reset();
					r=2;
					c=4;
					}
				if(gflag)
					{
					if(chan!=gflag)
						{
						rml=r;
						rcl=c;
						board();
						prin();
					       //	barxp(r,c);
						r=rmd;
						c=rcd;
						chan=gflag;
						boxp(r,c,1,0);
						}
					settextstyle(1,0,1);
					setfillstyle(SOLID_FILL,0);
					bar(80,0,800,25);
					setcolor(WHITE);
					outtextxy(300,5,"BLACK TURN");
					setfillstyle(SOLID_FILL,BLACK);
					setcolor(15);
					bar(0,0,100,600);
					settextstyle(0,0,1);
					sprintf(arr,"P=%d",p1);
					outtextxy(50,120,arr);
					sprintf(arr,"R=%d",r1);
					outtextxy(50,140,arr);
					sprintf(arr,"N=%d",n1);
					outtextxy(50,160,arr);
					sprintf(arr,"B=%d",b1);
					outtextxy(50,180,arr);
					sprintf(arr,"Q=%d",q1);
					outtextxy(50,200,arr);
					      //		/  ------------------------
					setcolor(6);
					setfillstyle(SOLID_FILL,0);
					bar(570,0,800,600);
					settextstyle(0,0,1);
					sprintf(arr,"P=%d",p2);
					outtextxy(600,120,arr);
					sprintf(arr,"R=%d",r2);
					outtextxy(600,140,arr);
					sprintf(arr,"N=%d",n2);
					outtextxy(600,160,arr);
					sprintf(arr,"B=%d",b2);
					outtextxy(600,180,arr);
					sprintf(arr,"Q=%d",q2);
					outtextxy(600,200,arr);
					clflag=1;
					}
				else
					{
					if(chan!=gflag)
						{
						clflag=0;
						rmd=r;
						rcd=c;
						board();
						prin();
						//barxp(r,c);
						r=rml;
						c=rcl;
						chan=gflag;
						boxp(r,c,1,0);

						}

					settextstyle(1,0,1);
					setfillstyle(SOLID_FILL,0);
					bar(80,0,800,25);
					setcolor(WHITE);
					outtextxy(300,5,"WHITE TURN");
					setfillstyle(SOLID_FILL,BLACK);
					setcolor(15);
					bar(0,0,100,200);
					settextstyle(0,0,1);
					sprintf(arr,"P=%d",p1);
					outtextxy(50,120,arr);
					sprintf(arr,"R=%d",r1);
					outtextxy(50,140,arr);
					sprintf(arr,"N=%d",n1);
					outtextxy(50,160,arr);
					sprintf(arr,"B=%d",b1);
					outtextxy(50,180,arr);
					sprintf(arr,"Q=%d",q1);
					outtextxy(50,200,arr);
					      //		/  ------------------------
					setcolor(6);
					setfillstyle(SOLID_FILL,BLACK);
					bar(570,0,800,600);
					settextstyle(0,0,1);
					sprintf(arr,"P=%d",p2);
					outtextxy(600,120,arr);
					sprintf(arr,"R=%d",r2);
					outtextxy(600,140,arr);
					sprintf(arr,"N=%d",n2);
					outtextxy(600,160,arr);
					sprintf(arr,"B=%d",b2);
					outtextxy(600,180,arr);
					sprintf(arr,"Q=%d",q2);
					outtextxy(600,200,arr);
					}
				}
			}
		}

	}
void stcon()
	{
	int w=1,in;
	char ch;
	while(1)
		{
		cleardevice();
		dlboxt(w);
		if(kbhit())
			{
			ch=getche();
			in=ch;
			if(in==27)exit(0);
			if(in==13)
				{
				if(w==1)
					{
					board();
					prin();
					board();
		  //			boxp(r,c,1,1);
					reset();
					control();
					break;
					}
				else if(w==2)
					{
					board();
					prin();
					board();
		    //			boxp(r,c,1,1);
					control();
					break;
					}
				else if(w==3)help();
				else exit(0);
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
void dlboxup(int x,int y,int x1,int y1,int speed)
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
		sy2=y2;
		sx2=x2;
		cn=0;
	color--;
	if(color==0)color=1;
	setcolor(color);
	if(color==15)color=1;
	else color++;
	rectangle(x,y,x1,y1);
	rectangle(x+1,y+1,x1+1,y1+1);
	rectangle(x+2,y+2,x1+2,y1+2);
	while(1)
		{
		sflag=1;
		sx=x;
		sy=y;
		sx1=x1;
		sy1=y1;
		scn=cn;
		scolor=color;
		if(kbhit())break;
		putpixel(x,y,color);
		putpixel(x+1,y+1,color);
		putpixel(x+2,y+2,color);
	      //	putpixel(x+3,y+3,color);
		delay(speed);
		if(y>y2&&cn==3)
			{
			y--;
			if(y==y2)
				{
				sflag=0;
				break;
				}
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
void gameover(int win)
	{
	char arr[10];
	int l;
	//board();
	//prin();
	setcolor(15);
	settextstyle(1,0,5);
	setfillstyle(SOLID_FILL,4);
	bar(230,180,500,280);
	outtextxy(250,200,"GAME OVER");
	delay(5000);
	cleardevice();
	if(win==1)
		{
		setcolor(15);
		settextstyle(1,0,5);
		outtextxy(150,10,"WHITE TEAM WIN");
		settextstyle(1,0,2);
		outtextxy(280,80,"RESULT");
		}
	else
		{
		setcolor(6);
		settextstyle(1,0,5);
		outtextxy(150,10,"BLACK TEAM WIN");
		settextstyle(1,0,2);
		outtextxy(280,80,"RESULT");
		}

	setfillstyle(SOLID_FILL,BLACK);
	setcolor(15);
	l=280;
	bar(0,0,100,200);
	settextstyle(0,0,1);
	sprintf(arr,"P=%d",p1);
	outtextxy(l,120,arr);
	sprintf(arr,"R=%d",r1);
	outtextxy(l,140,arr);
	sprintf(arr,"N=%d",n1);
	outtextxy(l,160,arr);
	sprintf(arr,"B=%d",b1);
	outtextxy(l,180,arr);
	sprintf(arr,"Q=%d",q1);
	outtextxy(l,200,arr);
	if(win==1)
		{
		sprintf(arr,"K=1");
		outtextxy(l,220,arr);
		}
	else
		{
		sprintf(arr,"K=0");
		outtextxy(l,220,arr);
		}
	      //	/  ------------------------
	setcolor(6);
	l=330;
	setfillstyle(SOLID_FILL,BLACK);
	bar(570,0,800,600);
	settextstyle(0,0,1);
	sprintf(arr,"P=%d",p2);
	outtextxy(l,120,arr);
	sprintf(arr,"R=%d",r2);
	outtextxy(l,140,arr);
	sprintf(arr,"N=%d",n2);
	outtextxy(l,160,arr);
	sprintf(arr,"B=%d",b2);
	outtextxy(l,180,arr);
	sprintf(arr,"Q=%d",q2);
	outtextxy(l,200,arr);
	if(win==2)
		{
		sprintf(arr,"K=1");
		outtextxy(l,220,arr);
		}
	else
		{
		sprintf(arr,"K=0");
		outtextxy(l,220,arr);
		}
	while(1)
		{
		if(win==1)
			{
			setcolor(color);
			settextstyle(1,0,5);
			outtextxy(150,10,"WHITE TEAM WIN");
			settextstyle(1,0,2);
			outtextxy(280,80,"RESULT");
			}
		else
			{
			setcolor(color);
			settextstyle(1,0,5);
			outtextxy(150,10,"BLACK TEAM WIN");
			settextstyle(1,0,2);
			outtextxy(280,80,"RESULT");
			}
		dlbox(260,70,370,260);
		if(kbhit())
			{
			getch();
			break;
			}
		}
	while(1)
		{
		if(kbhit())
			{
			getch();
			continue;
			}
		break;
		}
	//getch();
	stcon();
	//exit(0);
	}
int rep(int r,int c,int index)
	{
	int i;
	for(i=0;i<=32;i++)
		{
		if(loc[i][0]==r&&loc[i][1]==c&&i!=index)
			{

			if(colcd[i]==6&&colcd[i]!=colcd[index])
				{
				if(name[i]=='P')p1++;
				else if(name[i]=='R')r1++;
				else if(name[i]=='N')n1++;
				else if(name[i]=='B')b1++;
				else if(name[i]=='Q')q1++;
				else if(name[i]=='K')
					{
					//gameover(1);
					k1=1;
					}
				loc[i][0]=-5;
				loc[i][1]=-5;
				colcd[i]=-5;
				name[i]='\0';
				return 1;
				}
			if(colcd[i]==15&&colcd[i]!=colcd[index])
				{
				if(name[i]=='P')p2++;
				else if(name[i]=='R')r2++;
				else if(name[i]=='N')n2++;
				else if(name[i]=='B')b2++;
				else if(name[i]=='Q')q2++;
				else if(name[i]=='K')
					{
					k2=1;
					//gameover(2);
					}
				loc[i][0]=-5;
				loc[i][1]=-5;
				colcd[i]=-5;
				name[i]='\0';
				return 1;
				}
			}
		}
	return 0;
	}
int comp(int r,int c,int index)
	{
	int i;
	for(i=0;i<=32;i++)
		{
		if(loc[i][0]==r&&loc[i][1]==c&&i!=index)
			{
			if(colcd[i]==6)return 2;
			else if(colcd[i]==15)return 3;
			}
		}
	return 0;
	}
int cmp(int r,int c,int index)
	{
	int i;
	for(i=0;i<=32;i++)
		{
		if(loc[i][0]==r&&loc[i][1]==c&&i!=index)
			{
			return 1;
			}
		}
	return 0;
	}
int infr(int r,int c)
	{
	int i;
	for(i=0;i<=32;i++)
		{
		if(loc[i][0]==r&&loc[i][1]==c)
			{
			return i;
			}
		}
	return 0;
	}
void K(int r,int c,int index)
	{
	int dr,dc,cn=1, cl;
	int i,j;
	int hol,flag=0,sr,sc,gr,gc;
	dr=r;
	dc=c;
	sr=r;
	sc=c;
	gr=r;
	gc=c;
	while(1)
		{
		if(cn!=1)
			dlboxup(149-4,29-4,600-47,430+3,1);
		if(cn==1)
			{
			if(dr==r&&dc==c)boxp(r,c,1,1);
			else boxp(dr,dc,10,1);
			}
		if(colcd[index]==15&&cn==1&&gflag==0)
			{
			sr=gr;
			sc=gc+1;
			cn=comp(sr,sc,index);
			if(cn==3);//break;
			else if(cn==2)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr;
			sc=gc-1;
			cn=comp(sr,sc,index);
			if(cn==3);//break;
			else if(cn==2)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=gc+1;
			cn=comp(sr,sc,index);
			if(cn==3);//break;
			else if(cn==2)
				{
				cl=4;
				boxp(sr,sc,cl,0);
			     //	break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=c-1;
			cn=comp(sr,sc,index);
			if(cn==3);//break;
			else if(cn==2)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-1;
			sc=gc+1;
			cn=comp(sr,sc,index);
			if(cn==3);//break;
			else if(cn==2)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-1;
			sc=gc-1;
			cn=comp(sr,sc,index);
			if(cn==3);//break;
			else if(cn==2)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			//--------
			sr=gr-1;
			sc=gc;
			cn=comp(sr,sc,index);
			if(cn==3);
			else if(cn==2)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=gc;
			cn=comp(sr,sc,index);
			if(cn==3);//break;
			else if(cn==2)
				{
				cl=4;
				boxp(sr,sc,cl,0);
			       //	break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			flag=1;
			boxp(r,c,1,0);
			}
		if(colcd[index]==6&&cn==1&&gflag==1)
			{
			sr=gr;
			sc=gc+1;
			cn=comp(sr,sc,index);
			if(cn==2);//break;
			else if(cn==3)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr;
			sc=gc-1;
			cn=comp(sr,sc,index);
			if(cn==2);//break;
			else if(cn==3)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=gc+1;
			cn=comp(sr,sc,index);
			if(cn==2);//break;
			else if(cn==3)
				{
				cl=4;
				boxp(sr,sc,cl,0);
			     //	break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=c-1;
			cn=comp(sr,sc,index);
			if(cn==2);//break;
			else if(cn==3)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-1;
			sc=gc+1;
			cn=comp(sr,sc,index);
			if(cn==2);//break;
			else if(cn==3)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-1;
			sc=gc-1;
			cn=comp(sr,sc,index);
			if(cn==2);//3reak;
			else if(cn==3)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			//--------
			sr=gr-1;
			sc=gc;
			cn=comp(sr,sc,index);
			if(cn==2);
			else if(cn==3)
				{
				cl=4;
				boxp(sr,sc,cl,0);
				//break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=gc;
			cn=comp(sr,sc,index);
			if(cn==2);//break;
			else if(cn==3)
				{
				cl=4;
				boxp(sr,sc,cl,0);
			       //	break;
				}
			else
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			flag=2;
			boxp(r,c,1,0);
			}
		if(kbhit())
			{
			cn=1;
			hol=nav(r,c);
			if(hol==1)
				{
				barxp(r,c);
				r=pr;
				c=pc;
				boxp(r,c,1,0);
				prin();
				delay(60);
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
			if(hol==13)
				{
				if(flag==1)
					{
					int jk;
					sr=gr;
					sc=gc+1;
					cn=comp(sr,sc,index);
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=3)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr;
					sc=gc-1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=3)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr+1;
					sc=gc+1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=3)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr+1;
					sc=c-1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=3)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr-1;
					sc=gc+1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=3)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr-1;
					sc=gc-1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=3)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					//--------
					sr=gr-1;
					sc=gc;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=3)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr+1;
					sc=gc;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=3)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					}
				if(flag==2)
					{
					int jk;
					sr=gr;
					sc=gc+1;
					cn=comp(sr,sc,index);
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=2)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr;
					sc=gc-1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=2)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr+1;
					sc=gc+1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=2)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr+1;
					sc=c-1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=2)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr-1;
					sc=gc+1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=2)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr-1;
					sc=gc-1;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=2)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					//--------
					sr=gr-1;
					sc=gc;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=2)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					sr=gr+1;
					sc=gc;
					jk=comp(sr,sc,index);
					if(r==sr&&c==sc&&jk!=2)
						{
						loc[index][0]=pr;
						loc[index][1]=pc;
						gflag++;
						if(gflag==2)gflag=0;
						rep(pr,pc,index);
						}
					}
				break;
				}
			}
		}
	//getch();
	board();
	prin();
	boxp(r,c,index,0);
	}
void rule(int r,int c,char ch,int i)
	{
	if(ch=='P')
		{
		P(r,c,i);
		}
	else if(ch=='R')
		{
		R(r,c,i);
		}
	else if(ch=='N')
		{
		N(r,c,i);
		}
	else if(ch=='B')
		{
		B(r,c,i);
		}
	else if(ch=='Q')
		{
		Q(r,c,i);
		}
	else if(ch=='K')
		{
		K(r,c,i);
		}
	}
void Q(int r,int c,int index)
	{
	int dr,dc,cn=1, cl;
	int i,j;
	int hol,flag=0,sr,sc,gr,gc;
	dr=r;
	dc=c;
	sr=r;
	sc=c;
	gr=r;
	gc=c;
	while(1)
		{
		if(cn!=1)
			dlboxup(149-4,29-4,600-47,430+3,1);
		if(cn==1)
			{
			if(dr==r&&dc==c)boxp(r,c,1,1);
			else boxp(dr,dc,10,1);
			}
		if(colcd[index]==15&&cn==1&&gflag==0)
			{
			for(i=1;i<=8;i++)
				{
				sr=gr;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				cn=0;
				}
			flag=1;
			boxp(r,c,1,0);
			}
		else if(colcd[index]==6&&cn==1&&gflag==1)
			{
			flag=2;
		     //	printf("I entered 2");
			for(i=1;i<=8;i++)
				{
				sr=gr;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				cn=0;
				}
			boxp(r,c,1,0);
			}

		if(kbhit())
			{
			cn=1;
			hol=nav(r,c);
			if(hol==1)
				{
				barxp(r,c);
				r=pr;
				c=pc;
				boxp(r,c,1,0);
				prin();
				delay(60);
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
			if(hol==13)
				{
				if(flag==1)
					{
					int jk;
					for(i=1;i<=8;i++)
						{
						sr=gr;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					}
				else if(flag==2)
					{
					int jk;
					for(i=1;i<=8;i++)
						{
						sr=gr;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&j!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					}

				break;
				}
			}

		}
	board();
	prin();
	boxp(r,c,index,0);
	}
void B(int r,int c,int index)
	{
	int dr,dc,cn=1, cl;
	int i,j;
	int hol,flag=0,sr,sc,gr,gc;
	dr=r;
	dc=c;
	sr=r;
	sc=c;
	gr=r;
	gc=c;
	while(1)
		{
		if(cn!=1)
			dlboxup(149-4,29-4,600-47,430+3,1);
		if(cn==1)
			{
			if(dr==r&&dc==c)boxp(r,c,1,1);
			else boxp(dr,dc,10,1);
			}
		if(colcd[index]==15&&cn==1&&gflag==0)
			{
		       //	printf("I entered 1");
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				cn=0;
				}
			flag=1;
			boxp(r,c,1,0);
			}
		else if(colcd[index]==6&&cn==1&&gflag==1)
			{
			flag=2;
		     //	printf("I entered 2");
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,cl,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr+i;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc+i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				}
			for(i=1;i<=8;i++)
				{
				sr=gr-i;
				sc=gc-i;
				cn=comp(sr,sc,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(sr,sc,cl,0);
					break;
					}
				else cl=10;
				boxp(sr,sc,10,1);
				cn=0;
				}
			boxp(r,c,1,0);
			}

		if(kbhit())
			{
			cn=1;
			hol=nav(r,c);
			if(hol==1)
				{
				barxp(r,c);
				r=pr;
				c=pc;
				boxp(r,c,1,0);
				prin();
				delay(60);
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
			if(hol==13)
				{
				if(flag==1)
					{
					int jk;
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					}
				else if(flag==2)
					{
					int jk;
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&j!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc+i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr+i;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					for(i=1;i<=8;i++)
						{
						sr=gr-i;
						sc=gc-i;
						jk=comp(sr,sc,index);
						if(r==sr&&c==sc&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(sr,sc,index);
						if(jk!=0)break;
						}
					}

				break;
				}
			}

		}
	board();
	prin();
	boxp(r,c,index,0);
	}
void R(int r,int c,int index)
	{
	int i,j,cn=1,cl,hol,flag=0;
	int dr,dc;
	long  ff=0;
	dr=r;
	dc=c;
	while(1)
		{
		if(cn!=1)
			dlboxup(149-4,29-4,600-47,430+3,1);
		if(cn==1)
			{
			if(dr==r&&dc==c)
				boxp(r,c,1,1);
			else boxp(dr,dc,10,1);
			}
		if(colcd[index]==6&&cn==1&&gflag==1)
			{
			flag=1;
			cn=0;
			pr=r;
			pc=c;
			r=dr;
			c=dc;
			for(i=r;i<=8;i++)
				{
				cn=comp(i,c,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(i,c,cl,0);
					break;
					}
				else cl=10;
				boxp(i,c,cl,0);
				}
			for(i=r;i>=1;i--)
				{
				cn=comp(i,c,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(i,c,cl,0);
					break;
					}
				else cl=10;
				boxp(i,c,cl,0);
				}
			for(i=c;i<=8;i++)
				{
				cn=comp(r,i,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(r,i,cl,0);
					break;
					}
				else cl=10;
				boxp(r,i,cl,0);
				}
			for(i=c;i>=1;i--)
				{
				cn=comp(r,i,index);
				if(cn==2)break;
				else if(cn==3)
					{
					cl=4;
					boxp(r,i,cl,0);
					break;
					}
				else cl=10;
				boxp(r,i,cl,0);
				}
			r=pr;
			c=pc;
			boxp(r,c,1,0);
			}
		else if(colcd[index]==15&&cn==1&&gflag==0)
			{
			flag=2;
			cn=0;
			pr=r;
			pc=c;
			r=dr;
			c=dc;
			for(i=r;i<=8;i++)
				{
				cn=comp(i,c,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(i,c,cl,0);
					break;
					}
				else cl=10;
				boxp(i,c,cl,0);
				}
			for(i=r;i>=1;i--)
				{
				cn=comp(i,c,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(i,c,cl,0);
					break;
					}
				else cl=10;
				boxp(i,c,cl,0);
				}
			for(i=c;i<=8;i++)
				{
				cn=comp(r,i,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(r,i,cl,0);

					break;
					}
				else cl=10;
				boxp(r,i,cl,0);
				}
			for(i=c;i>=1;i--)
				{
				cn=comp(r,i,index);
				if(cn==3)break;
				else if(cn==2)
					{
					cl=4;
					boxp(r,i,cl,0);
					break;
					}
				else cl=10;
				boxp(r,i,cl,0);
				}
			r=pr;
			c=pc;
			boxp(r,c,1,0);
			}

		if(kbhit())
			{
			cn=1;
			hol=nav(r,c);
			if(hol==1)
				{
				barxp(r,c);
				r=pr;
				c=pc;
				boxp(r,c,1,0);
				prin();
				delay(60);
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
			if(hol==13)
				{
				int jk,in;
				if(colcd[index]==6&&flag==1&&gflag==1)
					{
					flag=1;
					cn=0;
					pr=r;
					pc=c;
					r=dr;
					c=dc;
					for(i=r;i<=8;i++)
						{
						jk=comp(i,c,index);
						if(i==pr&&pc==c&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(i,c,index);
						if(jk!=0)
							{
							break;
							}
						}
					for(i=r;i>=1;i--)
						{
						jk=comp(i,c,index);
						if(i==pr&&pc==c&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						in=infr(i,c);
						jk=cmp(i,c,index);
						if(jk!=0)
							{
							break;
							}
						}
					for(i=c;i<=8;i++)
						{
						jk=comp(r,i,index);
						if(r==pr&&pc==i&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						in=infr(r,i);
						jk=cmp(r,i,index);
						if(jk!=0)
							{
							break;
							}
						}
					for(i=c;i>=1;i--)
						{
						jk=comp(r,i,index);
						if(r==pr&&pc==i&&jk!=2)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						in=infr(r,i);
						jk=cmp(r,i,index);
						if(jk!=0)
							{
							break;
							}
						}
					r=loc[index][0];
					c=loc[index][1];
					boxp(r,c,1,0);
					}
				if(colcd[index]==15&&flag==2&&gflag==0)
					{
					flag=1;
					cn=0;
					pr=r;
					pc=c;
					r=dr;
					c=dc;
					for(i=r;i<=8;i++)
						{
						jk=comp(i,c,index);
						if(i==pr&&pc==c&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(i,c,index);
						if(jk!=0)break;
						}
					for(i=r;i>=1;i--)
						{
						jk=comp(i,c,index);
						if(i==pr&&pc==c&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(i,c,index);
						if(jk!=0)break;
						}
					for(i=c;i<=8;i++)
						{
						jk=comp(r,i,index);
						if(r==pr&&pc==i&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(r,i,index);
						if(jk!=0)break;
						}
					for(i=c;i>=1;i--)
						{
						jk=comp(r,i,index);
						if(r==pr&&pc==i&&jk!=3)
							{
							loc[index][0]=pr;
							loc[index][1]=pc;
							gflag++;
							if(gflag==2)gflag=0;
							rep(pr,pc,index);
							break;
							}
						jk=cmp(r,i,index);
						if(jk!=0)break;
						}
					r=pr;
					c=pc;
					boxp(r,c,1,0);
					}
				break;
				}
			}
		}
	board();
	prin();
	boxp(r,c,index,0);
	}

void N(int r,int c,int i)
	{
	int dr,dc,cn=1,cl=10,ch;
	int hol,flag=0,sr,sc,gr,gc;
	dr=r;
	dc=c;
	sr=r;
	sc=c;
	gr=r;
	gc=c;
	while(1)
		{
		if(cn!=1)
			dlboxup(149-4,29-4,600-47,430+3,1);
		if(cn==1)
			{
			if(dr==r&&dc==c)
				boxp(r,c,1,1);
			else boxp(dr,dc,10,1);
			}
		if(colcd[i]==15&&cn==1&&gflag==0)
			{
			sr=gr+2;
			sc=gc+1;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=3)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+2;
			sc=gc-1;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=3)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-2;
			sc=gc-1;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=3)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-2;
			sc=gc+1;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=3)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=gc+2;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=3)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=gc-2;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=3)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-1;
			sc=gc-2;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=3)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-1;
			sc=gc+2;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=3)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			flag=1;
			cn=0;
			boxp(gr,gc,10,9);
			boxp(r,c,1,9);
			}
		else if(colcd[i]==6&&cn==1&&gflag==1)
			{
			sr=gr+2;
			sc=gc+1;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=2)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+2;
			sc=gc-1;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=2)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-2;
			sc=gc-1;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=2)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-2;
			sc=gc+1;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=2)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=gc+2;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=2)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=gc-2;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=2)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-1;
			sc=gc-2;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=2)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			sr=gr-1;
			sc=gc+2;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			else if(hol!=2)
				{
				cl=10;
				boxp(sr,sc,cl,1);
				}
			flag=2;
			cn=0;
			boxp(gr,gc,10,9);
			boxp(r,c,1,9);
			}
		if(kbhit())
			{
			hol=nav(r,c);
			if(hol==1)
				{
				barxp(r,c);
				r=pr;
				c=pc;
				boxp(r,c,9,0);
				prin();
				delay(60);
				while(1)
					{
					if(kbhit())
						{
						getch();
						continue;
						}
					break;
					}
				cn=1;
				}
			else if(hol==13)
				{
				if(flag==1)
					{
					sr=gr+2;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					else if(hol!=3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					sr=gr+2;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					else if(hol!=3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					sr=gr-2;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					else if(hol!=3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					sr=gr-2;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					else if(hol!=3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}					boxp(sr,sc,cl,1);
						}
					sr=gr+1;
					sc=gc+2;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					else if(hol!=3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					sr=gr+1;
					sc=gc-2;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					else if(hol!=3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					sr=gr-1;
					sc=gc-2;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					else if(hol!=3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					sr=gr-1;
					sc=gc+2;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					else if(hol!=3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
					       //	boxp(sr,sc,cl,1);
						}
					}
				else if(flag==2)
					{
					sr=gr+2;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=4;
						boxp(sr,sc,cl,1);
						}
					else if(hol!=2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=10;
						boxp(sr,sc,cl,1);
						}
					sr=gr+2;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=4;
						boxp(sr,sc,cl,1);
						}
					else if(hol!=2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=10;
						boxp(sr,sc,cl,1);
						}
					sr=gr-2;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=4;
						boxp(sr,sc,cl,1);
						}
					else if(hol!=2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=10;
						boxp(sr,sc,cl,1);
						}
					sr=gr-2;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=4;
						boxp(sr,sc,cl,1);
						}
					else if(hol!=2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=10;
						boxp(sr,sc,cl,1);
						}
					sr=gr+1;
					sc=gc+2;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=4;
						boxp(sr,sc,cl,1);
						}
					else if(hol!=2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=10;
						boxp(sr,sc,cl,1);
						}
					sr=gr+1;
					sc=gc-2;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=4;
						boxp(sr,sc,cl,1);
						}
					else if(hol!=2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=10;
						boxp(sr,sc,cl,1);
						}
					sr=gr-1;
					sc=gc-2;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=4;
						boxp(sr,sc,cl,1);
						}
					else if(hol!=2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=10;
						boxp(sr,sc,cl,1);
						}
					sr=gr-1;
					sc=gc+2;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=4;
						boxp(sr,sc,cl,1);
						}
					else if(hol!=2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						cl=10;
						boxp(sr,sc,cl,1);
						}
					}
				break;
				}
			//break;
			}
		}
	board();
	pr=r;
	pc=c;
	prin();
	}

void P(int r,int c,int i)
	{
	int dr,dc,cn=1,cl=10,ch;
	int hol,flag=0,fr,fc,gr,gc,sr,sc;
	dr=r;
	dc=c;
	fr=r;
	fc=c;
	gr=r;
	gc=c;
	while(1)
		{
		if(cn!=1)
			dlboxup(149-4,29-4,600-47,430+3,1);
		dr=gr;
		dc=gc;
		if(dr==2&&i<8&&cn==1&&gflag==0)
			{
			dr++;
			hol=comp(dr,dc,i);
			if(hol==2||hol==3)
				{
				if(hol==2)
					 {
					 cl=4;
					 }
				sr=gr+1;
				sc=gc+1;
				hol=comp(sr,sc,i);
				if(hol==2)
					{
					cl=4;
					boxp(sr,sc,cl,1);
					}
				sr=gr+1;
				sc=gc-1;
				hol=comp(sr,sc,i);
				if(hol==2)
					{
					cl=4;
					boxp(sr,sc,cl,1);
					}
				flag=1;
				cn=0;
				boxp(gr,gc,10,9);
				boxp(r,c,1,9);

				continue;
				}
			else cl=10;
			boxp(dr,dc,cl,1);
			dr++;
			hol=comp(dr,dc,i);
			if(hol==2)
				{
				cl=4;
			   //	boxp(dr,dc,cl,1);
				}
			else if(hol==3);
			else
				{
				cl=10;
				boxp(dr,dc,cl,1);
				}
			sr=gr+1;
			sc=gc+1;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			sr=gr+1;
			sc=gc-1;
			hol=comp(sr,sc,i);
			if(hol==2)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			flag=1;
			cn=0;
			boxp(gr,gc,10,9);
			boxp(r,c,1,9);
			}
		else if(dr==7&&i>=8&&cn==1&&gflag==1)
			{
			dr--;
			hol=comp(dr,dc,i);
			if(hol)
				{
				if(hol==3)
					{
					cl=4;
				//	boxp(dr,dc,cl,1);
					}
				sr=gr-1;
				sc=gc-1;
				hol=comp(sr,sc,i);
			      //	printf("%d \n",hol);
				if(hol==3)
					{
					cl=4;
					boxp(sr,sc,cl,1);
					}
				sr=gr-1;
				sc=gc+1;
				hol=comp(sr,sc,i);
				if(hol==3)
					{
					cl=4;
					boxp(sr,sc,cl,1);
					}
				flag=2;
				cn=0;
				boxp(gr,gc,10,9);
				boxp(r,c,1,9);
				continue;
				}
			else cl=10;

			boxp(dr,dc,cl,1);
			dr--;
			hol=comp(dr,dc,i);
			if(hol==3)
				{
				cl=4;
			       //	boxp(dr,dc,cl,1);
				}
			else if(hol==2);
			else
				{
				cl=10;
				boxp(dr,dc,cl,1);
				}
			sr=gr-1;
			sc=gc+1;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			sr=gr-1;
			sc=gc-1;
			hol=comp(sr,sc,i);
			if(hol==3)
				{
				cl=4;
				boxp(sr,sc,cl,1);
				}
			flag=2;
			cn=0;
			boxp(gr,gc,10,9);
			boxp(r,c,1,9);
			}
		else if(cn==1)
			{
			if(i<8&&gflag==0)
				{
				dr++;
				hol=comp(dr,dc,i);
				//printf("\n%d ",hol);
				if(hol==2)
					{
					cl=4;
				//	boxp(dr,dc,cl,1);
					sr=gr+1;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						cl=4;
						boxp(sr,sc,cl,1);
						}
					sr=gr+1;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						cl=4;
						boxp(sr,sc,cl,1);
						}
					flag=3;
					cn=0;
					boxp(gr,gc,10,9);
					boxp(r,c,1,9);
					continue;
					}
				else if(hol==3)
					{
					flag=3;
					cn=0;
					sr=gr+1;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						cl=4;
						boxp(sr,sc,cl,1);
						}
					sr=gr+1;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						cl=4;
						boxp(sr,sc,cl,1);
						}
				  //	boxp(gr,gc,10,9);
					boxp(r,c,1,9);
					continue;
					}
				else cl=10;
				boxp(dr,dc,cl,0);
				sr=gr+1;
				sc=gc+1;
				hol=comp(sr,sc,i);
				if(hol==2)
					{
					cl=4;
					boxp(sr,sc,cl,1);
					}
				sr=gr+1;
				sc=gc-1;
				hol=comp(sr,sc,i);
				if(hol==2)
					{
					cl=4;
					boxp(sr,sc,cl,1);
					}
				flag=3;
				cn=0;
				boxp(gr,gc,10,9);
				boxp(r,c,1,9);
				}
			if(i>=8&&gflag==1)
				{
				dr--;
				hol=comp(dr,dc,i);
				if(hol)
					{
					if(hol==3)
						{
						cl=4;
				    //		boxp(dr,dc,cl,1);
						}
					sr=gr-1;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						cl=4;
						boxp(sr,sc,cl,1);
						}
					sr=gr-1;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						cl=4;
						boxp(sr,sc,cl,1);
						}
					flag=4;
					cn=0;
					boxp(gr,gc,10,9);
					boxp(r,c,1,9);
					continue;
					}
				else cl=10;

				boxp(dr,dc,cl,0);
				flag=4;
				sr=gr-1;
				sc=gc+1;
				hol=comp(sr,sc,i);
				if(hol==3)
					{
					cl=4;
					boxp(sr,sc,cl,1);
					}
				sr=gr-1;
				sc=gc-1;
				hol=comp(sr,sc,i);
				if(hol==3)
					{
					cl=4;
					boxp(sr,sc,cl,1);
					}
				}
			cn=0;
			boxp(gr,gc,10,9);
			boxp(r,c,1,9);
			}
		if(kbhit())
			{
			hol=nav(r,c);
			if(hol==1)
				{
				barxp(r,c);
				r=pr;
				c=pc;
				boxp(r,c,9,0);
				prin();
				delay(60);
				while(1)
					{
					if(kbhit())
						{
						getch();
						continue;
						}
					break;
					}
				cn=1;
				}
			else if(hol==13)
				{
				if(flag==1&&gflag==0)
					{
					int jk;
					fr=gr+1;
					jk=cmp(fr,gc,i);
				     //	printf("\n\nnot passed %d \n",jk);
					if(jk!=0);
					else
						{
						fr=gr+2;
						jk=cmp(fr,gc,i);
						//jk=flag16;
						if(fr==r&&gc==c&&jk==0||--fr==r&&gc==c&&jk==0)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					//int flag16=0;
					sr=gr+1;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
						    //	flag16=1;
							}
						}
					sr=gr+1;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
						      //	flag16=1;
							}
						}

					}
				else if(flag==2&&gflag==1)
					{
					int jk;
					fr=gr-1;
					jk=cmp(fr,c,i);
					if(jk!=0);
					else
						{
						fr=gr-2;
						jk=cmp(gr,gc,i);
						if(fr==r&&gc==c&&jk==0||++fr==r&&gc==c&&jk==0)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
							}
						}
					//int flag16=0;
					sr=gr-1;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
					  //		flag16=1;
							}
						}
					sr=gr-1;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
					    //		flag16=1;
							}
						}
					}
				else if(flag==3&&gflag==0)
					{
					int jk;
					fr=gr+1;
					jk=cmp(fr,gc,i);
					if(fr==r&&gc==c&&jk==0)
						{
						loc[i][0]=r;
						loc[i][1]=c;
						gflag++;
						if(gflag==2)gflag=0;
						rep(r,c,i);
						}
					sr=gr+1;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
						    //	flag16=1;
							}
						}
					sr=gr+1;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==2)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
						      //	flag16=1;
							}
						}

					}
				else if(flag==4&&gflag==1)
					{
					int jk;
					fr=gr-1;
					jk=cmp(fr,gc,i);
					if(fr==r&&gc==c&&jk==0)
						{
						loc[i][0]=r;
						loc[i][1]=c;
						gflag++;
						if(gflag==2)gflag=0;
						rep(r,c,i);
						}
					sr=gr-1;
					sc=gc-1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
					  //		flag16=1;
							}
						}
					sr=gr-1;
					sc=gc+1;
					hol=comp(sr,sc,i);
					if(hol==3)
						{
						if(sr==r&&sc==c)
							{
							loc[i][0]=r;
							loc[i][1]=c;
							gflag++;
							if(gflag==2)gflag=0;
							rep(r,c,i);
					    //		flag16=1;
							}
						}
					}
				break;
				}
			if(hol==13)break;
			}
		}

	board();
	pr=r;
	pc=c;
	prin();
	}

void check(int r,int c)
	{
	int i,j;
	for(i=0;i<=32;i++)
		{
		if(r==loc[i][0]&&c==loc[i][1])
			{
			rule(r,c,name[i],i);
			break;
			}
		}
	}
void prin()
	{
	int i;
	for(i=0;i<=32;i++)
		{
		chpl(loc[i][0],loc[i][1],colcd[i],name[i]);
		}
	}
int nav(int r,int c)
	{
	char ch;
	int in;
	ch=getch();
	in=ch;
	if(in==27)stcon();
	if(in==13)
		{
		return 13;
		}
	if(kbhit())
		{
		ch=getche();
		switch(ch)
			{
			case 'P':
				if(r==8)r=1;
				else r++;
				pr=r;
				pc=c;
				return 1;
			case 'H':
				if(r==1)r=8;
				else r--;
				pr=r;
				pc=c;
				return 1;
			 case 'M':
				if(c==8)c=1;
				else c++;
				pr=r;
				pc=c;
				return 1;
			case 'K':
				if(c==1)c=8;
				else c--;
				pr=r;
				pc=c;
				return 1;
			}
		}
	return 0;
	}
void reset()
	{
	int i,ed=1,flag=0;
	cleardevice();
	p1=0;
	p2=0;
	k1=0;
	k2=0;
	q1=0;
	q2=0;
	r1=0;
	r2=0;
	n1=0;
	n2=0;
	b1=0;
	b2=0;
	for(i=0;i<=15;i++)
		{
		name[i]='P';
		if(flag)
			{
			loc[i][0]=7;
			loc[i][1]=ed;
			chpl(loc[i][0],loc[i][1],6,name[i]);
			colcd[i]=6;
			}
		else
			{
			loc[i][0]=2;
			loc[i][1]=ed;
			chpl(loc[i][0],loc[i][1],15,name[i]);
			colcd[i]=15;
			}
		if(ed==8)
			{
			ed=1;
			flag=1;
			continue;
			}
		ed++;
		}

	name[i]='R';
	loc[i][0]=8;
	loc[i][1]=1;
	chpl(loc[i][0],loc[i][1],6,name[i]);
	colcd[i]=6;
	i++;
	name[i]='R';
	loc[i][0]=8;
	loc[i][1]=8;
	chpl(loc[i][0],loc[i][1],6,name[i]);
	colcd[i]=6;
	i++;
	name[i]='R';
	loc[i][0]=1;
	loc[i][1]=1;
	chpl(loc[i][0],loc[i][1],15,name[i]);
	colcd[i]=15;
	i++;
	name[i]='R';
	loc[i][0]=1;
	loc[i][1]=8;
	chpl(loc[i][0],loc[i][1],15,name[i]);
	colcd[i]=15;
	i++;
	name[i]='N';
	loc[i][0]=8;
	loc[i][1]=2;
	chpl(loc[i][0],loc[i][1],6,name[i]);
	colcd[i]=6;
	i++;
	name[i]='N';
	loc[i][0]=8;
	loc[i][1]=7;
	chpl(loc[i][0],loc[i][1],6,name[i]);
	colcd[i]=6;
	i++;
	name[i]='N';
	loc[i][0]=1;
	loc[i][1]=2;
	chpl(loc[i][0],loc[i][1],15,name[i]);
	colcd[i]=15;
	i++;
	name[i]='N';
	loc[i][0]=1;
	loc[i][1]=7;
	chpl(loc[i][0],loc[i][1],15,name[i]);
	colcd[i]=15;
	i++;
	name[i]='B';
	loc[i][0]=8;
	loc[i][1]=3;
	chpl(loc[i][0],loc[i][1],6,name[i]);
	colcd[i]=6;
	i++;
	name[i]='B';
	loc[i][0]=8;
	loc[i][1]=6;
	chpl(loc[i][0],loc[i][1],6,name[i]);
	colcd[i]=6;
	i++;
	name[i]='B';
	loc[i][0]=1;
	loc[i][1]=3;
	chpl(loc[i][0],loc[i][1],15,name[i]);
	colcd[i]=15;
	i++;
	name[i]='B';
	loc[i][0]=1;
	loc[i][1]=6;
	chpl(loc[i][0],loc[i][1],15,name[i]);
	colcd[i]=15;
	i++;
	name[i]='Q';
	loc[i][0]=1;
	loc[i][1]=4;
	chpl(loc[i][0],loc[i][1],15,name[i]);
	colcd[i]=15;
	i++;
	name[i]='Q';
	loc[i][0]=8;
	loc[i][1]=4;
	chpl(loc[i][0],loc[i][1],6,name[i]);
	colcd[i]=6;
	i++;
	name[i]='K';
	loc[i][0]=8;
	loc[i][1]=5;
	chpl(loc[i][0],loc[i][1],6,name[i]);
	colcd[i]=6;
	i++;
	name[i]='K';
	loc[i][0]=1;
	loc[i][1]=5;
	chpl(loc[i][0],loc[i][1],15,name[i]);
	colcd[i]=15;
	}

void chpl(int r,int c,int col,char ch)
	{
	int bl=1,i,j;
	char arr[2];
	int x=150,y=30,x1=200,y1=80;
	for(i=1;i<=r;i++)
		{
		int flag=0;
		if(i%2==0)bl=1;
		else bl=0;
		for(j=1;j<=c;j++)
			{
			if(r==i&&c==j)
				{
				setcolor(col);
				arr[0]=ch;
				arr[1]='\0';
				settextstyle(1,0,5);
				outtextxy(x+10,y+1,arr);
				break;
				}
			x+=50;
			x1+=50;
			}
		y+=50;
		y1+=50;
		x=150;
		x1=200;
		}
	}
void barxp(int r,int c)
	{
	int bl=1,i,j;
	int x=150,y=30,x1=200,y1=80;
	for(i=1;i<=r;i++)
		{
		int flag=0;
		if(i%2==0)bl=1;
		else bl=0;
		for(j=1;j<=c;j++)
			{
			if(r==i&&c==j)
				{
				if(i%2==0)
					{
					if(j%2==0)
						setfillstyle(SOLID_FILL,7);
					else
						setfillstyle(SOLID_FILL,0);
					}
				else
					{
					if(j%2!=0)
						setfillstyle(SOLID_FILL,7);
					else
						setfillstyle(SOLID_FILL,0);
					}
				bar(x,y,x1,y1);
				break;
				}
			x+=50;
			x1+=50;
			}
		y+=50;
		y1+=50;
		x=150;
		x1=200;
		}
	}
void boxp(int r,int c,int col,int flag)
	{
	int bl=1,i,j;
	int x=150,y=30,x1=200,y1=80;
	for(i=1;i<=r;i++)
		{
		int flag=0;
		if(i%2==0)bl=1;
		else bl=0;
		for(j=1;j<=c;j++)
			{
			if(r==i&&c==j&&r<=8&&r>=1&&c<=8&&c>=1)
				{
				setcolor(col);
				rectangle(x,y,x1,y1);
				rectangle(x+1,y+1,x1-1,y1-1);
				rectangle(x+2,y+2,x1-2,y1-2);
				break;
				}
			x+=50;
			x1+=50;
			}
		y+=50;
		y1+=50;
		x=150;
		x1=200;
		}
	}
void board()
	{
	int j,cl,wb=0;
	int i,x=150,y=30,x1=200,y1=80;
	for(i=1;i<=8;i++)
		{
		if(i%2==0)cl=2;
		else cl=1;
		for(j=1;j<=8;j++)
			{
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			if(cl%2==0)setfillstyle(SOLID_FILL,BLACK);
			bar(x,y,x1,y1);
			x+=50;
			x1+=50;
			cl++;
			}
		setcolor(15);
		if(i==8)
			{
			setcolor(DARKGRAY);
			/*printf("\n\n\nx1=%d,y1=%d",x1,y1);
			getch();
			exit(0);*/
			rectangle(149,29,x1-49,y1+1);
			rectangle(148,28,x1-48,y1+2);
			}
		y+=50;
		y1+=50;
		x=150;
		x1=200;
		}
	}

void newl()
	{
	setcolor(WHITE);
	settextstyle(1,0,3);
	outtextxy(150,100,"NEW");
	outtextxy(150,150,"PLAY");
	outtextxy(150,200,"HELP");
	outtextxy(150,250,"EXIT");
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
		y1=230;
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
		newl();
		dlbox(x,y,x1,y1);
		if(kbhit())break;
		}
	}
void help()
	{
	char helpmenu[]={"Chess is a two-player board game that is played on a square board with 64 squares, arranged in an 8x8 grid.\n\nEach player starts with 16 pieces: one king, one queen, two rooks, two knights, two bishops, and eight pawns.\n\nThe objective of the game is to checkmate your opponent's king, which means placing their king under attack in such a way that there is no legal move to get out of check.\n\nEach piece has its own unique way of moving across the board. For example, the pawn can move one or two squares forward on its first move, and then one square forward on subsequent moves. The knight moves in an L-shape, while the bishop moves diagonally.\n "};
	char helpmenu1[]={"The queen is the most powerful piece on the board, as it can move in any direction (diagonally, horizontally, or vertically) for any number of squares.\n\nPlayers take turns moving their pieces, with white always moving first.\n\nThere are a few special moves in chess, such as castling (where the king moves two squares towards a rook, and the rook moves"};
	char helpmenu2[]={"to the square the king crossed) and en passant (where a pawn can capture an opposing pawn that has just moved two squares forward on its first move).\n\nPlayers must also be careful to avoid putting their own king in danger, as this can lead to checkmate.\n\nThe game is won when one player checkmates their opponent's king, or when the opponent resigns."};
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
	color--;
	if(color==0)color=1;
	setcolor(color);
	if(color==15)color=1;
	else color++;
	rectangle(x,y,x1,y1);
	rectangle(x+1,y+1,x1+1,y1+1);
	rectangle(x+2,y+2,x1+2,y1+2);
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
	delay(del);
	arr[0]=str2[3];
	arr[1]='\0';
	setcolor(15);
	settextstyle(1,0,50);
	outtextxy(340,22,arr);
	delay(500);
	outtextxy(280,150,"in");
	//getch();
	C(450,350,0);
	}
void C(int x,int y,int flag)
	{
	int i,j=0,cl=1,coun=0;
	if(flag==0)
		{
		setcolor(0);
		settextstyle(1,0,2);
	      ///	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tPress any key to continue...");
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
			//if(kbhit())break;
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