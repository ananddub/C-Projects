#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void start(int, int, char *, int, int);
void scload(int, int, char **, char *, int, int, int, int, int, int, int);
void datal(int, int, char *, char *, int, int, int);
void keycheck(int, int, char **, char *, int *, int *, int *, int *, int *, int *, int *, int *);
int speckey(char **, char, int *, int *, int *, char *);
int normkey(char **, char, int *, int *, int *, int *, int *, int *, int *);
void midputc(char *, char, int *);
void up(char **, int *, int *);
void down(char **, int *, int *, int *);
void right(char *, int *);
void left(char *, int *);
void bks(char *, int *, int *, char *);
void fclear(char *);
void fappend(char *, char *);
void print(int, int, char *, int);
void calmx(int *, int *, int *, int *, int *, int *, int);
void clone(char *, char *);
void copy(char *, char *);
char *sepstr(char *, char);
void writef(char *, char *);
void newline(int *, int *, int *, int *, int *, char **);
void bksline(int *, int *, int *, int *, int *, char **);
void box(int, int, int, int, int);
void dfwrite(char **, char *, int);
int cmpstr(char *, char *);
int catstr(char *, char *);
int strstri(char *, char *);
char **dcaloc(int, int);
char **drealoc(char **, int, int);
void dfree(char **, int);
void dcat(char **, int, char **, int);
void dcpy(char **, char **, int, int);
void tab(char *, int *);
int bkstab(char *, int *, int *, char *);
int tabch(char *, int);
void simadd(char *, char, int);
void change(int *, int *, int);
void brach(char **, int *, int);
int count(char *, char);
void dch(char *, char, int *);
#define tk textcolor
#define bk textbackground
char kybd[1000] = {"abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~\n"
                   "!1@#$%^&*()_+234567890-=| }{\"':;?/,>.<}\\"};
char temp[] = "___temp.c";
short nstatus = 0;
int main()
        {
        char filename[1000] = "temp.c";
        fclear(filename); // 74
        start(22, 3, filename, 87, 29);
        return 1;
        }
void print(int dx, int dy, char *token, int line)
        {
        gotoxy(dx, dy);
        tk(YELLOW);
        token[line] = '\0';
        printf("%s", token);
        token += line + 1;
        tk(15);
        printf(" %s", token);
        }
void datal(int dx, int dy, char *token, char *chspc, int lmin, int lmax, int spac)
        {
        char temp[1000];
        char *ptr = temp;
        int i;
        int cmin = lmin - 1, cmax = lmax + 1;
        if (strlen(token) >= lmin)
                {
                char tempd[1024];
                sprintf(temp, "%s", token);
                ptr[cmin] = '\0';
                ptr[cmax] = '\0';
                ptr += lmin;
                sprintf(tempd, "%s%s", chspc, ptr);
                print(dx, dy, tempd, spac);
                }
        else
                print(dx, dy, chspc, spac);
        }
void scload(int dx, int dy, char **token, char *filename, int lmin, int lmax, int umin, int umax, int cn, int linec,
            int tlinec)
        {
        int x = dx, y = dy;
        int val = 0;
        int i;
        int spc = 0;
        char chspc[100];
        char data[1500];
        int max = 0;
        gotoxy(100, 2);
        sprintf(data, "%d", tlinec);
        spc = strlen(data);
        for (i = 0; i < tlinec; i++)
                {
                if (val >= umin && val <= umax)
                        {
                        i++;
                        sprintf(data, "%d", i);
                        max = spc - strlen(data);
                        simadd(chspc, ' ', max);
                        strcat(data, chspc);
                        sprintf(data, "%s%d ", chspc, i);
                        i -= 1;
                        strcpy(chspc, data);
                        strcpy(data, token[i]);
                        datal(dx, y, data, chspc, lmin, lmax, spc);
                        y += 1;
                        }
                val++;
                }
        x = cn - lmin + spc + 1;
        if (x <= 0)
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
        // gotoxy(1, 30);
        //  readf(temp);
        gotoxy(20, 20);
        // printf("lmin=%d lmax=%d linec=%d cn=%d umin=%d umax=%d ", lmin, lmax, linec, cn, umin, umax);
        gotoxy(x, y);
        }
