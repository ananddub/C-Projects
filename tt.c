#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void filer(char *, const char[]);
void filew(const char[], const char[]);
void filea(const char[], const char[]);
void space(char *, const int);
void purify(char *);
void locexa(char *, char *, char *);
int swcheck(char *, const int);
void cmd(const char[], const char[]);
void cdcmd(const char[], const char[], const char[]);
void namech(char *);
void rmfile(char *);
int chnew(char *);
void fappend(char *, char *);
void clone(char *, char *);
void fclear(char *);
void readf(char *);
void mfiler(char *);
int main(int arg, char *argc[])
{
        char data[1000000];
        char name[10000] = "test";
        if (arg == 0)
        {
                printf("please give filename");
                return 0;
        }
        strcpy(name, argc[1]);
        namech(name);
        filer(data, "temp.txt");
        filew(data, name);
        printf("read :%s\n%s", name, data);
        return 1;
}
void filer(char *token, const char name[])
{
        FILE *fp;
        char data[10000];
        fp = fopen(name, "r");
        if (fp == NULL)
        {
                printf("unable to open file for read");
                return;
        }
        token[0] = '\0';
        while ((fgets(data, sizeof(data), fp)) != NULL)
        {
                purify(data);
                strcat(token, data);
        }
}
void namech(char *token)
{
        char data[1000];
        char cd[1000];
        char temp[1000];
        char run[10000];
        strcpy(data, token);
        if (strchr(data, '/') != NULL)
        {
                locexa(cd, data, temp);
                cdcmd(cd, "temp.txt", temp);
                //              mfiler("temp.txt");
        }
        else if (strstr(data, ".c") == NULL)
        {
                sprintf(token, "%s.c", data);
                printf("%s", token);
                cmd("temp.txt", token);
                //                mfiler("temp.txt");
        }
        // system(run);
}
void locexa(char *cd, char *data, char *temp)
{
        char tempc[1000];
        char *ptr = tempc;
        char cc[10000];
        char *token = cc;
        char len;
        int cn = 0;
        int tlen = 0;
        int i;
        len = 0;
        strcpy(tempc, data);
        cd[0] = '\0';
        temp[0] = '\0';
        strcpy(cc, tempc);
        for (i = strlen(tempc); ptr[i] != '/'; i--)
        {
                ptr[i] = '\0';
        }
        sprintf(cd, "%s", ptr);
        token[i] = '\0';
        token += i + 1;
        strcpy(temp, token);
}
void cdcmd(const char cd[], const char dest[], const char name[])
{
        FILE *fp;
        char clang[] = "clang-format --style=\"{BasedOnStyle: Microsoft, IndentWidth: 8}\"";
        char cmdrun[1000];
        char data[10000];
        sprintf(cmdrun, "cd %s && %s %s", cd, clang, name);
        fp = popen(cmdrun, "r");
        if (fp == NULL)
        {
                printf("unable to run command");
                return;
        }
        filew("", dest);
        while (fgets(data, sizeof(data), fp) != NULL)
        {
                filea(data, dest);
        }
        pclose(fp);
}
void cmd(const char dest[], const char name[])
{
        FILE *fp;
        char clang[] = "clang-format --style=\"{BasedOnStyle: Microsoft, IndentWidth: 8}\"";
        char cmdrun[1000];
        char data[10000];
        sprintf(cmdrun, "%s %s", clang, name);
        fp = popen(cmdrun, "r");
        if (fp == NULL)
        {
                printf("unable to run command");
                return;
        }
        filew("", dest);
        while (fgets(data, sizeof(data), fp) != NULL)
        {
                filea(data, dest);
        }
        pclose(fp);
}
void purify(char *token)
{
        static int switchc = 0;
        if (strstr(token, "switch") || switchc == 1)
        {
                //  switchc = swcheck(token, 8);
        }
        else if (strchr(token, '(') == NULL && strstr(token, "!=") == NULL && strstr(token, "==") == NULL &&
                 (strchr(token, '=') == NULL) && (strchr(token, '{') != NULL || strchr(token, '}') != NULL))
        {
                space(token, 8);
        }
}
int swcheck(char *token, const int sp)
{
        static int casee = 0;
        static int broc = 0;
        static int rest = 0;
        static int iff = 1;
        if (strstr(token, "switch") != NULL)
                rest = 1;
        else if (strchr(token, '=') == NULL && strchr(token, '{') != NULL)
        {
                broc += 1;
                space(token, sp);
        }
        else if (strchr(token, '(') == NULL && strstr(token, "!=") == NULL && strstr(token, "==") == NULL &&
                 strchr(token, ';') == NULL && strchr(token, '}') != NULL)
        {
                broc -= 1;
                space(token, sp);
        }
        else if (broc >= 1)
        {
                space(token, sp);
        }
        if (rest)
                return 1;
        else if (broc == 0)
                return 0;
        else
                return 1;
}
void space(char *token, const int sp)
{
        char space[100];
        char cont[100000];
        int i;
        for (i = 0; i < sp; i++)
                space[i] = ' ';
        space[i] = '\0';
        strcpy(cont, token);
        sprintf(token, "%s%s", space, cont);
}
void filew(const char token[], const char name[])
{
        FILE *fp = fopen(name, "w");
        if (fp == NULL)
        {
                printf("unable to open file for write");
                return;
        }
        fp = fopen(name, "w");
        fprintf(fp, "%s", token);
        fclose(fp);
}
void filea(const char token[], const char name[])
{
        FILE *fp = fopen(name, "a");
        if (fp == NULL)
        {
                printf("unable to open file for append");
                return;
        }
        fprintf(fp, "%s", token);
        fclose(fp);
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
        }
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
