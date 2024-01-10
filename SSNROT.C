#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define enter 13
#define bksp 127
#define esc 0
#define L C
#define R D
#define UP A
#define DO B
#define tab 0xf09
#define Alt_F4 0x2100
#define Alt_N  0x3100
#define Alt_O  0x1800
#define Alt_E  0x1200
#define F2 0x3c00
#define F3 0x3d00
#define del 0x5300
FILE*fp;
int rml=0;
char clipboardx[300];
char data1[32000];
char filename[200];
int lop=0;
char clipboard[3200];
int cur=0;
int shmin=0,shmax=0;
int rmx=0;
int pline=0;
void print2(int,int,int,int,int,int);
int keyv(int);
int fdes();
int entry(int*,int*,int*,int*,int*,int*,int*,int*);
void store(int*,int*,int*,int*,char);
void cstore(int*,int*,int*,int*,char);
void design(long);
void sur(int*,int*,int*,int*,char);
void bk(int*,int*,int*,int*,char);
void H(int*,int*,int*,int*,int*,int*);
void P(int*,int*,int*,int*,int*,int*);
void t8(int*,int*,int*,int*,int);
void K(int*,int*,int*,int*);
void M(int*,int*,int*,int*);
int finder(int,int);
int arfin(int,int);
int extl(int);
int maxtl(int);
int maxpl(int);
int mintl(int);
int upl(int);
int dwl(int);
int findl(int);
int digit(int);
int vd1(int,int);
int curpl(int);
int reddigit(int);
int check2(int);
int shift();
int edit();
int dpr(int*,int,int,int,int,int,int,int);
void notepad();
void read2();
void fpwrite()
	{
	fp=fopen(filename,"w");
	if(fp==NULL)
		{
		printf("can't create a file");
		getch();
		}
	fprintf(fp,data1);
	fclose(fp);
	}
int file()
	{
	char arr[200];
	int i;
	char spec[]="` ~!@#$%^&*()-=_+{}|[]\\:;<>?,./";

	arr[0]='\0';

	textbackground(LIGHTGRAY);
	window(20,7,61,13);
	clrscr();
	textbackground(1);
	gotoxy(1,1);
	cprintf("                                             ");
	textcolor(15);
	textbackground(LIGHTGRAY);
	gotoxy(1,2);
	cprintf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
	textcolor(YELLOW);
	cprintf(" f");
	textcolor(15);
	cprintf("ilename ");
	cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(1,3);
	cprintf(" %c",186);
	gotoxy(40,3);
	cprintf(" %c",186);

	gotoxy(1,3);
	cprintf(" %c",186);
	gotoxy(40,3);
	cprintf(" %c",186);

	gotoxy(1,4);
	cprintf(" %c",186);
	gotoxy(40,4);
	cprintf(" %c",186);

	gotoxy(1,5);
	cprintf(" %c",186);
	gotoxy(40,5);
	cprintf(" %c",186);

	gotoxy(1,6);
	cprintf(" %c",186);
	gotoxy(40,6);
	cprintf(" %c",186);
	gotoxy(1,7);
	cprintf(" %c",200);
	gotoxy(40,7);
	cprintf(" %c",188);
	for(i=3;i<=40;i++)
		{
		gotoxy(i,7);
		cprintf("%c",205);
		}
	gotoxy(12,5);
	textbackground(GREEN);
	cprintf(" OK ");
	gotoxy(16,5);
	textbackground(LIGHTGRAY);
	textcolor(0);
	cprintf("%c",220);
	gotoxy(13,6);
	textbackground(LIGHTGRAY);
	textcolor(0);
	cprintf("%c%c%c%c",223,223,223,223);

	gotoxy(22,5);
	textbackground(GREEN);
	cprintf(" Cancel ");
	gotoxy(30,5);
	textbackground(LIGHTGRAY);
	textcolor(0);
	cprintf("%c",220);
	gotoxy(23,6);
	textbackground(LIGHTGRAY);
	textcolor(0);
	cprintf("%c%c%c%c",223,223,223,223);
	cprintf("%c%c%c%c",223,223,223,223);

	textbackground(0);
	window(22,14,62,14);
	clrscr();

	window(62,9,63,14);
	clrscr();
	textbackground(1);
	window(23,9,58,9);
	clrscr();
	window(24,9,57,9);
	delay(20);
	textcolor(YELLOW);
	printf("\r");
	arr[0]='\0';
	while(1)
		{
		char ch;
		static int cn=0;
		int in;
		clrscr();
		window(24,9,57,9);
		textcolor(YELLOW);
		gotoxy(20,2);
		cprintf("%s",arr);
		textcolor(YELLOW);
		ch=getch();
		in=ch;
		if(in==27)
			{
			window(1,1,80,25);
			cn=0;
			return 1;
			}
		else if(in==13)
			{
			cn=0;
			break;
			}
		else if(in==8)
			{
			if(cn>0)
				{
				cn--;
				arr[cn]='\0';
				}
			}
		else
			{
			if(cn<=30)
				{
				if(isalpha(ch)||isdigit(ch)||strchr(spec,ch)!=NULL)
					{
					arr[cn]=ch;
					cn+=1;
					arr[cn]='\0';
					}
				}
			}
		}
	filename[0]='\0';
	sprintf(filename,"%s",arr);
	window(1,1,80,25);
	textcolor(0);
	return 0;
	}
void read2()
	{
	char ch;
	int i;
	fp=fopen(filename,"r");
	data1[0]='\0';
	if(fp==NULL)
		{
		textcolor(0);
		gotoxy(10,10);
		cprintf("can't open a file");
		file();
		getch();
		}
	i=0;
	fread(data1,sizeof(char),32000,fp);
	printf("%c");
	fclose(fp);
	}
