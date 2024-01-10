#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void start(const int, const int, const char *, int, int);
void keycheck(int, int, char *, const char *, int *, int *, int *, int *, int *, int *, int *, int *);
int speckey(char *, char, int *, int *, const int *, const char *);
int normkey(char *, char, int *, int *, int *, int *, int *, const char *);
void midputc(char *, const char, int *);
void up(const char *, int *, int *, const int *);
void down(const char *, int *, int *, const int *);
void right(const char *, int *);
void left(const char *, int *);
void bks(char *, int *, int *, const char *);
void fclear(const char *);
void fappend(const char *, const char *);
char *line(const char *, const int);
void linew(const char *, const int, const char *);
void rm_line(const char *, const int);
void print(const int, const int, const char *);
void scload(const int, const int, const char *, const char *, const int, const int, const int, const int, const int,
            const int);
void datal(const int, const int, const char *, const int, const int);
void calmx(int *, int *, int *, int *, int *, const int, const int, const char *);
void clone(const char *, const char *);
void copy(char *, const char *);
void idx(char *, const int, const int, const char *);
void readf(const char *);
void writef(const char *, const char *);
int pwclen(const char *, const int, const int);
int pwc(const char *, const int);
void newline(int *, int *, int *, int *, char *);
void linelen(const char *, const int);
int totalline(const char *);
void ipush(int *, const long, const int, const int);
void ipop(int *, const long, const int);
int fnwl(const char *, int, const int);
int dline(char *, int);
int max(const char *, int);
#define tk textcolor
#define bk textbackground
const char kybd[1000] = {"abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~"
                         "!1@#$%^&*()_+234567890-=| }{\"':;?/,>.<}\\"};
const char temp[] = "___temp.txt";
short nstatus = 0;
int main()
        {
        char filename[1000] = "temp.c";
        fclear(filename);
        start(16, 1, filename, 10, 3);
        return 1;
        }
void print(const int dx, const int dy, const char *token)
        {
        gotoxy(dx, dy);
        printf("%s", token);
        }
void datal(const int dx, const int dy, const char *token, const int lmin, const int lmax)
        {
        char temp[1000];
        char *ptr = temp;
        int i;
        int cmin = lmin - 1, cmax = lmax + 1;
        if (strlen(token) >= lmin)
                {
                sprintf(temp, "%s", token);
                ptr[cmin] = '\0';
                ptr[cmax] = '\0';
                ptr += lmin;
                print(dx, dy, ptr);
                }
        }
void scload(const int dx, const int dy, const char *token, const char *filename, const int lmin, const int lmax,
            const int umin, const int umax, const int cn, const int linec)
        {
        FILE *fp;
        int x = dx, y = dy;
        char data[100000] = {'\0'};
        int val = 0;
        //    clrscr();
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (val >= umin && val <= umax)
                        {
                        datal(dx, y, data, lmin, lmax);
                        y += 1;
                        }
                val++;
                }
        x = pwc(temp, cn) - lmin;
        if (x < 0)
                {
                x = x * -1 + dx;
                }
        else
                x += dx;
        y = umin - linec;
        if (y < 0)
                {
                y = y * -1 + dy;
                }
        else
                y += dy;
        gotoxy(1, 30);
        readf(temp);
        gotoxy(20, 20);
        printf("lmin=%d lmax=%d linec=%d cn=%d umin=%d umax=%d ", lmin, lmax, linec, cn, umin, umax);
        fclose(fp);
        gotoxy(x, y);
        }
void start(const int dx, const int dy, const char *filename, int lmax, int umax)
        {
        int cn = 0;
        int linec = 0;
        int umin = 0, lmin = 0;
        char data[100000] = {'\0'};
        int bnwl[10000];
        int cnwl = 0;
        while (1)
                {
                if (kbhit())
                        {
                        clrscr();
                        keycheck(dx, dy, data, filename, &lmin, &lmax, &umin, &umax, &cn, &linec, bnwl, &cnwl);
                        linew(filename, linec, data);
                        scload(dx, dy, data, filename, lmin, lmax, umin, umax, cn, linec);
                        }
                }
        }
void keycheck(int x, int y, char *token, const char *filename, int *lmin, int *lmax, int *umin, int *umax, int *cn,
              int *linec, int *bnwl, int *cnwl)
        {
        char ch = getch();
        if (kbhit())
                {
                int check;
                check = speckey(token, ch, &*cn, &*linec, bnwl, filename);
                calmx(&*lmin, &*lmax, &*linec, &*umin, &*umax, *cn, 0, token);
                }
        else
                {
                int check;
                check = normkey(token, ch, &*cn, &*linec, &*lmin, &*lmax, bnwl, filename);
                if (check == 1)
                        {
                        int lined = *linec + 1;
                        calmx(&*lmin, &*lmax, &*linec, &*umin, &*umax, *cn, 1, token);
                        }
                else if (check == 2)
                        {
                        calmx(&*lmin, &*lmax, &*linec, &*umin, &*umax, *cn, 1, token);
                        }
                else
                        calmx(&*lmin, &*lmax, &*linec, &*umin, &*umax, *cn, 0, token);
                }
        nstatus = 0;
        }
