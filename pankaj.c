#include <conio.h>
#include <stdio.h>
void clean(char *);
void append(char *, char *);
void readf(char *);
void main()
        {
        char filename[]="pankaj.txt";
        clean(filename);
        append(filename,"piyush\nanand\npankaj");
        readf(filename);
        }
void readf(char *filename)
        {
        FILE *fp;
        char data[1000];
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to write in file");
                return;
                }
        while(fgets(data,sizeof(data),fp)!=NULL)
                puts(data);
        fclose(fp);
        }
void append(char *filename, char *data)
        {
        FILE *fp;
        fp = fopen(filename, "a");
        if (fp == NULL)
                {
                printf("\nUnable to write in file");
                return;
                }
        fputs(data, fp);
        fclose(fp);
        }
void clean(char *filename)
        {
        FILE *fp;
        fp = fopen(filename, "x");
        if (fp == NULL)
                {
                printf("\nUnable to write in file");
                return;
                }
        fclose(fp);
        }
