#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
char data[18][8][100];
char sen[1000],temp5[100][100];
int dlib,tcl=0;

void rect()
	{
	int i,j,y=0,y1=25,x=0,x1=50,gx=50,gy=12+25;
	int ex=0;
	char str[3];
	setcolor(DARKGRAY);
	//gotoxy(2,0);
      //	printf(" ");
      //	printf("\n");
	settextstyle(0,0,0);
	for(j=0;j<=18;j++)
		{
		x=0;
		x1=30;
		for(i=0;i<=8;i++)
			{
			ex=i;
			ex--;
			if(i==0||j==0)setcolor(WHITE);
			else
			setcolor(8);
			if(j==0&&i==0);
			else
				rectangle(x,y,x1,y1);
			if(i==0)
				{
				x=30;
				x1=100;
				continue;
				}
			x1+=70;
			x+=70;
			}
		y+=25;
		y1+=25;
		}
	setcolor(WHITE);
	rectangle(30,25,30,475);
	rectangle(30,25,590,25);
	setcolor(LIGHTGRAY);
	for(i=1;i<=18;i++)
		{
		sprintf(str," %d",i);
		outtextxy(2,gy,str);
		gy+=25;
		}
	for(i=65;i<=72;i++)
		{
		sprintf(str," %c",i);
		outtextxy(gx,10,str);
		gx+=70;
		}
       //	data2();

	}
int mrect(int cl,int w,int a,int w1,int a1)
	{
	int i,j,y=0,y1=25,x=0,x1=50;
	if(w==-1)return 0;
	w-=1;
	if(w1==-1)
		{
		w1=w;
		w--;
		w1--;
		}
	else
		{
		w--;
		w1-=2;
		}
	if(a1==-1)
		{
		a1=a;
		}
	if(a>a1&&a1!=-1)
		{
		a=a+a1;
		a1=a-a1;
		a=a-a1;
		}
       //	textcolor(0);
	//printf("w=%d,w1=%d\ta=%d,a1=%d\n",w,w1,a,a1);
       //	rect();
	for(j=0;j<=w;j++)
		{
		x=0;
		for(i=0;i<=a;i++)
			{
			if(i==0)
				{
				x=30;
				continue;
				}
			x+=70;
			}
		y+=25;
		}
	for(j=0;j<=w1;j++)
		{
		x1=30;
		for(i=0;i<=a1;i++)
			{
			if(i==0)
				{
				x1=100;
				continue;
				}
			x1+=70;
			}
		y1+=25;
		}
	setcolor(cl);
	rectangle(x,y,x1,y1);
	setcolor(BLACK);
	rectangle(x1+2,y1+2,x1-2,y1-2);
	setcolor(cl);
	rectangle(x1+1,y1+1,x1-1,y1-1);
	return 0;
	}
void data1(int cl)
	{

	int i,j,x2;
	int x=50,y1=25,y=0,ex,b;
	for(j=0;j<=17;j++)
		{
		x=25;
		for(i=0;i<=7;i++)
			{
			setcolor(cl);
			if(i==0)
				{
				outtextxy(x+7,y1+10,data[j][i]);
				x=30;
				continue;
				}
			x+=70;
			outtextxy(x+7,y1+10,data[j][i]);
			ex=i;
			ex--;
			}
		y+=25;
		y1+=25;
		}
	}

int rlcount(int w,int a,int w1,int a1)
	{
	int cmp,i,j,count=0;
	char p[1000];
	rect();
	if(w==-1)return 0;
	w-=1;
	if(w1==-1)
		{
		w1=w;
		w--;
		w1--;
		}
	else
		{
		w--;
		w1-=2;
		}
	if(a1==-1)
		{
		a1=a;
		}
	if(a>a1&&a1!=-1)
		{
		a=a+a1;
		a1=a-a1;
		a=a-a1;
		}
	for(i=w;i<=w1;i++)
		{
		for(j=a;j<=a1;j++)
			{
			cmp=strcmp(sen,data[i][j]);
			if(cmp==0)
				{
				count++;
				}
			}
		}
	rect();
	return count;
	}