int normkey(char *token, char ch, int *cn, int *linec, int *lmin, int *lmax, int *bnwl, const char *filename)
        {
        if (ch == 127)
                {
                if (token[*cn] == '\n')
                        ipop(bnwl, 10000, *linec);
                bks(token, &*cn, &*linec, filename);
                return 1;
                }
        else if (ch == '\n')
                {
                int t = *cn - 1;
                ipush(bnwl, 10000, *linec, t);
                newline(&*cn, &*lmin, &*lmax, &*linec, token);
                return 2;
                }
        else if (strchr(kybd, ch) != NULL)
                {
                midputc(token, ch, &*cn);
                }
        return 0;
        }
int speckey(char *token, char ch, int *cn, int *linec, const int *bnwl, const char *filename)
        {
        while (kbhit())
                ch = getch();
        switch (ch)
                {
        case 'A':
                up(token, &*linec, &*cn, bnwl);
                return 1;
        case 'B':
                down(token, &*linec, &*cn, bnwl);
                return 2;
        case 'C':
                right(token, &*cn);
                return 3;
        case 'D':
                left(token, &*cn);
                return 4;
        case '\n':
                midputc(token, '\n', &*cn);
                *linec += 1;
                return 5;
                }
        return 0;
        }
void newline(int *cn, int *lmin, int *lmax, int *linec, char *token)
        {
        midputc(token, '\n', &*cn);
        midputc(token, ' ', &*cn);
        *linec += 1;
        *lmax = *lmax - *lmin;
        *lmin = 0;
        }
void calmx(int *lmin, int *lmax, int *linec, int *umin, int *umax, const int cn, const int flag, const char *token)
        {
        gotoxy(100, 50);
        printf("pass umin");
        while (1)
                {
                if (*linec < *umin)
                        {
                        *umin -= 1;
                        *umax -= 1;
                        }
                else if (*linec > *umax)
                        {
                        *umax += 1;
                        *umin += 1;
                        }
                else
                        break;
                }
        while (1)
                {
                if (pwc(temp, cn) < *lmin && *lmin > 0)
                        {
                        *lmin -= 1;
                        *lmax -= 1;
                        }
                else if (pwc(temp, cn) > *lmax)
                        {
                        *lmax += 1;
                        *lmin += 1;
                        }
                else
                        break;
                }
        }
void up(const char *token, int *linec, int *cn, const int *bnwl)
        {
        unsigned int new, old, len;
        int lline = *linec;
        int flag = 0;
        if (*linec > 0)
                {
                old = pwc(temp, *cn);
                *linec -= 1;
                len = pwclen(temp, *linec, old);
                new = pwc(temp, len);
                if (new < strlen(line(temp, *linec)))
                        {
                        *cn = len;
                        flag = 0;
                        }
                else
                        {
                        flag = 1;
                        int check = max(token, *linec) - 1;
                        if (token[check] == '\n')
                                check += 1;
                        *cn = check;
                        }
                }
        gotoxy(50, 2);
        printf("flag=%d len%d", flag, len);
        }
void down(const char *token, int *linec, int *cn, const int *bnwl)
        {
        int new, old, len;
        int lline = *linec;
        if (*linec < totalline(temp) - 1)
                {
                old = pwc(temp, *cn);
                *linec += 1;
                len = pwclen(temp, *linec, old);
                new = pwc(temp, len);
                if (new < strlen(line(temp, *linec)))
                        {
                        *cn = len - 1;
                        }
                else
                        *cn = fnwl(token, *cn, 1) + 2;
                }
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
char *line(const char *filename, const int line)
        {
        FILE *fp;
        char tempc[10000];
        char *ptr = tempc;
        int count = 0;
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file ");
                }
        while (fgets(tempc, sizeof(tempc), fp) != NULL)
                {
                if (count == line)
                        return (char *)ptr;
                count += 1;
                }
        return NULL;
        }
void bks(char *data, int *cn, int *linec, const char *filename)
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
                if (*cn == '\n')
                        nstatus = 1;
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
void linew(const char *filename, const int line, const char *token)
        {
        writef(filename, token);
        writef(temp, token);
        }
