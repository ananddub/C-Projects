
#include<stdio.h>
#include<conio.h>
void main()
	{
	int c;
	char a;
	clrscr();
	while(1)
		{
		clrscr();
		printf("\nFor exit enter 'Esc'");
		printf("\nEnter a character :");
		fflush(stdin);
		a=getche();
		if(kbhit())
			{
			a=getch();
			}
		printf("\n-------------------------------------------------------------------------\n");
		c=a;

		if(c>=65 && c<=90||c>=97 && c<=122)

			{
			if(a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
				{
				printf("'%c'is a charcter and vowel \n",a);
				printf("it is in uppercase");
				}
			else if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
				{
				printf("'%c' is a charcter and vowel \n",a);
				printf("it is in lowercase ");
				}
			else if(c>=65 && c<=90)
				{
				printf("'%c' is a character and consonant\n",a);
				printf("it is in upper case");
				}
			else if(c>=97 && c<=122)
				{
				printf("'%c' is a character and consonant\n",a);
				printf("it is in lower case");
				}
			}

		else if(c>=32 && c<=47||c>=91&&c<=96||c>=123&&c<=127||c>=58&&c<=64||c<=31)
			{
			if(a=='['||a==']')
				{
				printf("'%c' is a square bracket and special character ",a);
				}
			else if(a=='+')
				{
				printf("'%c' is addition operator and special character ",a);
				}
			else if(a=='-')
				{
				printf("'%c' is substraction operator and special character ",a);
				}
			else if(a=='\\')
				{
				printf("'%c' is backslash and special character ",a);
				}
			else if(a=='*')
				{
				printf("'%c' is multiplication operator and special character ",a);
				}
			else if(a=='/')
				{
				printf("'%c' is divition operator and spedcial character ",a);
				}
			else if(a=='%')
				{
				printf("'%c' is percentile operator and special character ",a);
				}
			else if(a=='&')
				{
				printf("'%c' is ampercent operator and special character ",a);
				}
			else if(a=='{'||a=='}')
				{
				printf("'%c' is curli bracket and special character ",a);
				}
			else if(a=='('||a==')')
				{
				printf("'%c' is parenthesis bracket and special character ",a);
				}
			else if(a==';')
				{
				printf("'%c' is semi colon and special character ",a);
				}
			else if(a==':')
				{
				printf("'%c' is colon and special character ",a);
				}
			else if(a=='"')
				{
				printf("'%c' is double qoute and special character ",a);
				}
			else if(a=='\'')
				{
				printf("'%c' is single qoute and special character ",a);
				}
			else if(a==',')
				{
				printf("'%c' is coma and special character ",a);
				}
			else if(a=='<')
				{
				printf("'%c' is less than operator and special character ",a);
				}
			else if(a=='>')
				{
				printf("'%c' is greater than operator and special character ",a);
				}
			else if(a=='.')
				{
				printf("'%c' is full stop or dot and special character ",a);
				}
			else if(a=='?')
				{
				printf("'%c' is question mark and special character ",a);
				}
			else if(a=='_')
				{
				printf("'%c' is underscore and special character ",a);
				}
			else if(a=='=')
				{
				printf("'%c' is equal operator and special character ",a);
				}
			else if(a=='!')
				{
				printf("'%c' is not operator and special character ",a);
				}
			else if(a=='@')
				{
				printf("'%c' is at the sign and special character ",a);
				}
			else if(a=='#')
				{
				printf("'%c' is hash sign and special character ",a);
				}
			else if(a=='$')
				{
				printf("'%c' is dolar sign and special character ",a);
				}
			else if(a=='^')
				{
				printf("'%c' is circum flex sign and special character ",a);
				}
			else if(a=='~')
				{
				printf("'%c' is tilde operator and special character ",a);
				}
			else if(a=='`')
				{
				printf("'%c' is grave accent sign and special character ",a);
				}
			else if(a=='|')
				{
				printf("'%c' is bar and special character ",a);
				}
			else if(a==' ')
				{
				printf("'%c' is space and special character ",a);
				}
			else if(c==0)
				{
				printf("'%c'is Null and special character",a);
				}
			else if(c==1)
				{
				printf("'%c'is start of heading and special character",a);
				}
			else if(c==2)
				{
				printf("'%c'is start of text  and special character",a);
				}
			else if(c==3)
				{
				printf("'%c'is end of text and special character",a);
				}
			else if(c==4)
				{
				printf("'%c'is end of transmission and special character",a);
				}
			else if(c==5)
				{
				printf("'%c'is enquiry and special character",a);
				}
			else if(c==6)
				{
				printf("'%c'is acknowledge and special character",a);
				}
			else if(c==7)
				{
				printf("'%c'is bell and special character",a);
				}
			else if(c==8)
				{
				printf("'%c'is backspace and special character",a);
				}
			else if(c==9)
				{
				printf("'%c'is horizontal tab and special character",a);
				}
			else if(c==10)
				{
				printf("'%c'is NL line feed, new line and special character",a);
				}
			else if(c==11)
				{
				printf("'%c'is vertical tab and special character",a);
				}
			else if(c==12)
				{
				printf("'%c'is NP form feed, new page and special character",a);
				}
			else if(c==13)
				{
				printf("'%c'is carriage return  and special character",a);
				}
			else if(c==14)
				{
				printf("'%c'is shift out  and special character",a);
				}
			else if(c==15)
				{
				printf("'%c'is shift in and special character",a);
				}
			else if(c==16)
				{
				printf("'%c'is data link escape and special character",a);
				}
			else if(c==17)
				{
				printf("'%c'is device control 1 and special character",a);
				}
			else if(c==18)
				{
				printf("'%c'is device control 2 and special character",a);
				}
			else if(c==19)
				{
				printf("'%c'is device control 3 and special character",a);
				}
			else if(c==20)
				{
				printf("'%c'is device control 4 and special character",a);
				}
			else if(c==21)
				{
				printf("'%c'is negative acknowledge and special character",a);
				}
			else if(c==22)
				{
				printf("'%c'is synchronous idle and special character",a);
				}
			else if(c==23)
				{
				printf("'%c'is end of trans. block and special character",a);
				}
			else if(c==24)
				{
				printf("'%c'is cancel and special character",a);
				}
			else if(c==25)
				{
				printf("'%c'is end of medium and special character",a);
				}
			else if(c==26)
				{
				printf("'%c'is substitute and special character",a);
				}
			else if(c==27)
				{
				break;
				}
			}
		else if(c>=48&&c<=57)
			{
			printf("'%c' is digit ",a);
			}
		printf("\nIt has ascii value is %d",a);
		printf("\n-------------------------------------------------------------------------\n");
		printf("\n\nPress any key to continue.....");
		getch();
		}
	}
