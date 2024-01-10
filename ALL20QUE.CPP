#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
int intger_check()
	{
	int ch;
	scanf("%d",&ch);


	return ch;
	}

void pallindrome()
	{
	int i=0,len=0,ch=0,store=0;
	char data[20];
	clrscr();
	printf("\nenter a character >>> ");
	scanf("%s",&data);

	store=strlen(data);
	len=store;
	len--;
	while(len>=0)
		{

		if(data[i]==data[len])
			{
			ch++;
			}
		i++;
		len--;
		}
	if(store==ch)
		{
		printf("\nit is pallindrome <<< %s",data);
		}
	else
		{
		printf("\nit is not a pallindorme <<< %s",data);
		}
	}
int total_even_odd()
	{
	int st=0,end=0,even=0,odd=0,loop=0;
	clrscr();
	printf("\nenter start no. >>> ");
	st= intger_check();
	while(loop==0)
		{
		if(st>0)
			{
			break;
			}
		else
			{
			printf("\Retry Enter start no. >>>");
			st=intger_check();
			}

		}
	printf("\nenter end no. >>> ");
	end = intger_check();
	while(loop==0)
		{
		if(end>0)
			{
			break;
			}
		else
			{
			printf("\Retry Enter end no. >>>");
			end=intger_check();
			}

		}
	if(st<end){}
	else
		{
		st=st+end;
		end=st-end;
		st=st-end;
		}
	while(st<=end)
		{
		if(st%2==0)
			{
			even++;
			}
		else
			{
			odd++;
			}
		st++;
		}
	printf("\ntotal even no. <<< %d",even);
	printf("\ntotal odd no. <<< %d",odd);
	return 0;

	}


int factorial()
	{
	long int fact=0,data=1,loop=0;
	clrscr();
	printf("\nenter a no. for factorial >>> ");
	fact = intger_check();
	while(loop==0)
		{
		if(fact>0)
			{
			break;
			}
		else
			{
			printf("\Retry enter a no. for factorial >>>");
			fact=intger_check();
			}

		}
	while(fact>=1)
		{
		data = data*fact;
		fact--;
		}
	printf("\nfactorial <<< %d",data);

	return 0;
	}

int prime()
	{
	int n=0,ctr=2,test=0,loop=0;
	clrscr();
	printf("enter a no for prime >>> ");
	n = intger_check();
	while(loop==0)
		{
		if(n>0)
			{
			break;
			}
		else
			{
			printf("\Retry Enter a no for prime >>>");
			n=intger_check();
			}

		}
	while(ctr<n)
		{
		if(n%ctr==0)
			{
			test++;
			}

		ctr++;
		}
	if(test==0)
		{
		printf("Prime no. <<< %d",n);
		}
	else
		{
		printf("Not Prime no. <<< %d",n);
		}

	return 0;
	}

int armstrong()
	{
	int n,rem,data=0,temp,loop=0;
	clrscr();
	printf("Enter a no. for armstrong  >>> ");
	n = intger_check();
	while(loop==0)
		{
		if(n>0)
			{
			break;
			}
		else
			{
			printf("\nRetry Enter a no. for armstrong >>>");
			n=intger_check();
			}

		}
	temp=n;
	while(n>0)
		{
		rem=n%10;
		data=data+(rem*rem*rem);
		n=n/10;
		}
	if(temp==data)
		{
		printf("it is armstrong no. <<< %d",data);
		}
	else
		{
		printf("it is not armstorng no. <<< %d",data);
		}
	return 0;
	}
int grade()
	{
	int percent=0, marks=0,i=0,loop=0;

	clrscr();
	while(i==0)
		{
		printf("\nEnter your marks >>> ");
		marks = intger_check();
		while(loop==0)
			{
			if(marks>0)
				{
				break;
				}
			else
				{
				printf("\Retry Enter your marks >>>");
				marks=intger_check();
				}

			}
		if(marks>0)
			{
			if(marks<=80)
				{
				break;
				}
			}
		}
	percent=(marks*100)/80;

	if(percent>=90)
		{
		printf("\nGrade A <<< %d",percent);
		return 0;
		}
	if(percent>=80)
		{
		printf("\nGrade B <<< %d",percent);
		return 0;
		}
	if(percent>=60)
		{
		printf("\nGrade C <<< %d",percent);
		return 0;
		}
	if(percent>=40)
		{
		printf("\nGrade D <<< %d",percent);
		return 0;
		}


	printf("\nGrade Fail <<< %d",percent);
	return 0;
	}
