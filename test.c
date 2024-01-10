#include<stdio.h>
#include<conio.h>
int strfinds(char*,char*);
void main()
        {
        printf("%d",strfinds("hello","ll"));
        }
int strfinds(char*source,char*p)
        {
        char*ptr;
        char*cp=p;
        while(*source!=NULL)
                {
                cp=p;
                ptr=soucrce;
                while(*cp!=NULL)
                        {
                        if(*ptr==*cp)

                        else break;
                        cp+=1;

                        }
                source+=1;
                }

        }
