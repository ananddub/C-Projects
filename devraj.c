#include<stdio.h>
#include<uconio.h>
#define cprintf printf
void main() 
	{ 
	int i=0,j=0,h=23,w=75,x,y,fx,fy,l=3,in;
	char turbo[20],ch;
        clrscr();
        for(i=0;i<=h;i++)
                {
                for(j=0;j<=w;j++)
                        {
                        if(i==0 || i==h || j==0 || j==w)
                                {
                                textbackground(2);
                                textcolor(2);
                                printf("*");
                                }
                        else
                                {
                                if(i==x && j==y)
                                        {
                                        printf("ð",3);
                                        }
                                else if(i==fx && j==fy)
                                        {
                                        printf("‚",2);
                                        }
                                else
                                        {
                                        printf(" ");
                                        }
                                }
                        }
                printf("\n");
               }
                anup:
                if(w==1)
                        {
                        textbackground(GREEN);
                        textcolor(WHITE);
                        gotoxy(33,7);
                        cprintf(" Log in ");
                        }
                else
                        { 
                        textbackground(BLACK);
                        textcolor(WHITE);
                        gotoxy(33,7);
			cprintf(" Log in ");
			}
		if(w==2)
			{
			textbackground(GREEN);
			textcolor(WHITE);
			gotoxy(33,9);
			cprintf(" Check Balence ");
			}
		else
			{
			textbackground(BLACK);
			textcolor(WHITE);
			gotoxy(33,9);
			cprintf(" Check Balence ");
			}
		if(w==3)
			{
			textbackground(GREEN);
			textcolor(WHITE);
			gotoxy(33,11);
			cprintf(" Create Account");
			}
		else
			{
			textbackground(BLACK);
			textcolor(WHITE);
			gotoxy(33,11);
			cprintf(" Create Account");
			}
		if(w==4)
			{	
			textbackground(GREEN);
			textcolor(WHITE);
			gotoxy(33,13);
			cprintf(" Transfer Money");
			}
		else
			{
			textbackground(BLACK);
			textcolor(WHITE);
			gotoxy(33,13);
			cprintf(" Transfer Money");
			}
		if(w==5)
			{
			textbackground(GREEN);
			textcolor(WHITE);
			gotoxy(33,15);
			cprintf(" Add money ");
			}
		else
			{
			textbackground(BLACK);
			textcolor(WHITE);
			gotoxy(33,15);
			cprintf(" Add money ");
			}
		gotoxy(33,3);
		textbackground(BLACK);
		textcolor(RED);
		cprintf("MAIN MENU");
		gotoxy(3,5);
		printf("");
	ch=getche();
	switch(ch)
		{
		case '1':
			w=1;
			goto anup;
		case '2':
			w=2;
			goto anup;
		case '3':
			w=3;
			goto anup;
		case '4':
			w=5;
			goto anup;
		case '5':
			w=5;
			goto anup;
		}
	in=ch;
	if(ch=='w'||in==72)
		{
		if(w>1)
			w--;
		else
			w=5;
		goto anup;
		}
	else if(ch=='s'|| in==80)
		{
		if(w<5)
			w++;
		else
			w=1;
		goto anup;
		}
	else if(in==13)
		{
		if(w==5)goto exit;
		else if(w==1)
			{
			clrscr();
			printf("\nYou are under New");
			}
		else if(w==2)
			{
			clrscr();
			printf("\nYou are under old");
			}
		else if(w==3)			{
			clrscr();
			printf("\nYou are under Doc");
			}
		else if(w==4)
			{
			clrscr();
			printf("\nYou are under help");
			}
		getch();
		goto anup;
		}
	else
		{
		goto anup;
		}
	exit:
	}