int rlsum(int wl,int al,int w,int a,int w1,int a1)
	{
	int i,j,sum=0;
	rect();
	//printf("a=%d",a);
	if(w==-1)return 0;
	w-=1;
	if(w1==-1)
		{
		w1=w;
		w--;
		w1--;
		}
	else
		{
		w--;
		w1-=2;
		}
	if(a1==-1)
		{
		a1=a;
		}
	if(a>a1&&a1!=-1)
		{
		a=a+a1;
		a1=a-a1;
		a=a-a1;
		}
	for(i=w;i<=w1;i++)
		{
		for(j=a;j<=a1;j++)
			{
			if(isdigit(data[i][j][0]))
				{
				sum+=atol(data[i][j]);
				continue;
				}
			else if(data[i][j][0]=='\0'||data[i][j][0]==' ')
				{
				sum+=0;
				continue;
				}
			else
				{
				strcpy(data[wl][al],"#ERROR");
				return 0;
				}
			}
		}
	sprintf(data[wl][al],"%d",sum);
	rect();
	return 0;
	}
int rlavg(int wl,int al,int w,int a,int w1,int a1)
	{
	int i,j;
	float total,sum=0,avg=0;
	rect();
	//printf("a=%d",a);
	if(w==-1)return 0;
	w-=1;
	if(w1==-1)
		{
		w1=w;
		w--;
		w1--;
		}
	else
		{
		w--;
		w1-=2;
		}
	if(a1==-1)
		{
		a1=a;
		}
	if(a>a1&&a1!=-1)
		{
		a=a+a1;
		a1=a-a1;
		a=a-a1;
		}
	total=0;
	for(i=w;i<=w1;i++)
		{
		for(j=a;j<=a1;j++)
			{
			if(isdigit(data[i][j][0]))
				{
				sum+=atoi(data[i][j]);
				total++;
				continue;
				}
			else if(data[i][j][0]=='\0'||data[i][j][0]==' ')
				{
				sum+=0;
				continue;
				}
			else
				{
				strcpy(data[wl][al],"#ERROR");
				return 0;
				}
			}
		}
	avg=sum/total;
      //	printf("%0.2f",avg);
	sprintf(data[wl][al],"%0.2f",avg);
	rect();
	return 0;
	}
