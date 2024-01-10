#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void start(int, int, char *, int, int);
void keycheck(int, int, char *, char *, int *, int *, int *, int *, int *, int *, int *, int *);
int speckey(char *, char, int *, int *, int *, char *);
int normkey(char *, char, int *, int *, int *, int *, int *, char *);
void midputc(char *, char, int *);
void up(char *, int *, int *, int *);
void down(char *, int *, int *, int *);
void right(char *, int *);
void left(char *, int *);
void bks(char *, int *, int *, char *);
void fclear(char *);
void fappend(char *, char *);
char *line(char *, int);
void linew(char *, int, char *);
void rm_line(char *, int);
void print(int, int, char *);
void scload(int, int, char *, char *, int, int, int, int, int, int);
void datal(int, int, char *, int, int);
void calmx(int *, int *, int *, int *, int *, int, int, char *);
void clone(char *, char *);
void copy(char *, char *);
void idx(char *, int, int, char *);
char *sepstr(char *, char);
void readf(char *);
void writef(char *, char *);
int pwclen(char *, int, int);
int lpwclen(char *, int, int);
int pwc(char *, int);
void newline(int *, int *, int *, int *, char *);
void linelen(char *, int);
int totalline(char *);
void ipush(int *, long, int, int);
void ipop(int *, long, int);
int fnwl(char *, int, int);
int dline(char *, int);
int dpwc(char *, int);
int dfnwl(char *, int);
char *stle(char *);
void exaloc(char *, int);
int min(char *, int);
int max(char *, int);
void box(int, int, int, int, int);
void updw(char *, int *, int, char *);
int lenstr(char *);
int cmpstr(char *, char *);
int catstr(char *, char *);
int strstri(char *, char *);
#define tk textcolor
#define bk textbackground
char kybd[1000] = {"abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~\n"
                   "!1@#$%^&*()_+234567890-=| }{\"':;?/,>.<}\\"};
char temp[] = "___temp.txt";
short nstatus = 0;
int main()
        {
        char filename[1000] = "temp.c";
        fclear(filename);
        start(22, 1, filename, 74, 28);
        return 1;
        }
void print(int dx, int dy, char *token)
        {
        gotoxy(dx, dy);
        printf("%s", token);
        }
