#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define tk textcolor
#define bk textbackground
const char kybd[1000] = {"abcdefghijlnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~"
                         "!1@#$%^&*()_+234567890-=| }{\"':;?/,>.<}\\"};
void animc(char *);
void inputerxy(int, int, char *, const int);
void midputc(char *, const char, int *);
void bks(char *, int *);
void skey(char *, char, int *);
void nkey(char *, const char, int *);
void nav(char *, int *, int *, int *);
void print(const int, const int, const char *);
void calmx(int *, int *, const int);
void prcal(const int, const int, const char *, const int, const int, const int);
void prpro(const int, const int, const char *, const int, const int, const int);
int main()
        {
        char data[100000] = {'\0'};
        clrscr();
        inputerxy(50, 10, data, 10);
        printf("after input :%s", data);
        return 1;
        }
void print(const int x, const int y, const char *token)
        {
        gotoxy(x, y);
        printf("%s    ", token);
        }
void prpro(const int dx, const int dy, const char *token, const int cn, const int min, const int max)
        {
        char temp[1000];
        char *ptr = temp;
        int x, cmin = min - 1, cmax = max + 1;
        strcpy(temp, token);
        ptr[cmin] = '\0';
        ptr[cmax] = '\0';
        ptr += min;
        print(dx, dy, ptr);
        x = min - cn;
        if (x < 0)
                x = x * -1 + dx;
        else
                x += dx;
        // gotoxy(60, 20);
        //   printf("cn=%d,x=%d,min=%d   ", cn, x, min);
        gotoxy(x, dy);
        }
void inputerxy(int x, int y, char *data, int max)
        {
        char tempc[1000];
        char *fptr = tempc;
        int cn = 0;
        int min = 0;
        char ch;
        int i;
        if (strlen(data) > 0)
                {
                cn = strlen(data) - 2;
                }
        strcpy(tempc, data);
        while (1)
                {
                int cnt = cn + 1;
                prpro(x, y, tempc, cn, min, max);
                nav(tempc, &cn, &min, &max);
                }
        clrscr();
        }
void nav(char *token, int *cn, int *min, int *max)
        {
        char ch;
        ch = getch();
        gotoxy(1, 2);
        if (ch == 27)
                {
                skey(token, ch, &*cn);
                }
        else
                {
                nkey(token, ch, &*cn);
                }
        calmx(&*min, &*max, *cn);
        }
void nkey(char *token, char ch, int *cn)
        {
        //   printf("\n\n%s", token);
        if (ch == 127)
                {
                bks(token, &*cn);
                }
        else
                {
                midputc(token, ch, &*cn);
                }
        }
void skey(char *token, char ch, int *cn)
        {
        while (kbhit())
                ch = getch();
        gotoxy(3, 3);
        // printf("pass%d ", *cn);
        switch (ch)
                {
        case 'C':
                if (*cn < strlen(token))
                        {
                        *cn += 1;
                        }
                break;
        case 'D':
                if (*cn > 0)
                        {
                        *cn -= 1;
                        }
                break;
        case '\n':
                break;
                }
        }
void calmx(int *min, int *max, const int cn)
        {
        if (cn<*min && * min> 0)
                {
                *min -= 1;
                *max -= 1;
                }
        else if (cn > *max)
                {
                *max += 1;
                *min += 1;
                }
        }
void bks(char *data, int *cn)
        {
        char tempc[10000];
        int i = *cn;
        char tempj[10000];
        char *stp = tempc;
        char *endp = tempj;
        strcpy(tempc, data);
        strcpy(tempj, data);
        if (*cn > 0)
                {
                *cn -= 1;
                i = *cn;
                stp[i] = '\0';
                i = *cn;
                endp[i] = '\0';
                endp += i + 1;
                sprintf(data, "%s%s", stp, endp);
                }
        }
void midputc(char *data, const char ch, int *cn)
        {
        char tempc[10000];
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