int s(int wl,int al,int w2,int a2,int w1,int a1,int flag,int lib,int pass)
	{
	static int fl=1,orlib[100];
	static int cn=0;
	static char da[100][100];
	static int w[100][5],a[100][5],rs=0;
	int i=0,j,cmp;
	if(fl)
		{
		for(i=0;i<=99;i++)
			{
			for(j=0;j<=99;j++)
				{
				da[i][j]='\0';
				}

			w[i][0]=-500;
			a[i][0]=-500;
			w[i][1]=-500;
			a[i][1]=-500;
			w[i][2]=-500;
			a[i][2]=-500;
			orlib[i]=-500;
			}
		fl=0;
		}
	if(flag==2)
		{
		for(i=0;w[i][2]!=-500;i++)
			{
			//printf("we enter succusfully");
			if(w[i][2]==wl&&a[i][2]==al)
				{
				data[wl][al][0]='\0';
				strcpy(data[wl][al],temp5[i]);
				return i;
				}
			}
		}
	if(flag==1)
		{
		strcpy(da[cn],sen);
		orlib[cn]=lib;
		w[cn][0]=w2;
		a[cn][0]=a2;
		w[cn][1]=w1;
		a[cn][1]=a1;
		w[cn][2]=wl;
		a[cn][2]=al;
		cn++;
		}
	if(flag==3)
		{
		strcpy(da[pass],sen);
		orlib[pass]=lib;
		w[pass][0]=w2;
		a[pass][0]=a2;
		w[pass][1]=w1;
		a[pass][1]=a1;
		w[pass][2]=wl;
		a[pass][2]=al;
	       //	cn++;
		}
	for(i=0;i<=100&&w[i][0]!=-500&&flag==0;i++)
		{
		if(isdigit(data[w[i][2]][a[i][2]][0])&&orlib[i]==1)
			{
			strcpy(sen,da[i]);
			data1(0);
			rs=rlcount(w[i][0],a[i][0],w[i][1],a[i][1]);
			data[w[i][2]][a[i][2]][0]='\0';
			sprintf(data[w[i][2]][a[i][2]],"%d",rs);
			data1(15);
			}
		else if(isdigit(data[w[i][2]][a[i][2]][0])&&orlib[i]==2||data[w[i][2]][a[i][2]][0]=='#'&&data[w[i][2]][a[i][2]][1]=='E'&&data[w[i][2]][a[i][2]][2]=='R'&&data[w[i][2]][a[i][2]][3]=='R'&data[w[i][2]][a[i][2]][4]=='O'&&data[w[i][2]][a[i][2]][5]=='R'&&orlib[i]==2)
			{
			data1(0);
			data[w[i][2]][a[i][2]][0]='\0';
			rlsum(w[i][2],a[i][2],w[i][0],a[i][0],w[i][1],a[i][1]);
			data1(15);
			}

		else if(isdigit(data[w[i][2]][a[i][2]][0])&&orlib[i]==3||data[w[i][2]][a[i][2]][0]=='#'&&data[w[i][2]][a[i][2]][1]=='E'&&data[w[i][2]][a[i][2]][2]=='R'&&data[w[i][2]][a[i][2]][3]=='R'&data[w[i][2]][a[i][2]][4]=='O'&&data[w[i][2]][a[i][2]][5]=='R'&&orlib[i]==3)
			{
			data1(0);
			data[w[i][2]][a[i][2]][0]='\0';
			rlavg(w[i][2],a[i][2],w[i][0],a[i][0],w[i][1],a[i][1]);
			data1(15);
			}
		else
			{
			if(cn>0)
				{
				cn--;
				tcl--;
				}
			data1(0);
			w[cn][0]=w[i][0]+w[cn][0];
			w[i][0]=w[i][0]-w[cn][0];
			w[cn][0]=w[i][0]-w[cn][0];
			w[cn][1]=w[i][1]+w[cn][1];
			w[i][1]=w[i][1]-w[cn][1];
			w[cn][1]=w[i][1]-w[cn][1];
			w[cn][2]=w[i][2]+w[cn][2];
			w[i][2]=w[i][2]-w[cn][2];
			w[cn][2]=w[i][2]-w[cn][2];
			w[cn][0]=-500;
			w[cn][1]=-500;
			w[cn][2]=-500;
			data1(15);
			}
		}
	return 0;
	}
