#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void start(int, int, char *, int, int);
void scload(int, int, char **, char *, int, int, int, int, int, int, int);
void datal(int, int, char *, char *, int, int, int);
void keycheck(char **, char *, int *, int *, int *, int *, int *, int *, int *, int *);
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
void readf(char *);
char *sepstr(char *, char);
void writef(char *, char *);
void newline(int *, int *, int *, int *, int *, char **);
void bksline(int *, int *, int *, int *, int *, char **);
void box(int, int, int, int, int);
void dfwrite(char **, char *, int);
int llre(char *, char, int);
int catstr(char *, char *);
int strstri(char *, char *);
char **dcaloc(int, int);
char **drealoc(char **, int, int);
void dfree(char **, int);
void dcat(char **, int, char **, int);
void dcpy(char **, char **, int, int);
void tab(char *, int *);
int bkstab(char *, int *, int *, char *);
void el(char *, int *, int);
void elw(char *);
int tabch(char *, int);
void simadd(char *, char, int);
void change(int *, int *, int);
void brach(char **, int *, int);
int count(char *, char);
void dch(char *, char, int *);
int errorLoad(char **, char *);
int errwork(char **, int *, int *);
int errmatch(int *, int, int);
void errorsaver();
void intcle(int *, int);
int lenskip(char *, int);
void datascan(char *);
void funcload(char *, char *);
void funscan(char *, char *);
int funcheck(char *);
int wordin(char *);
void headerfunc(char *);
void headerloader(char *);
char *wordbr(char *);
int strf(char *, char *);
void test();
void varload(char *, char *);
void varscan(char *, char *);
int varcheck(char *);
int varin(char *);
void spacerem(char *);
int varpoint(char *);
int opencl(char *, char, char);
int isarr(char *);
void normarr(char *, char *);
int chopcl(char *);
void inchload(char *, int, char *);
void chrem(char *, char);
void datafunc(char *, char *, char *);
int cmpstr(char *, char *);
int cns(char *, char);
void fpar(char *, char *);
void parex(char *, char *);
void rev(char *);
#define tk textcolor
#define bk textbackground
char kybd[1000] = {"abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~\n"
                   "!1@#$%^&*()_+234567890-=| }{\"':;?/,>.<}\\"};
char temp[] = "___temp.c";
short nstatus = 0;
int cx, cy;
int main()
        {
        char filename[1000] = "temp.c";
        //  clrscr();
        // fclear(filename); // 74
        // test();
        start(22, 3, filename, 87, 29);
        return 1;
        }
void test()
        {
        char temp[] = "cba   ";
        fclear("___func.txt");
        fpar("ided.c", "___par.txt");
        rev(temp);
        printf("\nend");
        }
void print(int dx, int dy, char *token, int line)
        {
        gotoxy(dx, dy);
        //  tk(YELLOW);
        // token[line] = '\0';
        puts(token);
        // token += line + 1;
        // tk(15);
        // printf(" %s", token);
        }
