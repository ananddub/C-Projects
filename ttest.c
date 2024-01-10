#include <conio.h>
#include <stdio.h>
#include <string.h>
int errorLoad(char *, char *);
void errexact(char *, char *, int *);
int errline(char *);
void erract(char *, char *);
int llre(char *, char, int);
int strf(char *, char *);
int wordin(char *);
int opencl(char *, char, char);
void readl(char *);
int main()
        {
        char data[1000] = "char arr[100]={\"adsfaasdf\"sfaf\",carr[100];}fasdfasdfasdfasfd";
        clrscr(); 
        printf("opencl=%d len=%d\n", opencl(data, '"', '"'), strlen(data));
        readl(data);
        return 0;
        }
int opencl(char *token, char och, char cch)
        {
        int res = 0;
        int i = 0;
        int flag = 0;
        for (i = 0; token[i] != '\0'; i++)
                {
                if (och == cch)
                        {
                        if (och == token[i])
                                {
                                if(res)res=0;
                                else res=1;
                                }
                        }
                else
                        {
                        if (och == token[i])
                                res++;
                        else if (cch == token[i])
                                res--;
                        }
                if (res > 0)
                        flag = 1;
                if (res == 0 && flag == 1)
                        break;
                }
        printf("res=%d\n", res);
        return i;
        }
void readl(char *token)
        {
        int con = 0;
        int x = 1;
        while (*token != '\0')
                {
                gotoxy(10, 4);
                printf("index=%d", con++);
                gotoxy(x++, 6);
                printf(" %c", *token);
                getch();
                token++;
                }
        }
int wordin(char *token)
        {
        int i;
        int flag = 0;
        for (i = 0; i < strlen(token); i++)
                {
                if (token[i] == ' ' && flag == 0)
                        {
                        continue;
                        }
                else if (token[i] != ' ')
                        flag = 1;
                else if (token[i] == ' ')
                        break;
                }
        return i;
        }
int strf(char *dest, char *source)
        {
        int di = 0, si = 0;
        int i;
        int flag = 0;
        while (di < strlen(dest))
                {
                if (dest[di] == source[si])
                        {
                        di++;
                        si++;
                        flag = 1;
                        continue;
                        }
                else if (flag || flag == 0 && source[si] != ' ')
                        {
                        return 0;
                        }
                si++;
                }
        return 1;
        }
int funcheck(char *token)
        {
        char datatype[10][100] = {"void", "short", "int", "long", "float", "double", "char", "-1"};
        int i;
        for (i = 0; i <= 10; i++)
                {
                if (strstr(token, datatype) != NULL)
                        break;
                }
        return 0;
        }
void funcload(char *filename, char **token)
        {
        FILE *fp;
        int i;
        char data[10000];
        char in = 0;
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open function file");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                //    if (funccheck(data))
                        {
                        //               funcscan(data, token[in]);
                        in++;
                        }
                }
        strcpy(token[in], "-1");
        }
int errline(char *token)
        {
        int i;
        char ch[100];
        char temp[10000];
        char *ptr;
        char end;
        char st;
        ptr = temp;
        strcpy(temp, token);
        st = llre(ptr, ':', 1);
        end = llre(ptr, ':', 2);
        ptr[st] = '\0';
        ptr[end] = '\0';
        ptr += st + 1;
        strcpy(ch, ptr);
        // printf("\nst=%d end=%d",st,end);
        return atoi(ch);
        }
int llre(char *token, char ch, int in)
        {
        int i;
        int cou = 0;
        for (i = 0; i < strlen(token); i++)
                {
                if (token[i] == ch)
                        cou += 1;
                if (cou == in)
                        return i;
                }
        return -1;
        }
int errorLoad(char *token, char *command)
        {
        FILE *fp;
        char data[1000];
        char modifiedCommand[1100];
        int status;
        int index = 0;
        sprintf(modifiedCommand, "%s 2>error.txt", command);
        fp = popen(modifiedCommand, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file ");
                return -1;
                }
        token[0] = '\0';
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (strstr(data, "error") != NULL)
                        {
                        strcat(token, data);
                        }
                }
        status = pclose(fp);
        if (status == 0)
                {
                return 0;
                }
        else
                {
                return 1;
                }
        }
