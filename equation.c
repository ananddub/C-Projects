#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tk textcolor
void input(char *);
void midputc(char *, char, int *);
void bks(char *, int *);
int equ(char *dav);
void colprint(char *, char *, char *);
char *extrac(char *, int);
void ddprintf(char *);
char *high(char *, int);
void main()
{
        char e[100];
        int cn = 0;
        char ch;
        char key[20] = "0123456789/*-+";
        clrscr();
        while (1)
        {
                clrscr();
                tk(CYAN);
                printf("\nYour Equation :");
                tk(15);
                printf("%s", e);
                ch = getch();
                printf("\n");
                if ((int)ch == 127)
                {
                        if (cn >= 0)
                        {
                                cn -= 1;
                                e[cn] = '\0';
                        }
                }
                else if (ch == '\n')
                {
                        // gets(e);
                        extrac(e, 1);
                        cn=0;
                        e[0]='\0';
                        getch();
                }
                else if (strchr(key, ch) != NULL)
                {
                        e[cn] = ch;
                        cn++;
                        e[cn] = '\0';
                }
        }
}
char *extrac(char *data, int falg)
{
        // char dv[1000];
        char *dv = (char *)malloc(strlen(data) + 1);
        strcpy(dv, data);
        tk(CYAN);
        if (falg)
                printf("\nsolving :");
        while (high(dv, falg) != NULL)
        {
                tk(CYAN);
                if (falg)
                        printf("\nsolving :");
                // ddprintf(dv);
        }
        if (falg)
        {
                tk(YELLOW);
                printf("%s", dv);
                tk(CYAN);
                printf("\n\nAns :");
                tk(YELLOW);
                printf("%s", dv);
        }
        return (char *)dv;
        // free(arr);
}
char *high(char *token, int falg)
{
        int i;
        char pas[] = "0123456789 ";
        char hop[] = "/*+-";
        char *data = (char *)malloc(strlen(token) + 10);
        char val[2000];
        char chr;
        char *ch;
        char *st;
        static int c = 1;
        int flag = 0;
        int sflag = 0;
        char tt;
        char *end;
        if (strchr(hop, *token) != NULL)
        {
                flag = 1;
                // printf("g(%c)", *token);
                token++;
        }
        // printf("{%d|%s}", c, data);
        c++;
        for (i = 0; hop[i] != '\0'; i++)
                if ((ch = strchr(token, hop[i])) != NULL)
                        break;
        if (ch == NULL)
                return NULL;
        if (flag)
        {
                token--;
        }
        st = ch - 1;
        end = ch + 1;
        while (st >= token && strchr(pas, *st) != NULL)
                st--;
        if (st == token || *st == '-')
        {
                if (*ch != '/')
                        sflag = 1;
                else
                        st++;
        }
        else
                st++;
        while (*end != '\0' && strchr(pas, *end) != NULL)
                end++;
        chr = *end;
        if (falg)
                colprint(token, st, end);
        if (*end != '\0')
                *end = '\0';
        end++;

        // printf("%c%s",chr,end);
        // printf("%s",end);

        strcpy(val, st);
        // printf("{val=%s}",val);
        if (*st == '-')
                st++;
        i = equ(val);
        // printf("{i=%d}{sflag=%d}",i,sflag);
        if (i < 0 && st > token || sflag)
        {
                st -= 1;
                if (*st == '+')
                {
                        *st = '-';
                        i = -1 * i;
                }
                else if (*st == '-' || sflag)
                {
                        if (sflag)
                        {
                                // printf("p");
                                if (i > 0)
                                {
                                        *st = '+';
                                }
                                else
                                        i = -1 * i;
                        }
                        else
                        {
                                *st = '+';

                                i = -1 * i;
                        }
                }

                st++;
        }
        *st = '\0';
        sprintf(data, "%s%d%c%s", token, i, chr, end);
        sprintf(token, "%s", data);
}
int equ(char *token)
{
        char hop[] = "/*+-";
        int a;
        int b;
        int ans;
        char ch;
        int i;
        int flag = 0;
        int sflag = 0;
        char *ptr;

        if (strchr(hop, *token) != NULL)
        {
                flag = 1;
                // printf("ex(%c)", *token);
                token++;
        }
        for (i = 0; hop[i] != '\0'; i++)
                if ((ptr = strchr(token, hop[i])) != NULL)
                        break;
        if (flag)
                token--;
        ch = *ptr;

        // printf("op[%s %c]", token, ch);
        *ptr = '\0';
        ptr++;
        a = atoi(token);

        b = atoi(ptr);
        // printf("a=%s b=%d",token,b);
        switch (ch)
        {
        case '+':
                ans = a + b;
                break;

        case '-':
                ans = a - b;
                break;

        case '*':
                ans = a * b;
                break;

        case '/':
                ans = a / b;
                break;
        }
        return ans;
}
void colprint(char *token, char *st, char *end)
{
        long del;
        end--;
        while (*token != '\0')
        {
                fflush(stdout);
                tk(GREEN);
                if (token >= st && token <= end)
                {
                        tk(RED);
                        printf("%c", *token);
                }
                else
                {
                        // tk(15);
                        printf("%c", *token);
                }
                tk(GREEN);
                token++;
                for (del = 0; del < 90000000; del++)
                        ;
        }
}
