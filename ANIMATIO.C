#include<stdio.h>
#include<conio.h>

void main()
	{
	char name[100],rg,dl,rp,hl,ch;
	int skip=0,main_=0,a=0,cl=1;
	long range=0,delay=0, count_i=0,repeat=0,count_j=0,count_a=0,count_c=0;
	textcolor(15);
	cprintf("");
	if(skip==1)
		{
		main:
		clrscr();
		printf("\t<<<<<<<<<<<<<<<<<<<<<<<<<<< Main Menu >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\n1. Home");
		printf("\n2. Back");
		printf("\n3. Info");
		printf("\n4. Resume");
		printf("\n5. Exit");

		printf("\n\nEnter your choice :");
		fflush(stdin);
		ch=getch();

		if(ch=='1')
			{
			goto up1;
			}
		else if(ch=='2')
			{
			if(a==1)
				{
				a=0;
				goto up1;
				}
			else if(a==2)
				{
				a=0;
				goto up1;
				}
			else if(a==3)
				{
				a=0;
				goto up2;
				}
			else if(a==4)
				{
				a=0;
				goto up3;
				}
			else if(a==5)
				{
				a=0;
				goto up4;
				}

			}
		else if(ch=='3')
			{
			clrscr();
			printf("Info");
			printf("\nit is animation proigram \nit has many option");
			printf("\nfull costimzable in upp down and left right");
			printf("\n\nDevloped by");
			printf("\nName = Anand Kumar Dubey");
			printf("\nRoll no = 822110 ");
			printf("\nCourse = BCA");
			printf("\nSubject = PSPC");

			printf("\n\nPress any key to continue.......");
			getch();
			goto main;
			}
		else if(ch=='4')
			{
			if(a==1)
				{
				a=0;
				goto up1;
				}
			else if(a==2)
				{
				a=0;
				goto up2;
				}
			else if(a==3)
				{
				a=0;
				goto up3;
				}
			else if(a==4)
				{
				a=0;
				goto up4;
				}
			else if(a==5)
				{
				a=0;
				goto up5;
				}
			}
		else if(ch=='5')
			{
			goto exit;
			}
		else
			{
			clrscr();
			printf("\t<<<<<<<<<<<<<<<<<<<<<<<<<<< Main Menu >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
			printf("\n\n1. Home");
			printf("\n2. Back");
			printf("\n3. Info");
			printf("\n4. Resume");
			printf("\n5. Exit");

			printf("\n\nEnter your choice :%c",ch);
			printf("\n\nInvalid option");
			printf("\nRetry Press any key to continue.....");
			getch();
			goto main;
			}

		}
	while(1)
		{
		up1:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<< Welocome to animation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\n0.main menu ");
		printf("\n\nEnter your name to animate :");
		fflush(stdin);
		gets(name);
		if(name[0]=='0')
			{
			a =1;
			goto main;
			}
		up2:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<< Welocome to animation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\n0.main menu");
		printf("\n\nEnter your name to animate :%s",name);
		printf("\nEnter your range between (1to7) :");
		fflush(stdin);
		rg=getche();
		switch(rg)
			{
			case '0':

				a =2;
				goto main;
			case '1':
				range = 1*10;
				break;
			case '2':
				range = 2*10;
				break;
			case '3':
				range = 3*10;
				break;
			case '4':
				range = 4*10;
				break;
			case '5':
				range = 5*10;
				break;
			case '6':
				range = 6*10;
				break;
			case '7':
				range = 7*10;
				break;

			default:
				printf("\n\nInvalid range ");
				printf("\nPress any key to continue....");
				getch();
				goto up2;
			}
		up3:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<< Welocome to animation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\n0.main menu");
		printf("\n\nEnter your name to animate :%s",name);
		printf("\nEnter your range between (1to7) :%c",rg);
		printf("\nEnter your speed between(1to9):");
		fflush(stdin);
		dl=getche();
		switch(dl)
			{
			case '0':
				a=3;
				goto main;
			case '1':
				delay = 9*1000000;
				break;
			case '2':
				delay = 8*1000000;
				break;
			case '3':
				delay = 7*1000000;
				break;
			case '4':
				delay = 6*1000000;
				break;
			case '5':
				delay = 5*1000000;
				break;
			case '6':
				delay = 4*1000000;
				break;
			case '7':
				delay = 3*1000000;
				break;
			case '8':
				delay = 2*1000000;
				break;
			case '9':
				delay = 1*1000000;
				break;

			default:
				printf("\n\nInvalid range ");
				printf("\nPress any key to continue....");
				getch();
				goto up3;

			}

		up4:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<< Welocome to animation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\n0.main menu");
		printf("\n\nEnter your name to animate :%s",name);
		printf("\nEnter your range between (1to7) :%c",rg);
		printf("\nEnter your speed between(1to9):%c",dl);
		printf("\nEnter your repeation between(1to9)");
		fflush(stdin);
		rp = getche();
		switch(rp)
			{
			case '0':
				a=4;
				goto main;
			case '1':
				repeat=1;
				break;
			case '2':
				repeat=2;
				break;
			case '3':
				repeat=3;
				break;
			case '4':
				repeat=4;
				break;
			case '5':
				repeat=5;
				break;
			case '6':
				repeat=6;
				break;
			case '7':
				repeat=7;
				break;
			case '8':
				repeat=8;
				break;
			case '9':
				repeat=9;
				break;

			default:
				printf("\n\nInvalid range ");
				printf("\nPress any key to continue....");
				getch();
				goto up4;
			}
		up5:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<< Welocome to animation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\n0.main menu");
		printf("\n\nEnter your name to animate :%s",name);
		printf("\nEnter your range between (1to7) :%c",rg);
		printf("\nEnter your speed between(1to9):%c",dl);
		printf("\nEnter your repeation between(1to9) :%c",rp);
		printf("\n1.vertical \n2.horizontal");
		printf("\n\nEnter your choice :");
		fflush(stdin);
		hl = getche();
		if(hl=='0')
			{
			a=5;
			goto main;
			}
		else if(hl=='2')hl=' ';
		else if(hl=='1')
			{
			hl='\n' ;
			switch(rg)
				{
				case '1':
					range = 4;

					getch();
					break;
				case '2':
					range = 6;
					break;
				case '3':
					range = 8;
					break;
				case '4':
					range = 10;
					break;
				case '5':
					range = 15;
					break;
				case '6':
					range = 20;
					break;
				case '7':
					range = 25;
					break;
				}
			}
		else if(hl=='0')goto exit;
		else
			{
			printf("\n\nInvalid Option ");
			printf("\nPress any key to continue....");
			getch();
			goto up5;
			}


		for(count_a=0;count_a<repeat;count_a++)
			{
			for(count_i=0;count_i<=range;count_i++)
				{
				clrscr();
				if(cl==15)cl=1;
				if(cl==0)cl++;
				textcolor(cl);
				if(hl==' ')
					{
					cprintf("\n\n\n\n");
					}
				for(count_j=0;count_j<=count_i;count_j++)
					{
					if(hl=='\n')
						{
						cprintf("%c\t\t\t\t",hl);
						}
					else
						{
						cprintf("%c",hl);
						}
					}
				puts(name);
				if(hl==' ')
					{
					printf("\n<---------------------------------------------------------------------------->");
					}
				for(count_c=0;count_c<=delay;count_c++);
				cl++;
				}

			for(count_i=range;count_i>=0;count_i--)
				{
				clrscr();
				if(cl==15)cl=1;
				if(cl==0)cl++;
				textcolor(cl);
				if(hl==' ')
					{
					cprintf("\n\n\n\n");
					}
				for(count_j=0;count_j<=count_i;count_j++)
					{
					if(hl=='\n')
						{
						cprintf("%c\t\t\t\t",hl);
						}
					else
						{
						cprintf("%c",hl);
						}
					}
				puts(name);
				if(hl==' ')
					{
					printf("\n<---------------------------------------------------------------------------->");
					}
				for(count_c=0;count_c<=delay;count_c++);
				cl++;
				}
			}
		textcolor(15);
		cprintf("");
		printf("\n\n\nAnimation is over");
		printf("\nPress any key to continue.....");
		getch();
		}
	exit:
	}
