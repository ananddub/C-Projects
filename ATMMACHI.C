#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
	{
	char user[100][50]={{"admin"},{"Sanjay_sir"},{"Denis_Richi"},{"Mark_zuckerberg"},{"Steve_jobs"},{"Elon_Musk"},{"Mukes_ambani"},{"Anand_Dubey"},{"Piyush_sing"},{"Shiv"},{"Abhishek"},{"Anurag"},{"Sonu"},{"Pankaj"},{"Shreyansh"},{"Bhaivab"},{"Abhinav"},{"Mithu"},{"Ankur"}};
	char pass[100][25]={{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"},{"1234"}},scrkey[]="sanjay_sir";
	char ch,user1[100],pass1[100],carr[100];
	long money[100],money1;
	int star=0,cn3=0,chrint,sn=0;
	int cn,in,cmp,cn1,cn2=0,lg=0,flag=0,psw=0;
	int cmpresult,i,j,adminc,len,cr=19,count=0,st=0,st2=0;
	long dumy=0,sum=0;
	textcolor(WHITE);
	fflush(stdout);
	clrscr();
	for(i=0;i<100;i++)
		{
		money[i]=-1;
		}
	 for(i=18;i>=0;i--)
		{
		dumy+=10000;
		money[i]=dumy;
		}
	 money[0]=0;
	if(cr==500)
		{
		cr_up:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ATM MACHINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\nEnter your user name :");
		fflush(stdout);
		fflush(stdin);
		scanf("%s",&user[cr]);
		for(i=0;i<=100;i++)
			{
			cmpresult=strcmp(user[cr],user[i]);
			if(cmpresult==0&&cr!=i)
				{
				printf("\nUser already exist ");
				printf("\nPress any key to continue....");
				getch();
				goto cr_up;
				}
			}
		cn=0;
		pdup:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ATM MACHINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\nEnter your user name :%s",user[cr]);
		printf("\nEnter your Password  :");
		for(i=1;i<=cn;i++)
			{
			printf("*");
			}
		fflush(stdin);
		pass[cr][cn]=getche();
		in = pass[cr][cn];

		if(in==13)
			{
			if(cn>0)
				pass[cr][cn++]='\0';
			else
				{
				printf("\n\n\npassword could be empty");
				printf("\nPress any key to continue...");
				getch();
				goto pdup;
				}
			}
		else if(in==8&&cn>0)
			{
			cn--;
			goto pdup;
			}
		else if(in==8&&cn==0)goto pdup;
		else
			{
			cn++;
			goto pdup;
			}
		len=strlen(pass[cr]);
		if(len<4)
			{
			printf("\nPassword length should be minum 4digit");
			printf("\nPress any key to continue...");
			cn=0;
			getch();
			goto pdup;
			}
		cn-=2;
		cn1=0;
		pdup1:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ATM MACHINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\nEnter your user name :%s",user[cr]);
		printf("\nEnter your Password  :");

		for(i=0;i<=cn;i++)
				{
				printf("*");
				}
		printf("\nConfirm your Password:");
		for(i=1;i<=cn1;i++)
			{
			printf("*");
			}
		fflush(stdin);
		pass1[cn1]=getche();
		in = pass1[cn1];

		if(in==13)
			{
			if(cn1>0)
				pass1[cn1++]='\0';
			else
				{
				printf("\n\n\npassword could be empty");
				printf("\nPress any key to continue...");
				getch();
				goto pdup1;
				}
			}
		else if(in==8&&cn1>0)
			{
			cn1--;
			goto pdup1;
			}
		else if(in==8&&cn1==0)goto pdup1;
		else
			{
			cn1++;
			goto pdup1;
			}

		cmp=strcmp(pass[cr],pass1);
		if(cmp!=0)
			{
			printf("\n\nPassword does not matched");
			printf("\nPress any key to continue...");
			getch();
			cn=0;
			goto pdup;
			}

		cn1-=2;
		while(1)
			{
			clrscr();

			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ATM MACHINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
			printf("\n\nEnter your user name :%s",user[cr]);
			printf("\nEnter your Password  :");

			for(i=0;i<=cn;i++)
				{
				printf("*");
				}
			printf("\nConfirm your Password:");
			for(i=0;i<=cn1;i++)
				{
				printf("*");
				}
			printf("\nEnter your Depositial amount :");
			fflush(stdin);
			if(scanf("%lu",&money[cr]))
				{
				if(money[cr]>=0)
					break;


				else
					{
					printf("\n\nYour money should zero or above zero");
					printf("\nPress any key to continue...");
					getch();
					}
				}
		       else
				{
				printf("\nIt should be number ");
				printf("\nPress any key to continue....");
				getch();
				}
			}
		cr++;
		printf("\n\nYour Account is successfully Created ");
		printf("\nPress any key to continue...");
		getch();
		goto hm_up;
		}
	if(i==1000)
		{
		//Acount Information
		acup:
		clrscr();
		cn1=0;
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ATM MACHINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\nEnter your user name :");
		fflush(stdin);
		scanf("%s",user1);

		acup1:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ATM MACHINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\nEnter your user name :%s",user1);
		printf("\nEnter your Password  :");

		for(i=1;i<=cn1;i++)
				{
				printf("*");
				}

		fflush(stdin);
		pass1[cn1]=getche();
		in = pass1[cn1];

		if(in==13)
			{
			if(cn1>0)
				pass1[cn1++]='\0';
			else
				{
				printf("\n\n\npassword could be empty");
				printf("\nPress any key to continue...");
				getch();
				goto acup1;
				}
			}
		else if(in==8&&cn1>0)
			{
			cn1--;
			goto acup1;
			}
		else if(in==8&&cn1==0)goto acup1;
		else
			{
			cn1++;
			goto acup1;
			}
		cn=cn1;
		st=0;
		count=0;
		for(i=0;i<100;i++)
			{
			cmpresult=strcmp(user1,user[i]);
			adminc=strcmp(user1,user[0]);
			if(adminc==0)
				{

				cmpresult=strcmp(pass1,pass[0]);
				if(cmpresult==0)
						{
						cn1=0;
						scup:
						clrscr();

						printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ATM MACHINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
						printf("\n\nEnter your user name :%s",user1);
						printf("\nEnter your Password  :");

						for(i=2;i<=cn;i++)
							{
							printf("*");
							}
						printf("\nEnter a security key :");
						for(i=1;i<=cn1;i++)
							{
							printf("*");
							}
						fflush(stdin);
						pass1[cn1]=getche();
						in = pass1[cn1];

						if(in==13)
							{
							if(cn1>0)
								pass1[cn1++]='\0';

							else
								{
								printf("\n\n\npassword could be empty");
								printf("\nPress any key to continue...");
								getch();
								goto scup;
								}
							}
						else if(in==8&&cn1>0)
							{
							cn1--;
							goto scup;
							}

						else if(in==8&&cn1==0)goto scup;
						else
							{
							cn1++;
							goto scup;
							}

						//if(1)
							{
							adminc=strcmp(pass1,scrkey);
							if(adminc==0)
								{
								count=1;
								lg=1;
								st=i;
								}

							else
								{
								count=0;
								printf("\n\n\nSecurity code doesnot matched ");
								printf("\nPress any key to continue.....");
								getch();
								goto acup;
								}
							}
						}

				}

			else if(cmpresult==0)
				{

				cmpresult=strcmp(pass1,pass[i]);
				psw=i;
				if(cmpresult==0)
						{
						count=1;
						st=i;
						}

				}
			}
		if(count)
			{
			while(1)
				{
				main:
				clrscr();
				printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ATM MACHINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
				printf("\n\n\t\t\t\t1.Check Balance");
				printf("\n\t\t\t\t2.Deposit money");
				printf("\n\t\t\t\t3.Withdraw money");
				printf("\n\t\t\t\t4.Send money");
				if(lg)
					printf("\n\t\t\t\t5.Customer account");
				else
					printf("\n\t\t\t\t5.password change");
				printf("\n\t\t\t\t6.logout");
				printf("\n\t\t\t\t7.back");
				printf("\n\t\t\t\t8.Exit");

				printf("\n\nEnter your choice :");
				ch=getchar();
				if(ch=='1')
					{
					printf("\n\nYour Ballance is %lu",money[st]);
					}
				else if(ch=='2')
					{
					addup:
					clrscr();
					printf("\nEnter your Depositial amount :");
					fflush(stdin);
					if(scanf("%ld",&money1))
						{

							{
							money[st] += money1;

							printf("\n\nAmount Added sucessfully ");
							printf("\nYour current amount is %lu",money[st]);
							}

						}
					else
						{
						printf("\nIt should be number ");
						printf("\nPress any key to continue....");
						getch();
						goto addup;
						}
					}
				else if(ch=='3')
					{
					wdup:
					printf("\nEnter your withdraw amount :");
					fflush(stdin);
					if(scanf("%ld",&money1));
					else
						{
						printf("\nIt should be number ");
						printf("\nPress any key to continue....");
						getch();
						goto wdup;
						}
					if(money1>money[st])
						{
						printf("\n\nYour withdraw ammount is more than you ballance");
						printf("\nPress any key contnue....");
						getch();
						goto wdup;
						}
					money[st] -= money1;
					printf("\n\nAmount withdraw sucessfully ");
					printf("\nYour current ballance : %ld",money[st]);
					}
				else if(ch=='4')
					{
					rcup:
					clrscr();
					printf("Reciever Name :");
					fflush(stdin);
					scanf("%s",user1);
					cmpresult=strcmp(user1,user[st]);

					if(cmpresult==0)
						{
						printf("\nYou can send money own");
						printf("\nPress any key to continue...");
						getch();
						goto rcup;
						}
					adminc=strcmp(user1,user[0]);
					if(adminc==0)
						{
						printf("\nReciver user name doesnot exist ");
						printf("\nPress any key to continue...");
						getch();
						goto main;
						}

					count=0;
					for(i=0;i<100;i++)
						{
						cmpresult=strcmp(user1,user[i]);
						if(cmpresult==0)
							{
							count=1;
							st2=i;
							break;
							}
						}
					if(count)
						{
						sdup:
						clrscr();
						printf("Reciever Name :%s",user1);
						printf("\nEnter your amount to transfer :");
						if(scanf("%ld",&money1));
						else
							{
							printf("\nIt should be number ");
							printf("\nPress any key to continue....");
							getch();
							goto sdup;
							}
						if(money1>money[st])
							{
							printf("\nInsuffcient Amount ");
							printf("\nPress any key to continue....");
							getch();
							goto sdup;
							}
						while(1)
							{
							clrscr();
							printf("Reciever Name :%s",user1);
							printf("\nEnter your amount to transfer :%ld",money1);
							fflush(stdin);
							printf("\n\nDo you really want to transfer %s money %ld \n\nPress y for confirmation and n for cancel :",user[st],money1);
							ch=getchar();
							if(ch=='y')break;
							else if(ch=='n')
								{
								printf("\n\nTransaction is Cancledd succussfully");
								printf("\nPress any key to continue.....");
								goto main;
								}
							else
								{
								printf("\n\nInvalid option\npress any key to continuee...");
								getch();
								}
							}
						money[st]-=money1;
						money[st2]+=money1;
						printf("\nTransaction  completed");
						printf("\nYour current ballance :%ld",money[st]);

						}
					else
						{
						printf("\nReciver user name doesnot exist ");
						printf("\nPress any key to continue...");
					     //	goto rcup;

						}
					}

				else if(ch=='5')
					{
					if(lg)
						goto cmvw;
					else
						goto pshm;
					}

				else if(ch=='6')
					{
					lg=0;
					goto acup;
					}
				else if(ch=='7')
					{
					lg=0;
					break;
					}
				else if(ch=='8')
					{
					goto exit;
					}
				else
					{
					printf("\n\nInvalid option");
					printf("\nPress any key to continue....");

					}
				getch();
				}
			}
			else
				{
				printf("\nUser name or password is incorrect");
				printf("\nPress any key to continue.....");
				getch();
				goto acup;
				}
		}
	if(i=='a')
		{
		pshm:
		cn=0;
		cn2=0;
		pswch1:
		clrscr();
		printf("Enter your Password :");
		for(i=1;i<=cn;i++)
			{
			printf("*");
			}
		pass1[cn]=getche();
		in=pass1[cn];
		if(in==13&&cn>0)pass1[cn++]='\0';
		else if(in==8)
			{
			if(cn>0)

				cn--;
			else ;
			goto pswch1;
			}
		else
			{
			cn++;
			goto pswch1;
			}
		cmp=strcmp(pass1,pass[psw]);
		if(cmp==0)
			{
			cn=0;
			pswch2:
			clrscr();
			printf("create your Password :");
			for(i=1;i<=cn;i++)
				{
				printf("*");
				}
			pass1[cn]=getche();
			in=pass1[cn];
			if(in==13&&cn>0)pass1[cn++]='\0';
			else if(in==8)
				{
				if(cn>0)
					cn--;
				else ;

				goto pswch2;
				}
			else
				{
				cn++;
				goto pswch2;
				}
			cn--;
			cn2=0;
			pswch3:
			clrscr();
			printf("Create your Password :");
			for(i=1;i<=cn;i++)
				{
				printf("*");
				}
			printf("\nConfirm your Password :");
			for(i=1;i<=cn2;i++)
				{
				printf("*");
				}
			pass[psw][cn2]=getche();
			in=pass[psw][cn2];
			if(in==13&&cn2>0)pass[psw][cn2++]='\0';
			else if(in==8&&cn2>0)
				{
				if(cn2>0)
					cn2--;
				else ;
				goto pswch1;
				}
			else
				{
				cn2++;
				goto pswch3;
				}
			cmp=0;
			cmp=strcmp(pass1,pass[psw]);
			if(cmp!=0)
				{
				printf("\n\nPassword  doesnot matched");
				printf("\nPress any key to continue...");
				getch();
				cn=0;
				goto pswch2;
				}
			printf("\n\nPassword changed succusfully");
			printf("\nPress any key to continue....");
			getch();
			}
		else
			{
			printf("\n\nWrong password");
			printf("\nPress any key to continue...");
			getch();
			}
		goto main;
		}
	if(i=='c')
		{
		int cd;
		cmvw:
		cn=0;
		cn2=0;
		find:
		clrscr();
		cn3=cn;
		cn3--;
		sn=0;
		sum=0;
		cd=70;
		printf("Sn\t\tName\t\t\t\tBalance");
		printf("\n");
		for(i=0;i<=cd;i++)
			printf("%c",196);
		printf("\n");
		for(i=1;money[i]!=-1;i++)
			{
			sn++;
			printf("\n%d\t\t\t%s\t\t\t",i,user[i]);
			if(i>8&&i!=14&&i!=10)printf("\t");
			if(money[i]<100000&&money[i]>=10000)printf(" ");
			if(money[i]<10000&&money[i]>=1000)printf("  ");
			if(money[i]<1000&&money[i]>=100)printf("   ");
			if(money[i]<100&&money[i]>=10)printf("   ");
			if(money[i]<10&&money[i]>=0)printf("    ");
			printf("%ldrs",money[i]);
			sum+=money[i];
			}
		if(cn==0)
			{
			star=0;
			chrint=0;
			}
		else if(star)
			{
			if(star==1)
				{
				clrscr();
				printf("Sn\t\tName\t\t\tBalance\n");
				for(i=0;i<=cd;i++)
					printf("%c",196);
				printf("\n");
				sn=0;
				sum=0;
				for(i=1;money[i]!=-1;i++)
					{

					len=strlen(user[i]);
					len--;

					if(user[i][len]==carr[cn3])
						{
						sn++;
						printf("\n%d\t\t%s\t\t\t",i,user[i]);
						if(i>8&&i!=10&&i!=14)printf("\t");
						if(money[i]<100000&&money[i]>=10000)printf(" ");
						if(money[i]<10000&&money[i]>=1000)printf("  ");
						if(money[i]<1000&&money[i]>=100)printf("   ");
						if(money[i]<100&&money[i]>=10)printf("    ");
						if(money[i]<10&&money[i]>=0)printf("     ");
						printf("%ldrs",money[i]);
						sum+=money[i];
						}
					}

				}
			else
				{
				clrscr();
				cn2=cn;
				cn2-=2;
				sn=0;
				sum=0;
				printf("Sn\t\tName\t\t\t\tBalance");
				printf("\n");
				for(i=0;i<=cd;i++)
					printf("%c",196);
				printf("\n");
				for(i=1;money[i]!=-1;i++)
					{
					len=strlen(user[i]);
					len--;
					for(j=1;j<len;j++)
						{

						if(user[i][j]==carr[cn2])
							{
							sn++;
							printf("\n%d\t\t%s\t\t\t",i,user[i]);
							if(i>8&&i!=14&&i!=10)printf("\t");
							if(money[i]<100000&&money[i]>=10000)printf(" ");
							if(money[i]<10000&&money[i]>=1000)printf("  ");
							if(money[i]<1000&&money[i]>=100)printf("   ");
							if(money[i]<100&&money[i]>=10)printf("    ");
							if(money[i]<10&&money[i]>=0)printf("     ");
							printf("%ldrs",money[i]);
							sum+=money[i];
							}
						}

					}


				}

			}
		if(cn<=1&&star==0)
			{
			clrscr();
			printf("Sn\t\tName\t\t\t\tBalance");
			sn=0;
			sum=0;
			printf("\n");
			for(i=0;i<=cd;i++)
				printf("%c",196);
			printf("\n");
			for(i=1;money[i]!=-1;i++)
				{
				if(user[i][cn3]==carr[cn3]||cn==0)
						{
						sn++;
						printf("\n%d\t\t%s\t\t\t",i,user[i]);
						if(i>8&&i!=14&&i!=10)printf("\t");
						if(money[i]<100000&&money[i]>=10000)printf(" ");
						if(money[i]<10000&&money[i]>=1000)printf("  ");
						if(money[i]<1000&&money[i]>=100)printf("   ");
						if(money[i]<100&&money[i]>=10)printf("    ");
						if(money[i]<10&&money[i]>=0)printf("     ");
						printf("%ldrs",money[i]);
						sum+=money[i];
						}

				}

			}
		else if(cn>1&&star==0)
				{
			clrscr();
			printf("Sn\t\tName\t\t\t\tBalance");
			sn=0;
			sum=0;
			printf("\n");
			for(i=0;i<=cd;i++)
				printf("%c",196);
			printf("\n");
			for(i=1;money[i]!=-1;i++)
				{
				flag=0;

				for(j=0;j<cn;j++)
					{
					if(user[i][j]==carr[j]||cn==0)
						{flag++;}
					}

				if(flag==cn)
					{
					sn++;
					printf("\n%d\t\t%s\t\t\t",i,user[i]);
					if(i>8&&i!=14&&i!=10)printf("\t");
					if(money[i]<100000&&money[i]>=10000)printf(" ");
					if(money[i]<10000&&money[i]>=1000)printf("  ");
					if(money[i]<1000&&money[i]>=100)printf("   ");
					if(money[i]<100&&money[i]>=10)printf("    ");
					if(money[i]<10&&money[i]>=0)printf("     ");
					printf("%ldrs",money[i]);
					sum+=money[i];
					}
				}

			}

		cn2=cn;
		cn2--;
		if(sn==0)
			{
			printf("\t\t\t   Not Found");
			}
		printf("\n");
		for(i=0;i<=cd;i++)
			printf("%c",196);
		printf("\n");
		printf("\n\t\t\t\t\t\tTotal :%ld rs",sum);
		printf("\nEnter your query :");
		for(i=0;i<=cn2;i++)
			{
			printf("%c",carr[i]);
			}
		fflush(stdin);
		carr[cn]=getche();
		in=carr[cn];
		cn2=cn;
		cn2++;
		if(in==13);
		else if(in==42)
			{
			star++;
			cn++;
			carr[cn2]='\0';
			goto find;
			}
		else if(in==8)
			{
			if(cn>0)
				{
				cn--;
				cn2=cn;
				cn2++;
				carr[cn2]='\0';
				if(star==2)
					star--;
				goto find;
				}
			else
				{
				goto find;
				}
		}
		else
			{
			if(star)
				{
				cn++;
				carr[cn2]='\0';
				chrint++;
				goto find;

				}
			else
				{
				cn++;
				carr[cn2]='\0';
				goto find;
				}
			}

		goto main;
		}
	while(1)
		{
		hm_up:
		clrscr();
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ATM MACHINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n\n\t\t\t\t1.Create Account");
		printf("\n\t\t\t\t2.Login");
		printf("\n\t\t\t\t3.Exit");
		printf("\n\n\n\n\nEnter your choice :");
		fflush(stdin);
		ch=getchar();
		if(ch=='0');
		else if(ch=='1')
			{
			goto cr_up;
			}
		else if(ch=='2')
			{
			goto acup;
			}
		else if(ch=='3')
			{
			break;
			}
		else
			{
			printf("\n\nInvalid Option");
			printf("\nPress any key to continue....");
			getch();
			continue;
			}
		}
	exit:
	}
