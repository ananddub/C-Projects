#include<stdio.h>#include<conio.h>int cmp(char*,char*);void main()        {        if(cmp("void","    void"))printf("true");        else printf("false");        }int cmp(char*source,char*dest)        {        for(;*source!='\0'||*dest!='\0';source++,dest++)                {                if(*source==*dest)continue;                return 0;                }        return 1;        }