void datal(int dx, int dy, char *token, int lmin, int lmax)
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
void scload(int dx, int dy, char *t2, char *filename, int lmin, int lmax, int umin, int umax, int cn, int linec)
        {
        int x = dx, y = dy;
        char data[100000];
        int val = 0;
        char *token;
        strcpy(data, t2);
        gotoxy(100, 2);
        while ((token = sepstr(data, '\n')) != NULL)
                {
                if (val >= umin && val <= umax)
                        {
                        datal(dx, y, token, lmin, lmax);
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
        // readf(temp);
        gotoxy(20, 20);
        //  printf("lmin=%d lmax=%d linec=%d cn=%d umin=%d umax=%d ", lmin, lmax, linec, cn, umin, umax);
        gotoxy(x, y);
        }
void start(int dx, int dy, char *filename, int lmax, int umax)
        {
        int cn = 0;
        int linec = 0;
        int umin = 0, lmin = 0;
        char data[1000000] = "\n ";
        int bnwl[10000];
        int cnwl = 0;
        int smax = umax, smin = lmax + 3;
        int bx = dx, by = dy;
        dy += 1;
        dx += 1;
        umax -= 2;
        ungetc('\r', stdin);
        while (1)
                {
                if (kbhit())
                        {
                        clrscr();
                        keycheck(dx, dy, data, filename, &lmin, &lmax, &umin, &umax, &cn, &linec, bnwl, &cnwl);
                        linew(filename, linec, data);
                        box(bx, by, smin, smax, 2);
                        box(1, 3, 20, 89, 15);
                        box(1, 1, 20, 1, 1);
                        scload(dx, dy, data, filename, lmin, lmax, umin, umax, cn, linec);
                        }
                }
        }
void keycheck(int x, int y, char *token, char *filename, int *lmin, int *lmax, int *umin, int *umax, int *cn,
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
int normkey(char *token, char ch, int *cn, int *linec, int *lmin, int *lmax, int *bnwl, char *filename)
        {
        if (ch == 127)
                {
                int i = *cn - 1;
                if (token[*cn] == '\n')
                        ipop(bnwl, 10000, *linec);
                if (*cn > 0)
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
int speckey(char *token, char ch, int *cn, int *linec, int *bnwl, char *filename)
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
                // midputc(token, ' ', &*cn);
                //   midputc(token, '\n', &*cn);
                //     *linec += 1;
                ///        *cn -= 1;
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
        *cn -= 1;
        }
void calmx(int *lmin, int *lmax, int *linec, int *umin, int *umax, int cn, int flag, char *token)
        {
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
void up(char *token, int *linec, int *cn, int *bnwl)
        {
        if (*linec > 0)
                {
                *linec -= 1;
                updw(token, &*cn, *linec, "up");
                }
        }
void down(char *token, int *linec, int *cn, int *bnwl)
        {
        if (*linec < totalline(temp) - 2)
                {
                *linec += 1;
                updw(token, &*cn, *linec, "down");
                }
        }
void right(char *token, int *cn)
        {
        if (*cn < fnwl(token, *cn, 1))
                {
                if (token[*cn] == '\n')
                        *cn -= 1;
                *cn += 1;
                }
        }
void left(char *token, int *cn)
        {
        if (*cn > fnwl(token, *cn, -1))
                {
                *cn -= 1;
                if (token[*cn] == '\n')
                        {
                        *cn += 1;
                        }
                }
        }
char *line(char *filename, int line)
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
void bks(char *data, int *cn, int *linec, char *filename)
        {
        char tempc[10000];
        int i = *cn;
        char tempj[10000];
        char *stp = tempc;
        char *endp = tempj;
        int flag = 0;
        strcpy(tempc, data);
        strcpy(tempj, data);
        i -= 1;
        i = *cn;
        if (*cn > 0)
                {
                *cn -= 1;
                if (data[*cn] == '\n')
                        if (*linec > 0)
                                *linec -= 1;
                i = *cn;
                stp[i] = '\0';
                i = *cn;
                endp[i] = '\0';
                endp += i + 1;
                sprintf(data, "%s%s", stp, endp);
                }
        }
void midputc(char *data, char ch, int *cn)
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
void linew(char *filename, int line, char *token)
        {
        writef(filename, token);
        writef(temp, token);
        }
void rm_line(char *filename, int line)
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
void copy(char *token, char *file1) // file to copy int array
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
void idx(char *ptr, int lmin, int lmax, char *token)
        {
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
void writef(char *filename, char *token)
        {
        FILE *fp = fopen(filename, "w");
        if (fp == NULL)
                {
                printf("\nUnable to open file to write");
                return;
                }
        fputs(token, fp);
        fclose(fp);
        }
int pwclen(char *filename, int line, int cn)
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
                for (i = 0; i < strlen(data) - 1; i++, len++)
                        {
                        if (i == cn && line1 == line)
                                {
                                fclose(fp);
                                return len;
                                }
                        }
                line1 += 1;
                }
        fclose(fp);
        return len;
        }
int pwc(char *filename, int cn)
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
int totalline(char *filename)
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
void ipush(int *iptr, long size, int line, int cn)
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
void ipop(int *iptr, long size, int line)
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
int fnwl(char *token, int cn, int flag)
        {
        if (flag == 1)
                {
                for (; cn < strlen(token); cn++)
                        {
                        if (token[cn] == '\n')
                                {
                                return cn;
                                }
                        }
                }
        else if (flag == -1)
                {
                for (; cn > 0; cn--)
                        {
                        if (token[cn] == '\n')
                                {
                                return cn - 1;
                                }
                        }
                }
        return cn;
        }
int dpwc(char *token, int cn)
        {
        int i = 0;
        int cline = 0;
        int cun = 0;
        for (i = 0; token[i] != '\0'; i++)
                {
                if (i == cn)
                        return cun;
                if (token[i] == '\n')
                        {
                        cline++;
                        cun = 0;
                        }
                cun++;
                }
        return cun;
        }
int lpwclen(char *token, int line, int cn)
        {
        int i = 0;
        int cline = 0;
        int cun = 0;
        int flag = 0;
        for (i = 0; token[i] != '\0'; i++)
                {
                if (token[i] == '\n')
                        {
                        if (cline == line && cline == 0)
                                {
                                for (; i > 0 && i != cn; i++)
                                        ;
                                return i;
                                }
                        cline++;
                        if (cline == line)
                                {
                                cun = 0;
                                for (; i < strlen(token) && token[i] != '\n' && cun != cn; i--, cun++)
                                        ;
                                return i;
                                }
                        }
                }
        return i - 1;
        }
int dline(char *token, int line)
        {
        int i = 0;
        int cline = 0;
        int cun = 1;
        for (i = 0; token[i] != '\0'; i++)
                {
                if (token[i] == '\n')
                        {
                        if (cline == line)
                                {
                                i--;
                                for (; i > 0 && token[i] != '\n'; i--, cun++)
                                        ;
                                return cun;
                                }
                        cline++;
                        }
                }
        for (; i > 0 && token[i] != '\n'; i--, cun++)
                ;
        return cun;
        }
char *stle(char *token)
        {
        int i;
        for (i = 0; i < strlen(token); i++)
                {
                if (token[i] == '\n')
                        {
                        token[i] = '\0';
                        return (char *)token;
                        }
                }
        return NULL;
        }
int dfnwl(char *t2, int line)
        {
        int i;
        int cline = 0;
        char arr[100000];
        char *token = arr;
        strcpy(arr, t2);
        for (i = 0; token[i] != '\0'; i++)
                {
                if (token[i] == '\n')
                        {
                        if (cline == line && line == 0)
                                {
                                return i;
                                }
                        cline++;
                        if (cline == line)
                                {
                                token[i] = '\0';
                                token += i + 1;
                                return i + strlen(stle(token));
                                }
                        }
                }
        return i;
        }
int max(char *token, int line)
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
        return strlen(token) - 1;
        }
int min(char *token, int line)
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
void box(int dx, int dy, int sx, int sy, int col)
        {
        int x = dx, y = dy;
        int i;
        int parx, pary;
        tk(col);
        // stand
        for (i = y + 1; i <= y + sy - 1; i++)
                {
                parx = x + sx;
                gotoxy(dx, i);
                printf("\u2502");
                gotoxy(parx, i);
                printf("\u2502");
                }
        // flat
        for (i = x + 1; i <= x + sx - 1; i++)
                {
                pary = y + sy;
                gotoxy(i, dy);
                printf("\u2500");
                gotoxy(i, pary);
                printf("\u2500");
                }
        // up left corner
        gotoxy(dx, dy);
        printf("\u250C");
        // up right corner
        parx = dx + sx;
        gotoxy(parx, dy);
        printf("\u2510");
        // down left corner
        pary = dy + sy;
        gotoxy(dx, pary);
        printf("\u2514");
        // down right corner
        pary = dy + sy;
        parx = dx + sx;
        gotoxy(parx, pary);
        printf("\u2518");
        tk(15);
        }
char *sepstr(char *t2, char ch)
        {
        char temp[10000];
        char *token = temp;
        char temp1[10000];
        char *rest = temp1;
        int i;
        strcpy(temp, t2);
        strcpy(temp1, t2);
        for (i = 0; *rest != ch; i++, rest++)
                if (*rest == '\0')
                        {
                        if (strlen(t2) > 0)
                                {
                                *t2 = '\0';
                                return (char *)token;
                                }
                        return NULL;
                        };
        rest += 1;
        strcpy(t2, rest);
        token[i] = '\0';
        if (strlen(t2) > 0)
                return (char *)token;
        return NULL;
        }
int lenstr(char *token)
        {
        int i;
        for (i = 0; *token != '\0'; token++, i++)
                ;
        return 1;
        }
int cmpstr(char *source, char *dest)
        {
        int count = 0;
        int len = 0;
        char *ptr = dest;
        for (; *source != '\0'; source++, ptr++)
                {
                if (*source == *ptr)
                        {
                        count++;
                        }
                else
                        return 0;
                }
        return 1;
        }
void updw(char *t2, int *cn, int linec, char check[5])
        {
        int i;
        int count = 0;
        int minl = 0, maxl;
        int pc = 0;
        int lenc = 0;
        char temp[19990];
        char *token = temp;
        int len = 0, cline = 0;
        char *ptr;
        if (cmpstr(check, "up"))
                {
                pc = 0;
                for (i = *cn; token[i] != '\n' && i > 0; pc++, i--)
                        ;
                len = 0;
                linec--;
                len = max(t2, linec);
                if (linec < 0)
                        len = 0;
                *cn = len + pc;
                cline = *cn;
                linec++;
                len = max(t2, linec);
                if (*cn > len)
                        *cn = len;
                }
        else if (cmpstr(check, "down"))
                {
                pc = 0;
                for (i = *cn; token[i] != '\n' && i > 0; pc++, i--)
                        ;
                len = 0;
                linec--;
                len = max(t2, linec);
                *cn = len + pc;
                cline = *cn;
                linec++;
                len = max(t2, linec);
                if (*cn > len)
                        *cn = len;
                }
        gotoxy(100, 1);
        printf("cline=%d,len=%d,cn=%d,pc=%d,check=%s", cline, len, *cn, pc, check);
        }