void count(int x,int y,int x1,int y1,int w,int a,int fl,int pass)
	{
	int i,j,cn=0,in,rs,cnte[2];
	char a1[2][2],arr2[8]={"ABCDEFGH"},str[100];
	int x5[2],cn1=0,flag=0;
	char ch,temp[50],ex=0;
	setcolor(BLACK);
	setcolor(LIGHTGREEN);
	rectangle(x,y,x1,y1);
	rectangle(x1-1,y1-1,x1-1,y1-1);
	setcolor(BLACK);
	rectangle(x1+2,y1+2,x1-2,y1-2);
	ex=a;
	ex--;
	for(i=x;i<=x1&&data[w][ex]!='\0';i++)
		{
		setcolor(BLACK);
		rectangle(x,y,i,y1);
		}
	setcolor(GREEN);
	cn=strlen(data[w][a]);
	setcolor(BLACK);
	outtextxy(x+7,y+10,data[w][a]);
	while(1)
		{
		rect();
		x5[0]=-1;
		x5[1]=-1;
		sen[0]='\0';
		cnte[0]=-1;
		cnte[1]=-1;
		cn1=0;
		flag=0;
		for(i=8;i<=17;i++)
			{
			in=0;
			if(data[w][a][i]=='\0')break;
			if(isdigit(data[w][a][i]))
				{
				sen[in]=data[w][a][i];
				in++;
				i++;
				if(isdigit(data[w][a][i]))
					{
					sen[in]=data[w][a][i];
					in++;
					}
				sen[in]='\0';
				x5[cn1]=atoi(sen);
				x5[cn1]++;
				i++;
				if(data[w][a][i]=='\0')break;
				if(isdigit(data[w][a][i])==0)
					{
					flag++;
					cn1++;
					if(flag==2)break;
					}
				}
			}
		flag=0;
		cn1=0;
		for(i=0;i<=1000;i++)
			{
			if(data[w][a][i]=='\0')break;
			if(flag==0&&data[w][a][0]=='=')
				{
				data[w][a][i]=toupper(data[w][a][i]);
				}
			if(data[w][a][i]=='"')
				{
				flag++;
				}
			else if(flag==1)
				{
				sen[cn1]=data[w][a][i];
				cn1++;
				}
			else if	(flag==2)
				{
				sen[cn1]='\0';
				}

			}
		flag=0;
		cn1=0;
		for(i=7;i<=20;i++)
			{
			if(data[w][a][i]=='\0')break;
			if(i==7)
				{
				a1[0][0]=data[w][a][i];
				}
			else if(data[w][a][i]==':')
				{
				i++;
				a1[1][0]=data[w][a][i];
				}
			}
		flag=0;
		for(i=0;i<=7;i++)
			{
			if(arr2[i]=='\0')break;
			if(a1[flag][0]==arr2[i])
				{
				cnte[flag]=i;
				}
			if(i==7&&flag==0)
				{
				i=-1;
				flag=1;
				}
			}
		mrect(9,x5[0],cnte[0],x5[1],cnte[1]);
		setcolor(LIGHTGREEN);
		rectangle(x,y,x1,y1);
		setcolor(WHITE);
		outtextxy(x+2,y+10,data[w][a]);
		ch=getche();
		mrect(0,x5[0],cnte[0],x5[1],cnte[1]);
		setcolor(BLACK);
		outtextxy(x+2,y+10,data[w][a]);
		in=ch;
		if(in==13)
			{
			if(fl==5)
				{
				char tempr[1000];
				if(data[w][a][0]=='='&&data[w][a][1]=='C'&&data[w][a][2]=='O'&&data[w][a][3]=='U'&data[w][a][4]=='N'&&data[w][a][5]=='T'&&data[w][a][6]=='(')
					{
					strcpy(temp5[pass],data[w][a]);
					data[w][a][0]='5';
					data[w][a][1]='\0';
					s(w,a,x5[0],cnte[0],x5[1],cnte[1],3,1,pass);
					break;
					}
				else
					{
					break;
					}

				//s(0,0,0,0,0,0,0,0,0);
				}
			else
				{
				strcpy(temp5[tcl],data[w][a]);
				tcl++;
				data[w][a][0]='5';
				data[w][a][1]='\0';
				s(w,a,x5[0],cnte[0],x5[1],cnte[1],1,1,0);
				//rlcn=rlcount(x5[0],cnte[0],x5[1],cnte[1]);

				s(0,0,0,0,0,0,0,0,0);
				break;
				}


			}
		data[w][a][cn]=ch;
		if(in==8)
			{
			if(cn>0)
				{
				cn--;
				data[w][a][cn]='\0';
				}
			else if(cn==0)break;
			}

		else
			{
			cn++;
			data[w][a][cn]='\0';
			}

		}
	}