void voting()
	{
	int age=0,a=0;
	char ind,nri;
	info:
	if(a==1||a==2||a==3)
		{

		clrscr();
		printf("Info");
		delay(25);
		printf("\nit is a voting machine program");
		delay(25);
		printf("\nFirst it check indian or not ");
		delay(25);
		printf("\nIf yes it will ask your age to check \nwhether it is greater than or equal to 18age");
		delay(25);
		printf("\nif no it will ask are you nri or nott");
		delay(25);
		printf("\nIf yes it will check your age to check \nwhether it is greater than or equal to 18age");
		delay(25);
		printf("\nIf no then it you will no eligible to vote");
		delay(25);
		printf("\n\nDevloped by");
		delay(25);
		printf("\nName = Anand Kumar Dubey");
		delay(25);
		printf("\nRoll no = 822110 ");
		delay(25);
		printf("\nCourse = BCA");
		delay(25);
		printf("\n\nPress any key to continue");
		getch();
		if(a==1)
			{
			goto up;
			}
		else if(a==2)
			{
			goto up2;
			}
		else
			{
			goto up3;
			}

		}

	while(1)
		{
		up:
		clrscr();
		printf("--------------------------------------Welcome---------------------------------");
		printf("\n\nFor exit press 'ESC'");
		printf("\nFor more information press 'i'");
		delay(25);
		printf("\n\nAre you Indian (y/n) : ");
		fflush(stdin);
		scanf("%c",&ind);
		age=ind;
		if(age==27)
			{
			goto exit;
			}
		else if(ind=='i')
			{
			a=1;
			goto info;
			}
		else if(ind=='y'||ind=='Y')
			{
			nri='n';
			}
		else if(ind=='n'||ind=='N')
			{
			up2:
			clrscr();
			printf("--------------------------------------Welcome---------------------------------");
			printf("\n\nFor exit press 'ESC'");
			printf("\nFor more information press 'i'");
			delay(25);
			printf("\n\nAre you Indian (y/n) : %c",ind);
			delay(25);
			printf("\n\nAre you Nri (y/n) : ");
			fflush(stdin);
			scanf("%c",&nri);
			age=nri;
			if(age==27)
				{
				goto exit;
				}
			else if(nri=='i')
				{
				a=2;
				goto info;
				}

			else if(nri=='y'||nri=='Y');

			else if(nri=='n'||nri=='N')
				{
				goto last;
				}

			else
				{
				printf("\nInvalid option");
				printf("\nRetry Press  any key to continue......... ");
				getch();
				goto up2;
				}
			}

		else
			{
			printf("\nInvalid option");
			printf("\nRetry Press  any key to continue......... ");
			getch();
			goto up;
			}

		while(1)
			{
			up3:
			clrscr();
			age=0;
			printf("--------------------------------------Welcome---------------------------------");
			printf("\n\nFor exit press '-1'");
			printf("\nFor more information press '-2'");
			delay(25);
			printf("\n\nAre you Indian (y/n) : %c",ind);
			if(nri=='y'||nri=='Y')
				{
				delay(25);
				printf("\n\nAre you Nri (y/n) : %c",nri);
				}
			delay(25);
			printf("\n\nEnter your age : ");
			fflush(stdin);
			scanf("%d",&age);
			if(age==-2)
				{
				a=3;
				goto info;
				}
			else if(age>0)
				{
				if(age>=18)
					{
					printf("\nEligible for voting");
					break;
					}
				else
					{
					last:
					printf("\nNot eligible for Voting");
					break;
					}
				}
			else if(age==-1)
				{
				goto exit;
				}

			else
				{
				printf("\nInvalid option");
				printf("\nRetry Press  any key to continue......... ");
				getch();
				}
			}
		printf("\n\n\nPress any keyo to continue.........");
		getch();
		}
	exit:
	}
int swaping()
	{
	int a,b,loop=0;
	clrscr();
	printf("Enter 1st no. >>> ");
	a = intger_check();
	while(loop==0)
		{
		if(a>0)
			{
			break;
			}
		else
			{
			printf("\Retry Enter 1st no. >>>");
			a=intger_check();
			}

		}
	printf("Enter 2nd no. >>> ");

	b = intger_check();
	while(loop==0)
		{
		if(b>0)
			{
			break;
			}
		else
			{
			printf("\Retry Enter 2nd no. >>>");
			b=intger_check();
			}

		}
	printf("\nBefore Swaping \na<<< %d \nb<<< %d ",a,b);

	a=a+b;
	b=a-b;
	a=a-b;

	printf("\n\After Swaping \na<<< %d \nb<<< %d ",a,b);
	return 0;
	}
