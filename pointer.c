#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lenstr(char *);
void input(char *, int *);
void midputc(char *, char, int *);
void bks(char *, int *);
void print(char, int cn);
void cpystr(char *, char *);
short chrstr(char *, char);
void catstr(char *, char *);
int count(char *, char *);
int words(char *);
#define tk textcolor
#define bk textbackground
char kybd[1000] = {"abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~"
                   "!1@#$%^&*()_+234567890-=| }{\"':;?/,>.<}\\"};
void main()
        {
        int cn = 0;
        int i;
        char arr[1000] = {'\0'};
        char vowel[] = "aeiouAEIOU";
        char cons[] = "QWRTYPSDFGHJKLZXCVBNMqwrtypsdfghjklzxcvbnm";
        char num[] = "0123456789";
        char spec[] = {"\"`~!@#$%^&*()_+-=|}{\"':;?/,>.<}\\"};
        char space[] = " ";
        char *ptr = arr;
        int cl = 7;
        clrscr();
        while (1)
                {
                gotoxy(1, 1);
                ptr = arr;
                tk(1);
                printf("\nvowels\t\t  :%d   ", count(ptr, vowel));
                tk(2);
                printf("\nconsonent\t  :%d  ", count(ptr, cons));
                tk(6);
                printf("\nnum\t\t  :%d      ", count(ptr, num));
                tk(4);
                printf("\nspecial\t\t  :%d  ", count(ptr, spec));
                tk(5);
                printf("\nspace\t\t  :%d     ", count(ptr, space));
                tk(3);
                printf("\n\nwords\t\t  :%d     ", words(ptr));
                tk(16);
                printf("\nlength \t\t  :%d     ", lenstr(ptr));
                tk(7);
                printf("\n\nEnter your word   :");
                for (i = 0; *ptr != '\0'; ptr++)
                        {
                        if (chrstr(vowel, *ptr))
                                tk(1);
                        else if (chrstr(cons, *ptr))
                                tk(2);
                        else if (chrstr(num, *ptr))
                                tk(6);
                        else if (chrstr(spec, *ptr))
                                tk(4);
                        printf("%c", *ptr);
                        }
                printf("    ");
                ptr = arr;
                for (i = lenstr(ptr); i != cn && i > 0; i--)
                        printf("\b");
                printf("\b\b\b\b");
                ptr = arr;
                input(ptr, &cn);
                }
        }
void input(char *ptr, int *cn)
        {
        int in, i;
        char ch;
        ch = getch();
        in = ch;
        if (kbhit())
                {
                while (kbhit())
                        ch = getch();
                switch (ch)
                        {
                case 'C':
                        if (*cn < lenstr(ptr))
                                *cn += 1;
                        break;
                case 'D':
                        if (*cn > 0)
                                *cn -= 1;
                        break;
                        }
                }
        else if (in == '\n')
                exit(0);
        else if (in == 127)
                {
                bks(ptr, &*cn);
                }
        else
                {
                if (chrstr(kybd, ch))
                        midputc(ptr, ch, &*cn);
                }
        gotoxy(1, 2);
        for (i = 0; i < 100; i++)
                {
                printf(" ");
                }
        }
void bks(char *token, int *cn)
        {
        char stt[1000];
        char *sta = stt;
        char endd[1000];
        char *end = endd;
        int i = *cn;
        if (i > 0)
                {
                *cn -= 1;
                i = *cn;
                cpystr(stt, token);
                cpystr(end, token);
                sta += i;
                *sta = '\0';
                sta -= 1;
                end += i;
                *end = '\0';
                end += 1;
                *token = '\0';
                catstr(token, stt);
                catstr(token, end);
                }
        }
void midputc(char *token, char ch, int *cn)
        {
        char stt[1000];
        char *sta = stt;
        char endd[1000];
        char *end = endd;
        int i = *cn;
        char cht[] = {ch, '\0'};
        cpystr(stt, token);
        cpystr(end, token);
        sta += i;
        *sta = '\0';
        sta -= i;
        i -= 1;
        end += i;
        *end = '\0';
        end += 1;
        *cn += 1;
        *token = '\0';
        catstr(token, stt);
        catstr(token, cht);
        catstr(token, end);
        }
int count(char *ptr, char *data)
        {
        int coun = 0;
        for (; *ptr != '\0'; ptr++)
                {
                if (chrstr(data, *ptr))
                        coun++;
                }
        return coun;
        }
int words(char *ptr)
        {
        int word = 0;
        int flag = 0;
        if (*ptr != ' ' && *ptr != '\0')
                {
                word += 1;
                }
        for (; *ptr != '\0'; ptr++)
                {
                if (*ptr == ' ')
                        {
                        flag = 1;
                        }
                if (flag == 1 && *ptr != ' ')
                        {
                        word += 1;
                        flag = 0;
                        }
                }
        return word;
        }
int lenstr(char *ptr)
        {
        int i;
        for (i = 0; *ptr != '\0'; ptr++, i++)
                ;
        return i;
        }
void cpystr(char *dest, char *ptr)
        {
        for (ptr = ptr; *ptr != '\0'; ptr++, dest++)
                *dest = *ptr;
        *dest = '\0';
        }
short chrstr(char *ptr, char ch)
        {
        for (; *ptr != '\0'; ptr++)
                if (*ptr == ch)
                        return 1;
        return 0;
        }
void catstr(char *data, char *ptr)
        {
        for (; *data != '\0'; data++)
                ;
        for (; *ptr != '\0'; ptr++, data++)
                *data = *ptr;
        *data = '\0';
        }