int sum(int x,int y,int x1,int y1,int w,int a,int fl,int pass)
	{
	int i,j,cn=0,in,rs,cnte[2];
	char a1[2][2],arr2[8]={"ABCDEFGH"},str[100];
	int x5[2],cn1=0,flag=0;
	char ch,temp[50],ex=0;
	setcolor(BLACK);
	setcolor(LIGHTGREEN);
	rectangle(x,y,x1,y1);
	rectangle(x1-1,y1-1,x1-1,y1-1);
	setcolor(BLACK);
	rectangle(x1+2,y1+2,x1-2,y1-2);
	ex=a;
	ex--;
	for(i=x;i<=x1&&data[w][ex]!='\0';i++)
		{
		setcolor(BLACK);
		rectangle(x,y,i,y1);
		}
	setcolor(GREEN);
	cn=strlen(data[w][a]);
	setcolor(BLACK);
	outtextxy(x+7,y+10,data[w][a]);
	while(1)
		{
		rect();
		x5[0]=-1;
		x5[1]=-1;
		sen[0]='\0';
		cnte[0]=-1;
		cnte[1]=-1;
		cn1=0;
		flag=0;
		for(i=6;i<=17;i++)
			{
			in=0;
			if(data[w][a][i]=='\0')break;
			if(isdigit(data[w][a][i]))
				{
				sen[in]=data[w][a][i];
				in++;
				i++;
				if(isdigit(data[w][a][i]))
					{
					sen[in]=data[w][a][i];
					in++;
					}
				sen[in]='\0';
				x5[cn1]=atoi(sen);
				x5[cn1]++;
				i++;
				if(data[w][a][i]=='\0')break;
				if(isdigit(data[w][a][i])==0)
					{
					flag++;
					cn1++;
					if(flag==2)break;
					}
				}
			}
		flag=0;
		cn1=0;
		for(i=0;i<=1000;i++)
			{
			if(data[w][a][i]=='\0')break;
			if(flag==0&&data[w][a][0]=='=')
				{
				data[w][a][i]=toupper(data[w][a][i]);
				}
			if(data[w][a][i]=='"')
				{
				flag++;
				}
			else if(flag==1)
				{
				sen[cn1]=data[w][a][i];
				cn1++;
				}
			else if	(flag==2)
				{
				sen[cn1]='\0';
				}

			}
		flag=0;
		cn1=0;
		for(i=4;i<=40;i++)
			{
			if(data[w][a][i]=='\0')break;
			if(i==5)
				{
				a1[0][0]=data[w][a][i];
				}
			else if(data[w][a][i]==':')
				{
				i++;
				a1[1][0]=data[w][a][i];
			       //	break;
				}
			}
		flag=0;
		for(i=0;i<=7;i++)
			{
			if(arr2[i]=='\0')break;
			if(a1[flag][0]==arr2[i])
				{
				cnte[flag]=i;
				}
			if(i==7&&flag==0)
				{
				i=-1;
				flag=1;
				}
			}
		mrect(9,x5[0],cnte[0],x5[1],cnte[1]);
		setcolor(LIGHTGREEN);
		rectangle(x,y,x1,y1);
		setcolor(WHITE);
		outtextxy(x+2,y+10,data[w][a]);
		ch=getche();
		mrect(0,x5[0],cnte[0],x5[1],cnte[1]);
		setcolor(BLACK);
		outtextxy(x+2,y+10,data[w][a]);
		in=ch;
	if(in==13)
			{
			if(fl==5)
				{
				char tempr[1000];
				if(data[w][a][0]=='='&&data[w][a][1]=='S'&&data[w][a][2]=='U'&&data[w][a][3]=='M'&data[w][a][4]=='(')
					{
					strcpy(temp5[pass],data[w][a]);
					data[w][a][0]='5';
					data[w][a][1]='\0';
					s(w,a,x5[0],cnte[0],x5[1],cnte[1],3,2,pass);
					break;
					}
				else if(data[w][a][0]=='='&&data[w][a][1]=='A'&&data[w][a][2]=='V'&&data[w][a][3]=='G'&data[w][a][4]=='(')
					{
					strcpy(temp5[pass],data[w][a]);
					data[w][a][0]='5';
					data[w][a][1]='\0';
					s(w,a,x5[0],cnte[0],x5[1],cnte[1],3,3,pass);
					break;
					}
				else
					{
					s(0,0,0,0,0,0,4,0,pass);
					break;
					}

				//s(0,0,0,0,0,0,0,0,0);
				}
			else
				{

				if(data[w][a][0]=='='&&data[w][a][1]=='S'&&data[w][a][2]=='U'&&data[w][a][3]=='M'&data[w][a][4]=='(')
					{
					strcpy(temp5[tcl],data[w][a]);
					tcl++;
					data[w][a][0]='5';
					data[w][a][1]='\0';
					s(w,a,x5[0],cnte[0],x5[1],cnte[1],1,2,0);
					s(0,0,0,0,0,0,0,0,0);
					}
				else if(data[w][a][0]=='='&&data[w][a][1]=='A'&&data[w][a][2]=='V'&&data[w][a][3]=='G'&data[w][a][4]=='(')
					{
					strcpy(temp5[tcl],data[w][a]);
					tcl++;
					data[w][a][0]='5';
					data[w][a][1]='\0';
					s(w,a,x5[0],cnte[0],x5[1],cnte[1],1,3,0);
					s(0,0,0,0,0,0,0,0,0);
					}
				break;
				}

			}
		data[w][a][cn]=ch;
		if(in==8)
			{
			if(cn>0)
				{
				cn--;
				data[w][a][cn]='\0';
				}
			else if(cn==0)break;
			}

		else
			{
			cn++;
			data[w][a][cn]='\0';

			}

		}
	return 1;
	}