void start(int dx, int dy, char *filename, int lmax, int umax)
        {
        int cn = 0;
        long linec = 0;
        long umin = 0, lmin = 0;
        char **data = dcaloc(100000, 1024);
        int cnwl = 0;
        long tlinec = 1;
        int smax = umax, smin = lmax + 3;
        int bx = dx, by = dy;
        long tmax = tlinec + 5;
        int check = tmax;
        dy += 1;
        dx += 1;
        umax -= 2;
        ungetc('\r', stdin);
        while (1)
                {
                if (kbhit())
                        {
                        clrscr();
                        keycheck(dx, dy, data, filename, &lmin, &lmax, &umin, &umax, &cn, &linec, &tlinec, &cnwl);
                        box(bx, by, smin, smax, 2);
                        box(1, 3, 20, 89, 15);
                        box(1, 1, 20, 1, 1);
                        scload(dx, dy, data, filename, lmin, lmax, umin, umax, cn, linec, tlinec);
                        dfwrite(data, temp, tlinec);
                        }
                }
        }
void keycheck(int x, int y, char **token, char *filename, int *lmin, int *lmax, int *umin, int *umax, int *cn,
              int *linec, int *tlinec, int *cnwl)
        {
        char ch = getch();
        if (kbhit())
                {
                speckey(token, ch, &*cn, &*linec, &*tlinec, filename);
                }
        else
                {
                normkey(token, ch, &*cn, &*linec, &*tlinec, &*lmin, &*lmax, &*umin, &*umax);
                }
        change(&*lmin, &*lmax, *tlinec);
        calmx(&*lmin, &*lmax, &*linec, &*tlinec, &*umin, &*umax, *cn);
        nstatus = 0;
        }
int normkey(char **token, char ch, int *cn, int *linec, int *tlinec, int *lmin, int *lmax, int *umin, int *umax)
        {
        if (ch == 127)
                {
                int i = *cn - 1;
                if (*cn > 0)
                        {
                        if (bkstab(token[*linec], &*cn, &*linec, temp) == 0)
                                bks(token[*linec], &*cn, &*linec, temp);
                        }
                else if (*cn == 0 && *linec > 0)
                        {
                        bksline(&*cn, &*umin, &*umax, &*linec, &*tlinec, token);
                        }
                return 1;
                }
        else if (ch == 9)
                {
                tab(token[*linec], &*cn);
                }
        else if (ch == '\n')
                {
                newline(&*cn, &*umin, &*umax, &*linec, &*tlinec, token);
                return 2;
                }
        else if (strchr(kybd, ch) != NULL)
                {
                dch(token[*linec], ch, &*cn);
                }
        return 0;
        }
int speckey(char **token, char ch, int *cn, int *linec, int *tlinec, char *filename)
        {
        while (kbhit())
                ch = getch();
        switch (ch)
                {
        case 'A':
                up(token, &*linec, &*cn);
                return 1;
        case 'B':
                down(token, &*linec, &*tlinec, &*cn);
                return 2;
        case 'C':
                right(token[*linec], &*cn);
                return 3;
        case 'D':
                left(token[*linec], &*cn);
                return 4;
        case 9:
                tab(token[*linec], &*cn);
                return 5;
                }
        return 0;
        }
void calmx(int *lmin, int *lmax, int *linec, int *tlinec, int *umin, int *umax, int cn)
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
                if (cn<*lmin && * lmin> 0)
                        {
                        *lmin -= 1;
                        *lmax -= 1;
                        }
                else if (cn > *lmax)
                        {
                        *lmax += 1;
                        *lmin += 1;
                        }
                else
                        break;
                }
        }
