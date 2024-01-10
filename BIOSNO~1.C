#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<bios.h>
#define enter 0x1c0d
#define bksp 0xe08
#define esc 0x11b
#define L 0x4B00
#define R 0x4D00
#define UP 0x4800
#define DO 0x5000
void notepad();
int entry(int*,int*,int*,int*,int*,int*,int*);
void move(int*,int*,int*,int*,int*,int*,int*,int);
void bk(int*,int*,int*,int*,int*,int*,int*);
void bk0(int*,int*,int*,int*,int*,int*,int*);
void bk1(int*,int*,int*,int*,int*,int*,int*);
void newline(int*,int*,int*,int*,int*,int*,int*);
void store(int*,int*,int*,int*,char);
void print(int,int,int,int,int,int,int);
void H(int*,int*,int*,int*);
void P(int*,int*,int*,int*,int*);
void K(int*,int*,int*);
void M(int*,int*,int*,int*);
void whdl();
int keyv(int);
void datarm();
char data[100][500]={'\0'};
void main()
	{
	datarm();
	notepad();
	}
void datarm()
	{
	int i,j;
	for(i=0;i<=99;i++)
		{
		for(j=0;j<=499;j++)
			{
			data[i][j]='\0';
			}
		}
	}
void whdl()
	{
	delay(25);
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
void print(int linecn,int max,int min,int minl,int maxl,int cn,int finalcn)
	{
	int i,j,l;
	cn--;
	if(max>77)
		{
      //		textcolor(BLACK);
	   //	cprintf("max=%d",max);
		min++;
	 //	getch();
		}
       //	max-=2;
	whdl();
	textbackground(LIGHTGRAY);
	textcolor(BLACK);
	printf("\033[1;%dH",1*0);
	for(i=0;i<=72;i++)
		{
		cprintf(" ");
		if(i==35)
			cprintf("Notepad");
		}
	for(i=minl;i<=maxl&&i<=finalcn;i++)
		{
		int len;
		int flag=0;
		len=strlen(data[i]);
		len--;
		printf("\n ");
		l=cn;
		l++;
		flag=0;
		if(linecn==i&&cn==-1&&flag==0)
			{
			textcolor(YELLOW);
			textbackground(LIGHTBLUE);
			cprintf("%c",179);
			flag=1;
			}
		if(linecn==i&&l==min&&flag==0)
			{
			textcolor(YELLOW);
			textbackground(LIGHTBLUE);
			cprintf("%c",179);
			flag=1;
			}
		for(j=min;j<=max&&j<=len;j++)
			{

			textcolor(LIGHTGREEN);
			textbackground(LIGHTBLUE);
			cprintf("%c",data[i][j]);
			if(linecn==i&&cn==j&&flag==0)
				{
				textcolor(YELLOW);
				cprintf("%c",179,min,cn);
				}
			}
		l=min+76;
		j--;
		if(linecn==i)
			{
			j++;
			}
		for(j=j;j<=l;j++)
			{
			cprintf(" ");
			}
		}
	for(j=0;j<=70&&linecn>minl&&finalcn<maxl;j++)
		{
		cprintf(" ");
		}
	//printf("\r");
	textcolor(4);
	textbackground(LIGHTBLUE);
	printf("\033[26;%dH",1*0);
	printf("\t\t\t\t\t\t\t\t");

	cprintf(" ");
	textbackground(LIGHTBLUE);
	textcolor(BLUE);
	cprintf("| ");
	cn++;
	max+=2;
	//printf("\n");
	//cprintf("cn=%d line=%d max=%d min=%d finalcn=%d minl=%d maxl=%d",cn,linecn,max,min,finalcn,minl,maxl);
	}
void notepad()
	{
	int  linecn=0;
	int max=77,min=0;
	int finalcn=0;
	int minl=0,maxl=22;
	int cn=0;
	int i;
	textbackground(LIGHTBLUE);
	textcolor(BLUE);
	printf("| ");
	clrscr();
	textbackground(LIGHTGRAY);
	textcolor(BLACK);
	for(i=0;i<=72;i++)
		{
		cprintf(" ");
		if(i==35)
			cprintf("Notepad");
		}
	textbackground(LIGHTBLUE);
	printf("\n");
	textcolor(YELLOW);
	cprintf(" %c",179);

	while(1)
		{
		if(kbhit())
			{
			entry(&linecn,&max,&min,&minl,&maxl,&finalcn,&cn);
			print(linecn,max,min,minl,maxl,cn,finalcn);
			}
		}
	}
void k(int *min,int *max,int *cn)
	{
	int max1;
	max1=*max-78;
	if(*cn>0)
		{
		*cn-=1;
		if(*cn==max1)
			{
			*min-=1;
			*max-=1;
			if(*min<0)*min=0;
			}
		}
	if(*cn<0)*cn=0;
	}
void M(int *min,int *max,int *cn,int *linecn)
	{
	int len;
	len=strlen(data[*linecn]);
	if(*cn<len)
		{
		*cn+=1;
		if(*cn==*max)
			{
			*min+=1;
			*max=*min+78;
			}
		}
	}
void H(int *minl,int *maxl,int *linecn ,int *cn)
	{
	int max1;
	int len;
	max1=*minl-1;
	if(*linecn>0)
		{
		*linecn-=1;
		if(*linecn==max1&&max1>-1)
			{
			*minl-=1;
			*maxl=*minl+22;
			}
		}
	if(*minl<0)
		{
		*minl=0;
		*maxl=*minl+22;
		}
	if(*linecn<0)*linecn=0;
	len=strlen(data[*linecn]);
	if(*cn>len)*cn=len;
       //	textcolor(15);
       //	cprintf("linecn :%d \t *min=%d",*linecn,*minl);
       //	delay(200);
	}
void P(int *minl,int *maxl,int *linecn ,int *cn,int *finalcn)
	{
	int max1;
	int len;
	max1=*maxl;
	if(*linecn<*finalcn)
		{
		*linecn+=1;
		if(*linecn==max1&&max1<finalcn)
			{
			*minl+=1;
			*maxl=*minl+22;
			}
		}
	if(*linecn<0)*linecn=0;
	len=strlen(data[*linecn]);
	if(*cn>len)*cn=len;
	}
void move(int *linecn,int *max,int *min,int *minl,int *maxl,int *finalcn,int *cn,int key)
	{
	int len;
	switch(key)
		{
		case UP:
			H(&*minl,&*maxl,&*linecn,&*cn);
			break;
		case DO:
			P(&*minl,&*maxl,&*linecn,&*cn,&*finalcn);
			break;
		case R:
			M(&*min,&*max,&*cn,&*linecn);
			break;
		case L:
			k(&*min,&*max,&*cn);
			break;
		}
	if(*cn<0)*cn=0;
	}
void bk0(int*linecn,int*max,int*min,int*minl,int*maxl,int*finalcn,int*cn)
	{
	int cn2;
	int i,j;
	int len;
	int max1;
	char dump[10][200];
	max1=*max-78;
	len=strlen(data[*linecn]);
	dump[0][0]='\0';
	cn2=0;
	*cn-=1;
	j=*cn;
	for(i=j+1;data[*linecn][i]!='\0';i++)
		{
		dump[0][cn2]=data[*linecn][i];
		cn2++;
		}
	dump[0][cn2]='\0';
	data[*linecn][*cn]='\0';
	strcat(data[*linecn],dump[0]);
	if(*cn==max1)
		{
		*max-=1;
		*min-=1;
		if(*min<0)*min=0;
		}

       }
void bk1(int*linecn,int*max,int*min,int*minl,int*maxl,int*finalcn,int*cn)
	{
	int cn2;
	int i,j;
	int len;
	int max1;
	char dump[10][200];
	max1=*maxl-21;
	len=strlen(data[*linecn]);
	dump[0][0]='\0';
	cn2=0;
	strcat(dump[0],data[*linecn]);
	*cn=0;
	cn2=1;
	data[*linecn][0]='\0';
	*linecn+=1;
	i=1;
	for(j=*linecn;j<=*finalcn;j++)
		{
		dump[cn2][0]='\0';
		strcat(dump[cn2],data[j]);
		data[j][0]='\0';
		cn2++;
		}
	cn2=1;
	*finalcn-=1;
	*linecn-=2;
	for(j=*linecn;j<=*finalcn;j++)
		{
		if(j==*linecn)
			{
			*cn=strlen(data[j]);
			strcat(data[j],dump[0]);
			continue;
			}
		data[j][0]='\0';
		strcat(data[j],dump[cn2]);
		dump[cn2][0]='\0';
		cn2++;
		}
	len=strlen(data[*linecn]);
	len--;
	if(len>78)
		{
		*max=len;
		*min=*max-78;
		}
	if(*linecn==max1)
		{
		*minl-=1;
		*maxl-=1;
		if(*minl<0)*minl=0;
		}
	}
void bk(int*linecn,int*max,int*min,int*minl,int*maxl,int*finalcn,int*cn)
	{
	if(*cn>0)
		{
		bk0(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
		}
	else if(*cn==0&&*linecn>0)
		{
		bk1(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
		}
	}
void store(int*linecn,int*cn,int*min,int*max,char ch)
	{
	char dump[5][200];
	int len,count,i;
	len=strlen(data[*linecn]);
	dump[0][0]='0';
	count=0;
	len--;
	for(i=*cn;data[*linecn][i]!='\0';i++)
		{
		dump[0][count]=data[*linecn][i];
		count++;
		}
	dump[0][count]='\0';
	data[*linecn][*cn]=ch;

	*cn+=1;
	data[*linecn][*cn]='\0';
	strcat(data[*linecn],dump[0]);
	if(*cn==*max)
		{
		*min+=1;
		*max=*min+78;
		}
	}
void newline(int*linecn,int*max,int*min,int*minl,int*maxl,int*finalcn,int*cn)
	{
	int cn2;
	int i,j;
	int len;
	int max1;
	char dump[100][200];
	len=strlen(data[*linecn]);
	dump[0][0]='\0';
	cn2=0;
	for(i=*cn;data[*linecn][i]!='\0';i++)
		{
		dump[0][cn2]=data[*linecn][i];
		cn2++;
		}
	dump[0][cn2]='\0';
	data[*linecn][*cn]='\0';

	*linecn+=1;
	*cn=0;
	cn2=1;
	*finalcn+=1;
	for(j=*linecn;j<=*finalcn;j++)
		{
		dump[j][0]='\0';
		strcat(dump[cn2],data[j]);
		data[j][0]='\0';
		cn2++;
		}
	cn2=1;
	for(j=*linecn;j<=*finalcn;j++)
		{
		if(j==*linecn)
			{
			data[j][0]='\0';
			strcat(data[j],dump[0]);
			continue;
			}
		data[j][0]='\0';
		strcat(data[j],dump[cn2]);
		dump[cn2][0]='\0';
		cn2++;
		}
	if(*linecn==*maxl)
		{
		*minl+=1;
		*maxl+=1;
		}
	*min=0;
	*max=77;
	}
int keyv(int key)
      {
      char ch,spec[]="`~ !@#$%^&*()-=_+{}|[]\\:\";'<>?,./";
      int i;
      if (isalnum(key & 0xFF))
		{
	     //	printf("'%c' key pressed\n", key);
		return 0;
		}
      ch=key;
      for(i=0;spec[i]!='\0';i++)
		{
		if(spec[i]==ch)
			{
		  //	printf("'%c' key pressed\n", key);
			return 0;
			}
		}
      return 1;
      }
int entry(int*linecn,int*max,int*min,int*minl,int*maxl,int*finalcn,int*cn)
	{
	char ch;
	int key,in;
	key=bioskey(0);
	ch=key;
	in=ch;
	if(key==esc)exit(0);
	else if(key==enter)
		{
		newline(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
		return 0;
		}
	else if(key==bksp)
		{
		bk(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
		return 0;
		}
	else if(key==UP||key==DO||key==L||key==R)
		{
		move(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn,key);
		return 0;
		}
	else
		{
		store(&*linecn,&*cn,&*min,&*max,ch);
		}
	return 1;
	}