int enot(int x,int y,int x1,int y1,int w,int a)
	{
	int i,j,cn=0,in,pass=0;
	char ch,str,temp[50],ex=0,tempr[100];
	setcolor(BLACK);
	setcolor(LIGHTGREEN);
	rectangle(x,y,x1,y1);
	rectangle(x1+1,y1+1,x1-1,y1-1);
	setcolor(BLACK);
	rectangle(x1+2,y1+2,x1-2,y1-2);
	ex=a;
	ex--;
	pass=s(w,a,0,0,0,0,2,0,0);
	//data[w][a][cn]='\0';
	strcpy(tempr,data[w][a]);
	strupr(tempr);
	if(tempr[0]=='='&&tempr[1]=='C'&&tempr[2]=='O'&&tempr[3]=='U'&&tempr[4]=='N'&&tempr[5]=='T'&&tempr[6]=='(')
		{
		cn++;
		//data[w][a][cn]='\0';
	       //	strupr(data[w][a]);
		count(x,y,x1,y1,w,a,5,pass);
		//s(0,0,0,0,0,0,0);
		return 0;
		}
	if(tempr[0]=='='&&tempr[1]=='S'&&tempr[2]=='U'&&tempr[3]=='M'&&tempr[4]=='(')
		{
		cn++;
		//data[w][a][cn]='\0';
	       //	strupr(data[w][a]);
		sum(x,y,x1,y1,w,a,5,pass);
		//s(0,0,0,0,0,0,0);
		return 0;
		}
	if(tempr[0]=='='&&tempr[1]=='A'&&tempr[2]=='V'&&tempr[3]=='G'&&tempr[4]=='(')
		{
		cn++;
		//data[w][a][cn]='\0';
	       //	strupr(data[w][a]);
		sum(x,y,x1,y1,w,a,5,pass);
		//s(0,0,0,0,0,0,0);
		return 0;
		}

	for(i=x;i<=x1&&data[w][ex]!='\0';i++)
		{
		setcolor(BLACK);
		rectangle(x,y,i,y1);
		}
	setcolor(GREEN);
	cn=strlen(data[w][a]);
	setcolor(BLACK);
	outtextxy(x+7,y+10,data[w][a]);
	while(1)
		{
	       //	s(0,0,0,0,0,0,0);
		setcolor(WHITE);
		rectangle(x,0,x1,25);
		setcolor(WHITE);
		rectangle(0,y,30,y1);
		setcolor(BLACK);
		rectangle(x,23,x1,25);
		rectangle(x,22,x1,25);
		setcolor(BLACK);
		rectangle(28,y,30,y1);
		rectangle(27,y,30,y1);
		setcolor(LIGHTGREEN);
		rectangle(x,24,x1,25);
		rectangle(x,23,x1,25);
		rectangle(x,22,x1,25);
		setcolor(LIGHTGREEN);
		rectangle(29,y,30,y1);
		rectangle(28,y,30,y1);
		rectangle(27,y,30,y1);
		setcolor(LIGHTGREEN);
		rectangle(x,y,x1,y1);
		rectangle(x1+1,y1+1,x1-1,y1-1);
		setcolor(BLACK);
		rectangle(x1+2,y1+2,x1-2,y1-2);
		setcolor(WHITE);
		outtextxy(x+2,y+10,data[w][a]);
		strcpy(temp,data[w][a]);
		ch=getche();
		setcolor(BLACK);
		outtextxy(x+2,y+10,data[w][a]);
		in=ch;
		if(in==13)
			{
			s(0,0,0,0,0,0,0,0,0);
			break;
			}
		data[w][a][cn]=ch;
		if(in==8)
			{
			if(cn>0)
				{
				cn--;
				data[w][a][cn]='\0';
				}
			else if(cn==0)data[w][a][0]='\0';
			}

		else
			{
			//int rs=0;
			char tempr[100];
			cn++;
			data[w][a][cn]='\0';
			strcpy(tempr,data[w][a]);
			strupr(tempr);
			if(tempr[0]=='='&&tempr[1]=='C'&&tempr[2]=='O'&&tempr[3]=='U'&&tempr[4]=='N'&&tempr[5]=='T'&&tempr[6]=='(')
				{
				cn++;
				data[w][a][cn]='\0';
			       //	strupr(data[w][a]);
				count(x,y,x1,y1,w,a,0,0);
				//s(0,0,0,0,0,0,0);

				break;
				}
			if(tempr[0]=='='&&tempr[1]=='S'&&tempr[2]=='U'&&tempr[3]=='M'&&tempr[4]=='(')
				{
				cn++;
				data[w][a][cn]='\0';
			       //	strupr(data[w][a]);
				sum(x,y,x1,y1,w,a,0,0);
				//s(0,0,0,0,0,0,0);

				break;
				}
			if(tempr[0]=='='&&tempr[1]=='A'&&tempr[2]=='V'&&tempr[3]=='G'&&tempr[4]=='(')
				{
				cn++;
				data[w][a][cn]='\0';
			       //	strupr(data[w][a]);
				sum(x,y,x1,y1,w,a,0,0);
				//s(0,0,0,0,0,0,0);

				break;
				}
			}
		}
	rect();
	return 0;
	}
