#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pass printf("pass");
void solve(char *);
int left(char *, char *);
int right(char *, char *);
int exec(int, char, int);
char *foc(char *, char *);
void midputc(char *, char, int *);
void datainput(char *, int);
int main()
{
        char equ[1000] = "2+2/2+1";
        solve(equ);
}
void solve(char *data)
{
        char mas[] = "/*+-";
        char *equ = malloc(strlen(data) * sizeof(char) + 100);
        char *ch;
        char chc;
        int s1, s2;
        int i = 0;
        strcpy(equ, data);
        printf("equation :%s\n\n", equ);
        while (strlen(equ) > 1)
        {
                ch = foc(equ, mas);
                chc = *ch;

                        s1 = left(equ, foc(equ, mas));
                // printf("\n1main:%s", equ);
                s2 = right(equ, foc(equ, mas));
                printf("\n2main:%s", equ);
                printf("\ns1=%d ch=%c s2=%d\noutput :%d", s1, chc, s2, exec(s1, chc, s2));
                datainput(equ, exec(s1, chc, s2));
                printf("\n3ssmain:%s", equ);
                i++;
        }
}
void datainput(char *equ, int ans)
{
        char *j = strchr(equ, 'i') + 1;
        char *i = j - 1;
        char *ch = j;
        int cn = j - equ - 1;
        int ctr;
        char arr[200];
        if (i == NULL)
                return;
        while (*j != '\0')
        {
                *i = *j;
                i++;
                j++;
        }
        *i = '\0';
        sprintf(arr, "%d", ans);
        for (ctr = 0; ctr < strlen(arr); ctr++)
                midputc(equ, arr[ctr], &cn);
}
int exec(int s1, char ch, int s2)
{
        switch (ch)
        {
        case '/':
                return s1 / s2;

        case '*':
                // pass
                return s1 * s2;

        case '+':
                return s1 + s2;

        case '-':
                return s1 - s2;
        }
}
int left(char *end, char *ch)
{
        char num[15] = "0123456789 ";
        char *data = malloc(strlen(end) * sizeof(char) + 1);
        int max = 0;
        int in = 0;
        int con = 0;
        char *i, *j;
        max = ch - end;
        strcpy(data, end);
        ch = data + max;
        *ch = '\0';
        while (ch > data)
        {
                ch -= 1;
                if (strchr(num, *ch) == NULL || ch == data)
                {
                        if (ch != data)
                                ch++;
                        in = atoi(ch);
                        printf("\ndata:%s", data);
                        free(data);
                        i = end + max;
                        if (i > end)
                                i -= 1;

                        j = end + max - con + 1;

                        while (*j != '\0')
                        {
                                *i = *j;
                                i++;
                                j++;
                        }
                        *i = '\0';
                        return in;
                }
                con++;
        }
        in = atoi(ch);
        printf("\ndata:%s", data);
        free(data);
        i = end + max;
        if (i > end)
                i -= 1;
        j = end + max - con + 1;
        while (*j != '\0')
        {
                *i = *j;
                i++;
                j++;
        }
        *i = '\0';
        return in;
}
int right(char *end, char *ch)
{
        char num[15] = "0123456789 ";
        char *data = malloc(strlen(end) * sizeof(char) + 1);
        int max = 0;
        int in = 0;
        int con = 0;
        char *ls;
        char *i, *j;
        max = ch - end;
        strcpy(data, end);
        ls = data + max + 1;
        ch = ls;
        while (ch <= &data[strlen(data)])
        {
                ch += 1;
                if (strchr(num, *ch) == NULL || *ch == '\0')
                {
                        *ch = '\0';
                        in = atoi(ls);
                        free(data);
                        i = end + max;
                        *i = 'i';
                        i++;
                        j = i + con + 1;
                        while (*j != '\0')
                        {
                                *i = *j;
                                i++;
                                j++;
                        }
                        *i = '\0';
                        return in;
                }
                con++;
        }
        printf("%d\n", con);
        free(data);
        return 0;
}
char *foc(char *equ, char *mas)
{
        int i;
        char *reset = equ;
        while (*mas != '\0')
        {
                equ = reset;
                while (*equ != '\0')
                {
                        if (*mas == *equ)
                        {
                                return (char *)(equ);
                        }
                        equ++;
                }
                mas++;
        }
        return NULL;
}
void midputc(char *data, char ch, int *cn)
{
        char tempc[1024];
        int i = *cn;
        char tempj[10000];
        char *stp = tempc;
        char *endp = tempj;
        strcpy(tempc, data);
        strcpy(tempj, data);
        i = *cn;
        stp[i] = '\0';
        i = *cn - 1;
        endp[i] = '\0';
        endp += i + 1;
        *cn += 1;
        sprintf(data, "%s%c%s", stp, ch, endp);
}