void up(char **token, int *linec, int *cn)
        {
        if (*linec > 0)
                {
                if (*linec > 0)
                        {
                        int len;
                        *linec -= 1;
                        len = strlen(token[*linec]);
                        if (*cn > len)
                                *cn = len;
                        }
                }
        }
void down(char **token, int *linec, int *tlinec, int *cn)
        {
        if (*linec < *tlinec - 1)
                {
                int len;
                *linec += 1;
                len = strlen(token[*linec]);
                if (*cn > len)
                        *cn = len;
                }
        }
void right(char *token, int *cn)
        {
        if (*cn < strlen(token))
                {
                *cn += 1;
                }
        }
void left(char *token, int *cn)
        {
        if (*cn > 0)
                {
                *cn -= 1;
                }
        }
void dch(char *token, char ch, int *cn)
        {
        if (ch == '{')
                {
                midputc(token, ch, &*cn);
                midputc(token, '}', &*cn);
                *cn -= 1;
                }
        else if (ch == '(')
                {
                midputc(token, ch, &*cn);
                midputc(token, ')', &*cn);
                *cn -= 1;
                }
        else if (ch == '[')
                {
                midputc(token, ch, &*cn);
                midputc(token, ']', &*cn);
                *cn -= 1;
                }
        else if (ch == '"')
                {
                midputc(token, ch, &*cn);
                midputc(token, ch, &*cn);
                *cn -= 1;
                }
        else if (ch == '\'')
                {
                midputc(token, ch, &*cn);
                midputc(token, ch, &*cn);
                *cn -= 1;
                }
        else
                {
                midputc(token, ch, &*cn);
                }
        }  