void nav()
	{
	char cm;
	int  y=25,y1=50,x=30,x1=100;
	int in,w=1,str,a=1,i,ex;

	while(1)
		{
		rect();
		data1(15);
	       //	s(0,0,0,0,0,0,0);
		setcolor(WHITE);
		rectangle(x,0,x1,25);
		setcolor(WHITE);
		rectangle(0,y,30,y1);
		setcolor(WHITE);
		rectangle(x,23,x1,25);
		rectangle(x,22,x1,25);
		rectangle(x1+1,y1+1,x1-1,y1-1);
		setcolor(WHITE);
		rectangle(28,y,30,y1);
		rectangle(27,y,30,y1);
		setcolor(LIGHTGREEN);
		rectangle(x,24,x1,25);
		rectangle(x,23,x1,25);
		rectangle(x,22,x1,25);
		setcolor(LIGHTGREEN);
		rectangle(29,y,30,y1);
		rectangle(28,y,30,y1);
		rectangle(27,y,30,y1);
		setcolor(LIGHTGREEN);
		rectangle(x,y,x1,y1);
		rectangle(x1+1,y1+1,x1-1,y1-1);
		setcolor(BLACK);
		rectangle(x1+2,y1+2,x1-2,y1-2);
		cm=getche();
		setcolor(BLACK);
		rectangle(x,23,x1,25);
		rectangle(x,22,x1,25);
		setcolor(BLACK);
		rectangle(28,y,30,y1);
		rectangle(27,y,30,y1);
		in=cm;
		if(in==27)exit();
		else if(in==13)
			{
			w--;
			a--;
			enot(x,y,x1,y1,w,a);
			s(0,0,0,0,0,0,0,0,0);
			w++;
			a++;
			}
		else if(in==72||in==80||in==77||in==75)
			{
			if(cm=='w'||in==72)
				{
				setcolor(BLACK);
				rectangle(x1+1,y1+1,x1-1,y1-1);
				rectangle(29,y,30,y1);
				rectangle(x+1,y+1,x1-1,y1-1);
				setcolor(WHITE);
				rectangle(30,y,30,y1);
				if(w==1)
					{
					w=18;
					y=25*w;
					y1=(25*w)+25;
					}
				else
					{
					w-=1;
					y=25*w;
					y1=(25*w)+25;
					}


				}
			if(cm=='s'||in==80)
				{
				setcolor(BLACK);
				rectangle(29,y,30,y1);
				rectangle(x+1,y+1,x1-1,y1-1);
				rectangle(x1+1,y1+1,x1-1,y1-1);
				setcolor(WHITE);
				rectangle(30,y,30,y1);
				if(w==18)
					{
					w=1;
					y=25*w;
					y1=(25*w)+25;
					}
				else
					{
					w++;
					y=25*w;
					y1=(25*w)+25;
					}

				}
			else if(cm=='a'||in==75)
				{
				setcolor(BLACK);
				rectangle(x+1,y+1,x1-1,y1-1);
				rectangle(x,24,x1,25);
				rectangle(x1+1,y1+1,x1-1,y1-1);
				rectangle(29,y,30,y1);
				setcolor(WHITE);
				rectangle(x,25,x1,25);
				if(a==1)
					{
					a=8;
					for(i=0;i<=a;i++)
						{
						setcolor(WHITE);
						rectangle(x,y,x1,y1);
						if(i==0)
							{
							setcolor(GREEN);
							rectangle(x,y,x1,y1);
							x=30;
							x1=100;
							continue;
							}
						else if(i==a)break;
						x1+=70;
						x+=70;
						}
					}
				else
					{
					a--;
					for(i=0;i<=a;i++)
						{
						setcolor(WHITE);
						rectangle(x,y,x1,y1);
						if(i==0)
							{
							x=30;
							x1=100;
							continue;
							}
						else if(i==a)break;
						x1+=70;
						x+=70;
						}
					}

				}
			else if(cm=='d'||in==77)
				{
				setcolor(BLACK);
				rectangle(x,24,x1,25);
				rectangle(x1+1,y1+1,x1-1,y1-1);
				rectangle(x+1,y+1,x1-1,y1-1);
				setcolor(WHITE);
				rectangle(x,25,x1,25);
				if(a==8)
					{
					a=1;
					for(i=0;i<=a;i++)
						{
						setcolor(WHITE);
						rectangle(x,y,x1,y1);
						if(i==0)
							{
							x=30;
							x1=100;
							continue;
							}
						else if(i==a)break;
						x1+=70;
						x+=70;
						}
					}
				else
					{
					a++;
					for(i=0;i<=a;i++)
						{
						setcolor(WHITE);
						rectangle(x,y,x1,y1);
						if(i==0)
							{
							x=30;
							x1=100;
							continue;
							}
						else if(i==a)break;
						x1+=70;
						x+=70;
						}
					}
				}

			}

		}
	}