void datal(int dx, int dy, char *token, char *chspc, int lmin, int lmax, int spac)
        {
        char temp[1000];
        char *ptr = temp;
        int i;
        int cmin = lenskip(token, lmin) - 1, cmax = lenskip(token, lmax) + 1;
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
        char spacc[100];
        int max = 0;
        char **derr = dcaloc(100, 500);
        int in[100];
        int tot = -7;
        int counb = 0;
        intcle(in, 100);
        // gotoxy(100, 2);
        sprintf(data, "%d", tlinec);
        spc = strlen(data);
        errwork(derr, in, &tot);
        simadd(spacc, ' ', 100);
        for (i = 0; i < tlinec; i++)
                {
                if (val >= umin && val <= umax)
                        {
                        int flc = 0;
                        int rei = i;
                        tk(15);
                        ;
                        i++;
                        sprintf(data, "%d", i);
                        max = spc - strlen(data);
                        simadd(chspc, ' ', max);
                        strcat(data, chspc);
                        if (errmatch(in, rei, tot) != -1)
                                sprintf(data, "\x1b[93m%s%d\x1b[31m✘\x1b[97m", chspc, i);
                        else
                                sprintf(data, "\x1b[93m%s%d \x1b[97m", chspc, i);
                        i -= 1;
                        strcpy(chspc, data);
                        strcpy(data, token[i]);
                        datascan(data);
                        if (errmatch(in, i, tot) != -1)
                                {
                                char back[1000]; //\x1b[31m
                                strcat(data, "   \x1b[31m ■");
                                strcat(data, derr[errmatch(in, i, tot)]);
                                }
                        simadd(spacc, ' ', 60);
                        strcat(data, spacc);
                        datal(dx, y, data, chspc, lmin, lmax, spc);
                        y += 1;
                        counb += 1;
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
        dfree(derr, 100);
        gotoxy(x, y);
        cx = x;
        cy = y;
        }
void start(int dx, int dy, char *filename, int lmax, int umax)
        {
        int cn = 0;
        int linec = 0;
        int umin = 0, lmin = 0;
        char **data = dcaloc(100000, 1024);
        int cnwl = 0;
        int tlinec = 1;
        int smax = umax, smin = lmax + 3;
        int bx = dx, by = dy;
        long tmax = tlinec + 5;
        int check = tmax;
        dy += 1;
        dx += 1;
        umax -= 2;
        ungetc('\r', stdin);
        clrscr();
        while (1)
                {

                if (kbhit())
                        {
                        keycheck(data, filename, &lmin, &lmax, &umin, &umax, &cn, &linec, &tlinec, &cnwl);
                        //clrscr();
                        box(1, 3, 20, 89, 15);
                        box(1, 1, 20, 1, 1);
                        box(bx, by, smin, smax, 2);
                        scload(dx, dy, data, filename, lmin, lmax, umin, umax, cn, linec, tlinec);
                        gotoxy(cx,cy);
                        }
                }
        }
void keycheck(char **token, char *filename, int *lmin, int *lmax, int *umin, int *umax, int *cn, int *linec,
              int *tlinec, int *cnwl)
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
        while(kbhit!=0)ch=getch();
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
        dfwrite(token, temp, *tlinec);
        errorsaver();
        return 0;
        }
int speckey(char **token, char ch, int *cn, int *linec, int *tlinec, char *filename)
        {
        while (kbhit()!=0)
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
                dfwrite(token, temp, *tlinec);
                errorsaver();
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
        while (1)
                {
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
                else
                        break;
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
int errorLoad(char **token, char *command)
        {
        FILE *fp;
        char data[1000];
        char com[1100];
        int status;
        int in = 0;
        fflush(stderr);
        fp = fopen("error.txt", "r");
        if (fp == NULL)
                {
                return -1;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (strstr(data, "collect2") == NULL && data[0] == '_')
                        {
                        data[strlen(data) - 1] = '\0';
                        strcpy(token[in], data);
                        in += 1;
                        }
                }
        strcpy(token[in], "-1");
        status = fclose(fp);
        getch();
        if (status == 0)
                {
                return in;
                }
        else
                {
                return in;
                }
        }
int llre(char *token, char ch, int in)
        {
        int i;
        int cou = 0;
        for (i = 0; i < strlen(token); i++)
                {
                if (token[i] == ch)
                        cou += 1;
                if (cou == in)
                        return i;
                }
        return -1;
        }
void el(char *token, int *in, int i)
        {
        char temp[1000];
        int st, end;
        char *ptr = temp;
        strcpy(temp, token);
        st = llre(ptr, ':', 1);
        end = llre(ptr, ':', 2);
        ptr[st] = '\0';
        ptr[end] = '\0';
        ptr += st + 1;
        in[i] = atoi(ptr) - 1;
        }
void elw(char *token)
        {
        char temp[10000];
        char *ptr = temp;
        int lenc = 0;
        // error purfi ying
        strcpy(temp, token);
        lenc = llre(ptr, ';', 1);
        if (lenc > 30)
                ptr[lenc] = '\0';
        ptr[llre(ptr, ',', 4)] = '\0';
        ptr[llre(ptr, '#', 2)] = '\0';
        ptr += llre(temp, ':', 4) + 1;
        strcpy(token, ptr);
        }
int errwork(char **token, int *in, int *tot)
        {
        int i, st, end;
        // cclrscr();
        *tot = errorLoad(token, "gcc ___temp.c -o ___temp.out");
        for (i = 0; i < *tot; i++)
                {
                el(token[i], in, i);
                elw(token[i]);
                }
        if (*tot > 1)
                return 1;
        else
                return 0;
        }
int errmatch(int *in, int check, int tot)
        {
        int i;
        for (i = 0; i < tot; i++)
                {
                if (in[i] == check)
                        {
                        return i;
                        }
                }
        return -1;
        }
void intcle(int *in, int tot)
        {
        int i;
        for (i = 0; i < tot; i++)
                {
                in[i] = -1;
                }
        }
void errorsaver()
        {
        FILE *fp;
        fp = popen("gcc ___temp.c -o ___temp.out 0>input.txt 1>output.txt  2>error.txt", "r");
        pclose(fp);
        }
int lenskip(char *token, int len)
        {
        int i, coun = 0;
        for (i = 0; i < strlen(token); i++)
                {
                if (token[i] == '\x1b')
                        {
                        i += 6;
                        }
                if (coun == len)
                        break;
                coun++;
                }
        return i;
        }
void datascan(char *token)
        {
        int com = 0;
        char temp[10000];
        char *ptr = temp;
        char *end = temp;
        char datpas[20000] = "";
        strcpy(temp, token);
        /*
         while (1)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 {
                 int line=llre(ptr, ' ', 1);
                 ptr[line] = '\0';
                 printf("%s", ptr);
                 ptr+=line;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 }*/
        }
int funcheck(char *token)
        {
        char datatype[100][100] = {"void", "extern", "volatile", "unsigned", "short", "int",
                                           "long", "float",  "double",   "char",     "-1"};
        int i;
        char data[1000];
        char notc[100] = "~!@#$%^+=";
        char *ptr = data;
        int flag = 0;
        strcpy(data, token);
        for (i = 0; notc[i] != '\0'; i++)
                if (strchr(token, notc[i]) != NULL)
                        return 0;
        ptr += llre(token, '(', i);
        for (i = 0; strstr(datatype[i], "-1") == NULL; i++)
                {
                if (strf(datatype[i], token))
                        {
                        flag = 1;
                        break;
                        }
                }
        if (flag)
                {
                if (strchr(token, '(') != NULL)
                        {
                        return 1;
                        }
                }
        return 0;
        }
void funcscan(char *dest, char *source)
        {
        char temp[10000];
        char *ptr = temp;
        int flag = 1;
        strcpy(temp, dest);
        ptr += llre(temp, '(', 1);
        *ptr = '\0';
        for (; *ptr != ' ' && ptr != temp || flag == 1 && ptr != temp; --ptr)
                {
                if (*ptr != ' ' && flag == 1 && *ptr != '\0')
                        {
                        flag = 0;
                        }
                else if (flag == 1)
                        *ptr = '\0';
                }
        *ptr = '\0';
        ptr++;
        strcpy(source, ptr);
        }
void funcload(char *filename, char *dname)
        {
        FILE *fp;
        int i;
        char data[100000];
        char temp[100000];
        char *token = temp;
        char in = 0;
        fp = fopen(filename, "r");
        fclear("___funcpara.txt");
        if (fp == NULL)
                {
                printf("\nUnable to open function file");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (funcheck(data))
                        {
                        fappend("___funcpara.txt", data);
                        funcscan(data, token);
                        strcat(token, "\n");
                        fappend(dname, token);
                        in++;
                        }
                }
        }
int strf(char *dest, char *source)
        {
        int di = 0, si = 0;
        int i = 0;
        int flag = 0;
        while (di < strlen(dest))
                {
                i++;
                if (dest[di] == source[si])
                        {
                        di++;
                        si++;
                        flag = 1;
                        continue;
                        }
                else if (flag || flag == 0 && source[si] != ' ')
                        {
                        return 0;
                        }
                si++;
                }
        if (source[i] == ' ' || source[i] == '\n' || source[i] == '\0')
                {
                return 1;
                }
        else
                {
                return 0;
                }
        }
int wordin(char *token)
        {
        int i;
        int flag = 0;
        for (i = 0; i < strlen(token); i++)
                {
                if (token[i] == ' ' && flag == 0)
                        {
                        continue;
                        }
                else if (token[i] != ' ')
                        flag = 1;
                else if (token[i] == ' ')
                        break;
                }
        return i;
        }
char *wordbr(char *token)
        {
        char wr[1000];
        char *ptr = wr;
        char *dptr = wr;
        strcpy(wr, token);
        *ptr += wordin(token);
        strcpy(token, ptr);
        dptr[wordin(wr)] = '\0';
        return (char *)dptr;
        }
void headerloader(char *filename)
        {
        FILE *fp;
        char data[10000];
        char command[10000];
        fclear(filename);
        fp = popen("cd /usr/include && ls *.h ", "r");
        while (fgets(command, sizeof(command), fp) != NULL)
                fappend(filename, command);
        pclose(fp);
        }
void hfunc(char *filename)
        {
        FILE *fp;
        char data[100000];
        int con = 0;
        fp = fopen(filename, "r");
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                con++;
                char temp[100000];
                data[strlen(data) - 1] = '\0';
                sprintf(temp, "/usr/include/%s", data);
                printf("%d|%s\n", con, temp);
                funcload(temp, "___func.txt");
                }
        fclose(fp);
        }
int varcheck(char *token)
        {
        char datatype[100][100] = {"void", "FILE", "extern", "volatile", "unsigned", "short",
                                           "int",  "long", "float",  "double",   "char",     "-1"};
        int i;
        char data[10000];
        char notc[100] = "";
        char *ptr = data;
        int flag = 0;
        strcpy(data, token);
        if (strchr(token, '(') != NULL)
                {
                if (strchr(token, '=') == NULL || strchr(token, '"') == NULL || strchr(token, '\'') == NULL)
                        return 0;
                }
        for (i = 0; strstr(datatype[i], "-1") == NULL; i++)
                {
                if (strf(datatype[i], token))
                        {
                        flag = 1;
                        break;
                        }
                }
        if (flag)
                {
                return 1;
                }
        return 0;
        }
void varload(char *filename, char *name)
        {
        FILE *fp;
        char data[100000];
        fclear(name);
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file varload error");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (varcheck(data))
                        {
                        tk(RED);
                        // printf("%s", data);
                        tk(WHITE);
                        varscan(name, data);
                        continue;
                        }
                // printf("%s", data);
                }
        fclose(fp);
        // readf(name);
        }
void spacerem(char *token)
        {
        int i;
        char temp[10000];
        char *ptr = temp;
        strcpy(ptr, token);
        while (*ptr == ' ')
                ptr++;
        strcpy(token, ptr);
        }
int varin(char *token)
        {
        int i;
        int flag = 0;
        char notc[100] = "!,~@#$%^&()_+-=,.<./?:\"';:'{}\\|";
        for (i = 0; i < strlen(token); i++)
                {
                if (strchr(notc, token[i]) != NULL)
                        {
                        break;
                        }
                if (token[i] == ' ' && flag == 0)
                        {
                        continue;
                        }
                else if (token[i] != ' ')
                        flag = 1;
                else if (token[i] == ' ')
                        break;
                }
        return i;
        }
int chopcl(char *token)
        {
        int res = 0;
        int i = 0;
        int df = i;
        char not [] = ",;*";
        int bkc = 0;
        int flag = 0;
        int dflag = 1;
        for (i = 0; i < strlen(token); i++)
                {
                // printf("%d|%c\n", i, token[i]);
                if (token[bkc] != '/' && token[i] == '"')
                        {
                        //   printf("pass %d\n", dflag);
                        if (dflag)
                                {
                                dflag = 0;
                                res++;
                                }
                        else
                                {
                                dflag = 1;
                                res--;
                                }
                        }
                if (token[i] == '{')
                        res++;
                else if (token[i] == '}')
                        res--;
                // if (res > 0 || res == 0 && token[i] == ';')
                //       flag = 1;
                if (res == 0 && strchr(not, token[i]) != NULL)
                        {
                        if (token[i] == '*')
                                i -= 1;
                        break;
                        }
                bkc = i;
                }
        return i + 1;
        }
void inchload(char *source, int max, char *dest)
        {
        int i;
        for (i = 0; i <= max; i++, source++, dest++)
                *dest = *source;
        *dest = '\0';
        }
void varscan(char *filename, char *token)
        {
        char *ptr = token;
        char temp[10000];
        char *lptr = &token[strlen(token)];
        int in;
        ptr += varin(token) + 1;
        while (ptr < lptr)
                {
                in = varin(ptr);
                inchload(ptr, in, temp);
                if (strlen(temp) > 1)
                        {
                        strcat(temp, "\n");
                        spacerem(temp);
                        chrem(temp, ',');
                        chrem(temp, ';');
                        fappend(filename, temp);
                        }
                ptr += in;
                in = chopcl(ptr);
                ptr += in;
                }
        }
void chrem(char *token, char ch)
        {
        char temp[10000];
        char *ptr = temp;
        char dd[10000];
        char *dest = dd;
        strcpy(temp, token);
        strcpy(dest, token);
        while (*dest != '\0')
                {
                if (*dest != ch)
                        {
                        *ptr = *dest;
                        ptr++;
                        }
                dest++;
                }
        *ptr = '\0';
        strcpy(token, temp);
        }
void datafunc(char *filename, char *check, char *dname)
        {
        FILE *fp;
        int i;
        char data[100000];
        char temp[100000];
        char *token = temp;
        char in = 0;
        int flag = 0;
        fp = fopen(filename, "r");
        fclear(dname);
        if (fp == NULL)
                {
                printf("\nUnable to open function file");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (funcheck(data))
                        {
                        if (strstr(data, check) != NULL)
                                {
                                // fappend(dname, data);
                                funcscan(data, token);
                                strcat(token, "()\n");
                                fappend(dname, token);
                                in++;
                                flag = 1;
                                }
                        else
                                flag = 0;
                        }
                else if (flag)
                        {
                        fappend(dname, data);
                        }
                }
        fclose(fp);
        }
int cns(char *ptr, char ch)
        {
        int i = 0;
        for (; *ptr != '\0'; ptr++)
                if (*ptr == ch)
                        i++;
        return i;
        }
void fpar(char *source, char *dest)
        {
        FILE *fp;
        char data[190000];
        fp = fopen(source, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file parameter ");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (funcheck(data))
                        parex(data, dest);
                }
        fclose(fp);
        }
void parex(char *source, char *dest)
        {
        int max = cns(source, ',');
        int i;
        for (i = 1; i <= max; i++)
                {
                int in;
                char temp[1000];
                char *ptr = temp;
                strcpy(temp, source);
                rev(temp);
                }
        }
void rev(char *source)
        {
        int status = 1;
        int flag = 0;
        char *sdef = source + strlen(source) - 1;
        char temp[1000];
        char *ddef = temp;
        int len, i;
        printf("sdef=%s %c\n", source, *sdef);
        while (status || sdef >= source)
                {
                *ddef = *sdef;
                if (*sdef != ' ')
                        {
                        flag = 1;
                        }
                if (*sdef != ' ' && flag == 1)
                        status = 0;
                ddef += 1;
                sdef -= 1;
                }
        *ddef = '\0';
        sprintf(source, "%s", temp);
        }
