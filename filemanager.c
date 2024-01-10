#include <conio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
void pass(int);
void folder(int, int, int);
void file(int, int, int);
void video(int, int, int);
void input();
void print();
void refresh();
void test();
int skey(char);
int nkey(char);
void start();
void output(char *);
void back();
void date(char *, char *);
void size(char *, char *);
void filet(char *, char *);
void filen(char *);
char *filenum(int, char *);
void cursor(int, int, int);
int anal(int);
void inputxy(int, int, int, char *);
void null();
#define tk textcolor
#define bk textbackground
struct _curs
        {
        int cur;
        int set_fl;
        int set_cur;
        int x, y;
        int rx, ry;
        int st;
        int end;
        int cnt;
        int cn;
        };
typedef struct _data
        {
        char filename[10000];
        char filetype[10000];
        char out[100000];
        char size[1000];
        char date[1000];
        int clipboard[10000];
        char temp[10000];
        char cd[10000];
        } _data;
struct _data d;
struct _curs c;
const char kybd[] = " abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ12345"
                    "6789/*-+`~!@#$%^&*()_+{}|:\"<>?[];',./\\";
int main()
        {
        // inputxy(10, 20, 10, d.filename);
        start();
        return 1;
        }
void test()
        {
        while (1)
                {
                if (kbhit())
                        {
                        getch();
                        }
                }
        }
void start()
        {
        bk(0);
        clrscr();
        sprintf(d.cd, "/home/dubey");
        filen(d.filename);
        output(d.out);
        c.cur = 1;
        print();
        c.st = 0;
        c.end = 1;
        while (1)
                {
                if (kbhit())
                        {
                        refresh();
                        }
                }
        }
void refresh()
        {
        input();
        output(d.out);
        filen(d.filename);
        print();
        }
void print()
        {
        void (*fptr[5])(int, int, int) = {file, folder, video};
        int i, ck = 0;
        int test = c.end * 33;
        int sttest = c.st * 8;
        if (sttest == 0)
                sttest++;
        clrscr();
        bk(15);
        tk(0);
        gotoxy(40, 1);
        for (i = 0; i <= 85; i++)
                printf(" ");
        gotoxy(42, 1);
        printf(" %s ", d.cd);
        bk(0);
        c.x = 30;
        c.y = 5;
        if (strlen(d.filename) == 0)
                {
                tk(15);
                gotoxy(50, 20);
                printf("Empty Folder");
                }
        cursor(c.rx, c.ry, 0);
        gotoxy(1, 1);
        for (i = sttest; i < test && i < c.cnt; i++)
                {
                int j;
                if (i == c.cur)
                        {
                        cursor(c.x, c.y, 3);
                        c.set_cur = 1;
                        c.rx = c.x;
                        c.ry = c.y;
                        }
                j = anal(i);
                //   if(
                fptr[j](c.x, c.y, i);
                //  anal(i);
                ck++;
                if (ck == 3)
                        ck = 0;
                if (c.x > 120)
                        {
                        c.y += 10;
                        c.x = 30;
                        }
                else
                        c.x += 15;
                }
        bk(15);
        gotoxy(40, 1);
        for (i = 0; i <= 85; i++)
                printf(" ");
        gotoxy(42, 1);
        tk(0);
        printf(" %s ", d.cd);
        tk(15);
        bk(0);
        }
void inputxy(int x, int y, int len, char *token)
        {
        char temp[10000];
        char intemp[10000];
        char *fptr = temp;
        int i, j, cn = 0;
        int bks = 0;
        char ch;
        strcpy(temp, token);
        cn = strlen(temp);
        strcpy(intemp, temp);
        while (1)
                {
                char *inptr = intemp;
                int templen;
                // strcpy(, temp);
                gotoxy(x, y);
                templen = strlen(intemp);
                if (templen >= 8)
                        {
                        inptr[templen] = '\0';
                        inptr += templen + 1;
                        }
                tk(15);
                printf("test:%s", temp);
                bks = strlen(intemp) - cn;
                for (i = 0; i < bks; i++)
                        printf("\b");
                ch = getch();
                if (strchr(kybd, ch))
                        {
                        intemp[cn] = ch;
                        cn++;
                        }
                else
                        {
                        while (1)
                                {
                                if (kbhit())
                                        {
                                        ch = getch();
                                        continue;
                                        }
                                break;
                                }
                        switch (ch)
                                {
                        case 'C':
                                if (cn <= strlen(intemp))
                                        cn++;
                                break;
                        case 'D':
                                if (cn > 0)
                                        cn--;
                                break;
                        case 'A':
                                exit(0);
                                }
                        strcpy(temp, intemp);
                        }
                }
        }
