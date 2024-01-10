#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
char data[18][8][100];
char sen[1000],temp5[100][100];
char rpl[1000]={'\0'},fr[1000]={'\0'};
char copy[100]={'\0'},paste[100]={'\0'};
char cut[100]={'\0'};
int dlib,tcl=0;

void srp(int cl)
	{
	int i,j,l,mn[10];
	int w[100],a[100],cn=0,rs=0;
	int len;
	for(i=0;i<=99;i++)
		{
		w[i]=-1;
		a[i]=-1;
		}
	cn=0;
	for(i=0;i<=16;i++)
		{
		for(j=0;j<=7;j++)
			{
			int pass;
			rs=strcmp(data[i][j],sen);
			pass=s(i,j,0,0,0,0,2,0,0);
			if(pass!=-500)continue;
			if(strstr(data[i][j],sen)!=NULL||rs==0)
				{
				w[cn]=i;
				w[cn]++;
				a[cn]=j;
				a[cn]++;
				cn++;
				}
			}
		}
	for(l=0;l<=cn||w[l]!=-1;l++)
		{
		int y=25,y1=50,x=30,x1=100;
		for(i=0;i<=a[l];i++)
			{
			if(i==0)
				{
				x=30;
				x1=100;
				continue;
				}
			if(l==0&&i==0)
				{
				mn[0]=x;
				mn[1]=y;
				mn[2]=x1;
				mn[3]=y1;
				}
			else if(i==a[l])break;
			x1+=70;
			x+=70;
			}
		y=25*w[l];
		y1=(25*w[l])+25;
		if(cl)
			{
			setcolor(14);
			}
		else
			{
			setcolor(8);
			}
		rectangle(x,y,x1,y1);
		}

	}
void srrd()
	{
	int i,j,l,mn[10],len=0;
	int w[100],a[100],rs=0;
	for(i=0;i<=99;i++)
		{
		w[i]=-1;
		a[i]=-1;
		}
	for(i=0;i<=16;i++)
		{
		for(j=0;j<=7;j++)
			{
			rs=strcmp(data[i][j],fr);
			if(strstr(data[i][j],fr)!=NULL||rs==0)
				{
				int flag=0,fl=0,loop,mlen,pass;
				char temp45[1000]={'\0'};
				len=strlen(fr);
				mlen=strlen(data[i][j]);
				//mlen--;
				strcpy(temp45,data[i][j]);
				pass=s(i,j,0,0,0,0,2,0,0);
				if(pass!=-500)continue;
			       // mlen--;
				for(l=0;l<=mlen;l++)
					{
					char arr2[1000]={'\0'};
					int cr7=0,m,temp=0;
					flag=0;
					temp=strlen(fr);
					temp--;
				       //	if()
					for(m=0;m<=l;m++)
						{
					  /*	if(l==mlen)
								{
								printf("%c",fr[cr7]);
								}
					    */	if(temp45[m]==fr[cr7])
							{
							flag++;

							if(flag==len)
								{
								break;
								}
							if(cr7==temp)
								{
								cr7=0;
								}
							else
								{
								cr7++;
								}
							continue;
							}
						else
							{
							flag=0;
							}
						if(cr7==temp)
							{
							cr7=0;
							}
						else
							{
							cr7++;
							}
						}

					if(flag==len)
						{
						cr7=0;
						arr2[0]='\0';
					     //	printf("i intered");
					       //	 getch();
						gotoxy(20,20);
						for(loop=l+1;loop<=mlen;loop++)
							{
							fl=1;
							arr2[cr7]=temp45[loop];
							cr7++;
							}
						if(len==1)
							{
							temp45[l]='\0';
							}
						else
							{
							int test=0;
							test=l-len;
							test++;
							temp45[test]='\0';
							}
						arr2[cr7]='\0';
						strcat(temp45,rpl);
						strcat(temp45,arr2);
						mlen=strlen(temp45);
						}
					}
				if(fl)
					{
					data[i][j][0]='\0';
					strcpy(data[i][j],temp45);
					}
				}
			}
		}
	}
