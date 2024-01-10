// new language name anashi
#include <krishna.h>
int readf(char *);
int scan(char*);
// void
void main()
{
        scan("dma.hi");
}
int scan(char*filename)
        {
        FILE *fp;
        char *data = (char *)malloc(10000);
        fp = fopen(filename, "r");
        if (fp == NULL)
        {
                printf("\nUnable to open file");
                return 1;
        }
        while(fgets(data,10000,fp)!=NULL)
        {
                printf("%s",data);
        }
        free(data);
        return 0;
        }
void detect(char *token)
        {
        int i;
        for(i=0;i<strlen(token);i++)
                {
                if()
                }
        }
int readf(char *filename)
{
        FILE *fp;
        char *data = (char *)malloc(10000);
        fp = fopen(filename, "r");
        if (fp == NULL)
        {
                printf("\nUnable to open file");
                return 1;
        }
        while(fgets(data,10000,fp)!=NULL)
                {
                printf("%s",data);
                }
        free(data);
        return 0;
}