void back()
        {
        char tempc[1000];
        char *ptr = tempc;
        int i, len;
        strcpy(tempc, d.cd);
        len = strlen(tempc) - 2;
        ptr[strlen(tempc) - 1] = '\0';
        for (i = len; ptr[i] != '/'; i--)
                ;
        ptr[i] = '\0';
        //    printf("%s",tempc);
        strcpy(d.cd, tempc);
        clrscr();
        }
void input()
        {
        char ch = getch();
        skey(ch);
        }
int nkey(char ch)
        {
        }
int skey(char ch)
        {
        int test;
        long nav = 0;
        nav = ch;
        test = ch / 10;
        while (1)
                {
                if (kbhit())
                        {
                        ch = getch();
                        nav += ch;
                        continue;
                        }
                break;
                }
        gotoxy(100, 50);
        printf("              ");
        tk(test);
        gotoxy(100, 50);
        printf("%ld", nav);
        switch (nav)
                {
        case 183:
                test = c.cur;
                if (test > 1)
                        test -= 8;
                if (test < 0)
                        ;
                else
                        c.cur = test;
                test = c.st * 8;
                if (c.cur <= test)
                        {
                        if (c.st > 0)
                                {
                                clrscr();
                                c.end -= 1;
                                c.st -= 1;
                                }
                        }
                break;
        case 184:
                test = c.cur;
                if (test < c.cnt - 1)
                        test += 8;
                if (test >= c.cnt)
                        ;
                else
                        c.cur = test;
                test = c.end * 32;
                if (c.cur >= test)
                        {
                        clrscr();
                        c.end += 1;
                        c.st += 1;
                        }
                break;
        case 185:
                if (c.cur < c.cnt - 1)
                        {
                        c.cur += 1;
                        test = c.end * 32;
                        if (c.cur == test)
                                {
                                clrscr();
                                c.st += 1;
                                c.end += 1;
                                }
                        }
                break;
        case 186:
                if (c.cur > 1)
                        {
                        c.cur -= 1;
                        test = c.st * 8;
                        if (c.cur == test)
                                {
                                if (c.st > 0)
                                        {
                                        clrscr();
                                        c.end -= 1;
                                        c.st -= 1;
                                        }
                                }
                        }
                break;
        case 10:
                char tempc[10000];
                clrscr();
                strcpy(tempc, d.cd);
                sprintf(d.cd, "%s/%s", tempc, filenum(c.cur, d.filename));
                c.cur = 1;
                break;
        case 345:
                if (strcmp(d.cd, "/home/dubey") == 0)
                        break;
                back();
                break;
                }
        return 1;
        }
void cursor(int x, int y, int cl)
        {
        int i;
        x -= 2;
        bk(cl);
        y -= 1;
        for (i = y; i <= y + 4; i++)
                {
                gotoxy(x, i);
                printf("            ");
                }
        bk(0);
        gotoxy(x, i);
        }
int anal(int in)
        {
        char *ptr = filenum(in, d.filetype);
        ptr[4] = '\0';
        if (strcmp(ptr, "-rwx") == 0)
                {
                bk(GREEN);
                c.set_fl = 1;
                return 0;
                }
        else if (strcmp(ptr, "-rw-") == 0)
                {
                bk(WHITE);
                return 0;
                }
        else if (strcmp(ptr, "drwx") == 0)
                {
                bk(5);
                return 1;
                }
        // pass(4);
        return 2;
        }
void null()
        {
        d.date[0] = '\0';
        d.size[0] = '\0';
        d.filetype[0] = '\0';
        d.temp[0] = '\0';
        d.temp[0] = '\0';
        }
char *filenum(int con, char *token)
        {
        char tempc[100000];
        char *ptr = tempc;
        int cnt = 0, lenc = 0;
        int i, j, h = 0;
        strcpy(tempc, token);
        for (i = 0; ptr[i] != '\0'; i++)
                {
                if (ptr[i] == '\n')
                        {
                        tk(6);
                        cnt += 1;
                        tk(15);
                        }
                if (cnt == con)
                        {
                        ptr[i] = '\0';
                        ptr += h;
                        break;
                        }
                if (ptr[i] == '\n')
                        h = i + 1;
                }
        return (char *)(ptr);
        }
void filen(char *token)
        {
        FILE *fp;
        char tempc[100000];
        sprintf(tempc, "cd %s && ls ", d.cd);
        fp = popen(tempc, "r");
        //    if(fp==NULL)printf("unable to open");
        token[0] = '\0';
        c.cnt = 0;
        while (fgets(tempc, sizeof(tempc), fp) != NULL)
                {
                strcat(token, tempc);
                c.cnt += 1;
                }
        //  printf("%s",token);
        pclose(fp);
        }
