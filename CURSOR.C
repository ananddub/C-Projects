#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
void main()
	{
	int gd=DETECT,gm;
	int in,x=0,y=0,max,maxy,cn=0;
	int len=0,cun=0,flag=0;
	int hash=0;
	long i,cr=90000,j,ys[100],linecn=0,flag45=0,bk=0;
	char ch,arr[100][100],dump[2];
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	max=getmaxx();
	maxy=getmaxy();
	arr[1][0]='\0';
	cn=0;
	y=20;
	while(1)
		{
		for(j=0;j<=linecn;j++)
			{
			int cr2=0,flag5=0;
			int cun2=0;
			cun=0;
			cun2=0;
			len=strlen(arr[j]);
			hash=0;
			for(i=0;i<=len&&flag==1;i++)
				{
				int l,g;
				l=i;
				g=i;
				//in=arr[i];
				setcolor(GREEN);
				if(arr[j][i]=='"')
					{
					setcolor(RED);
					cun++;
					}
				else if(arr[j][i]=='#')
					{
					setcolor(BLUE);
					hash++;
					}
				else if(arr[j][i]=='\'')
					{
					setcolor(MAGENTA);
					cun2++;
					}
				else if(isdigit(arr[j][i]))setcolor(LIGHTGRAY);
				else if(cun==1)setcolor(RED);
				else if(arr[j][i]=='+'||arr[j][i]=='-'||arr[j][i]=='/'||arr[j][i]=='*'||arr[j][i]==','||arr[j][i]=='='||arr[j][i]=='}'||arr[j][i]=='{'||arr[j][i]==']'||arr[j][i]=='['||arr[j][i]=='('||arr[j][i]==')'||arr[j][i]==';')setcolor(YELLOW);
				else if(arr[j][i]=='i'&&arr[j][++g]=='f')
					{
					flag5=2;
					cr2=1;
					setcolor(15);
					}
				g=i;
				if(arr[j][i]=='e'&&arr[j][++g]=='l'&&arr[j][++g]=='s'&&arr[j][++g]=='e')
					{
					cr2=1;
					setcolor(15);
					flag5=1;
					}
				else if(cr2<=3&&cr2>=1&&flag5==1)
					{
					setcolor(15);
					cr2++;
					}
				else if(cr2<=2&&cr2>=1&&flag5==2)
					{
					cr2++;
					setcolor(15);
					}
				else if(cun2==1)setcolor(MAGENTA);
				else if(cr2==3&&flag5==0)cr2=0;
				else if(cun==2)cun=0;
				else if(cun2==2)cun2=0;
				else if(cr2==3&&flag5==1)
				       {
				       cr2=0;
				       flag5=0;
				       }
				else if(hash>0)
					{
					setcolor(BLUE);
					setfillstyle(SOLID_FILL,LIGHTBLUE);
				       //	bar(0,y,x,y+10);
					}
				dump[0]=arr[j][i];
				dump[1]='\0';
				outtextxy(l*8,ys[j],dump);
				}

			}
		i=0;
		while(cr==90000)
			{
			setcolor(0);
			line(x,y,x,y+10);
			for(i=0;i<=100000;i++)if(kbhit())break;
			setcolor(YELLOW);
			line(x,y,x,y+10);
			for(i=0;i<=400000;i++)if(kbhit())break;
			if(kbhit())
				{
				cr=0;
				break;
				}
			}
		cr++;
		setcolor(YELLOW);
		line(x,y,x,y+10);
		flag=0;
		if(kbhit())
			{
			arr[linecn][cn]=getche();
			flag=1;
			}
		setcolor(0);
		if(flag)
			{
			line(x,y,x,y+10);
			}
		in=arr[linecn][cn];
		if(in==27&&flag==1)
			{
			break;
			}
		if(in==13&&flag==1)
			{
			ys[linecn]=y;
			y+=15;
			flag45=1;
			}
		if(in==8&&flag==1)
			{
			if(cn>0)
				{
				char arr3[2];
				int lg;
				cn--;
				lg=strlen(arr[linecn]);
				arr3[0]=arr[linecn][cn];
				arr3[1]='\0';

				setfillstyle(SOLID_FILL,0);
				bar(x-8,y,x,y+10);
				arr[linecn][cn]='\0';
				}
			else
				{
				arr[linecn][0]='\0';
				if(linecn>0)
					{
					int lg;
					linecn--;
					y=ys[linecn];
					lg=strlen(arr[linecn]);
					cn=lg;
					}
				}
			}
		else if(flag==1)
			{
			cn++;
			arr[linecn][cn]='\0';
			}
		if(flag45==1)
		       {
		       arr[linecn][--cn]='\0';
		       linecn++;
		       arr[linecn][0]='\0';
		       ys[linecn]=y;
		       flag45=0;
		       cn=0;
		       }
		len=strlen(arr[linecn]);
		x=0;
		x=len*8;
	      //	if(in==32)printf("%d",len);


		/*if(ch=='w'||ch=='H')
			{
			if(y>=0)
				y-=10;
			if(y==-10)
				y=0;
			}
		else if(ch=='s'||ch=='P')
			{
			if(y<=479)
				y+=10;
			if(y>=479)
				y=479;
			}
		else if(ch=='a'||ch=='K')
			{
			if(x>=0)
				x-=10;
			if(x==-10)
				x=0;
			}
		else if(ch=='d'||ch=='M')
			{
			if(x<=639)
				x+=10;
			if(x>=639)
				x=639;
			}*/

		}

	}