int fabonic()
	{
	long n,ctr=1,sum=0,sum1=0,sum2=0,p1=0,p2=1,loop=0;
	clrscr();
	printf("Enter a number >>> ");
	n = intger_check();
	while(loop==0)
		{
		if(n>0)
			{
			break;
			}
		else
			{
			printf("\Retry Enter a number >>> ");
			n=intger_check();
			}

		}

	printf("\n%ld",sum);

	while(ctr<=n)
		{
		sum1 = sum2;
		sum=p1+p2;
		printf("\n%ld",sum);
		sum2=sum1+sum;
		p2=p1;
		p1=sum;
		ctr++;
		}

	printf("\n\nsum of fabonic no. <<< %ld",sum2);

	return 0;
	}

int mobile_no()
	{
	char  number[10];
	int loop=0,len=0;
	clrscr();
	while(loop==0)
		{
		printf("\nEnter a mobile number >>> ");
		scanf("%s",number);
		len=strlen(number);
		if(len==10)
			{
			printf("\nCorrect number ");
			return 0;
			}

		printf("\10digit it has only %d digit\n",len);
		}
	return 0;
	}
int table()
	{
	int n,ctr=1,how=0,mul=0,loop=0;
	clrscr();
	printf("\nEnter your table number >>> ");
	n = intger_check();
	while(loop==0)
		{
		if(n>0)
			{
			break;
			}
		else
			{
			printf("\Retry Enter your table number >>>");
			n=intger_check();
			}

		}
	printf("\nHow much table you want >>> ");
	how = intger_check();
	while(loop==0)
		{
		if(how>0)
			{
			break;
			}
		else
			{
			printf("\Retry How much table you want >>>");
			how=intger_check();
			}

		}
	while(ctr<=how)
		{
		mul=n*ctr;
		delay(25);
		printf("\n%d * %d = %d ",n,ctr,mul);
		ctr++;
		}

	return 0;
	}
int even_odd_check()
	{
	int n=0,loop=0;
	clrscr();

	printf("\nenter a number >>> ");
	n = intger_check();
	while(loop==0)
		{
		if(n>0)
			{
			break;
			}
		else
			{
			printf("\Retry Enter a number >>>");
			n=intger_check();
			}

		}

	if(n%2==0)
		{
		printf("\nEven no. <<< %d",n);
		}
	else
		{
		printf("\nOdd no. <<< %d",n);
		}
	return 0;
	}
void main()
	{
	int loop=0,choice=0,country;
	while(loop==0)
		{
		clrscr();
		printf("1.  factorial \n");
		delay(25);
		printf("2.  total even or odd in range \n");
		delay(25);
		printf("3.  prime no. \n");
		delay(25);
		printf("4.  armstorng no. \n");
		delay(25);
		printf("5.  grade check \n");
		delay(25);
		printf("6.  voiting machine \n");
		delay(25);
		printf("7.  Swaping\n");
		delay(25);
		printf("8.  Fabonic no \n");
		delay(25);
		printf("9.  Mobile No check \n");
		delay(25);
		printf("10. Table \n");
		delay(25);
		printf("11. Even Odd check \n");
		delay(25);
		printf("12. Pallindrome check\n");
		delay(25);
		printf("\n13. exit \n");
		delay(25);
		printf("\nenter your choice >>> ");

		choice=intger_check();
		if(choice==1)
			{
			country = factorial();
			getch();
			}
		else if(choice==2)
			{
			country = total_even_odd();
			getch();
			}
		else if(choice==3)
			{
			country = prime();
			getch();
			}
		else if(choice==4)
			{
			country = armstrong();
			getch();
			}
		else if(choice==5)
			{
			country =grade();
			getch();
			}
		else if(choice==6 )
			{
			voting();
			}
		else if(choice==7)
			{
			country = swaping();
			getch();
			}
		else if(choice==8)
			{
			country = fabonic();
			getch();
			}
		else if(choice==9)
			{
			country = mobile_no();
			getch();
			}

		else if(choice==10)
			{
			country = table();
			getch();
			}
		else if(choice==11)
			{
			country = even_odd_check();
			getch();
			}
		else if(choice==12)
			{
			pallindrome();
			getch();
			}
		else if(choice==13)
			{

			break;
			}
		else
			{
			printf("\n\nInvalid input");
			printf("\nRetry Press any key to continue ......");
			getch();
			}
		}
	}