void rrd()
	{
	int i;
	int cn=0,in;
	char arr[100]={'\0'},ch;
	strcpy(fr,sen);
	setfillstyle(SOLID_FILL,BLACK);
	bar(380,0,590,25);
	setcolor(LIGHTGREEN);
	rectangle(380,0,590,25);
	while(1)
		{
		if(cn==1)
			{
			setcolor(0);
			outtextxy(385,10,"replace here");
			}
		if(cn==0)
			{
			setcolor(8);
			outtextxy(385,10,"replace here");
			}

		else
			{
			setcolor(15);
			outtextxy(385,10,arr);
			}
		if(cn>0)
			{
			rpl[0]='\0';
			strcpy(rpl,arr);
			}
		if(cn==0)
			{
			rpl[0]='\0';
			strcpy(rpl,"qwertyuiop[]\asdfghjkl;'zxcvbn,.//");
			}
		setcolor(LIGHTGREEN);
		rectangle(30,0,120,0);
		ch=getche();
		in=ch;
		setcolor(0);
		outtextxy(385,10,arr);
		if(cn<=23)
			{
			if(in>=21)
				{
				arr[cn]=ch;
				}
			else if(in==8||in==13);
			else
				{
				continue;
				}
			}
		if(in==27)
			{
			setfillstyle(SOLID_FILL,BLACK);
			bar(30,0,240,25);
			bar(380,0,590,25);
			break;
			}
		if(in==13)
			{
			setcolor(0);
			outtextxy(385,10,"replace here");
			srrd();
			setfillstyle(SOLID_FILL,BLACK);
			bar(0,0,639,479);
			break;
			}
		else if(in==8)
			{
			if(cn>0)
				{
				cn--;
				arr[cn]='\0';
				}
			else
				{
				arr[0]=' ';
				}
			}
		else
			{
			if(cn<=23)
				{
				cn++;
				arr[cn]='\0';
				}
			}
		}
	}
void frd()
	{
	int i;
	int cn=0,in;
	char arr[100]={'\0'},ch;
	setfillstyle(SOLID_FILL,BLACK);
	bar(30,0,240,25);
	bar(380,0,590,25);
	setcolor(LIGHTGREEN);
	rectangle(30,0,240,25);
	setcolor(WHITE);
	rectangle(380,0,590,25);
	while(1)
		{
		if(cn==1)
			{
			setcolor(0);
			outtextxy(35,10,"find here");
			}
		if(cn==0)
			{
			setcolor(8);
			outtextxy(35,10,"find here");
			outtextxy(385,10,"Replace here");
			}

		else
			{
			setcolor(15);
			outtextxy(35,10,arr);
			}
		if(cn>0)
			{
			sen[0]='\0';
			strcpy(sen,arr);
			}
		if(cn==0)
			{
			sen[0]='\0';
			strcpy(sen,"qwertyuiop[]\asdfghjkl;'zxcvbn,.//");
			}
		if(cn!=0)
			{
			srp(1);
			}
		setcolor(LIGHTGREEN);
		rectangle(30,0,240,25);
		setcolor(WHITE);
		rectangle(380,0,590,25);
	//	setcolor(cl);
	  //	rectangle(30,0,120,0);
		ch=getche();

		in=ch;
		setcolor(0);
		outtextxy(35,10,arr);
		if(cn<=23)
			{
			if(in>=21)
				{
				arr[cn]=ch;
				}
			else if(in==8||in==13||in==27);
			else
				{
				continue;
				}
			}
		if(in==27)
			{
			setfillstyle(SOLID_FILL,BLACK);
			bar(30,0,240,25);
			bar(380,0,590,25);
			break;
			}
		if(in==13)
			{
			if(cn!=0)
				{
				setcolor(0);
				}
			else setcolor(8);
			outtextxy(35,10,"find here");
			if(cn!=0)
				{
				setcolor(15);
				outtextxy(35,10,arr);
				}
			setcolor(8);
			outtextxy(385,10,"Replace here");
			rrd();
			setfillstyle(SOLID_FILL,BLACK);
			bar(30,0,240,25);
			bar(380,0,590,25);
			break;
			}
		else if(in==8)
			{
			if(cn>0)
				{
				cn--;
				arr[cn]='\0';
				}
			else
				{
				arr[0]=' ';
				}
			}
		else
			{
			if(cn<=23)
				{
				cn++;
				arr[cn]='\0';
				}
			}
		if(cn>=0)
			{
			srp(0);
			}
		}
	}
void srd()
	{
	int i;
	int cn=0,in;
	char arr[100]={'\0'},ch;
	setfillstyle(SOLID_FILL,BLACK);
	bar(380,0,590,25);
	setcolor(LIGHTGREEN);
	rectangle(380,0,590,25);
	while(1)
		{
		if(cn==1)
			{
			setcolor(0);
			outtextxy(385,10,"find here");
			}
		if(cn==0)
			{
			setcolor(8);
			outtextxy(385,10,"find here");
			}

		else
			{
			setcolor(15);
			outtextxy(385,10,arr);
			}
		if(cn>0)
			{
			sen[0]='\0';
			strcpy(sen,arr);
			}
		if(cn==0)
			{
			sen[0]='\0';
			strcpy(sen,"qwertyuiop[]\asdfghjkl;'zxcvbn,.//");
			}
		if(cn!=0)
			{
			srp(15);
			}
		setcolor(15);
		rectangle(30,0,120,0);
		ch=getche();
		if(cn>=0)
			{
			srp(0);
			}
		in=ch;
		setcolor(0);
		outtextxy(385,10,arr);
		if(cn<=23)
			{
			if(in>=21)
				arr[cn]=ch;
			else if(in==8||in==13);
			else
				{
				continue;
				}
			}
		if(in==13)
			{
			setcolor(0);
			outtextxy(385,10,"find here");
			break;
			}
		else if(in==8)
			{
			if(cn>0)
				{
				cn--;
				arr[cn]='\0';
				}
			else
				{
				arr[0]=' ';
				}
			}
		else
			{
			if(cn<=23)
				{
				cn++;
				arr[cn]='\0';
				}
			}
		}
	}