void whdl1(int dl)
	{
	delay(dl);
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
void main()
	{
	strcpy(filename,"NONAME00.C");
	notepad();
	}

int findl(int cn)
	{
	int line=0;
	int i;
	int len;
	len=strlen(data1);
	for(i=0;i<=len;i++)
		{
		if(data1[i]=='\n')
			{
			line++;
			}
		if(cn==i)
			{
			break;
			}
		}
	return line;
	}

int finder(int pline,int flag)
	{
	int count=0;
	int line=0;
	int flag6=0;
	int len=0;
	int i;
	len=strlen(data1);
	for(i=0;i<len;i++)
		{
		if(data1[i]=='\n')
			{
			if(pline==line&&flag==5)
				{
				count++;
				flag6=1;
				break;
				}
			line++;
			if(pline==line&&flag==1||pline==line&&flag==3)
				{
				flag6=1;
				break;
				}
			if(pline==line&&flag==4)
				{
				count++;
				flag6=1;
				break;
				}
			if(flag==3)
				count=0;
			}
		count++;
		}
	if(flag6==0&&line>0)count--;

	if(flag==1||flag==2)
		{
		return line;
		}
	if(flag==3||flag==4||flag==5)
		{
		return count;
		}
	}
int curpl(int i)
	{
	textcolor(YELLOW);
	textbackground(0);
	if(data1[i]!='\n'&&data1[i]!='\t')
		{
		cprintf("%c",data1[i]);
		if(shmax==0)
			check2(i);
		}
	else if(data1[i]=='\n')
		{
		textcolor(15);
		textbackground(LIGHTGRAY);
		cprintf(".");
		printf("%c",data1[i]);
		}
	else if(data1[i]=='\t')
		{
		int x,y,x1;
		int max;
		int j;
		textbackground(LIGHTGRAY);
		cprintf(" ");
		x=wherex();
		y=wherey();
		printf("%c",data1[i]);
		x1=wherex();
		max=x1;
		x1-=x;
		gotoxy(x1,y);
		textcolor(0);
		textbackground(1);
		}
	return 1;
	}

int check2(int cn)
	{
	int ii=cn,j,jj=cn;
	int tp=cn;
	int count=0;
	int flag=0,i;
	int final;
	int len=0;
	int len2;
	int in=0;
	int inl;
	char ch;
	char str[2]={'\0','\0'};
	char jstore[100];
	int coun=0;
	int first=0;
	char keyword[][30]={"/*","*/","&&","||","^=","/=","!=","*=","<=",">=","-=","+=","==","auto ","break;","main()","case  :", "char ", "const", "continue;", "default ", "do", "double" , "else","else if()", "enum ", "extern ", "float ", "for()", "goto",
		"if()","int ", "long ", "register ", "return  ;","getch();" ,"short ", "signed ", "sizeof();", "static ", "struct{};", "switch{}", "typedef();", "union", "unsigned", "void ",
		"volatile", "while()","abs", "acos", "asin", "atan", "atan2","clrscr();","calloc();", "ceil", "cos", "cosh", "exit();", "exp", "fabs",
		"fclose();", "feof", "ferror", "fflush();", "fgetc();", "fgets();", "floor", "fmod", "fprintf();", "fputc();",
		"fputs();", "fread();", "free", "freopen", "frexp", "fscanf();", "fseek();", "fsetpos", "ftell();", "fwrite();",
		"getchar();", "getenv", "gmtime", "isalnum();", "isalpha();", "iscntrl();", "isdigit", "isgraph", "islower",
		"isprint();", "ispunct();", "isspace();", "isupper();", "isxdigit();", "labs", "ldexp", "log", "log10", "longjmp",
		"malloc", "memchr", "memcmp", "memcpy", "memmove", "memset", "mktime", "modf",
		"printf(\"\");", "putc();", "putchar();", "puts();","cprintf();", "qsort","perror","pow();", "raise", "rand();", "realloc();", "remove", "rename",
		"rewind", "scanf();", "setbuf", "setjmp", "setlocale", "setvbuf", "signal", "sin", "sinh", "sprintf(\"\");",
		"sqrt", "srand", "sscanf();", "strcat();", "strchr();", "strcmp();", "strcoll", "strcpy", "strcspn", "strerror",
		"strftime", "strlen();", "strncat();", "strncmp();", "strncpy();", "strpbrk", "strrchr", "strspn", "strstr",
		"strtod", "strtok", "strtol", "strtoul", "strxfrm", "system", "tan", "tanh", "time", "tmpfile",
		"tmpnam", "tolower();", "toupper();", "ungetc", "va_arg", "va_end", "va_start", "vfprintf", "vprintf",
		"vsprintf","graph","initgraph();","closegraph();","line();","rectangle();","circle();","ellipse();","arc();","outtextxy();","setcolor();","setbkcolor();",
		"settextstyle();","setfillstyle();","delay(1);","cleardevice();","#include","#include<","assert.h","complex.h","ctype.h","errno.h","fenv.h","float.h","inttypes.h","iso646.h","limits.h","locale.h","math.h","setjmp.h",
		"signal.h","stdalign.h","stdarg.h","stdbool.h","stddef.h","stdint.h","stdio.h","stdlib.h","string.h","tgmath.h","threads.h","time.h","uchar.h",
		"wchar.h","wctype.h","graphics.h","#include\"C:\\TURBOC3\\BIN\"","#include<stdio.h>","#include<conio.h>","#define ","#include<assert.h>","#include<complex.h>","#include<ctype.h>","#include<errno.h>","#include<fenv.h>","#include<float.h>","#include<inttypes.h>","#include<iso646.h>","#include<limits.h>","#include<locale.h>","#include<math.h>","#include<setjmp.h>",
		"#include<signal.h>","#include<stdalign.h>","#include<stdarg.h>","#include<stdbool.h>","#include<stddef.h>","#include<stdint.h>","#include<stdlib.h>","#include<string.h>","#include<tgmath.h>","#include<threads.h>","#include<time.h>","#include<uchar.h>",
		"#include<wchar.h>","#include<wctype.h>","#include<graphics.h>","1"
		};
	j+=1;
	ch=data1[j];
	textcolor(0);
	if(ch!='\n'&&ch!=' '&&ch!='\0')
		{
		return 0;
		}
	j=jj;
	ch=data1[j];
	if(ch!='\n'&&ch!=' '&&ch!='\0')
		{
		return 0;
		}
	textcolor(0);
	str[0]=data1[j];
	jstore[0]='\0';
	coun=0;
	if(data1[cn]==' '||data1[cn]=='\n'||data1[cn]=='\0')
		{
		j=cn-1;
		}
	else
		{
		j=cn;
		}
	for(i=j;data1[i]!='\n'&&data1[i]!=' '&&i>=0;i--)
		{
		jstore[coun]=data1[i];
		coun++;
		}
	jstore[coun]='\0';
	strrev(jstore);
	textcolor(6);
	for(i=0;keyword[i][0]!='1';i++)
		{
		int len3;
		tp=jj;
		len=strlen(keyword[i]);
		final=len;
		len3=strlen(jstore);
		count=0;
		for(j=0;j<=len3;j++)
			{
			if(jstore[j]==keyword[i][j])
				{
				count++;
				}
			else break;
			}

		if(count==len3&&len3>0)
			{
			int len2;
			char ch;
			int il;
			ch=data1[tp];
			textcolor(0);
			textcolor(LIGHTGRAY);
			textbackground(LIGHTBLUE);
			rmx=0;
			il=0;
			//len3--;
			for(j=len3;j<len;j++)
				{
				cprintf("%c",keyword[i][j]);
				clipboardx[il]=keyword[i][j];
				il+=1;
				jj++;
				rmx+=1;
				}
			clipboardx[il]='\0';
			return 0;
			}
		}
	rmx=0;
	clipboardx[0]='\0';
	return 0;
	}

int vd1(int z,int cn)
	{
	int i=z;
	int tp=z;
	int j;
	int count=0;
	int flag=0;
	int final;
	int len=0;
	int len2;
	char ch;
	char str[2]={'\0','\0'};
	char spec[]={"` ~!@#$%^&*()-=_+{}|[]\\:;<>?,./"};
	char keyword[35][40]={"auto", "break", "case", "char", "const", "continue", "default","double", "do", "else", "enum"
		, "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed"
		, "sizeof","new","static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while","1"};
	j=z;
	j--;
	str[0]=data1[j];
	if(j>0)
		{
		if(strstr(spec,str)==NULL)
			{
			if(data1[j]=='\n');
			else
				{
				return 0;
				}
			}
		}
	for(i=0;keyword[i][0]!='1';i++)
		{
		tp=z;
		len=strlen(keyword[i]);
		final=len;
		count=0;
		for(j=0;j<len;j++)
			{
			if(data1[tp]==keyword[i][j])
				{
				count++;
				}
			else break;
			tp++;
			}

		if(count==len)
			{
			int len2;
			char ch;
			char minch;
			int min;
			char spec[]="0123456789` ~!@#$%^&*()-=_+{}|[]\\:;<>?,./";
			len2=strlen(spec);
			ch=data1[tp];
			if(strchr(spec,ch))
				{
				textcolor(0);
				flag=1;

				return strlen(keyword[i]);
				}
			else if(ch=='\0'||ch=='\n')
				{
				textcolor(0);
				flag=1;
				return final;
				}


			break;
			}
		}
	return 0;
	}
int digit(int z)
	{
	int i;
	int flag=0;
	char spec[]={"`~!@$%^&*()-=_+{}|[]\\:;<>?,./0123456789"};
	if(isdigit(data1[z]))
		{
		}
	else return 0;
	i=z-1;
	if(strchr(spec,data1[i]!=NULL))
		{
		flag==1;
		}
	i=z+1;
	if(strchr(spec,data1[i]!=NULL)&&flag==1)
		{
		return 0;
		}
	for(i=z;data1[i]!=' '&&data1[i]!='\n'&&i>0;i--)
		{
		if(strchr(spec,data1[i])==NULL)
			{
			return 0;
			}
		}

	return 1;
	}
int reddigit(int z)
	{
	int i;
	char spec[]={"`~!@$%^&*  ()-=_+{}|[]\\:;<>?,./0123456789"};
	i=z-1;
	if(isdigit(data1[z]))
		{
		}
	else return 0;
	for(i=z;data1[i]!=' '&&data1[i]!='\n'&&i>0;i--)
		{
		if(strchr(spec,data1[i])==NULL)
			{
			return 0;
			}
		}
	for(i=z;data1[i]!=' '&&data1[i]!='\n'&&data1[i]!='\0';i++)
		{
		if(strchr(spec,data1[i])==NULL)
			{
			return 1;
			}
		}
	return 0;
	}
int dpr(int *i,int minl,int maxl,int min,int max,int cn,int flagship,int flag)
	{
	char spec[]={"`~!@$%^&*()-=_+{}|[]\\:;<>?,./"};
	char red[]={"\@$`\\"};
	int mx=0,mn=0;
	static int dq=0,sq=0,sl=0,hs=0;
	static int cm=0,vd=0,len=0;
	static int per=0;
	static int flhs=0;
	static int shfl=0;
	static int hex=0;
	int shdmin=shdmin,shdmax=shmax;
	int dg=0;
	int sti=*i;
	mx=*i+1;
	rmx=0;
	if(flag)
		{
		dq=0;
		sq=0;
		sl=0;
		hs=0;
		vd=0;
		flhs=0;
		len=0;
		hex=0;
		if(flag==-1)cm=0;
		textbackground(1);
		if(flag!=-1)
		return 0;
		}
	if(data1[*i]!='\0'&&data1[*i]!='#'&&data1[*i]!='\n'&&data1[*i]!=' '&&flhs==0&&hs==0)
		{
		flhs=1;
		textcolor(0);
		textbackground(RED);
		}
	if(per>=1)
		{
		per++;
		if(per==3)
			{
			per=0;
			}
		}
	if(data1[*i]=='%')
		{
		per++;
		if(per==3)
			{
			per=0;
			return 0;
			}
		}

	if(data1[*i]=='"'&&dq==0||dq==1)
		{
		textbackground(1);
		textcolor(RED);
		 if(data1[*i]=='"')
			{
			dq++;
			sq=-1;
			sl=-1;
			hs=-1;
			vd=-1;
			hex=-1;
			}
		if(dq==2)
			{
			dq=0;
			sq=0;
			sl=0;
			hs=0;
			vd=0;
			hex=0;
			}
		}
	else if(data1[*i]=='\''&&sq==0||sq==1)
		{
		textbackground(1);
		textcolor(MAGENTA);
		if(data1[*i]=='\'')
			{
			sq++;
			dq=-1;
			sl=-1;
			hs=-1;
			vd=-1;
			hex=-1;
			}
		if(sq==2)
			{
			sq=0;
			dq=0;
			sl=0;
			hs=0;
			vd=0;
			hex=0;
			}
		}
	else if(data1[*i]=='/'&&data1[mx]=='/'&&sl==0||sl==1)
		{
		textbackground(1);
		textcolor(CYAN);
		sl=1;
		dq=-1;
		sq=-1;
		hs=-1;
		vd=-1;
		hex=-1;
		}
	else if(data1[*i]=='*'&&data1[mx]=='/'&&cm==1||cm==2)
		{
		textbackground(1);
		textcolor(CYAN);
		cm++;
		if(cm==3)
			{
			sl=0;
			dq=0;
			sq=0;
			hs=0;
			cm=0;
			vd=0;
			hex=0;
			}
		}
	else if(data1[*i]=='/'&&data1[mx]=='*'&&cm==0||cm==1)
		{
		textbackground(1);
		textcolor(CYAN);
		cm=1;
		sl=-1;
		dq=-1;
		sq=-1;
		hs=-1;
		vd=-1;
		hex=-1;
		}
	else if(data1[*i]=='0'&&data1[mx]=='x'&&hex==0||hex==1)
		{
		textbackground(1);
		textcolor(0);
		hex=1;
		sl=-1;
		dq=-1;
		sq=-1;
		hs=-1;
		vd=-1;
		cm=-1;
		}
	else if(data1[*i]=='#'&&hs==0&&flhs==0||hs==1)
		{
		textbackground(CYAN);
		textcolor(BLUE);
		hs=1;
		sl=-1;
		dq=-1;
		sq=-1;
		vd=-1;
		hex=-1;
		}
	else if(strchr(spec,data1[*i])!=NULL)
		{
		textbackground(1);
		textcolor(YELLOW);
		}
	else if(digit(*i))
		{
		dg=1;
		textbackground(1);
		textcolor(LIGHTGRAY);
		}
	else if(vd1(*i,cn)&&vd==0||vd>0)
		{
		sl=-1;
		dq=-1;
		sq=-1;
		hs=-1;
		if(vd==0)
			{
			len=vd1(*i,cn);
			len-=1;
			}
		textbackground(1);
		textcolor(15);
		if(vd<len)
			{
			vd++;
			}
		else
			{
			sl=0;
			dq=0;
			len=0;
			sq=0;
			hs=0;
			cm=0;
			vd=0;
			}
		}
	//else
	else
		{
		textbackground(1);
		textcolor(LIGHTGREEN);
		}

	if(hs==0&&dq==0&&sq==0&&cm==0&&flhs==1&&data1[*i]=='#')
		{
		textcolor(0);
		textbackground(RED);
		}
	if(strchr(red,data1[*i])!=NULL&&data1[*i]!='\0'&&cm==0&&hs==0&&dq==0&&sq==0)
		{
		textcolor(0);
		textbackground(RED);
		}
	min=*i-1;
	mx=*i+1;
	if(reddigit(*i)&&cm==0&&sq==0&&hs==0&&dq==0)
		{
		textcolor(0);
		textbackground(RED);
		}
	if(*i>shmin&&*i<shmax&&shmax>0)
		 {
		 textbackground(7);
		 textcolor(1);
		 }
	if(sti==cn)
		{
		curpl(sti);
		return 1;
		}
	if(flagship==1)
		{
		cprintf("%c",data1[*i]);
		}
	}
void print2(int cn,int minl,int maxl,int min,int max,int finalcn)
	{
	int in=0;
	int store=0;
	int flag=0;
	int flag1=0;
	int i;
	int line=0;
	int cur=0;
	int len=0;
	int con=0;
	int checkmax=0;
	int flagship=0;
	int checkmin=0;
	int cr=0;
	int xch=0;
	int xflag=0;
	char text1[12]="FESRCDPOWH";
	char text[13][10]={"ile","dit","earch","un","ompile","ebug"
		       ,"roject","ptions","indow","elp"
			};
	textcolor(15);
	textbackground(0);
	in=0;
	line=0;
	checkmax=finder(0,2);
	cur=0;
	in=0;
	i=0;
	textcolor(15);
	textbackground(0);
	textcolor(0);
	textbackground(15);
	len=strlen(data1);
	textbackground(LIGHTGRAY);
	textcolor(BLACK);
	gotoxy(1,1);
	for(i=0;i<strlen(text1);i++)
		{
		cprintf(" ");
		if(i==0)
			{
			textcolor(RED);
			cprintf(" %c  ",240);
			textcolor(0);
			}
		else if(text1[i]=='W')printf("   ");
		else printf(" ");
		textcolor(RED);
		cprintf("%c",text1[i]);
		textcolor(0);
		cprintf("%s",text[i]);
		}
	textbackground(LIGHTBLUE);
	printf("\n");
	design(cn);
	gotoxy(2,3);
	flag1=0;
	for(i=0;i<=len;i++)
		{
		int x;
		con++;
		flagship=0;
		if(data1[i]=='\n')
			{
			line++;
			if(line>=minl&&line<maxl)
				{
				int x;
				int y;
				char ch[2]=" ";
				flag1++;
				x=wherex();
				y=wherey();
				flagship=1;
				for(x;x<=79&&flag1!=1;x++)
					{
					textbackground(1);
					textcolor(1);
					cprintf(".");
					flagship=1;
					dpr(&i,minl,maxl,min,max,cn,flagship,1);
					}
				if(data1[i]=='\n')
					{
					if(flag1!=1)
						printf("%c%c",data1[i],186);
					con=0;
					flagship=1;
					dpr(&i,minl,maxl,min,max,cn,flagship,1);
					continue;
					}
				flagship=1;
				if(dpr(&i,minl,maxl,min,max,cn,flagship,1))flag=1;
				if(flag1==1&&i>0)
					{
					gotoxy(2,3);
					}

				}
			if(flagship==0);
				{
				if(dpr(&i,minl,maxl,min,max,cn,flagship,0))flag=1;
				}
			con=0;
			continue;
			xch=0;
			xflag=0;
			}
		x=wherex();
		if(xch==78)
			{
			xch=1;
			xflag=1;
			}
		else
			{
			xch=x;
			}
		if(line>=minl&&line<maxl&&xflag==0)
			{
			if(con>=min&&con<max)
				{
				int rsflag=0;
				flag1++;
				flagship=1;
				if(i==0)
					{
					rsflag=-1;
					}
				flagship=1;
				if(dpr(&i,minl,maxl,min,max,cn,flagship,rsflag))flag=1;
				if(flag1==1&&i>0)
					{
					gotoxy(2,3);
					}
				max-=rmx;
				continue;
				}
			}

		if(flagship==0)
			{
			dpr(&i,minl,maxl,min,max,cn,flagship,0);
			}
		}
	//end
	if(flag==0)
		{
		textcolor(1);
		textbackground(LIGHTGRAY);
		cprintf(" ");
		check2(i);
		}
	for(con=wherex()+1;con<=79;con++)
		{
		textbackground(1);
		textcolor(1);
		cprintf(".");
		}
	for(i=wherey();i<23;i++)
		{
		textbackground(1);
		textcolor(1);
		printf("\n");
		cprintf("%c",186);
		for(con=0;con<78;con++)
			{
			textbackground(1);
			textcolor(1);
			cprintf(".");
			}
		}
	gotoxy(79,3);
	textbackground(1);
	textcolor(15);
	cprintf(".");
	design(cn);
	textcolor(0);
	textbackground(1);
	gotoxy(80,24);               /*
	printf("");
	gotoxy(40,10);
	cprintf("flag=%d,store=%d,cn=%d",flag,store,cn);
	gotoxy(40,11);
	cprintf("in=%d,cur=%d,pline=%d",i,cur,pline);
	gotoxy(40,12);
	cprintf("line=%d,maxl=%d,minl=%d",line,maxl,minl,con);
	gotoxy(40,13);
	cprintf("min=%d,max=%d",min,max);
	gotoxy(40,14);
	cprintf("cn=%d,pline=%d,con=%d\n",cn,pline,con);
	gotoxy(40,15);
	cprintf("extl=%d,maxtl=%d,mintl=%d",extl(cn),maxtl(cn),mintl(cn));
	gotoxy(40,16);
	cprintf("maxpl=%d,x=%d,y=%d",maxpl(cn),wherex(),wherey());
	gotoxy(40,17);
	cprintf("data=[%c][%d],coun=%d,flagship=%d",data1[cn],data1[cn],finder(0,2),flagship);
	gotoxy(40,18);
	cprintf("clipboard=%s,shmin=%d,shmax=%d",clipboard,shmin,shmax);*/
	gotoxy(80,24);
	}
void notepad()
	{
	int linecn=0;
	int max=77,min=0;
	int finalcn=0;
	int minl=0,maxl=21;
	int tab1=0;
	int cn=0;
	int i;
	textcolor(15);
	textbackground(0);
	clrscr();
  //	data1[0]='\0';
	textcolor(LIGHTGRAY);
	window(1,25,80,25);
	clrscr();
	window(1,1,80,25);
	textbackground(LIGHTBLUE);
	textcolor(BLUE);
	printf("| ");
	clrscr();
	textbackground(LIGHTGRAY);
	window(1,25,80,25);
	clrscr();
	window(1,1,80,25);
	textbackground(LIGHTGRAY);
	textcolor(BLACK);
	for(i=0;i<=72;i++)
		{
		cprintf(" ");
		if(i==35)
			cprintf("TURBO C");
		}
	textbackground(LIGHTBLUE);
	printf("\n");
	textcolor(YELLOW);
	cprintf(" %c",179);
	print2(cn,minl,maxl,min,max,finalcn);
	while(1)
		{
		if(kbhit())
			{
			int in=0;
			entry(&in,&max,&min,&minl,&maxl,&finalcn,&cn,&tab1);
			fpwrite();
			print2(cn,minl,maxl,min,max,finalcn);
			}
		}
	}
void store(int*linecn,int*cn,int*min,int*max,char ch)
	{
	char** dump;
	int len,count,i;
	int cn2;
	len=strlen(data1);
	dump=(char**)calloc(1,sizeof(char));
	dump[0]=(char*)calloc(32000,sizeof(char));
	dump[0][0]='\0';
	count=0;
	len--;
	for(i=*cn;data1[i]!='\0';i++)
		{
		dump[0][count]=data1[i];
		count++;
		}
	dump[0][count]='\0';
	data1[*cn]=ch;
	*cn+=1;
	data1[*cn]='\0';
	strcat(data1,dump[0]);
	if(extl(*cn)==*max)
		{
		if(*min==0)*min+=1;
		*min+=1;
		*max=*min+77;
		}
	free(dump[0]);
	free(dump);
	}
int maxpl(int cn)
	{
	int i;
	int min=0;
	for(i=0;i<=extl(cn);i++)
		{
		if(i>77)
			{
			min++;
			}
		}
	min++;
	return min;
	}


void bk0(int*linecn,int*max,int*min,int*minl,int*maxl,int*finalcn,int*cn)
	{
	char** dump;
	int len,count,i;
	len=strlen(data1);
	dump=(char**)calloc(1,sizeof(char));
	dump[0]=(char*)calloc(32000,sizeof(char));
	dump[0][0]='\0';
	count=0;
	len--;
	*cn-=1;
	for(i=*cn+1;data1[i]!='\0';i++)
		{
		dump[0][count]=data1[i];
		count++;
		}
	dump[0][count]='\0';
	data1[*cn]='\0';


	data1[*cn]='\0';
	strcat(data1,dump[0]);
	if(extl(*cn)==*min)
		{
		*min-=1;
		*max=*min+77;
		}
	free(dump[0]);
	free(dump);
	}
int bkc(int*linecn,int*max,int*min,int*minl,int*maxl,int*finalcn,int*cn)
	{
	int i=0;
	if(*cn>0)
		{
		int jn;
		int flag=0;
		int arr[5];
		int len;
		jn=*cn-1;
		if(data1[jn]=='\n')
			{
			len=maxtl(*cn)-mintl(*cn);
			bk0(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
		     //	bk0(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
			flag=1;
			}
		arr[0]=*cn-1;
		arr[1]=*cn-2;
		arr[2]=*cn-3;
		arr[3]=*cn-4;
		if(data1[arr[0]]==' '&&data1[arr[1]]==' '&&data1[arr[2]]==' ' &&data1[arr[3]]==' ')
			{
			int i;
			for(i=0;i<=3;i++)
				{
				bk0(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
				}
			}
		if(data1[arr[0]]=='%'&&data1[arr[1]]=='%')
			{
			bk0(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
			}
		bk0(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
		if(flag)
			{
			*min=maxpl(*cn);
			*min-=1;
			if(*min>1)
				*min+=len;
			else
				{
				*min=0;
				}
			*max=*min+77;
			}
		}
	pline=findl(*cn);
	return 0;
	}
int extl(int cn)
	{
	int line=0;
	int i;
	int count=0;
	int len;
	int flag=0;
	len=strlen(data1);
	for(i=0;i<len;i++)
		{
		if(i==cn)
			{
			break;
			}
		if(data1[i]=='\n')
			{
			count=0;
			}
		count++;
		}
	return count;
	}
int maxtl(int cn)
	{
	int line=0;
	int i;
	int count=0;
	int flag=0;
	int len;
	len=strlen(data1);
	for(i=0;i<len;i++)
		{
		if(data1[i]=='\n'&&i>0)
			{
			if(i==cn)
				{
				i--;
				break;
				}
			if(flag)
				{
				i--;
				break;
				}
			}
		if(i==cn)
			{
			flag=1;
			}
		}
	return i;
	}
int mintl(int cn)
	{
	int line=0;
	int i;
	int count=0;
	int flag=0;
	int len;
	len=strlen(data1);
	for(i=0;i<len;i++)
		{
		if(data1[i]=='\n'&&i>0)
			{
			count=i+1;
			}
		if(i==cn)
			{
			break;
			}
		}
	return count;
	}
int upl(int dline)
	{
	int line=0;
	int i;
	int count=0;
	int len;
	int flag=0;
	if(dline>0)
		dline-=1;
	len=strlen(data1);
	for(i=0;i<len;i++)
		{
		if(dline==0)flag=1;
		if(data1[i]=='\n')
			{
			if(flag==1)
				{
				count=1;
				break;
				}
			if(dline==line)
				{
				flag=1;
				}
			line++;
			if(dline==line)
				{
				flag=1;
				}
			}
		if(flag==1)
			{
			if(count==1)break;
			count++;
			}
		}
	gotoxy(5,19);
	return i;
	}
int dwl(int dline)
	{
	int line=0;
	int i;
	int count=0;
	int len;
	int flag=0;
	if(dline>1)
		dline+=1;
	len=strlen(data1);
	for(i=0;i<len;i++)
		{
		if(data1[i]=='\n')
			{
			if(flag==1)
				{
				count=1;
				break;
				}
			if(dline==line)
				{
				flag=1;
				}
			line++;
			if(dline==line)
				{
				flag=1;
				}
			}
		if(flag)
			{
			if(count==1)break;
			count++;
			}
		}
	gotoxy(5,19);
	return i;
	}
void k(int *min,int *max,int *cn)
	{
	int max1;
	max1=*max-78;
	if(*cn>mintl(*cn))
		{
		*cn-=1;
		gotoxy(78,3);
		textbackground(1);
	     //	textcolor(1);
	       //	cprintf("aa");
		if(extl(*cn)==max1)
			{
			*min-=1;
			*max=*min+77;
			if(*min<=0)
				{
				*min=0;
				*max=*min+78;
				}
			}
		}
	if(*cn<0)*cn=0;
	pline=findl(*cn);
	}
void M(int *min,int *max,int *cn,int *linecn)
	{
	int len;
	int max1;
	int cn2;
	len=strlen(data1);
	max1=*min+78;
	if(*cn<maxtl(*cn))
		{
		*cn+=1;
		cn2=extl(*cn);
		if(cn2==max1)
			{
			*min+=1;
			*max=*min+77;
			}
		else if(data1[*cn]=='\n')
			{
			*min=0;
			*max=*min+77;
			}
		}
	pline=findl(*cn);
	}
void H(int *minl,int *maxl,int *min,int *max,int *linecn ,int *cn)
	{
	int max1;
	int len;
	int ming;
	int eing;
	int maxing;
	max1=*minl-1;
	if(pline>0)
		{
		int st;
		pline=findl(*cn);
		st=upl(pline);
		len=extl(*cn);
		*cn=st;
		st=maxtl(*cn);
		*cn=st;
		if(len<extl(*cn)&&len<77)
			{
			st=mintl(*cn);
			*cn=st;
			*cn+=len-1;
			if(*cn>maxtl(*cn))*cn=maxtl(*cn);
			}
		else
			{
			M(&*min,&*max,&*cn,&*linecn);
			}
		pline=findl(*cn);
		if(pline==max1&&max1>-1)
			{
			*minl-=1;
			*maxl=*minl+21;
			}
		}
	if(*minl<0)
		{
		*minl=0;
		*maxl=*minl+21;
		}
	}
int arfin(int dline,int cn)
	{
	int line=0;
	int i;
	int count=0;
	int len;
	int flag=0;
	len=strlen(data1);
	for(i=0;i<len;i++)
		{
		count++;
		if(data1[i]=='\n')
			{
			if(dline==line)
				{
				break;
				}
			line++;
			}

		}
	return count;
	}
void P(int *minl,int *maxl,int *min,int *max,int *linecn ,int *cn)
	{
	int max1;
	int len;
	int check;
	int lst=0;
	max1=*maxl;
	check=finder(0,2)+1;
	lst=findl(*cn);
	if(pline<check)
		{
		int st;
		pline=findl(*cn);
		len=extl(*cn);
		st=dwl(pline);
		st=maxtl(*cn)+3;
		if(st>=strlen(data1))st=maxtl(*cn)-1;
		*cn=st;
		st=maxtl(*cn);
		*cn=st;
		if(len<extl(*cn)&&len<77)
			{
			st=mintl(*cn);
			if(lst>0)st--;
			*cn=st;
			*cn+=len;
			}
		else
			{
			M(&*min,&*max,&*cn,&*linecn);
			}
		pline=findl(st);
		if(pline>=max1)
			{
			*minl+=1;
			*maxl=*minl+21;
			}
		}
	}
void move(int *linecn,int *max,int *min,int *minl,int *maxl,int *finalcn,int *cn,int key)
	{
	int len;
	switch(key)
		{
		case UP:
			H(&*minl,&*maxl,&*min,&*max,&*linecn,&*cn);
			*min=maxpl(*cn);
			*max=*min+77;
			break;
		case DO:
			P(&*minl,&*maxl,&*min,&*max,&*linecn,&*cn);
			*min=maxpl(*cn);
			*max=*min+77;                    			break;
		case R:
			M(&*min,&*max,&*cn,&*linecn);
			break;
		case L:
			k(&*min,&*max,&*cn);
			break;
		}
	if(*cn<0)*cn=0;
	}
int keyv(int key)
	{
	char ch,spec[]="`~ !@#$%^&*()-=_+{}|[]\\:\";'<>?,./";
	int i;
	if(isalnum(key&0xFF))
		{
		return 0;
		}
	ch=key;
	for(i=0;spec[i]!='\0';i++)
		{
		if(spec[i]==ch)
			{
			return 0;
			}
		}
	return 1;
	}
void t8(int *linecn,int *cn,int *min,int *max,int flag)
	{
	int i;
	int tab1=0;
	int found=0;
	for(i=0;i<*cn;i++)
		{
		if(data1[i]=='\n')
			{
			tab1=0;
			}
		if(data1[i]=='{')
			{
			found++;
			}
		else if(data1[i]=='}')
			{
			found--;
			}
		tab1++;
		if(i==*cn)break;
		}
	if(flag==0||found>0)
		{
		if(found==0)found=1;
		for(i=0;i<found;i++)
			{
			int j;
			for(j=0;j<=4;j++)
				{
				store(&*linecn,&*cn,&*min,&*max,' ');
				}
			}
		}
	else
		{
		for(i=0;i<found;i++)
			{
			int j;
			for(j=0;j<=4;j++)
				{
				store(&*linecn,&*cn,&*min,&*max,' ');
				}
			}
		}
	}
void cstore(int*linecn,int*cn,int*min,int*max,char ch)
	{
	if(ch=='\''||ch=='"')
		{
		store(&*linecn,&*cn,&*min,&*max,ch);
		store(&*linecn,&*cn,&*min,&*max,ch);
		*cn-=1;
		}
	else if(ch=='{'||ch=='('||ch=='[')
		{
		store(&*linecn,&*cn,&*min,&*max,ch);
		if(ch=='{')ch='}';
		if(ch=='(')ch=')';
		if(ch=='[')ch=']';
		store(&*linecn,&*cn,&*min,&*max,ch);
		*cn-=1;
		}
	else
		{
		store(&*linecn,&*cn,&*min,&*max,ch);
		}
	}
int shclip()
	{
	int i;
	int j=0;
	clipboard[0]='\0';
	for(i=shmin;i<shmax;i++)
		{
		clipboard[j]=data1[i];
		j++;
		}
	clipboard[j]='\0';
	return 0;
	}
int entry(int*linecn,int*max,int*min,int*minl,int*maxl,int*finalcn,int*cn,int *tab1)
	{
	char ch;
	int key,in;
	key=bioskey(0);
	ch=key;
	in=ch;
	if(key==esc)
		{
		free(data1);
		free(clipboardx);
		exit(0);
		}
	else if(key==Alt_E)
		{
		int con=0;
		con=edit();
		if(con==3&&shmax>0)
			{
			int i;
			int shhm=shmax;
			shclip();
			for(i=shhm;i>shmin&&i>0;)
				{
				bkc(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&i);
				}
			shmax=0;
			shmin=0;
			}
		else if(con==4&&shmax>0)
			{
			shclip();
			}
		else if(con==5&&clipboard[0]!='\0')
			{
			int i;
			int len;
			len=strlen(clipboard);
			shmin=*cn-1;
			for(i=0;i<len;i++)
				{
				store(&i,&*cn,&*min,&*max,clipboard[i]);
				}
			shmax=*cn;
			}
		if(con==6&&shmax>0)
			{
			int i;
			int shmm=shmax;
			*cn=shmin;
			for(i=shmm;i>=shmin&&i>0;)
				{
				bkc(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&i);
				}
			shmax=0;
			shmin=0;
			}
		}
	else if(key==DO||key==UP||key==R||key==L)
		{
		static int flag=0,con=0;
		static int fl=0,fl2=0;
		if(shift())
			{
			if(con==0)
				{
				if(key==DO)
					{
					shmin=*cn;
					fl=1;
					}
				else if(key==UP)
					{
					fl=2;
					shmax=*cn;
					}
				else if(key==L)
					{
					fl=3;
					shmax=*cn;
					}
				else
					{
					fl=4;
					shmin=*cn;
					}
				flag=1;
				}
			con=1;
			}
		else 	{
			flag=0;
			con=0;
			shmin=0;
			shmax=0;
			}
		move(&pline,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn,key);
		if(flag)
			{
			if(key==DO)
				{
				if(fl==2||fl==3)
					{
					shmin=*cn;
					}
				else
					shmax=*cn;
				}
			else if(key==UP)
				{
				if(fl==1||fl==4)
					{
					shmax=*cn;
					}
				else
					shmin=*cn;
				}
			else if(key==L)
				{
				if(fl==4||fl==1)
					{
					shmax=*cn;
					}
				else
					shmin=*cn;
				}
			else
				{
				if(fl==3||fl==2)
					{
					shmin=*cn;
					}
				else
					shmax=*cn;
				}
			//shclip();
			}
		}
	else if(key==enter)
		{
		int i=0;
		int cn1;
		i=*cn-1;
		if(data1[i]=='{'&&data1[*cn]=='}')
			{
			i=0;
			store(&i,&*cn,&*min,&*max,' ');
			store(&i,&*cn,&*min,&*max,'\n');
			cn1=*cn;
			t8(&*linecn,&*cn,&*min,&*max,1);
			store(&i,&*cn,&*min,&*max,' ');
			store(&i,&*cn,&*min,&*max,'\n');
			t8(&*linecn,&*cn,&*min,&*max,1);
			*cn=cn1;
			}
		else
			{
			i=0;
			store(&i,&*cn,&*min,&*max,' ');
			store(&i,&*cn,&*min,&*max,'\n');
		      //	store(&i,&*cn,&*min,&*max,' ');
		      //	*cn-=1;
			}

		pline=findl(*cn);
		*min=0;
		*max=*min+77;
		if(pline==*maxl)
			{
			*minl+=1;
			*maxl=*minl+21;
			}
		t8(&*linecn,&*cn,&*min,&*max,1);
		return 0;
		}
	else if(key==Alt_F4||key==F2||key==F3)
		{
		int check=0;
		if(key!=F2&&key!=F3)
			{
			check=fdes();
			}
		textcolor(0);
		gotoxy(5,10);
		if(check==1||key==F2)
			{
			int ch1=0;


			design(*cn);
			if(lop<4)
				lop+=1;
			print2(*cn,*minl,*maxl,*min,*max,*finalcn);

			ch=file();
			if(ch1==1)
				{
				*cn=0;
				sprintf(data1,"pass");
				strupr(filename);
				fpwrite();
				}

			}
		else if(check==2||key==F3)
			{
			int ch1=0;
			design(*cn);
			print2(*cn,*minl,*maxl,*min,*max,*finalcn);
		       //	arr1[0]='\0';
		    //	strcpy(filename,arr1);
			ch1=file();
			if(ch1==0)
				{
				strupr(filename);
				read2();
				}

			}
		else if(check==3||key==F2)
			{
			static int i=0;
			if(i==0)
				{
				*cn=0;
				design(*cn);
				print2(*cn,*minl,*maxl,*min,*max,*finalcn);
				file();
				strupr(filename);
				fpwrite();
				i++;
				}
			}
		else if(check==4)
			{
			*cn=0;
			design(*cn);
			print2(*cn,*minl,*maxl,*min,*max,*finalcn);
			file();
			strupr(filename);
			fpwrite();
			}
		}
	else if(key==tab)
		{
		if(clipboardx[0]!='\0')
			{
			int il;
			int st;
			int flag,flag2=0;
			int i;
			int len;
			flag=0;
			st=*cn;
			len=strlen(clipboardx);
			for(i=0;clipboardx[i]!='\0';i++)
				{
				if(clipboardx[i]=='"'&&flag==0||clipboardx[i]=='"'&&flag==1)
					{
					st=*cn+1;
					flag++;
					}
			if(clipboardx[i]=='('&&flag==0)
					{
					st=*cn+1;
					flag=1;
					}
				store(&*linecn,&*cn,&*min,&*max,clipboardx[i]);
				if(flag==0)
					st++;
				}
			*cn=st;
			clipboardx[0]='\0';
			}
		else
			{
			t8(&*linecn,&*cn,&*min,&*max,0);
			}
		}
	else if(key==del)
		{
		*cn+=1;
		bkc(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
		return 0;
		}
	else if(key==bksp)
		{
		bkc(&*linecn,&*max,&*min,&*minl,&*maxl,&*finalcn,&*cn);
		return 0;
		}
	else
		{
		int in=0;
		static int cn12=0;
		static int per=0;
		if(keyv(key))return 0;  /*
		if(*cn==0&&cn12==0)
		       {
		       cstore(&in,&*cn,&*min,&*max,' ');
		       *cn-=1;
		       cn12=1;
		       }   */
		if(ch=='%')
			{
			store(&in,&*cn,&*min,&*max,'%');
			store(&in,&*cn,&*min,&*max,'%');
			}
		else    {
			cstore(&in,&*cn,&*min,&*max,ch);
			}

		shmin=0;
		shmax=0;
		cur+=1;
		}
	return 1;
	}
int fdes()
	{
	int i=0;
	int key=0;
	int w=1;

	textbackground(GREEN);
	textcolor(RED);
	gotoxy(5,1);
	cprintf(" F");
	textcolor(0);
	cprintf("ile ");
	textbackground(LIGHTGRAY);
	gotoxy(1,1);
	for(i=2;i<=14;i++)
		{
		gotoxy(3,i);
		cprintf("                       ");
		}
	for(i=3;i<14;i++)
		{
		textcolor(0);
		gotoxy(4,i);
		cprintf("%c",179);
		gotoxy(24,i);
		cprintf("%c",179);
		}

	for(i=4;i<=24;i++)
		{
		int ch=196;
		if(i==4)
			{
			ch=195;
			}
		else if(i==24)
			{
			ch=180;
			}
		textcolor(0);
		gotoxy(i,2);
		cprintf("%c",ch);
		gotoxy(i,8);
		cprintf("%c",ch);
		gotoxy(i,12);
		cprintf("%c",ch);
		gotoxy(i,14);
		cprintf("%c",ch);
		}
	gotoxy(3,2);
	cprintf("                       ");
	textbackground(0);
	gotoxy(4,15);
	cprintf("                       ");
	for(i=3;i<=15;i++)
		{
		gotoxy(26,i);
		cprintf("  ");
		}
	textbackground(LIGHTGRAY);
	for(i=4;i<=24;i++)
		{
		int ch=196;
		if(i==4)
			{
			ch=218;
			}
		else if(i==24)
			{
			ch=191;
			}
		textcolor(0);
		gotoxy(i,2);
		cprintf("%c",ch);
		if(i==4)
			{
			ch=192;
			}
		else if(i==24)
			{
			ch=217;
			}
		gotoxy(i,14);
		cprintf("%c",ch);
		}
	while(1)
		{
		char ch1;
		if(w==1)
			{
			textbackground(LIGHTGREEN);
			}
		else
			{
			textbackground(LIGHTGRAY);
			}
		gotoxy(5,3);
		textcolor(RED);
		cprintf(" N");
		textcolor(0);
		cprintf("ew               ");

		if(w==2)
			{
			textbackground(LIGHTGREEN);
			}
		else
			{
			textbackground(LIGHTGRAY);
			}
		gotoxy(5,4);
		textcolor(RED);
		cprintf(" O");
		textcolor(0);
		cprintf("pen...        F3 ");
		if(w==3)
			{
			textbackground(LIGHTGREEN);
			}
		else
			{
			textbackground(LIGHTGRAY);
			}
		gotoxy(5,5);
		textcolor(RED);
		cprintf(" S");
		textcolor(0);
		cprintf("ave           F2 ");
		if(w==4)
			{
			textbackground(LIGHTGREEN);
			}
		else
			{
			textbackground(LIGHTGRAY);
			}
		gotoxy(5,6);
		cprintf(" S");
		textcolor(RED);
		cprintf("a");
		textcolor(0);
		cprintf("ve as...        ");
		if(w==5)
			{
			textbackground(LIGHTGREEN);
			}
		else
			{
			textbackground(LIGHTGRAY);
			}
		gotoxy(5,7);
		cprintf(" Save a");
		textcolor(RED);
		cprintf("l");
		textcolor(0);
		cprintf("l          ");
		if(w==6)
			{
			textbackground(LIGHTGREEN);
			}
		else
			{
			textbackground(LIGHTGRAY);
			}
		gotoxy(5,9);
		textcolor(RED);
		cprintf(" C");
		textcolor(0);
		cprintf("hange dir...     ");
		if(w==7)
			{
			textbackground(LIGHTGREEN);
			}
		else
			{
			textbackground(LIGHTGRAY);
			}
		gotoxy(5,10);
		textcolor(RED);
		cprintf(" P");
		textcolor(0);
		cprintf("rint             ");
		if(w==8)
			{
			textbackground(LIGHTGREEN);
			}
		else
			{
			textbackground(LIGHTGRAY);
			}
		gotoxy(5,11);
		textcolor(RED);
		cprintf(" D");
		textcolor(0);
		cprintf("OS shell         ");
		if(w==9)
			{
			textbackground(LIGHTGREEN);
			}
		else
			{
			textbackground(LIGHTGRAY);
			}
		gotoxy(5,13);
		textcolor(RED);
		cprintf(" Q");
		textcolor(0);
		cprintf("uit        ALT+X ");
		gotoxy(80,25);
		key=bioskey(0);
		ch1=key;
		if(key==UP)
			{
			if(w>1)w-=1;
			else w=9;
			}
		else if(key==DO)
			{
			if(w<9)w+=1;
			else w=1;
			}

		else if(ch1=='N'||ch1=='n')
			{
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(5,1);
			cprintf(" F");
			textcolor(0);
			cprintf("ile ");
			return 1;
			}
		else if(ch1=='O'||ch1=='o')
			{
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(5,1);
			cprintf(" F");
			textcolor(0);
			cprintf("ile ");
			return 2;
			}
		else if(ch1=='S'||ch1=='s')
			{
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(5,1);
			cprintf(" F");
			textcolor(0);
			cprintf("ile ");
			return 3;
			}
		else if(ch1=='A'||ch1=='a')
			{
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(5,1);
			cprintf(" F");
			textcolor(0);
			cprintf("ile ");
			return 4;
			}
		else if(key==enter)
			{
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(5,1);
			cprintf(" F");
			textcolor(0);
			cprintf("ile ");
			return w;
			}
		else
			{
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(5,1);
			cprintf(" F");
			textcolor(0);
			cprintf("ile ");
			return 0;
			}
		}
	return 0;
	}
int maxppl()
	{
	int i;
	int line=0;
	int len;
	len=strlen(data1);
	for(i=0;i<len;i++)
		{
		if(data1[i]=='\n')
			{
			line++;
			}
		}
	return line;
	}
void design(long cn)
	{
	int i;
	double test;
	long perup,perr,def,mul,div;
	int fin;
	int cn2,linecn2;
	textcolor(15);
	cn2=cn;
	perup=0;
	linecn2=maxppl()+20;
	def=pline*100;
	mul=def/linecn2;
	perup=mul;
	fflush(stderr);
	if(mul<105)
		perup+=4;

	for(i=2;i<=23;i++)  //right
		{
		textbackground(BLUE);
		textcolor(15);
		gotoxy(80,i);
		if(i==23)
			{
			textbackground(CYAN);
			textcolor(BLUE);
			cprintf("%c",31);

			textbackground(BLUE);
			textcolor(15);
			}
		else if(i==3)
			{
			textbackground(CYAN);
			textcolor(BLUE);
			cprintf("%c",30);
			}
		else if(i==24)
			{
			textbackground(CYAN);
			textcolor(BLUE);
			cprintf("%c",31);
			textbackground(BLUE);
			textcolor(15);
			}
		else
			{
		 //	cnr++;
			if(perup==i)
				{
				textbackground(CYAN);
				textcolor(1);
				cprintf("%d",perup,254);
				}
			else
				{
				textcolor(CYAN);
				cprintf("%c",177);
				}
			}
		}
	printf("\033[26;%dH",1*0);
	cn2=extl(cn);
       //	lenc2=findl(cn);
	if(pline>0)
		{
		cn2-=1;
		}
	test=(cn*100)/1024;
	perup=test/1.7;
	perup+=19;

	for(i=1;i<=78;i++)
		{
		gotoxy(i,24);
		textbackground(BLUE);
		textcolor(15);
		//cnr=0;
		//printf("%d||",perup);
		if(i>=19&&i!=78)
			{
			//cprintf("%d",perup);
			if(perup==i)
				{
			       //	cprintf("pass");
				textbackground(CYAN);
				textcolor(1);
				cprintf("%c",254);
				}
			else
				{
				textcolor(CYAN);
				cprintf("%c",177);
				}
			}
		else if(i==18)
			{
			textbackground(CYAN);
			textcolor(BLUE);
			cprintf("%c",17);
			}
		else if(i==78)
			{
			textbackground(CYAN);
			textcolor(BLUE);
			cprintf("%c",16);
			textbackground(BLUE);
			textcolor(15);
			}

		else if(i==6)
			{
			int check;
			textcolor(15);
			check=cprintf(" %d:%d ",pline,cn2);
			i+=check-1;
			}
		else
			{
			cprintf("%c",205);
			}
		}
	for(i=2;i<=80;i++)        //up
		{
		textcolor(15);
		textbackground(BLUE);
		gotoxy(i,2);
		if(i==80)
			{
			cprintf("%c",187);
			}
		else if(i==3)
			{
			textcolor(15);
			cprintf("[");
			textcolor(LIGHTGREEN);
			cprintf("%c",254);
			textcolor(15);
			cprintf("]");
			i+=2;
			}
		else if(i==35)
			{
			int check;
			strupr(filename);
			check=cprintf(" %s ",filename);
			i+=check-1;
			}
		else if(i==74)
			{
			cprintf("1");
			}
		else if(i==76)
			{
			textcolor(15);
			cprintf("[");
			textcolor(LIGHTGREEN);
			cprintf("%c",18);
			textcolor(15);
			cprintf("]");
			i+=2;
			}
		else
			cprintf("%c",205);
		}
	for(i=2;i<=23;i++)//left
		{
		textcolor(15);
		textbackground(BLUE);
		gotoxy(1,i);
		if(i==2)
			cprintf("%c",201);
		else
			cprintf("%c",186);
		}
	gotoxy(1,24);
	cprintf("%c",200);
	gotoxy(79,24);
	textcolor(LIGHTGREEN);
	cprintf("%c%c",196,217);
	textbackground(LIGHTGRAY);
	gotoxy(1,25);
	textcolor(RED);
	cprintf(" F1");
	textcolor(0);
	cprintf(" Help");
	textcolor(RED);
	cprintf("  Alt-F8");
	textcolor(0);
	cprintf(" Next Msg");
	textcolor(RED);
	textcolor(RED);
	cprintf("  Alt-F7");
	textcolor(0);
	cprintf(" Prev Msg");
	textcolor(RED);
	cprintf("  Alt-F9");
	textcolor(0);
	cprintf(" Compile");
	textcolor(RED);
	cprintf("  F9");
	textcolor(0);
	cprintf(" Make");
	textcolor(RED);
	cprintf("  F10");
	textcolor(0);
	cprintf(" Menu");
	textbackground(1);
	textcolor(LIGHTGRAY);
	gotoxy(80,25);
	}
int shift()
	{
	int value=0;
	value=peek(0x0040, 0x0017);
	if(value&1||value&2)
		{
		return 1;
		}
	return 0;
	}
int edit()
	{
	int i,j;
	int w=1;
	textbackground(LIGHTGRAY);
	for(j=2;j<=13;j++)
		{
		for(i=11;i<=37;i++)
			{
			gotoxy(i,j);
			cprintf(" ");
			}
		}
	for(i=13;i<=39;i++)
		{
		textbackground(0);
		gotoxy(i,14);
		cprintf(" ");
		}
	for(i=3;i<=14;i++)
		{
		textbackground(0);
		gotoxy(38,i);
		cprintf("  ");
		}
	for(i=3;i<=13;i++)
		{
		textbackground(LIGHTGRAY);
		textcolor(0);
		gotoxy(12,i);
		cprintf("%c",179);
		gotoxy(36,i);
		cprintf("%c",179);
		}
	for(i=12;i<=35;i++)
		{
		gotoxy(i,2);
		cprintf("%c",196);

		gotoxy(i,5);
		cprintf("%c",196);

		gotoxy(i,11);
		cprintf("%c",196);

		gotoxy(i,13);
		cprintf("%c",196);
		}
	gotoxy(12,2);
	cprintf("%c",218);

	gotoxy(36,2);
	cprintf("%c",191);

	gotoxy(12,5);
	cprintf("%c",195);

	gotoxy(36,5);
	cprintf("%c",180);

	gotoxy(12,11);
	cprintf("%c",195);

	gotoxy(36,11);
	cprintf("%c",180);

	gotoxy(12,13);
	cprintf("%c",192);

	gotoxy(36,13);
	cprintf("%c",217);
	while(1)
		{
		char ch;
		int key;
		textbackground(GREEN);
		textcolor(RED);
		gotoxy(11,1);
		cprintf(" E");
		textcolor(0);
		cprintf("dit ");
		if(w==1&&shmax>0)
		       {
			textbackground(GREEN);

			textcolor(RED);
			gotoxy(13,3);
			cprintf(" U");
			textcolor(0);
			cprintf("ndo         Alt+BkSp ");
			}
		else if(shmax>0)
			{
			textbackground(LIGHTGRAY);

			textcolor(RED);
			gotoxy(13,3);
			cprintf(" U");
			textcolor(0);
			cprintf("ndo         Alt+BkSp ");
			}
		else
			{
			if(w==1)
				{
				textbackground(DARKGRAY);
				textcolor(LIGHTGRAY);
				}
			else
				{
				textbackground(LIGHTGRAY);
				textcolor(DARKGRAY);
				}
			gotoxy(13,3);
			cprintf(" U");
			cprintf("ndo         Alt+BkSp ");
			}
		if(w==2&&shmax>0)
		       {
			textbackground(GREEN);

			textcolor(RED);
			gotoxy(13,4);
			cprintf(" R");
			textcolor(0);
			cprintf("edo   Shift+Alt+BkSp ");

			}
		else if(shmax>0)
			{
			textbackground(LIGHTGRAY);

			textcolor(RED);
			gotoxy(13,4);
			cprintf(" R");
			textcolor(0);
			cprintf("edo   Shift+Alt+BkSp ");

			}
		else
			{
			if(w==2)
				{
				textbackground(DARKGRAY);
				textcolor(LIGHTGRAY);
				}
			else
				{
				textbackground(LIGHTGRAY);
				textcolor(DARKGRAY);
				}
		  //	textcolor(RED);
			gotoxy(13,4);
			cprintf(" R");
		//	textcolor(0);
			cprintf("edo   Shift+Alt+BkSp ");

			}
		if(w==3&&shmax>0)
		       {
			textbackground(GREEN);


			gotoxy(13,6);
			cprintf(" Cu");
			textcolor(RED);
			cprintf("t");
			textcolor(0);
			cprintf("         Shift+Del ");
			}
		else if(shmax>0)
			{
			textbackground(LIGHTGRAY);


			gotoxy(13,6);
			cprintf(" Cu");
			textcolor(RED);
			cprintf("t");
			textcolor(0);
			cprintf("         Shift+Del ");
			}
		else
			{
			if(w==3)
				{
				textbackground(DARKGRAY);
				textcolor(LIGHTGRAY);
				}
			else
				{
				textbackground(LIGHTGRAY);
				textcolor(DARKGRAY);
				}

			gotoxy(13,6);
			cprintf(" Cu");
	//		textcolor(RED);
			cprintf("t");
	  //		textcolor(0);
			cprintf("         Shift+Del ");
			}
		if(w==4&&shmax>0)
		       {
			textbackground(GREEN);

			textcolor(RED);
			gotoxy(13,7);
			cprintf(" C");
			textcolor(0);
			cprintf("opy          Ctr+Ins ");
			}
		else if(shmax>0)
			{
			textbackground(LIGHTGRAY);


			textcolor(RED);
			gotoxy(13,7);
			cprintf(" C");
			textcolor(0);
			cprintf("opy          Ctr+Ins ");
			}
		else
			{
			if(w==4)
				{
				textbackground(DARKGRAY);
				textcolor(LIGHTGRAY);
				}
			else
				{
				textbackground(LIGHTGRAY);
				textcolor(DARKGRAY);
				}

		//	textcolor(RED);
			gotoxy(13,7);
			cprintf(" C");
		  //	textcolor(0);
			cprintf("opy          Ctr+Ins ");
			}
		if(w==5&&clipboard[0]!='\0')
		       {
			textbackground(GREEN);

			textcolor(RED);
			gotoxy(13,8);
			cprintf(" P");
			textcolor(0);
			cprintf("aste       Shift+Ins ");
	       //	w=6;
			}
		else if(clipboard[0]!='\0')
			{
			textbackground(LIGHTGRAY);

			textcolor(RED);
			gotoxy(13,8);
			cprintf(" P");
			textcolor(0);
			cprintf("aste       Shift+Ins ");
	       //	w=6;
			}
		else
			{
			if(w==5)
				{
				textbackground(DARKGRAY);
				textcolor(LIGHTGRAY);
				}
			else
				{
				textbackground(LIGHTGRAY);
				textcolor(DARKGRAY);
				}

		       //	textcolor(RED);
			gotoxy(13,8);
			cprintf(" P");
			//textcolor(0);
			cprintf("aste       Shift+Ins ");
	       //	w=6;
			}
		if(w==6&&shmax>0)
		       {
			textbackground(GREEN);

			gotoxy(13,9);
			cprintf(" C");
			textcolor(RED);
			cprintf("l");
			textcolor(0);
			cprintf("ear         Ctr+Del ");
			}
		else if(shmax>0)
			{
			textbackground(LIGHTGRAY);

			gotoxy(13,9);
			cprintf(" C");
			textcolor(RED);
			cprintf("l");
			textcolor(0);
			cprintf("ear         Ctr+Del ");
			}
		else
			{
			if(w==6)
				{
				textbackground(DARKGRAY);
				textcolor(LIGHTGRAY);
				}
			else
				{
				textbackground(LIGHTGRAY);
				textcolor(DARKGRAY);
				}

			gotoxy(13,9);
			cprintf(" C");
		//	textcolor(RED);
			cprintf("l");
		  //	textcolor(0);
			cprintf("ear         Ctr+Del ");
			}
		gotoxy(13,10);
		textcolor(DARKGRAY);
		textbackground(LIGHTGRAY);

		if(w==7)
			{
			textcolor(LIGHTGRAY);
			textbackground(DARKGRAY);
			}
		cprintf(" Copy example          ");
		if(w==8)
			textbackground(GREEN);
		else
			{
			textbackground(LIGHTGRAY);
			}
		textcolor(RED);
		gotoxy(13,12);
		cprintf(" S");
		textcolor(0);
		cprintf("how clipboard        ");
		gotoxy(80,25);
		key=bioskey(0);
		ch=key;
		if(key==UP)
			{
			if(w>1)w-=1;
			else w=8;
			}
		else if(key==DO)
			{
			if(w<8)w+=1;
			else w=1;
			}

		else if(ch=='t'||ch=='T')
			{
			textbackground(GREEN);
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(11,1);
			cprintf(" E");
			textcolor(0);
			cprintf("dit ");
			return 3;
			}
		else if(ch=='c'||ch=='C')
			{
			textbackground(GREEN);
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(11,1);
			cprintf(" E");
			textcolor(0);
			cprintf("dit ");
			return 4;
			}

		else if(ch=='p'||ch=='P')
			{
			textbackground(GREEN);
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(11,1);
			cprintf(" E");
			textcolor(0);
			cprintf("dit ");
			return 5;
			}
		else if(ch=='L'||ch=='l')
			{
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(11,1);
			cprintf(" E");
			textcolor(0);
			cprintf("dit ");
			return 6;
			}
		else if(key==enter)
			{
		       //	textbackground(GREEN);
			textbackground(LIGHTGRAY);
			textcolor(RED);
			gotoxy(11,1);
			cprintf(" E");
			textcolor(0);
			cprintf("dit ");
			return w;
			}
		else break;
		}
	textbackground(LIGHTGRAY);
	textcolor(RED);
	gotoxy(11,1);
	cprintf(" E");
	textcolor(0);
	cprintf("dit ");
	return 0;
	}