void rm_line(const char *filename, const int line)
        {
        FILE *fp;
        char data[100000];
        char string[100000] = {'\0'};
        char cline = 0;
        char linel = line;
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\n Unable to rm  open file");
                return;
                }
        fclear("___temp.txt");
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (cline == linel)
                        {
                        strcat(string, data);
                        string[strlen(data) - 1] = '\0';
                        if (fgets(data, sizeof(data), fp) != NULL)
                                strcat(string, data);
                        fappend("___temp.txt", string);
                        cline++;
                        continue;
                        }
                fappend("___temp.txt", data);
                cline++;
                }
        fclose(fp);
        clone(filename, "___temp.txt");
        }
void fappend(const char *filename, const char *token)
        {
        FILE *fp;
        fp = fopen(filename, "a");
        if (fp == NULL)
                {
                printf("\nUnable to open append file");
                return;
                }
        fprintf(fp, token);
        fclose(fp);
        }
void clone(const char *file1, const char *file2) // clone same file
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
void copy(char *token, const char *file1) // file to copy int array
        {
        FILE *fp;
        int i;
        char data[1000000];
        token[0] = '\0';
        fp = fopen(file1, "r");
        if (fp == NULL)
                {
                printf("\nunable to open clone file");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                strcat(token, data);
                }
        fclose(fp);
        }
void idx(char *ptr, const int lmin, const int lmax, const char *token)
        {
        }
void readf(const char *filename)
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
void fclear(const char *filename)
        {
        FILE *fp = fopen(filename, "w");
        if (fp == NULL)
                {
                printf("\nUnable to open file to clear");
                return;
                }
        fclose(fp);
        }
void writef(const char *filename, const char *token)
        {
        FILE *fp = fopen(filename, "w");
        if (fp == NULL)
                {
                printf("\nUnable to open file to write");
                return;
                }
        fprintf(fp, token);
        fclose(fp);
        }
int pwclen(const char *filename, const int line, const int cn)
        {
        FILE *fp;
        int i = 0;
        int len = 0;
        int line1 = 0;
        char data[100000];
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file ");
                return -1;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                for (i = 0; i < strlen(data); i++)
                        {
                        if (i == cn && line == line1)
                                {
                                fclose(fp);
                                return len;
                                }
                        len++;
                        }
                line1 += 1;
                }
        fclose(fp);
        return len;
        }
int pwc(const char *filename, const int cn)
        {
        FILE *fp;
        int i = 0;
        int len = 0;
        char data[100000];
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file ");
                return -1;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                for (i = 0; i < strlen(data); i++)
                        {
                        if (len == cn)
                                {
                                fclose(fp);
                                return i;
                                }
                        len++;
                        }
                }
        fclose(fp);
        return i;
        }
int totalline(const char *filename)
        {
        FILE *fp;
        int count = 0;
        char data[100000];
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file to count total");
                return -1;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                count++;
                }
        return count;
        }
void ipush(int *iptr, const long size, const int line, const int cn)
        {
        long i;
        int arr[10000];
        int *ptr = arr;
        int ic = 0;
        for (i = 0; i < size; i++)
                {
                if (i == line)
                        {
                        arr[ic] = cn;
                        ic += 1;
                        }
                arr[ic] = iptr[i];
                ic += 1;
                }
        for (i = 0; i < size; i++)
                iptr[i] = arr[i];
        }
void ipop(int *iptr, const long size, const int line)
        {
        long i;
        int arr[10000];
        int *ptr = arr;
        int ic = 0;
        for (i = 0; i < size; i++)
                {
                if (i == line)
                        {
                        continue;
                        }
                arr[ic] = iptr[i];
                ic += 1;
                }
        for (i = 0; i < size; i++)
                iptr[i] = arr[i];
        }
int fnwl(const char *token, int cn, const int flag)
        {
        if (flag == 1)
                {
                for (cn = cn; cn < strlen(token); cn++)
                        {
                        if (token[cn] == '\n')
                                {
                                return cn;
                                }
                        }
                }
        else if (flag == -1)
                {
                for (cn = cn; cn > 0; cn--)
                        {
                        if (token[cn] == '\n')
                                {
                                return cn;
                                }
                        }
                }
        return cn;
        }
int dline(char *token, int line)
        {
        int i = 0;
        int cline = 0;
        for (i = 0; token[i] != '\0'; i++)
                {
                if (token[i] == '\n')
                        {
                        cline++;
                        }
                if (line == cline)
                        break;
                }
        return i + 1;
        }
int max(const char *token, int line)
        {
        int i;
        int cline = 0;
        for (i = 0; i < strlen(token); i++)
                {
                if (token[i] == '\n')
                        {
                        if (cline == line)
                                return i;
                        cline++;
                        }
                }
        return i;
        }
int min(const char *token, int line)
        {
        int i;
        int cline = 0;
        for (i = 0; i < strlen(token); i++)
                {
                if (token[i] == '\n')
                        {
                        if (cline == line)
                                {
                                for (; i > 0 && token[i] != '\n'; i--)
                                        ;
                                return i;
                                }
                        cline++;
                        }
                }
        return i;
        }