void an()
	{
	int x,y,flag=1,i,j,loop,cl=1;
	int ls=0;
	x=getmaxx()/2;
	y=getmaxy()/2;
	loop=y-20;
	while(1)
		{
		up:
		if(cl==15)cl=1;
		cl++;
		for(i=190;i<=240;i++)
			{
			setcolor(cl);
			circle(x,y,i);
			delay(50);
			}
		cl++;
		for(i=190;i<=240;i++)
			{
			setcolor(cl);
			circle(x,y,i);
			delay(50);
			}
		if(flag)
			{
			setcolor(WHITE);
			settextstyle(7,0,5);
			outtextxy(x-130,y-20,"EXCEL IN 'C'");
			if(cl==3)
				goto up;
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
			setcolor(YELLOW);
			settextstyle(7,0,4);
			outtextxy(x-160,y-20,"Name :Anand Dubey");
			outtextxy(x-160,y+10,"Roll No :822110");
			flag=0;
			}
		if(ls==5)break;
		ls++;
		}

	getch();
	}

void main()
	{
	int gd=DETECT,gm;
	int i,j,l;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  //	an();
	for(j=0;j<=17;j++)
			{
			for(i=0;i<=7;i++)
				{
				for(l=0;l<=99;l++)
					{
					data[j][i][l]='\0';
					}
				}
			}
	cleardevice();
	nav();
	rect();
	getch();
	closegraph();
	}