void output(char *token)
        {
        FILE *fp;
        char tempc[100000];
        int cnt = 0;
        sprintf(tempc, "cd %s && ls -lh ", d.cd);
        fp = popen(tempc, "r");
        if (fp == NULL)
                {
                //            printf("unable to open");
                }
        token[0] = '\0';
        null();
        while (fgets(tempc, sizeof(tempc), fp) != NULL)
                {
                char atemp[100000];
                strcpy(atemp, tempc);
                strcat(token, tempc);
                date(d.date, atemp);
                size(d.size, atemp);
                if (cnt == 0)
                        cnt = 1;
                else
                        filet(d.filetype, atemp);
                }
        pclose(fp);
        }
void filet(char *t2, char *token)
        {
        char tempc[100000];
        char *ptr = tempc;
        strcpy(tempc, token); // 30 // 24
        ///  printf("\nlen=%d",strlen("-rwxr-xr-x 1 dubey dubey"));
        ptr[11] = '\n';
        ptr[12] = '\0';
        // ptr-=13;
        strcat(t2, ptr);
        //    printf("%s\n",ptr);
        }
void size(char *t2, char *token)
        {
        char tempc[100000];
        char *ptr = tempc;
        strcpy(tempc, token); // 30 // 24
        ///  printf("\nlen=%d",strlen("-rwxr-xr-x 1 dubey dubey"));
        ptr += 24;
        *ptr = '\0';
        ptr += 6;
        *ptr = '\n';
        ptr += 1;
        *ptr = '\0';
        ptr -= 5;
        strcat(t2, ptr);
        }
void date(char *t2, char *token)
        {
        char tempc[100000];
        char *ptr = tempc;
        strcpy(tempc, token); // 43 // 28
        // printf("\n\n-rwxr-xr-x 1 dubey dubey    34 May 23 09:48
        // \nstrlen=%d",strlen("-rwxr-xr-x 1 dubey dubey    "));
        ptr += 28;
        *ptr = '\0';
        ptr += 15;
        *ptr = '\n';
        ptr += 1;
        *ptr = '\0';
        ptr -= 14;
        strcat(t2, ptr);
        }
void folder(int x, int y, int num)
        {
        int i;
        char *ptr;
        x += 2;
        gotoxy(x, y);
        bk(6);
        printf("      ");
        x -= 2;
        y += 1;
        gotoxy(x, y);
        for (i = y; i <= y + 1; i++)
                {
                gotoxy(x, i);
                printf("        ");
                }
        bk(0);
        gotoxy(x, i);
        if (c.set_cur)
                bk(3);
        else
                bk(0);
        c.set_cur = 0;
        ptr = filenum(num, d.filename);
        ptr[10] = '\0';
        printf("%s", ptr);
        }
void file(int x, int y, int num)
        {
        int i;
        char *ptr;
        gotoxy(x, y);
        for (i = y; i <= y + 2; i++)
                {
                gotoxy(x, i);
                printf("       ");
                }
        bk(0);
        gotoxy(x, i);
        ptr = filenum(num, d.filename);
        if (c.set_cur)
                bk(3);
        else
                bk(0);
        c.set_cur = 0;
        ptr[10] = '\0';
        printf("%s", ptr);
        if (c.set_fl)
                {
                gotoxy(x + 3, y + 1);
                bk(GREEN);
                tk(0);
                printf("\u2699\n");
                bk(0);
                tk(WHITE);
                }
        else
                {
                int min;
                bk(15);
                ptr = filenum(num, d.filename);
                for (i = strlen(ptr); ptr[i] != '.'; i--, min++)
                        ;
                i--;
                ptr[i] = '\0';
                ptr += i + 1;
                i++;
                ptr[5] = '\0';
                gotoxy(x + 1, y + 1);
                tk(0);
                printf("%s", ptr);
                bk(0);
                tk(WHITE);
                }
        c.set_fl = 0;
        }
void video(int x, int y, int num)
        {
        int i;
        char *ptr;
        bk(5);
        gotoxy(x, y);
        for (i = y; i <= y + 2; i++)
                {
                gotoxy(x, i);
                printf("         ");
                }
        gotoxy(x + 4, y + 1);
        tk(15);
        printf("\u25B6 \n");
        bk(0);
        gotoxy(x, i);
        if (c.set_cur)
                bk(3);
        else
                bk(0);
        c.set_cur = 0;
        ptr = filenum(num, d.filename);
        ptr[10] = '\0';
        printf("%s", ptr);
        }
void pass(int p)
        {
        printf("pass %d", p);
        }
