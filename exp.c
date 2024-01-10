#include <conio.h>
#include <stdio.h>
int lenskip(char *, int);
void main()
        {
        char data[1000]="\x1b[32m ✘ helloasdf";
        clrscr();   
        printf("lenskip=%d", lenskip(data,5));
        printf("\nlen ✘=%d", strlen(data));
        getch(); 
        }
int lenskip(char *token,int len)
        {
        int i, coun = 0;
        for (i = 0; i < strlen(token); i++)
                {
                if (token[i] == '\x1b')
                        {
                        i += 6;
                        }
                if (coun == len)
                        break;
                coun++;
                }
        return i;
        }
