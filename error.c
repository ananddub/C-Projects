#include <conio.h>
#include <stdio.h>
#include <string.h>
void errorload(char *, char *);
void errorp(char *);
int main()
        {
        char err[1000];
        char run[1000];
        clrscr();
        strcpy(run, "asdf");
        errorload(err, "gcc");
        getch();
        }
void errorload(char *token, char *run)
        {
        FILE *fp;
        char data[1000];
        strcat(run, " 2> /dev/null ");
        fflush(stderr);
        fp = popen(run, "r");
        fflush(stderr);
        if (fp == NULL)
                {
                printf("\nUnable to open file ");
                return;
                }
        printf("Data load:\n");
        token[0] = '\0';
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                printf("%s", data);
                strcat(token, data);
                }
        if (pclose(fp) == 0)
                {
                printf("error");
                return;
                }
        }
