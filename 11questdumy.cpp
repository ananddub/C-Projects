#include<stdio.h>
#include<string.h>


int intger_check()
	{
	int count=0,loop=0,test=0,data=0;
	char b[6];
	scanf("%s",&b);
	loop = strlen(b);
	while(test<=loop)
		{
		if(count==0)
			{
			if(b[0]=='0')
				{
				break;
				}
			else if(b[0]=='1')
				{
				data = data+1;
				}
			else if(b[0]=='2')
				{
				data = data+2;
				}
			else if(b[0]=='3')
				{
				data = data+3;
				}
			else if(b[0]=='4')
				{
				data = data+4;
				}
			else if(b[0]=='5')
				{
				data = data+5;
				}
			else if(b[0]=='6')
				{
				data = data+6;
				}
			else if(b[0]=='7')
				{
				data = data+7;
				}
			else if(b[0]=='8')
				{
				data = data+8;
				}
			else if(b[0]=='9')
				{
				data = data+9;
				}
			else {break;}
			}
	    else if(count>=1&& count != loop)
			{
			if(b[test]=='0')
				{
				data=data*10;
				}
			else if(b[test]=='1')
				{
				data = (data*10)+1;
				}
			else if(b[test]=='2')
				{
				data = (data*10)+2;
				}
			else if(b[test]=='3')
				{
				data = (data*10)+3;
				}
			else if(b[test]=='4')
				{
				data = (data*10)+4;
				}
			else if(b[test]=='5')
				{
				data = (data*10)+5;
				}
			else if(b[test]=='6')
				{
				data = (data*10)+6;
				}
			else if(b[test]=='7')
				{
				data = (data*10)+7;
				}
			else if(b[test]=='8')
				{
				data = (data*10)+8;
				}
			else if(b[test]=='9')
				{
				data = (data*10)+9;
				}
			else{data = 0;break;}
			
			}

	    else if(count==loop)
			{
			if(b[test]=='0')
				{
				data=data*10;
				}
			else if(b[test]=='1')
				{
				data = data+1;
				}
			else if(b[test]=='2')
				{
				data = data+2;
				}
			else if(b[test]=='3')
				{
				data = data+3;
				}
			else if(b[test]=='4')
				{
				data = data+4;
				}
			else if(b[test]=='5')
				{
				data = data+5;
				}
			else if(b[test]=='6')
				{
				data = data+6;
				}
			else if(b[test]=='7')
				{
				data = data+7;
				}
			else if(b[test]=='8')
				{
				data = data+8;
				}
			else if(b[test]=='9')
				{
				data = data+9;
				}
			else{break;}
			}
		count++;
		test++;
		}
	return data;
	}

int total_even_odd()
	{
	int st=0,end=0,even=0,odd=0,loop=0;
	system('cls');
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
			printf("\nRetry Enter start no. >>>");
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
			printf("\nRetry Enter end no. >>>");
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
	printf("\ntotal odd no. <<< %d\n\n",odd);
	return 0;
	}

int factorial()
	{
	long int fact=0,data=1,loop=0;
	system("cls");
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
			printf("\nRetry enter a no. for factorial >>>");
			fact=intger_check();
			}

		}
	while(fact>=1)
		{
		data = data*fact;
		fact--;
		}
	printf("\nfactorial <<< %d\n",data);

	return 0;
	}

int prime()
	{
	int n=0,ctr=2,test=0,loop=0;
	system("cls");
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
			printf("\nRetry Enter a no for prime >>>");
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
		printf("Prime no. <<< %d\n\n",n);
		}
	else
		{
		printf("Not Prime no. <<< %d\n\n",n);
		}

	return 0;
	}

int armstrong()
	{
	int n,rem,data=0,temp,loop=0;
	system("cls");
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
		printf("it is armstrong no. <<< %d\n\n",data);
		}
	else
		{
		printf("it is not armstorng no. <<< %d\n\n",data);
		}
	return 0;
	}
	
int grade()
	{
	int percent=0, marks=0,i=0,loop=0;

	system("cls");
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
				printf("\nRetry Enter your marks >>>");
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
		printf("\nGrade A <<< %d\n\n",percent);
		return 0;
		}
	if(percent>=80)
		{
		printf("\nGrade B <<< %d\n\n",percent);
		return 0;
		}
	if(percent>=60)
		{
		printf("\nGrade C <<< %d\n\n",percent);
		return 0;
		}
	if(percent>=40)
		{
		printf("\nGrade D <<< %d%n\n",percent);
		return 0;
		}


	printf("\nGrade Fail <<< %d\n\n",percent);
	return 0;
	}
	
void age()
	{
	int age=0,loop=0;
	printf("\nEnter your age >>> ");
	age = intger_check();
	while(loop==0)
		{
		if(age>0)
			{
			break;
			}
		else
			{
			printf("\nRetry Enter your age >>>");
			age=intger_check();
			}

		}
	if(age>=18)
		{
		printf("\nEligible for voting \n\n");

		}
	else
		{
		printf("\nNot Eligible for voting \n\n");
		}

	}
	