void bks(char *data, int *cn, int *linec, char *filename)
        {
        char tempc[1024];
        int i = *cn;
        char tempj[1024];
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
void newline(int *cn, int *lmin, int *lmax, int *linec, int *tlinec, char **token)
        {
        char **dest, flag = 1;
        char temp[1024];
        char *ptr = temp;
        int len = *tlinec - *linec;
        int lined = *linec - 2;
        int tmax = *tlinec + 5;
        dest = dcaloc(tmax, 1024);
        flag = 0;
        strcpy(temp, token[*linec]);
        token[*linec][*cn] = '\0';
        ptr += *cn;
        *linec += 1;
        *tlinec += 1;
        dcpy(dest, token, *linec, *tlinec);
        token[*linec][0] = '\0';
        strcpy(token[*linec], ptr);
        *linec += 1;
        dcat(token, *linec, dest, len);
        *lmax = *lmax - *lmin;
        *lmin = 0;
        *cn = 0;
        *linec -= 1;
        dfree(dest, tmax);
        brach(token, &*cn, *linec);
        }
void bksline(int *cn, int *lmin, int *lmax, int *linec, int *tlinec, char **token)
        {
        char **dest;
        char temp[1024];
        char *ptr = temp;
        int len = *tlinec - *linec;
        int lend;
        int tmax = *tlinec + 5;
        int lined = *linec - 1;
        dest = dcaloc(tmax, 1024);
        lend = strlen(token[lined]);
        strcpy(temp, token[*linec]);
        strcat(token[lined], temp);
        *linec += 1;
        dcpy(dest, token, *linec, *tlinec);
        *linec -= 1;
        dcat(token, *linec, dest, len);
        *lmax = *lmax - *lmin;
        *lmin = 0;
        *cn = lend;
        *linec -= 1;
        *tlinec -= 1;
        dfree(dest, tmax);
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
char **drealoc(char **resize, int row, int colum)
        {
        char **doublea = (char **)realloc(resize, row * sizeof(char *));
        int i;
        if (doublea == NULL)
                {
                printf("memory allocation failed");
                exit(0);
                }
        resize = doublea;
        for (i = 0; i < row; i++)
                {
                resize[i] = (char *)realloc(resize[i], colum * sizeof(char));
                if (resize[i] == NULL)
                        {
                        printf("memory allocation failed");
                        exit(0);
                        }
                }
        return resize;
        }
char **dcaloc(int row, int colum)
        {
        char **array2d = (char **)calloc(row, sizeof(char *));
        int i;
        for (i = 0; i < row; i++)
                {
                array2d[i] = (char *)calloc(colum, sizeof(char));
                }
        return array2d;
        }
void dfree(char **array2d, int row)
        {
        int i;
        for (i = 0; i < row; i++)
                {
                free(array2d[i]);
                }
        free(array2d);
        }
void dcat(char **dest, int drow, char **source, int max)
        {
        int i;
        for (i = 0; i <= max; i++, drow++)
                {
                strcpy(dest[drow], source[i]);
                }
        }
void dcpy(char **dest, char **source, int min, int max)
        {
        int i;
        int row = 0;
        for (i = min; i <= max; i++, row++)
                {
                strcpy(dest[row], source[i]);
                }
        }
int bkstab(char *token, int *cn, int *linec, char *temp)
        {
        int i;
        int cur = 0;
        int tabs = 0;
        int cnn = *cn - 1;
        if (tabch(token, cnn) == 0)
                {
                return 0;
                }
        for (i = cnn; i > 0; i--)
                {
                if (i % 8 == 0)
                        {
                        tabs += 8;
                        break;
                        }
                cur++;
                }
        tabs -= 8;
        for (; cur >= tabs; cur--)
                bks(token, &*cn, &*linec, temp);
        return 1;
        }
void tab(char *token, int *cn)
        {
        int i;
        int cur = 0;
        int tabs = 8;
        for (i = 0; i <= *cn; i++)
                {
                if (i % 8 == 0)
                        {
                        cur = 0;
                        }
                cur++;
                }
        if (tabs <= 0)
                tabs += 8;
        for (; cur <= tabs; cur++)
                midputc(token, ' ', &*cn);
        }
int tabch(char *token, int cn)
        {
        for (; cn > 0; cn--)
                {
                if (token[cn] != ' ' && token[cn] != '\0')
                        return 0;
                if (cn % 8 == 0)
                        break;
                }
        return 1;
        }
void simadd(char *token, char ch, int max)
        {
        int i;
        for (i = 0; i < max; i++, token++)
                *token = ch;
        *token = '\0';
        }
void change(int *lmin, int *lmax, int tlinec)
        {
        static int max = 0;
        char data[100];
        int len = 0;
        int chg;
        sprintf(data, "%d ", tlinec);
        len = strlen(data);
        if (max < len)
                {
                chg = len - max;
                // if (*lmin > chg)
                //         *lmin -= chg;
                *lmax -= chg;
                max = len;
                }
        else if (max > len)
                {
                chg = max - len;
                //   if (*lmin > chg)
                //         *lmin += chg;
                *lmax += chg;
                max = len;
                }
        }
void dfwrite(char **token, char *filename, int tline)
        {
        int i;
        fclear(filename);
        for (i = 0; i < tline; i++)
                {
                char temp[1024];
                strcpy(temp, token[i]);
                strcat(temp, "\n");
                fappend(filename, temp);
                }
        }
int count(char *token, char ch)
        {
        int cou = 0;
        for (; *token != '\0'; token++)
                {
                if (*token == ch)
                        cou++;
                }
        return cou;
        }
void brach(char **token, int *cn, int cmax)
        {
        int i;
        int op = 0;
        int clos = 0;
        int res = 0;
        for (i = 0; i < cmax; i++)
                {
                op += count(token[i], '{');
                clos += count(token[i], '}');
                }
        res = op - clos;
        for (i = 0; i < res; i++)
                tab(token[cmax], &*cn);
        }