void rect()
	{
	int i,j,y=0,y1=25,x=0,x1=50,gx=50,gy=12+25;
	int ex=0,lx=0,lx1=0,ly=0,ly1=0;
	char str[3];
	char lib4[10][500] ;
	setcolor(DARKGRAY);
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
				{
				if(j!=18)
					rectangle(x,y,x1,y1);
				}
			if(j==18&&i==0)
				{
				lx=x;
				ly=y;
			  //	ly1=y1;
				}
			else if(j==18&&i==8)
				{
				ly1=y1;
				lx1=x1;
				}

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
	setcolor(15);
	rectangle(30,25,30,450);
	setcolor(15);
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
	settextstyle(0,0,0);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(lx,ly,lx1,ly1);
	setcolor(RED);
	settextstyle(5,0,4);
	outtextxy(10,460,"CTR+N");
	outtextxy(100,460,"CTR+O");
	outtextxy(200,460,"CTR+S");
	setcolor(BLACK);
	outtextxy(60,460,"New");
	outtextxy(150,460,"Open");
	outtextxy(250,460,"Save");
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
	int y5=0,y6=25,x5=0,x6=50;
	int x=50,y1=25,y=0,ex,b;
      //	int flag=0;
	for(j=0;j<=17;j++)
		{
		x=25;
		x5=0;
		x6=50;
		for(i=0;i<=7;i++)
			{
			int lg,ly;
			lg=i;
			lg++;
			setcolor(cl);
			if(i==0)
				{
				outtextxy(x+7,y1+10,data[j][i]);
				x=30;
				x5=30;
				x6=100;
				if(data[j][lg][0]!='\0')
					{
					int y10,y11,x10;
					y10=y5+25;
					y11=y6+25;
					x10=x5+70;
					//x11=x6+140;
					setfillstyle(SOLID_FILL,BLACK);
					bar(x10,y10,639,y11);
				 //	flag=1;
					}
				continue;
				}

			x+=70;
			x5+=70;
			x6+=70;
			/*if(data[j][i][0]!='\0')
				{
				setfillstyle(SOLID_FILL,BLACK);
				bar(x,y,x6+x,y+25);
				}   */
			outtextxy(x+7,y1+10,data[j][i]);
			ex=i;
			ex--;
			if(data[j][lg][0]!='\0')
				{
				int y10,y11,x10;
				y10=y5+25;
				y11=y6+25;
				x10=x5+70;
				//x11=x6+140;
				setfillstyle(SOLID_FILL,BLACK);
				bar(x10,y10,639,y11);
			  //	flag=1;
				}
			//lg++;
			///printf("");

			}
	    //	flag=0;
		y+=25;
		y1+=25;
		y5+=25;
		y6+=25;
		}
	}
