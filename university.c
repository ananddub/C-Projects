#include<stdio.h> 
#include<string.h>
#include<fcntl.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>
void start();
void logins();
void login();
void tc(int);
void clrscr();
void bk(int);
void gotoxy(int,int);
void ppass(int,int);
char getch();
void space(int,int,int);
void man(int,int);
int input(int,int,int,int);
void inputc(int); 
int kbhit();   
struct __admin 
    {
    char user[100];
    char temp[100]; 
    char pass[100]; 
    }; 
int cn=0;
struct __admin ad;
int main()
    {
    start();
    return 1;   
    }
void start()
    {
    bk(0); 
    clrscr();
    login();
    }
void login() 
    { 
    int ex=0;
    int flag=0;
    logins();
    bk(15); 
    tc(0);
    ad.temp[0]='\0';
    man(55,8 );
    space(51,18,20);
    space(51,20,20);  
    gotoxy(53 ,22);
    printf(" LOGIN ");
    while(1)  
        {
        
          
        bk(0);
        tc(0);
        gotoxy(100,62); 
        ex=0; 
        if(kbhit())
                {
              
                bk(15);
                tc(0);
                if(flag==0) 
                     ex=input(51,18,20,1); 
                else 
                     ex=input(51,20,20,0);
                } 
       
        if(ex)
            {
            flag++;
            if(flag==1)
                {
                ad.user[0]='\0';
                //strcpy(ad.temp,ad.user);
                sprintf(ad.user,"%s",ad.temp); 
                ad.temp[0]='\0'; 
                cn=0; 
                }
    
            if(flag==2) 
                {
                sprintf(ad.pass,"%s",ad.temp);
                ad.temp[0]='\0';
                break;   
                }
            } 
        }
    tc(5);
     bk(0); 
    printf("\nFlag=%d,temp=%s",flag,ad.temp ); 
    }
int input(int x,int y,int len,int flag) 
    {
    int in;
    char ch;
    int i; 
    int len2;
    ch=getch();
    in=ch;
         
    if(in==10)return 1;
    else if(in==27)return 1;
    else if(in!=127&&cn>len)return 0;
    else inputc(ch);    
    
    len2=strlen(ad.temp); 
    if(flag)
        {
        gotoxy(x,y);
        printf("%s",ad.temp,ch);
        }  
    else ppass(x,y); 
    for(i=len2;i<=len;i++)printf(" ");
   
    return 0;
    }
void inputc(int ch)
    {
    int in; 
    in=ch;
    if(in==127)
            {
            if(cn>0)
                {
                cn-=1;
                ad.temp[cn]='\0';
                }
            }
    else 
        {
        ad.temp[cn]=ch;
        cn+=1;
        ad.temp[cn]='\0';
        } 
    }
void logins()
    { 
    int i; 
    bk(15); 
    tc(1); 
    gotoxy(40,18);
    printf(" username ");
    gotoxy(40,20); 
    printf(" pass     ");
    tc(0); 
    for(i=5;i<=25;i++)
        { 
        bk(15);
        gotoxy(30,i); 
        printf(" ");
        gotoxy(80,i); 
        printf(" ");
        }
    for(i=31;i<=79;i++)
        {
         bk(15);
        gotoxy(i,5); 
        printf(" ");
        gotoxy(i,25);  
        printf(" ");
        }
    bk(0); 
    }
void ppass(int x,int y)
    {
    int len=strlen(ad.temp);
    int i; 
    gotoxy(x,y);
    for(i=0;i<len;i++)
        {
        printf("*");
        }
    }
void man(int x,int y)
    {
    int dx,dy;
    dx=x;
    dy=y;
    gotoxy(dx,dy); 
    printf(" ");
    dx=x-1;
    dy=y+1 ;
    gotoxy(dx,dy);
    printf("   "); 
    dx=x-2;
    dy=y+2;
    gotoxy(dx,dy);
    printf("     ");
    dy=y+3;  
    dx=x-1; 
    gotoxy(dx,dy); 
    printf("   "); 
    dy=y+4;
    dx=x-2;
    gotoxy(dx,dy);
    printf("     ");
    dy=y+5;
    dx=x-3;
    gotoxy(dx,dy); 
    printf("       "); 
 
    }
void space(int x,int y,int len)
    {
    int i=x;
    gotoxy(x,y);
    for(;i<=len+x;i++)
           {
            printf(" ");
           }

    }
void gotoxy(int x,int y)
    { 
    printf("\033[%d;%df",y,x);
    fflush(stdout);
    }
void tc(int color) 
    {
    printf("\033[38;5;%dm",color);
    }   
void bk(int color) 
    {
    printf("\033[48;5;%dm",color);
    }
void clrscr() 
    {
    printf("\033[2J\033[1;1H");
    }
int kbhit()
    { 
    struct termios   old,new;
    char ch;
    int oldf;
    tcgetattr(STDIN_FILENO,&old);
    new=old; 
    new.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&new);
    oldf=fcntl(STDIN_FILENO,F_GETFL);
    fcntl(STDIN_FILENO,F_GETFL,oldf|O_NONBLOCK);
    ch=getchar(); 
    tcsetattr(STDIN_FILENO,TCSANOW,&old);
    fcntl(STDIN_FILENO,F_GETFL,oldf);
    if(ch!=EOF)
        {  
        ungetc(ch,stdin);
        return 1;
        }
    return 0;
    }
char getch()
    {
    struct termios old,new;
    char ch;
    tcgetattr(STDIN_FILENO,&old);
    new=old;
    new.c_lflag&=~(ICANON|ECHO);   
    tcsetattr(STDIN_FILENO,TCSANOW,&new);
    ch=getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&old);
    tc(0); 
    return ch;
    }

