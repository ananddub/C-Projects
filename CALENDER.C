#include<stdio.h>
#include<conio.h>

void main()
	{
	int year=0,week=0,month,day,leap=0,d_year=2022;
	while(1)
		{

		back1:
		top:
		up:
		back:
		clrscr();
		week=0;
		month=0;
		day=0;
		leap=0;
		d_year=2022;

		year=0;
		printf("For exit press '-1'");
		printf("\n\nEnter year :");
		fflush(stdin);
		scanf("%d",&year);
		if(year==-1)
			{
			goto exit;
			}
		if(year>0)
			{
			if(year>=2022)
				{
				break;
				}
			}

		printf("\n\nInvalid year it is less than 2022 ");
		printf("\n\nRetry press any key to continue .....");
		getch();

	}

	if(year%400==0)
		{
		leap=2;
		}
	else
		{
		if(year%4!=0)
			{
			leap = 1;
			}
		else
			{
			if(year%100!=0)
				{
				leap=2;
				}
			else
				{
				leap=1;
				}
			}
		}





	week=0;
	while(1)
		{

		clrscr();
		month=0;
		printf("For back press '-2'");
		printf("\n\nEnter month in number eg(1 for january) :");
		fflush(stdin);
		scanf("%d",&month);
		if(month == -2)
			{
			goto back1;
			}
		if(month>0)
			{
			if(month<=12)
				{
				break;
				}
			}

		printf("\n\nInvalid month");
		printf("\n\nRetry press any key to continue .....");
		getch();

		}
	d:
	clrscr();
	day=0;
	printf("For back press '-2'");
	printf("\n\nEnter month in number eg(1 for january) :%d\n",month);

	printf("\n\nEnter a day :");
	fflush(stdin);
	scanf("%d",&day);
	if(day==-2)
		{
		goto back;
		}

	if(leap==1)
		{
		switch(month)
			{
			case 1:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in January");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}

				printf("\n\nJanuary");
				break;
			case 2:

				if(day<=28&&day>0);
				else
					{
					printf("\nIvalid day in February");
					printf("\nPress any key to continue....");
					getch();

					goto d;


					}
				printf("\n\nFebruary");
				day = day+31;
				break;
			case 3:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in March");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nMarch");
				day = day+59;
				break;
			case 4:

				if(day<=30&&day>0);
				else
					{
					printf("\nIvalid day in April");
					printf("\nPress any key to continue....");
					getch();

					goto d;
					}
				printf("\n\nApril");
				day = day+90;
				break;
			case 5:

				if(day<=31&&day>0);

				 else
					{
					printf("\nIvalid day in May");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nMay");
				day=day+120;
				break;
			case 6:

				if(day<=30&&day>0);
				else
					{
					printf("\nIvalid day in June");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nJune");
				day = day+151;
				break;
			case 7:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in July");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nJuly");
				day = day+181;
				break;
			case 8:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in Agust");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nAgust");
				day = day+212;
				break;
			case 9:

				if(day<=30&&day>0);
				else
					{
					printf("\nIvalid day in September");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nSeptember");
				day = day+243;
				break;
			case 10:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in October");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nOctober");
				day = day+273;
				break;
			case 11:

				if(day<=30&&day>0);
				else
					{
					printf("\nIvalid day in November");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nNovember");
				day = day+304;
				break;
			case 12:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in Decmber");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nDecmber");
				day = day+334;

				break;

			default:
				printf("\n\nInvalid month ");
				printf("\nRetry Press any key ");
				getch();
				goto up;
			}
		}
	//leap yaer
	if(leap==2)
		{
		switch(month)
			{
			case 1:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in January");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}

				printf("\n\nJanuary");
				break;
			case 2:

				if(day<=29&&day>0);
				else
					{
					printf("\nIvalid day in February");
					printf("\nPress any key to continue....");
					getch();

					goto d;


					}
				printf("\n\nFebruary");
				day = day+31;
				break;
			case 3:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in March");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nMarch");
				day = day+60;
				break;
			case 4:

				if(day<=30&&day>0);
				else
					{
					printf("\nIvalid day in April");
					printf("\nPress any key to continue....");
					getch();

					goto d;
					}
				printf("\n\nApril");
				day = day+91;
				break;
			case 5:

				if(day<=31&&day>0);

				 else
					{
					printf("\nIvalid day in May");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nMay");
				day=day+121;
				break;
			case 6:

				if(day<=30&&day>0);
				else
					{
					printf("\nIvalid day in June");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nJune");
				day = day+152;
				break;
			case 7:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in July");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nJuly");
				day = day+182;
				break;
			case 8:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in Agust");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nAgust");
				day = day+213;
				break;
			case 9:

				if(day<=30&&day>0);
				else
					{
					printf("\nIvalid day in September");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nSeptember");
				day = day+244;
				break;
			case 10:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in October");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nOctober");
				day = day+274;
				break;
			case 11:

				if(day<=30&&day>0);
				else
					{
					printf("\nIvalid day in November");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nNovember");
				day = day+305;
				break;
			case 12:

				if(day<=31&&day>0);
				else
					{
					printf("\nIvalid day in Decmber");
					printf("\nPress any key to continue....");
					getch();

					goto d;

					}
				printf("\n\nDecmber");
				day = day+335;

				break;

			default:
				printf("\n\nInvalid month ");
				printf("\nRetry Press any key ");
				getch();
				goto up;
			}
		}
	//swapping
	if(d_year<=year);
	else
		{
		year=d_year+year;
		d_year=year-d_year;
		year=year-d_year;
		}



	while(d_year<year)
		{
		if(d_year==year)
			break;
		if(year%400==0)
			{
			day=day+366;
			}
		else
			{
			if(year%4!=0)
				{
				day=day+365;
				}
			else
				{
				if(year%100!=0)
					{
					day=day+366;
					}
				else
					{
					day=day+365;
					}
				}
			}
		d_year++;
		}
	printf("\nday = %d",day);
	while(day>0)
		{
		if(week==7)
			{
			week=0;
			}
		if(day>=1)
			{
			week++;
			}
		if(day==1&&week==0)
			{
			week++;
			}
		day--;

		}


	printf("\n\nLeap=%d",leap);

	switch(week)
		{
		case 1:
			printf("\nSaturday");
			break;
		case 2:
			printf("\nSunday");
			break;
		case 3:
			printf("\nMonday");
			break;
		case 4:
			printf("\nTuesday");
			break;
		case 5:
			printf("\nWednesday");
			break;
		case 6:
			printf("\nThurday");
			break;
		case 7:
			printf("\nFriday");
			break;
		}


	printf("\n\nPress any key to continue....... ");
	getch();
	goto top;
	exit:
	}
