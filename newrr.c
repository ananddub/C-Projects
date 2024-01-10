#include <conio.h>
#include <stdio.h>
#include <string.h>
void rmfile(char *);
int chnew(char *);
void fappend(char *, char *);
void clone(char *, char *);
void fclear(char *);
void readf(char *);
void mfiler(char*);
int main()
        {
        mfiler("tt.c");  
        }
void mfiler(char *filename)
        {
        FILE *fp;
        int i;
        char data[10000];
        char temp[] = "_____temp.c"; 
        fclear(temp);
        fp = fopen(filename, "r");
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                rmfile(data);
                fappend(temp, data);
                // printf("%s", data);
                }
        // printf("\n*******************");
        fclose(fp);
        clone(filename, temp);
        readf(filename);
        }
void rmfile(char *t2)
        {
        char temp[10000];
        char *ptr = temp;
        char *token = t2;
        int i, count = 0;
        if (chnew(token))
                {
                *t2 = '\0';
                *ptr = '\0';
                }
        else
                for (; *token != '\0'; token++)
                        {
                        // if (*token == '\n')
                        //        count++;
                        *ptr = *token;
                        *ptr++;
                                //         }
                        //      else
                        //             break;
                        }
        *ptr = '\0';
        ptr = temp;
        strcpy(t2, ptr);
        }
int chnew(char *token)
        {
        for (; *token != '\0'; token++)
                {
                if (*token != '\n' && *token != ' ' && *token != '\t')
                        return 0;
                }
        return 1;
        }
void fappend(char *filename, char *token)
        {
        FILE *fp;
        fp = fopen(filename, "a");
        if (fp == NULL)
                {
                printf("\nUnable to open append file");
                return;
                }
        fputs(token, fp);
        fclose(fp);
        }
void clone(char *file1, char *file2) // clone same file
        {
        FILE *fp;
        int i;
        char data[1000000];
        fclear(file1);
        fp = fopen(file2, "r");
        if (fp == NULL)
                {
                printf("\nunable to open clone file");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                fappend(file1, data);
                }
        fclose(fp);
        }
void fclear(char *filename)
        {
        FILE *fp = fopen(filename, "w");
        if (fp == NULL)
                {
                printf("\nUnable to open file to clear");
                return;
                }
        fclose(fp);
        }
void readf(char *filename)
        {
        FILE *fp;
        int count = 0;
        char string[100000];
        fp = fopen(filename, "r");
        gotoxy(1, 15);
        if (fp == NULL)
                {
                printf("\n Unable to open file");
                return;
                }
        while (fgets(string, sizeof(string), fp) != NULL)
                {
                printf("%d |%s", count, string);
                count++;
                }
        if (count == 0)
                printf("file is blank");
        fclose(fp);
        }