void barr()
	{
	int i,j,y=0,y1=25,x=0,x1=50;
	int ex=0;
	char str[3];
	char lib4[10][500] ;
	setcolor(DARKGRAY);
	settextstyle(0,0,0);
	for(j=0;j<=18;j++)
		{
		x=0;
		x1=30;
		for(i=0;i<=8;i++)
			{
			ex=i;
			ex--;
		     //	if(i==0||j==0)setcolor(WHITE);
		    //	else
		      //	setcolor(8);
			if(j==0&&i==0);
			else
				{
				if(j!=18)
					{
					setfillstyle(SOLID_FILL,BLACK);
					bar(x,y,x1,y1);
					data1(15);
					}
				}
			if(j==18&&i==0)
				{
		      //		lx=x;
			//	ly=y;
				}
			else if(j==18&&i==8)
				{
			      //	ly1=y1;
			       //	lx1=x1;
				}

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
			if(isdigit(data[i][j][0])||data[i][j][0]=='-'&&isdigit(data[i][j][1]))
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
			if(isdigit(data[i][j][0])||data[i][j][0]=='-'&&isdigit(data[i][j][1]))
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
int rlmax(int wl,int al,int w,int a,int w1,int a1)
	{
	int i,j,arr[100];
	int max=0,total=0;
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
			if(isdigit(data[i][j][0])||data[i][j][0]=='-'&&isdigit(data[i][j][1]))
				{
				arr[total]=atoi(data[i][j]);
				total++;
				continue;
				}
			else if(data[i][j][0]=='\0'||data[i][j][0]==' ')
				{
				continue;
				}
			else
				{
				strcpy(data[wl][al],"#ERROR");
				return 0;
				}
			}
		}
	//printf("1");
	total--;
	max=arr[0];
	for(i=0;i<=total;i++)
		{
		if(max<arr[i])
			{
			max=arr[i];
			}
		}
	sprintf(data[wl][al],"%d",max);
	rect();
	return 0;
	}
int rlmin(int wl,int al,int w,int a,int w1,int a1)
	{
	int i,j,arr[100];
	int min=0,total=0;
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
			if(isdigit(data[i][j][0])||data[i][j][0]=='-'&&isdigit(data[i][j][1]))
				{
				arr[total]=atoi(data[i][j]);
				total++;
				continue;
				}
			else if(data[i][j][0]=='\0'||data[i][j][0]==' ')
				{
			      //	sum+=0;
				continue;
				}
			else
				{
				strcpy(data[wl][al],"#ERROR");
				return 0;
				}
			}
		}
	//printf("1");
	total--;
	min=arr[0];
	for(i=0;i<=total;i++)
		{
		if(min>arr[i])
			{
			min=arr[i];
			}
		}
	sprintf(data[wl][al],"%d",min);
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
		return -500;
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
		else if(data[w[i][2]][a[i][2]][0]=='-'&&isdigit(data[w[i][2]][a[i][2]][1])&&orlib[i]==2||isdigit(data[w[i][2]][a[i][2]][0])&&orlib[i]==2||data[w[i][2]][a[i][2]][0]=='#'&&data[w[i][2]][a[i][2]][1]=='E'&&data[w[i][2]][a[i][2]][2]=='R'&&data[w[i][2]][a[i][2]][3]=='R'&data[w[i][2]][a[i][2]][4]=='O'&&data[w[i][2]][a[i][2]][5]=='R'&&orlib[i]==2)
			{
			data1(0);
			data[w[i][2]][a[i][2]][0]='\0';
			rlsum(w[i][2],a[i][2],w[i][0],a[i][0],w[i][1],a[i][1]);
			data1(15);
			}

		else if(data[w[i][2]][a[i][2]][0]=='-'&&isdigit(data[w[i][2]][a[i][2]][1])&&orlib[i]==3||isdigit(data[w[i][2]][a[i][2]][0])&&orlib[i]==3||data[w[i][2]][a[i][2]][0]=='#'&&data[w[i][2]][a[i][2]][1]=='E'&&data[w[i][2]][a[i][2]][2]=='R'&&data[w[i][2]][a[i][2]][3]=='R'&data[w[i][2]][a[i][2]][4]=='O'&&data[w[i][2]][a[i][2]][5]=='R'&&orlib[i]==3)
			{
			data1(0);
			data[w[i][2]][a[i][2]][0]='\0';
			rlavg(w[i][2],a[i][2],w[i][0],a[i][0],w[i][1],a[i][1]);
			data1(15);
			}
		else if(data[w[i][2]][a[i][2]][0]=='-'&&isdigit(data[w[i][2]][a[i][2]][1])&&orlib[i]==4||isdigit(data[w[i][2]][a[i][2]][0])&&orlib[i]==4||data[w[i][2]][a[i][2]][0]=='#'&&data[w[i][2]][a[i][2]][1]=='E'&&data[w[i][2]][a[i][2]][2]=='R'&&data[w[i][2]][a[i][2]][3]=='R'&data[w[i][2]][a[i][2]][4]=='O'&&data[w[i][2]][a[i][2]][5]=='R'&&orlib[i]==4)
			{
			data1(0);
			data[w[i][2]][a[i][2]][0]='\0';
			rlmax(w[i][2],a[i][2],w[i][0],a[i][0],w[i][1],a[i][1]);
			data1(15);
			}
		else if(data[w[i][2]][a[i][2]][0]=='-'&&isdigit(data[w[i][2]][a[i][2]][1])&&orlib[i]==5||isdigit(data[w[i][2]][a[i][2]][0])&&orlib[i]==5||data[w[i][2]][a[i][2]][0]=='#'&&data[w[i][2]][a[i][2]][1]=='E'&&data[w[i][2]][a[i][2]][2]=='R'&&data[w[i][2]][a[i][2]][3]=='R'&data[w[i][2]][a[i][2]][4]=='O'&&data[w[i][2]][a[i][2]][5]=='R'&&orlib[i]==5)
			{
			data1(0);
			data[w[i][2]][a[i][2]][0]='\0';
			rlmin(w[i][2],a[i][2],w[i][0],a[i][0],w[i][1],a[i][1]);
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
	int len=0,lx=0,x45,y45;
	setcolor(BLACK);
	setcolor(LIGHTGREEN);
	lx=x1;
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
		len=strlen(data[w][a]);
		if(len>=8)
			{
			int tr2=1,len2=0;
			tr2=8;
			rect();
			len2=0;
			setfillstyle(SOLID_FILL,0);
			bar(x,y,lx,y1);
			setcolor(DARKGRAY);
			rectangle(x,y,lx,y1);
			setcolor(0);
			rectangle(x+1,y1+1,lx-1,y1-1);
			setcolor(BLACK);
			rectangle(x1+2,y1+2,lx-2,y1-2);
			while(1)
				{
				if(len<tr2)break;
				else
					{
					len2++;
				       //	tr2++;
					tr2=8*len2;
					}
				}
			if(len<8)len=1;
			else
				len=len2;
			//len++;
			setcolor(0);

			//bar(x,y,lx,y1);
			lx=(len*70)+x;
			//setcolor(0);
		    //	 x1=lx;
			setfillstyle(SOLID_FILL,0);
			bar(x,y,lx,y1);
			setcolor(LIGHTGREEN);
			rectangle(x,y,lx,y1);
			rectangle(lx+1,y1+1,lx-1,y1-1);
			setcolor(BLACK);
			rectangle(lx+2,y1+2,lx-2,y1-2);
		     //	rectangle(lx-1,y-1,lx+1,y1+1);
			//flag++;
			//getch();
			//rect();
			}
		else if(len<8)
			{
			rect();
			lx=x1;
			setcolor(LIGHTGREEN);
			rectangle(x,y,lx,y1);

			}
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
	       //	setcolor(LIGHTGREEN);
	      //	rectangle(x,y,x1,y1);
		setcolor(WHITE);
		outtextxy(x+2,y+10,data[w][a]);
		setcolor(YELLOW);
		y45=y+8;
		len=strlen(data[w][a]);
		x45=len*8+x+2;
		line(x45,y45,x45,y45+10);
		ch=getche();
		mrect(0,x5[0],cnte[0],x5[1],cnte[1]);
		setcolor(BLACK);
		line(x45,y45,x45,y45+10);
		outtextxy(x+2,y+10,data[w][a]);
		in=ch;
		if(in==13)
			{
			if(cn==0)data[w][a][0]='\0';
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
		if(in>=21)
			{
			data[w][a][cn]=ch;
			}
		else if(in==8||in==13);
		else
			{
			continue;
			}
		if(in==8)
			{
			if(cn>0)
				{
				cn--;
				data[w][a][cn]='\0';
				}
			else if(cn==0)
				{
				data[w][a][0]=' ';
				data[w][a][1]='\0';
				}
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
	int len,lx=0,x45,y45;
	setcolor(BLACK);
	setcolor(LIGHTGREEN);
	lx=x1;
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
		len=strlen(data[w][a]);
		if(len>=8)
			{
			int tr2=1,len2=0;
			tr2=8;
			rect();
			len2=0;
			setfillstyle(SOLID_FILL,0);
			bar(x,y,lx,y1);
			setcolor(DARKGRAY);
			rectangle(x,y,lx,y1);
			setcolor(0);
			rectangle(x+1,y1+1,lx-1,y1-1);
			setcolor(BLACK);
			rectangle(x1+2,y1+2,lx-2,y1-2);
			while(1)
				{
				if(len<tr2)break;
				else
					{
					len2++;
				       //	tr2++;
					tr2=8*len2;
					}
				}
			if(len<8)len=1;
			else
				len=len2;
			//len++;
			setcolor(0);

			//bar(x,y,lx,y1);
			lx=(len*70)+x;
			//setcolor(0);
		    //	 x1=lx;
			setfillstyle(SOLID_FILL,0);
			bar(x,y,lx,y1);
			setcolor(LIGHTGREEN);
			rectangle(x,y,lx,y1);
			rectangle(lx+1,y1+1,lx-1,y1-1);
			setcolor(BLACK);
			rectangle(lx+2,y1+2,lx-2,y1-2);
		      //	rectangle(lx-1,y-1,lx+1,y1+1);
			//flag++;
			//getch();
			//rect();
			}
		else if(len<8)
			{
			rect();
			lx=x1;
			setcolor(LIGHTGREEN);
			rectangle(x,y,lx,y1);

			}
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
		//setcolor(LIGHTGREEN);
	       //	rectangle(x,y,x1,y1);

		setcolor(WHITE);
		outtextxy(x+2,y+10,data[w][a]);
		setcolor(YELLOW);
		y45=y+8;
		len=strlen(data[w][a]);
		x45=len*8+x+2;
		line(x45,y45,x45,y45+10);
		ch=getche();
		mrect(0,x5[0],cnte[0],x5[1],cnte[1]);
		setcolor(BLACK);
		line(x45,y45,x45,y45+10);
		outtextxy(x+2,y+10,data[w][a]);
		in=ch;
		if(in==13)
			{
			if(cn==0)data[w][a][0]='\0';
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
				else if(data[w][a][0]=='='&&data[w][a][1]=='M'&&data[w][a][2]=='A'&&data[w][a][3]=='X'&data[w][a][4]=='(')
					{
					strcpy(temp5[pass],data[w][a]);
					data[w][a][0]='5';
					data[w][a][1]='\0';
					s(w,a,x5[0],cnte[0],x5[1],cnte[1],3,4,pass);
					break;
					}
				else if(data[w][a][0]=='='&&data[w][a][1]=='M'&&data[w][a][2]=='I'&&data[w][a][3]=='N'&data[w][a][4]=='(')
					{
					strcpy(temp5[pass],data[w][a]);
					data[w][a][0]='5';
					data[w][a][1]='\0';
					s(w,a,x5[0],cnte[0],x5[1],cnte[1],3,5,pass);
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

					}
				else if(data[w][a][0]=='='&&data[w][a][1]=='M'&&data[w][a][2]=='A'&&data[w][a][3]=='X'&data[w][a][4]=='(')
					{
					strcpy(temp5[tcl],data[w][a]);
					tcl++;
					data[w][a][0]='5';
					data[w][a][1]='\0';
					s(w,a,x5[0],cnte[0],x5[1],cnte[1],1,4,0);
				    //	break;
					}
				else if(data[w][a][0]=='='&&data[w][a][1]=='M'&&data[w][a][2]=='I'&&data[w][a][3]=='N'&data[w][a][4]=='(')
					{
					strcpy(temp5[tcl],data[w][a]);
					tcl++;
					data[w][a][0]='5';
					data[w][a][1]='\0';
					s(w,a,x5[0],cnte[0],x5[1],cnte[1],1,5,0);
				    //	break;
					}
				s(0,0,0,0,0,0,0,0,0);
				break;
				}

			}
		if(in>=21)
			{
			data[w][a][cn]=ch;
			}
		else if(in==8||in==13);
		else
			{
			continue;
			}
		if(in==8)
			{
			if(cn>0)
				{
				cn--;
				data[w][a][cn]='\0';
				}
			else if(cn==0)
				{
				data[w][a][0]=' ';
				data[w][a][0]='\0';
				break;
				}
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
	int flag=0,len=0,lx,flag1=0;
	int len3=0,y45=0,x45=0;
	char ch,str,temp[50],ex=0,tempr[100];
	data1(0);
	data1(15);
	setcolor(BLACK);
	setcolor(LIGHTGREEN);
	rectangle(x,y,x1,y1);
	rectangle(x1+1,y1+1,x1-1,y1-1);
	setcolor(BLACK);
	rectangle(x1+2,y1+2,x1-2,y1-2);
	ex=a;
	ex--;
	lx=x1;
	pass=s(w,a,0,0,0,0,2,0,0);
	//data[w][a][cn]='\0';
	if(pass!=-500)flag=1;
	strcpy(tempr,data[w][a]);
	strupr(tempr);
	if(tempr[0]=='='&&tempr[1]=='C'&&tempr[2]=='O'&&tempr[3]=='U'&&tempr[4]=='N'&&tempr[5]=='T'&&tempr[6]=='('&&flag==1)
		{
		cn++;
		//data[w][a][cn]='\0';
	       //	strupr(data[w][a]);
		count(x,y,x1,y1,w,a,5,pass);
		//s(0,0,0,0,0,0,0);
		return 0;
		}
	if(tempr[0]=='='&&tempr[1]=='S'&&tempr[2]=='U'&&tempr[3]=='M'&&tempr[4]=='('&&flag==1)
		{
		cn++;
		//data[w][a][cn]='\0';
	       //	strupr(data[w][a]);
		sum(x,y,x1,y1,w,a,5,pass);
		//s(0,0,0,0,0,0,0);
		return 0;
		}
	if(tempr[0]=='='&&tempr[1]=='A'&&tempr[2]=='V'&&tempr[3]=='G'&&tempr[4]=='('&&flag==1)
		{
		cn++;
		//data[w][a][cn]='\0';
	       //	strupr(data[w][a]);
		sum(x,y,x1,y1,w,a,5,pass);
		//s(0,0,0,0,0,0,0);
		return 0;
		}
	if(tempr[0]=='='&&tempr[1]=='M'&&tempr[2]=='A'&&tempr[3]=='X'&&tempr[4]=='('&&flag==1)
		{
		cn++;
		//data[w][a][cn]='\0';
	       //	strupr(data[w][a]);
		sum(x,y,x1,y1,w,a,5,pass);
		//s(0,0,0,0,0,0,0);
		return 0;
		}
	if(tempr[0]=='='&&tempr[1]=='M'&&tempr[2]=='I'&&tempr[3]=='N'&&tempr[4]=='('&&flag==1)
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
	y45=y;
	while(1)
		{

	       //	s(0,0,0,0,0,0,0);
	      //	rect();
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

		setcolor(WHITE);

		len=strlen(data[w][a]);
		if(len>=8)
			{
			int tr2=1,len2=0;
			tr2=8;
			rect();
			len2=0;
			setfillstyle(SOLID_FILL,0);
			bar(x,y,lx,y1);
			setcolor(DARKGRAY);
			rectangle(x,y,lx,y1);
			setcolor(0);
			rectangle(x+1,y1+1,lx-1,y1-1);
			setcolor(BLACK);
			rectangle(x1+2,y1+2,lx-2,y1-2);
			while(1)
				{
				if(len<tr2)break;
				else
					{
					len2++;
				       //	tr2++;
					tr2=8*len2;
					}
				}
			if(len<8)len=1;
			else
				len=len2;
			//len++;
			setcolor(0);

			//bar(x,y,lx,y1);
			lx=(len*70)+x;
			//setcolor(0);
		    //	 x1=lx;
			setfillstyle(SOLID_FILL,0);
			bar(x,y,lx,y1);
			setcolor(LIGHTGREEN);
			rectangle(x,y,lx,y1);
			rectangle(lx+1,y1+1,lx-1,y1-1);
			setcolor(BLACK);
			rectangle(lx+2,y1+2,lx-2,y1-2);
		      //	rectangle(lx-1,y-1,lx+1,y1+1);
			//flag++;
			//getch();
			//rect();
			}
		else if(len<8)
			{
			rect();
			lx=x1;
			setcolor(LIGHTGREEN);
			rectangle(x,y,lx,y1);

			}
		setcolor(15);
		outtextxy(x+2,y+10,data[w][a]);
		strcpy(temp,data[w][a]);
		len=strlen(data[w][a]);
		setcolor(YELLOW);
		//x45=x;
		y45=y+8;
		x45=len*8+x+2;
		line(x45,y45,x45,y45+10);
		ch=getche();
		setcolor(BLACK);
		outtextxy(x+2,y+10,data[w][a]);
		line(x45,y45,x45,y45+10);
		in=ch;
		if(in==13)
			{
			setfillstyle(SOLID_FILL,0);
			bar(x,y,lx+20,y1+30);
			rect();
			data1(15);
			s(0,0,0,0,0,0,0,0,0);
			break;
			}
		if(in>=21)
			{
			data[w][a][cn]=ch;
			}
		else if(in==8||in==13);
		else
			{
			continue;
			}
		if(in==8)
			{
			if(cn>0)
				{
				cn--;
				data[w][a][cn]='\0';
				}
			else if(cn==0)
				{
				data[w][a][0]=' ';
				data[w][a][0]='\0';
				}
			}

		else
			{
			char tempr[100];
			cn++;
			data[w][a][cn]='\0';
			strcpy(tempr,data[w][a]);
			strupr(tempr);
			if(tempr[0]=='='&&tempr[1]=='C'&&tempr[2]=='O'&&tempr[3]=='U'&&tempr[4]=='N'&&tempr[5]=='T'&&tempr[6]=='(')
				{
				cn++;
				data[w][a][cn]='\0';
				count(x,y,x1,y1,w,a,0,0);
				break;
				}
			if(tempr[0]=='='&&tempr[1]=='S'&&tempr[2]=='U'&&tempr[3]=='M'&&tempr[4]=='(')
				{
				cn++;
				data[w][a][cn]='\0';
				sum(x,y,x1,y1,w,a,0,0);
				break;
				}
			if(tempr[0]=='='&&tempr[1]=='A'&&tempr[2]=='V'&&tempr[3]=='G'&&tempr[4]=='(')
				{
				cn++;
				data[w][a][cn]='\0';
				sum(x,y,x1,y1,w,a,0,0);
				break;
				}
			if(tempr[0]=='='&&tempr[1]=='M'&&tempr[2]=='A'&&tempr[3]=='X'&&tempr[4]=='(')
				{
				cn++;
				data[w][a][cn]='\0';
				sum(x,y,x1,y1,w,a,0,0);
				break;
				}
			if(tempr[0]=='='&&tempr[1]=='M'&&tempr[2]=='I'&&tempr[3]=='N'&&tempr[4]=='(')
				{
				cn++;
				data[w][a][cn]='\0';
				sum(x,y,x1,y1,w,a,0,0);
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
	char rev_d[50][100];
	int rev_w[100],rev_a[100];
	int rev_ch=0;
	char fr_d[50][100];
	int fr_w[50],fr_a[50];
	int fr_ch=0;
	while(1)
		{
		rect();
		setcolor(15);
		rectangle(x,0,x1,25);
		setcolor(15);
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
		in=cm;
		if(in==6)
			{
			srd(15);
			}
		else if(in==18)
			{
			frd(15);
			data1(15);
			}
		else if(in==3)
			{
			w--;
			a--;
			cut[0]='\0';
			copy[0]='\0';
			strcpy(copy,data[w][a]);
			w++;
			a++;
			}
		else if(in==24)
			{
			w--;
			a--;
			setfillstyle(SOLID_FILL,BLACK);
			bar(x,y,x1,y1);
			rev_d[rev_ch][0]='\0';

			strcpy(rev_d[rev_ch],data[w][a]);
			//printf("%s",data[w][a]);
			//if(re)
			rev_w[rev_ch]=w;
			rev_a[rev_ch]=a;
			rev_ch++;
			cut[0]='\0';
			copy[0]='\0';
			strcpy(cut,data[w][a]);
			data[w][a][0]='\0';
			//data1(15);
			s(0,0,0,0,0,0,0,0,0);
			w++;
			a++;
			}
		else if(in==25)
			{
			if(fr_ch>0)
				{
			      //	setfillstyle(SOLID_FILL,BLACK);
			      //	bar(x,y,x1,y1);
				fr_ch--;
				//******************************
				rev_d[rev_ch][0]='\0';
				strcpy(rev_d[rev_ch],data[fr_w[fr_ch]][fr_a[fr_ch]]);
				rev_w[rev_ch]=fr_w[fr_ch];
				rev_a[rev_ch]=fr_a[fr_ch];
				rev_ch++;
				//*******************************
				data[fr_w[fr_ch]][fr_a[fr_ch]][0]='\0';

				strcpy(data[fr_w[fr_ch]][fr_a[fr_ch]],fr_d[fr_ch]);
				data1(15);
				s(0,0,0,0,0,0,0,0,0);
				}
			if(fr_ch==0)
				{
			     //	setfillstyle(SOLID_FILL,BLACK);
			       //	bar(x,y,x1,y1);
				//fr_ch--;
				//******************************
				rev_d[rev_ch][0]='\0';
				strcpy(rev_d[rev_ch],data[fr_w[fr_ch]][fr_a[fr_ch]]);
				rev_w[rev_ch]=fr_w[fr_ch];
				rev_a[rev_ch]=fr_a[fr_ch];
				//rev_ch++;
				//*******************************
				data[fr_w[fr_ch]][fr_a[fr_ch]][0]='\0';
				strcpy(data[fr_w[fr_ch]][fr_a[fr_ch]],fr_d[fr_ch]);
				}
			setfillstyle(SOLID_FILL,BLACK);
			bar(0,0,679,439);
			data1(15);
			s(0,0,0,0,0,0,0,0,0);
			}
		else if(in==26)
			{
			if(rev_ch>0)
				{
				setfillstyle(SOLID_FILL,BLACK);
				bar(x,y,x1,y1);
				rev_ch--;
				//**********************
				fr_d[fr_ch][0]='\0';
				strcpy(fr_d[fr_ch],data[rev_w[rev_ch]][rev_a[rev_ch]]);
				fr_w[fr_ch]=rev_w[rev_ch];
				fr_a[fr_ch]=rev_a[rev_ch];
				fr_ch++;
				//***********************
				data[rev_w[rev_ch]][rev_a[rev_ch]][0]='\0';
				strcpy(data[rev_w[rev_ch]][rev_a[rev_ch]],rev_d[rev_ch]);
				data1(15);
				s(0,0,0,0,0,0,0,0,0);
				}
			 else if(rev_ch==0)
				{
				data[rev_w[rev_ch]][rev_a[rev_ch]][0]='\0';
				}
			setfillstyle(SOLID_FILL,BLACK);
			bar(0,0,679,439);
			data1(15);
			s(0,0,0,0,0,0,0,0,0);
			}
		else if(in==22)
			{
			w--;
			a--;
			setfillstyle(SOLID_FILL,BLACK);
			bar(x,y,x1,y1);
			rev_d[rev_ch][0]='\0';
			strcpy(rev_d[rev_ch],data[w][a]);
			rev_a[rev_ch]=a;
			rev_w[rev_ch]=w;
			rev_ch++;
			if(cut[0]!='\0')
				{
				strcat(data[w][a],cut);
				cut[0]='\0';
				}
			else
				{
				strcat(data[w][a],copy);
				}
			s(0,0,0,0,0,0,0,0,0);
			data1(15);
			w++;
			a++;
			}
		setcolor(BLACK);
		rectangle(x,23,x1,25);
		rectangle(x,22,x1,25);
		setcolor(BLACK);
		rectangle(28,y,30,y1);
		rectangle(27,y,30,y1);
		if(in==27)exit(0);

		else if(in==13)
			{
			w--;
			a--;
			rev_d[rev_ch][0]='\0';
			strcpy(rev_d[rev_ch],data[w][a]);
			rev_w[rev_ch]=w;
			rev_a[rev_ch]=a;
			rev_ch++;
			enot(x,y,x1,y1,w,a);
			rev_d[rev_ch][0]='\0';
			data1(15);
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
					w=17;
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
				if(w==17)
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
	int gd=0,gm;
	int i,j,l;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	for(j=0;j<=17;j++)
			{
			for(i=0;i<=7;i++)
				{
				for(l=0;l<=99;l++)
					{
					data[j][i][l]='\0';
				       /*	rev_a[l]=-500;
					rev_w[l]=-500;   */
					}
				}
			}
	cleardevice();
	nav();
	rect();
	getch();
	closegraph();
	}
