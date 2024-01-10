#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define tk textcolor
#define bk textbackground
const char kybd[1000] = {"abcdefghijlnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~\n"
                         "!1@#$%^&*()_+234567890-=| }{\"':;?/,>.<}\\"};
void animc(char *);
void inputerxy(int, int, char *, int, int);
void midputc(char *, const char, int *);
void bks(char *, int *);
void skey(char *, char, int *);
void nkey(char *, const char, int *);
void nav(char *, int *, int *, int *, int *, int *);
void print(const int, const int, const char *);
void calmx(int *, int *, int *, int *, const int, const int, const char *);
// void prcal(const int, const int,  const char *, const int, const int, const int,const int,const int);
void prpro(const int, const int, const char *, const int, const int, const int, const int, const int);
int xfind(const char *, const int, const int, const int);
int yfind(const char *, const int, const int, const int);
int count(const char *, const char, const int);
int llen(const char *, const int);
void up(const char *token, int *);
void down(const char *token, int *);
void left(const char *token, int *);
void right(const char *token, int *);
char *sep(char *, const char);
char *line(const char *, const int);
char *datpr(const char *, const int);
int totall(const char *);
int main()
        {
        char data[100000] = {'\0'};
        clrscr();
        inputerxy(1, 1, data, 10, 5);
        printf("after input :%s", data);
        return 1;
        }
// Input area
void print(const int x, const int y, const char *token)
        {
        gotoxy(x, y);
        printf("%s\b", token);
        }
/* char *datptr(const char *token, const int line)
                                        {
        int i;
        char temp[1000];
        char *ptr = temp;
        temp[0] = '\0';
        ptr = sep(token, line);
        return (char *)ptr;
                                        }*/
void prpro(const int dx, const int dy, const char *token, const int cn, const int lmin, const int lmax, const int umin,
           const int umax)
        {
        char temp[1000];
        char *ptr = temp;
        int i;
        int x, y, cmin = lmin - 1, cmax = lmax + 1;
        strcpy(temp, token);
        ptr[cmin] = '\0';
        ptr[cmax] = '\0';
        ptr += lmin;
        gotoxy(1, 1);
        x = 1;
        x = dx - 1;
        gotoxy(x, dy);
        printf("|");
        x = dx + 2;
        gotoxy(x, dy);
        printf("|");
        y = dy;
        for (i = 0; i <= totall(token); i++)
                {
                gotoxy(dx, y);
                print(dx, y, line(token, 2));
                y += 1;
                }
        x = xfind(token, dx, cn, lmin);
        y = yfind(token, cn, umin, dy);
        gotoxy(100, 10);
        printf("x=%d y=%d", x, y);
        gotoxy(x, y);
        }
void inputerxy(int x, int y, char *data, int lmax, int umax)
        {
        char tempc[1000];
        char *fptr = tempc;
        int cn = 0;
        int lmin = 0;
        int umin = 0;
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
                prpro(x, y, tempc, cn, lmin, lmax, umin, umax);
                nav(tempc, &cn, &lmin, &lmax, &umin, &umax);
                }
        }
void nav(char *token, int *cn, int *lmin, int *lmax, int *umin, int *umax)
        {
        char ch;
        ch = getch();
        if (kbhit())
                {
                gotoxy(1, 1);
                skey(token, ch, &*cn);
                }
        else
                {
                nkey(token, ch, &*cn);
                calmx(&*lmin, &*lmax, &*umin, &*umax, *cn, 1, token);
                return;
                }
        calmx(&*lmin, &*lmax, &*umin, &*umax, *cn, 0, token);
        }
void nkey(char *token, char ch, int *cn)
        {
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
        switch (ch)
                {
        case 'A':
                up(token, &*cn);
                break;
        case 'B':
                // down(token,&*cn);
                break;
        case 'C':
                right(token, &*cn);
                break;
        case 'D':
                left(token, &*cn);
                break;
        case '\n':
                midputc(token, ch, &*cn);
                break;
                }
        }
void calmx(int *min, int *max, int *umin, int *umax, const int cn, const int flag, const char *token)
        {
        int tcn = -1;
        if (flag)
                tcn = cn - 1;
        if (token[tcn] == '\n' || token[cn] == '\n')
                {
                if (*umax < count(token, '\n', cn))
                        {
                        *umax += 1;
                        *umin += 1;
                        }
                else if (*umin > count(token, '\n', cn))
                        {
                        *umin -= 1;
                        *umax -= 1;
                        }
                }
        else if (cn<*min && * min> 0)
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
char *sep(char *token, const char ch)
        {
        int i;
        int flag = 0, check = 0;
        char tmp[10000];
        char data[100000];
        char *string = tmp;
        char temd[100000];
        char *cons = temd;
        strcpy(tmp, token);
        strcpy(cons, token);
        strcpy(temd, token);
        for (i = 0; i <= strlen(tmp); i++)
                {
                if (string[i] == ch || string[i] == NULL)
                        {
                        clrscr();
                        i += 1;
                        string[i] = '\0';
                        cons[i] = '\0';
                        string += i + 1;
                        sprintf(token, "%s", string);
                        return (char *)cons;
                        }
                }
        return NULL;
        }
char *line(const char *token, const int line)
        {
        int i;
        int count = 0;
        char tempc[10000];
        char *ptr = tempc;
        char tmpp[100000];
        char *ptrc = tmpp;
        char y = 1;
        strcpy(tempc, token);
        while ((ptrc = sep(ptr, '\n')) != NULL && count != line)
                {
                gotoxy(100, y);
                printf("%s", ptrc);
                count += 1;
                y += 1;
                }
        return (char *)ptrc;
        }
int llen(const char *token, const int cn)
        {
        return strlen(line(token, count(token, '\n', cn)));
        }
int count(const char *token, const char ch, const int tcn)
        {
        int i;
        int cn = 0;
        for (i = 0; i < strlen(token) && i <= tcn; i++)
                if (token[i] == ch)
                        cn++;
        return cn;
        }
int totall(const char *token)
        {
        int i, con = 0;
        for (i = 0; i <= strlen(token); i++)
                {
                if (token[i] == '\n')
                        con++;
                }
        return con;
        }
void up(const char *token, int *cn)
        {
        int linec = count(token, '\n', cn);
        if (0 < linec)
                {
                printf("pass");
                }
        }
void down(const char *token, int *cn)
        {
        }
void right(const char *token, int *cn)
        {
        if (*cn <= strlen(token))
                {
                if (token[*cn] == '\n')
                        *cn -= 1;
                *cn += 1;
                }
        }
void left(const char *token, int *cn)
        {
        if (*cn > 0)
                {
                *cn -= 1;
                if (token[*cn] == '\n')
                        {
                        *cn += 1;
                        }
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
int xfind(const char *token, const int dx, const int cn, const int min) // find value of x in gotoxy
        {
        int x;
        x = cn - min;
        if (x < 0)
                {
                x = x * -1 + dx;
                }
        else
                x += dx;
        return x;
        }
int yfind(const char *token, const int cn, const int umin, const int dy) // find value of y in gotoxy
        {
        int y1 = count(token, '\n', cn);
        int y;
        y = umin - y1;
        if (y < 0)
                {
                y = y * -1 + dy;
                }
        else
                y += dy;
        return y;
        }