int nri()
	{
	char country_check;
	int loop_pass=0;
	printf("\nAre you NRi y/n >>> ");
	scanf("%s",&country_check);
	while(loop_pass==0)
		{
		if(country_check=='y')
			{
			return 1;
			}
		if(country_check=='n')
			{
			return 0;
			}
		printf("\nretry");
		printf("\nAre you Nri y/n >>> ");
		scanf("%s",&country_check);
		}
	return 1;
	}
	
int voting()
	{
	char country_check;
	int loop_pass=0;
	system("cls");
	printf("\nAre you Indian y/n >>> ");
	scanf("%s",&country_check);
	while(loop_pass==0)
		{
		if(country_check=='y')
			{
			return 1;
			}
		else if(country_check=='n')
			{
			return 0;
			}

		else 
			{
			printf("\nretry");
			printf("\nAre you Indian y/n >>> ");
			scanf("%s",&country_check);
			}

		}
	return 1;
	}
	
int swaping()
	{
	int a,b,loop=0;
	system("cls");
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
			printf("\nRetry Enter 1st no. >>>");
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
			printf("\nRetry Enter 2nd no. >>>");
			b=intger_check();
			}

		}
	printf("\nBefore Swaping \na<<< %d \nb<<< %d ",a,b);

	a=a+b;
	b=a-b;
	a=a-b;

	printf("\nAfter Swaping \n<<< %d \n<<< %d\n\n ",a,b);
	return 0;
	}
	
int fabonic()
	{
	long n,ctr=1,sum=0,sum1=0,sum2=0,p1=0,p2=1,loop=0;
	system("cls");
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
			printf("\nRetry Enter a number >>> ");
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

	printf("\n\nsum of fabonic no. <<< %ld\n\n",sum2);

	return 0;
	}

int mobile_no()
	{
	char  number[10];
	int loop=0,len=0;
	system("cls");
	while(loop==0)
		{
		printf("\nEnter a mobile number >>> ");
		scanf("%s",number);
		len=strlen(number);
		if(len==10)
			{
			printf("\nCorrect number \n\n");
			return 0;
			}

		printf("\10digit it has only %d digit\n",len);
		}
	return 0;
	}
	
int table()
	{
	int n,ctr=1,how=0,mul=0,loop=0;
	system("cls");
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
			printf("\nRetry Enter your table number >>>");
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
			printf("\nRetry How much table you want >>>");
			how=intger_check();
			}

		}
	while(ctr<=how)
		{
		mul=n*ctr;
		printf("\n%d * %d = %d ",n,ctr,mul);
		ctr++;
		}

	return 0;
	}
	
int even_odd_check()
	{
	int n=0,loop=0;
	system("cls");

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
			printf("\nRetry Enter a number >>>");
			n=intger_check();
			}

		}

	if(n%2==0)
		{
		printf("\nEven no. <<< %d\n\n",n);
		}
	else
		{
		printf("\nOdd no. <<< %d\n\n",n);
		}
	return 0;
	}
	
int main()
	{
	int loop=0,choice=0,country;
	while(loop==0)
		{
		system("cls");
		printf("1.  factorial \n");
		
		printf("2.  total even or odd in range \n");
		
		printf("3.  prime no. \n");
		
		printf("4.  armstorng no. \n");
			
		printf("5.  grade check \n");
		
		printf("6.  voiting machine \n");
		
		printf("7.  Swaping\n");
		
		printf("8.  Fabonic no \n");
		
		printf("9.  Mobile No check \n");
		
		printf("10. Table \n");
		
		printf("11. Even Odd check \n");
		
		printf("\n12. exit \n");
		
		printf("\nenter your choice >>> ");
		choice=intger_check();
		if(choice==1)
			{
			country = factorial();
			system("PAUSE");
			}
		if(choice==2)
			{
			country = total_even_odd();
			system("PAUSE");
			}
		if(choice==3)
			{
			country = prime();
			system("PAUSE");
			}
		if(choice==4)
			{
			country = armstrong();
			system("PAUSE");
			}
		if(choice==5)
			{
			country =grade();
			system("PAUSE");
			}
		if(choice==6 )
			{
			country = voting();
			if(country==1)
				{
				age();
				system("PAUSE");
				}
			else
				{
				country=nri();
				if(country==1)
					{
					age();
					system("PAUSE");
					}
				else
					{
					printf("\nNot Eligible\n");
					system("PAUSE");
					}
				}

			}
		if(choice==7)
			{
			country = swaping();
			system("PAUSE");
			}
		if(choice==8)
			{
			country = fabonic();
			system("PAUSE");
			}
		if(choice==9)
			{
			country = mobile_no();
			system("PAUSE");
			}

		if(choice==10)
			{
			country = table();
			system("PAUSE");
			}
		if(choice==11)
			{
			country = even_odd_check();
			system("PAUSE");
			}
		if(choice==12)
			{
			printf("thankyou for using\n\n ");
			break;
			}
		else
			{
			printf("Retry ");
			}
	}
	}
