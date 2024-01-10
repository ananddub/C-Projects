#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pass printf("pass");
#define tk textcolor
typedef struct minmax
{
        char *min;
        char *max;
} minmax;
void input(char *);
void midputc(char *, char, int *);
void bks(char *, int *);
minmax first(char *, char, char);
float equ(char *);
void colprint(char *, char *, char *);
char *extrac(char *, int);
int check(char *, char *);
int br(char *, int);
void spacrem(char *);
void pmch(char *);
void bscan(char *);
void ddprintf(char *);
char *high(char *, int);
void main()
{
        char e[100] = ""; //"2*{2+2*(2+2)}";
        int cn = 0;
        char ch;
        char key[20] = "0123456789/*-+[{()}]";
        clrscr();
        extrac(e, 1);
        while (1)
        {
                clrscr();
                tk(CYAN);
                // extrac(e, 0);
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
                        cn = 0;
                        e[0] = '\0';
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
        char *dv = (char *)malloc(strlen(data) + 100000);
        strcpy(dv, data);
        tk(CYAN);
        // if (falg)
        // strcpy(dv, "2(2+2)2");
        bscan(dv);
        //         printf("\nsolving :");
        br(dv, falg);
        // if (falg)
        // {
        //         tk(YELLOW);
        //         printf("%s", dv);
        //         tk(CYAN);
        //         printf("\n\nAns :");
        //         tk(YELLOW);
        //         printf("%s", dv);
        // }
        return (char *)dv;
        // free(arr);
}
int br(char *md, int falg)
{
        minmax val;
        int i = 0;
        char *add;
        char hop[] = "/*+-";
        char op[] = "({[";
        char cl[] = ")}]";
        char *dv = (char *)malloc(strlen(md) + 10000);
        strcpy(dv, md);
        // printf("question :%s\n", md);
        while (i < 3)
        {
                strcpy(dv, md);
                val = first(dv, op[i], cl[i]);
                // printf("\nval:%s",val.min);
                if (val.min != NULL)
                {
                        char ch;
                        int flag = 0;
                        tk(BLUE);
                        if (falg)
                                printf("\nSolving:");
                        val.max += 1;
                        if (falg)
                                colprint(dv, val.min, val.max);
                        val.max -= 1;
                        // val.min -= 1;
                        // printf("{%c}",*val.min);

                        //          val.min += 1;
                        *val.min = '\0';

                        val.min += 1;
                        // val.max += 1;
                        *val.max = '\0';
                        val.max += 1;
                        // val.max -= 1;
                        fflush(stdout);
                        while (high(val.min, 0) != NULL)
                                ;
                        if (flag == 1)
                        {
                                pass sprintf(md, "%s%c%s%s", dv, ch, val.min, val.max);
                        }
                        // else if (flag == 2)
                        // {
                        //         sprintf(md, "%s%s%c%s", dv, val.min, ch, val.max);
                        // }
                        // else if (flag == 3)
                        // {
                        //         sprintf(md, "%s%c%s%c%s", dv, ch, val.min, ch, val.max);
                        // }
                        else
                                sprintf(md, "%s%s%s", dv, val.min, val.max);
                        continue;
                }
                i++;
        }
        if (falg)
        {
                tk(BLUE);
                printf("\nSolving:", md);
                while (high(md, falg) != NULL)
                {
                        tk(BLUE);
                        printf("\nSolving:");
                }
                tk(YELLOW);
                printf("%s", md);
                tk(BLUE);
        }
        else
                while (high(md, falg) != NULL)
                        ;
        printf("\n\nAns :");
        tk(YELLOW);
        printf("%s", md);
}
int check(char *ch, char *base)
{
        char *min = ch;
        char *max = ch + 1;
        char fix = *ch;
        char hop = "/*+-[{()}]";
        char match[] = "qwertyuiopasdfghklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
        char *p2 = (char *)malloc(1000);
        char *p1 = (char *)malloc(1000);
        int i;
        p1[0] = '\0';
        p2[0] = '\0';
        i = 0;
        while (min < base)
        {
                if (strchr(match, *min) != NULL)
                {
                        p1[i] = *min;
                        i++;
                }
                if (strchr(hop, *min) != NULL)
                {
                        break;
                }
                min--;
        }
        p1[i] = '\0';
        i = 0;
        while (*max != '\0')
        {

                if (strchr(match, *max) != NULL)
                {
                        p2[i] = *max;
                        i++;
                }
                if (strchr(hop, *max) != NULL)
                {
                        break;
                }
                max++;
        }
        p2[i] = '\0';
        if (strcmp(p1, p2) == 0)
                return 1;
        else
                return 0;
}
char *high(char *token, int falg)
{
        int i;
        char pas[] = "0123456789 .";
        char hop[] = "/*+-";
        char *data = (char *)malloc(strlen(token) + 10000);
        char val[2000];
        char chr;
        float f;
        char *base=token;
        char *ch = NULL;
        char *st;
        static int c = 1;
        int flag = 0;
        int eflag = 0;
        int sflag = 0;
        char tt;
        char *end;
        spacrem(token);
        pmch(token);
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
                        // if (check(ch, base))
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
        while (*end != '\0' && strchr(pas, *end) != NULL || eflag == 0)
        {
                if (strchr(pas, *end) != NULL)
                        eflag = 1;
                end++;
        }
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
        f = equ(val);
        i = (int)f;
        // printf("{i=%d}{sflag=%d}",i,sflag);
        if (f < 0 && st > token || sflag)
        {
                st -= 1;
                if (*st == '+')
                {
                        *st = '-';
                        f = -1 * f;
                }
                else if (*st == '-' || sflag)
                {
                        if (sflag)
                        {
                                // printf("p");
                                if (f > 0)
                                {
                                        *st = '+';
                                }
                                else
                                        f = -1 * f;
                        }
                        else
                        {
                                *st = '+';

                                f = -1 * f;
                        }
                }

                st++;
        }
        *st = '\0';
        sprintf(data, "%s%d%c%s", token, (int)f, chr, end);
        sprintf(token, "%s", data);
}
float equ(char *token)
{
        char hop[] = "/*+-";
        float a;
        float b;
        float ans = 0;
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
        a = atof(token);

        b = atof(ptr);
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
minmax first(char *token, char op, char cl)
{
        minmax m;
        while (*token != '\0')
        {
                if (*token == op)
                        m.min = token;
                if (*token == cl)
                {
                        m.max = token;
                        return m;
                }
                token += 1;
        }
        m.min = NULL;
        m.max = NULL;
        return m;
}
void spacrem(char *token)
{
        char *data = (char *)malloc(strlen(token) + 10);
        char *ptr = data;
        char *tptr = token;
        while (*token != '\0')
        {
                if (*token == ' ')
                {
                        token++;
                        continue;
                }
                *data = *token;
                token++;
                data++;
        }
        *data = '\0';
        // printf("\nrem :%s", ptr);
        strcpy(tptr, ptr);
}
void pmch(char *token)
{
        char hop[] = "*/+-";
        char *max = token + 1;
        char *min = token;
        while (*max != '\0')
        {
                if (strchr(hop, *max) != NULL)
                {
                        if (*min == '+' && *max == '-' || *min == '-' && *max == '+')
                        {
                                *min = ' ';
                                *max = '-';
                        }
                        else if (*min == '-' && *max == '-')
                        {
                                *min = ' ';
                                *max = '+';
                        }
                        else if ((*min == '/' || *min == '*') && *max == '+')
                        {
                                *max = ' ';
                        }
                        else if (*min == '/' && *max == '/')
                        {
                                *max = ' ';
                        }
                        else if (*min == '*' && *max == '*')
                        {
                                *max = ' ';
                        }
                        else if (*min == '/' && *max == '*' || *min == '*' && *max == '/')
                        {
                                *max = ' ';
                        }
                }
                min++;
                max++;
        }
        spacrem(token);
}
void bscan(char *token)
{
        char *dv = (char *)malloc(strlen(token) + 100);
        char *fix = dv;
        char *min = token;
        char *max = token + 1;
        char num[] = "0123456789";
        char hop[] = "/*-+";
        char opbrac[] = "[{(";
        char clbrac[] = ")}]";
        *dv = *min;
        while (*max != '\0')
        {
                if (strchr(num, *min) != NULL && strchr(opbrac, *max) != NULL)
                {
                        dv++;
                        *dv = '*';
                }
                if (strchr(clbrac, *min) != NULL && strchr(num, *max) != NULL)
                {
                        dv++;
                        *dv = '*';
                }
                min++;
                max++;
                dv++;
                *dv = *min;
        }
        dv++;
        *dv = '\0';
        strcpy(token, fix);
}
