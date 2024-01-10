#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ABOLD "\033[1m"
#define RBOLD "\033[0m"
#define vald val[*index]
#define vali val[index]
#define valg val[tabc->index]
#define valgi val[tabc.index]
typedef struct
        {
        int cn;
        int linec;
        int umin, lmin;
        char **data;
        int cnwl;
        int tlinec;
        int umax;
        int lmax;
        char filename[1000];
        int smax, smin;
        int dx, dy;
        int bx, by;
        long tmax;
        int check;
        } mainv;
typedef struct
        {
        int index;
        int totin;
        int max;
        int min;
        } tabm;
typedef struct
        {
        char clip[100][1000];
        char data[100][1000];
        } intle;
typedef struct
        {
        char derr[1000][5000];
        } err;
void beep();
void detailprint(mainv *, tabm);
void valuprov(mainv *, int *, int, int *, int *, int *);
void start(int, int, char *, int, int);
void erindata(char *, char *, int);
void scload(int, int, char **, char *, int, int, int, int, int, int, int);
void datal(int, int, char *, char *, int, int, int);
void edatal(int, int, char *, char *, int, int, int);
void keycheck(mainv *, tabm *, tabm *);
int speckey(mainv *, int *, int *, char);
int normkey(mainv *, int *, int *, char, tabm *, tabm *);
void initlizer(mainv *, int, char *, int, int, int, int);
void midputc(char *, char, int *);
void up(mainv *, int);
void down(mainv *, int);
void right(mainv *, int);
void left(mainv *, int);
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
void ebox(int, int, int, int, int);
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
int errorLoad(err *, char *);
int errwork(err *, int *, int *);
int errmatch(int *, int, int);
void errorsaver();
void errortime();
void intcle(int *, int);
int lenskip(char *, int);
void datascan(char *);
void funcload(char *, int, char *);
void purivar(char *, char *);
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
void fpar(char *, int, char *);
void parex(char *, char *);
void rev(char *);
void tabbox(int, int, mainv val[], tabm);
void stabbox(int, int, char *, int);
void chtab(tabm *);
void lsdata(char *, char *);
void lspr(char *, int, int, int);
void lsmove(tabm *);
void lsindata(char *, char *, int);
void valinch(mainv *, tabm *);
void fdataloader(char *, mainv *, int);
void modifyls(char *);
int totallc(char *);
void create(mainv *, int *, int *);
void createmade(mainv *, int *, int *);
void terminate(mainv *, int *, int *);
void delete(mainv *, int *, int *);
void initlize(mainv *, int *, int, int *, int *, int *);
void copyval(mainv *, mainv *, int, int);
void remval(mainv *, mainv *, int, int);
void searchfind();
void flush();
void errtabbox(int, int, mainv[], tabm);
void tabbox(int, int, mainv[], tabm);
void delwhile(long long int);
void gccrun(char *);
int intex(char *, int, intle *);
int intelsence(int, int, intle *, mainv *, int);
int mfs(intle *, char *, char *);
void ipr(int, int, tabm *, char *);
int inmove(int, int, int, char *);
int istatus(int, int);
int checkst(char *, int);
void filemid(char *, int, int, mainv *);
void oipr(int, int, char *);
void intro();
void cat(char *, char *);
int finder(char *, char *);
void duprem(char *, char *);
void structload(char *, char *);
int structcheck(char *);
void structrem(char *);
int structvar(char *);
void structmain(char *, char *, char *);
void clean();
#define tk textcolor
#define bk textbackground
intle inte;
char kybd[1000] = {"abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~\n"
                   "!1@#$%^&*()_+234567890-=| }[]{\"':;?/,>.<}\\"};

char temp[] = "___temp.c";
short nstatus = 0;
int cx, cy;
int main()
        {
        char filename[1000] = "Untilted 0";
        system("rm Untilted' '0");
        // getch();
        // fclear("___keyword.txt");
        fclear(temp);
        clean();
        // cat("___keyword.txt", "kw.txt");
        //  intro();
        // test();
        start(22, 4, filename, 93, 28);
        return 1;
        }

void test()
        {
        structload("tests.c", "struct.txt");
        //      readf("struct.txt");
        }
void intro()
        {
        char data[10][1000] = {"  Visual Code clone made by ", "  Name    : Anand Kumar Dubey", "  Roll No : 822110",
                                       "  Course  : Bca A"};
        int i, j;
        long del = 0;
        int x = 30, y = 10;
        // fflush(stdi);
        box(29, 9, 32, 9, 3);
        for (i = 0; i < 4; i++)
                {
                int c = i + 1;
                box(29, 9, 32, 9, c);
                gotoxy(x, y);
                for (j = 0; j < strlen(data[i]); j++)
                        {

                        tk(c);
                        fflush(stdout);
                        printf("%s%c%s", ABOLD, data[i][j], RBOLD);
                        for (del = 0; del < 39999999; del++)
                                ;
                        }
                y += 2;
                }
        box(29, 9, 32, 9, 6);
        tk(15);
        getch();
        }
void print(int dx, int dy, char *token, int line)
        {
        gotoxy(dx, dy);
        puts(token);
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
void edatal(int dx, int dy, char *token, char *chspc, int lmin, int lmax, int spac)
        {
        char temp[1000];
        char *ptr = temp;
        int i;
        int cmin = lenskip(token, lmin) - 1, cmax = lenskip(token, lmax) + 5;
        char tempd[1024];
        sprintf(temp, "%s", token);
        ptr[cmin] = '\0';
        ptr[cmax] = '\0';
        ptr += lmin;
        sprintf(tempd, "%s", ptr);
        print(dx, dy, tempd, spac);
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
        err e;
        // char **derr = dcaloc(100, 500);
        int in[100];
        int tot = -7;
        int counb = 0;
        int clear = 0;
        int maxc = 0;
        intcle(in, 100);
        // gotoxy(100, 2);
        sprintf(data, "%d", tlinec);
        spc = strlen(data);
        errwork(&e, in, &tot);
        simadd(spacc, ' ', 100);
        for (i = 0; i < tlinec; i++)
                {
                if (val >= umin && val <= umax)
                        {
                        int flc = 0;
                        int rei = i;
                        tk(15);
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
                                // erindata("error.txt", derr, errmatch(in, i, tot));
                                strcat(data, e.derr[errmatch(in, i, tot)]);
                                }
                        simadd(spacc, ' ', 100);
                        strcat(data, spacc);
                        // strcat(data, "pass");
                        datal(dx, y, data, chspc, lmin, lmax, spc);
                        y += 1;
                        counb += 1;
                        clear += 1;
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
        gotoxy(x, y);
        cx = x;
        cy = y;
        }
void initlizer(mainv *val, int index, char *dfilename, int dlmax, int ddx, int ddy, int dumax)
        {
        vali.cn = 0;
        vali.linec = 0;
        vali.umin = 0;
        vali.lmin = 0;
        vali.lmax = dlmax;
        vali.data = dcaloc(10000, 1024);
        vali.cnwl = 0;
        strcpy(vali.filename, dfilename);
        vali.tlinec = 1;
        vali.smax = dumax;
        vali.smin = dlmax + 3;
        vali.dx = ddx;
        vali.dy = ddy;
        vali.tmax = vali.tlinec + 5;
        vali.check = vali.tmax;
        vali.dy = ddy + 1;
        vali.dx = ddx + 1;
        vali.bx = ddx;
        vali.by = ddy;
        vali.umax = dumax - 2;
        }
void valprov(mainv *val, int index, char *dfilename, int dlmax, int ddx, int ddy, int dumax)
        {
        vali.cn = 0;
        vali.linec = 0;
        vali.umin = 0;
        vali.lmin = 0;
        vali.lmax = dlmax;
        vali.data = dcaloc(10000, 1024);
        vali.cnwl = 0;
        int rn = index - 1;
        strcpy(vali.filename, dfilename);
        vali.tlinec = 1;
        vali.smax = val[rn].smax;
        vali.smin = val[rn].smin;
        vali.tmax = vali.tlinec + 5;
        vali.check = vali.tmax;
        vali.dy = val[rn].dy;
        vali.dx = val[rn].dx;
        vali.bx = val[rn].bx;
        vali.by = val[rn].by;
        vali.umax = dumax;
        }
void start(int dx, int dy, char *filename, int lmax, int umax)
        {
        mainv val[100];
        tabm tabc;
        tabm lsm;
        int matchin = 0;
        int i, m = 1;

        tabc.index = 0;
        tabc.totin = 0;
        tabc.min = 0;
        tabc.max = 3;
        lsm.index = 0;
        lsm.min = 0;
        lsm.max = 27;
        lsdata("ls ", "ls.txt");
        lsm.totin = totallc("ls.txt");
        for (i = 0; i < 100; i++)
                initlizer(val, i, filename, lmax, dx, dy, umax);
        fdataloader(filename, val, tabc.index);
        lsdata("ls ", "ls.txt");
        // lspr("ls.txt", 2);
        box(1, 3, 20, 89, 15);
        box(1, 1, 20, 1, 1);
        box(valgi.bx, valgi.by, valgi.smin, valgi.smax, 2);
        while (1)
                {
                gotoxy(cx, cy);
                if (kbhit() || m == 1)
                        {
                        if (m == 0)
                                keycheck(val, &tabc, &lsm);
                        m = 0;
                        clrscr();
                        scload(valgi.dx, valgi.dy, valgi.data, valgi.filename, valgi.lmin, valgi.lmax, valgi.umin,
                               valgi.umax, valgi.cn, valgi.linec, valgi.tlinec);

                        lspr("ls.txt", 1000, 0, 27);
                        tabbox(valgi.bx, 1, val, tabc);
                        box(1, 4, 20, 89, 15);
                        stabbox(1, 1, "search", 1);
                        box(valgi.bx, valgi.by, valgi.smin, valgi.smax, 2);
                        box(valgi.bx, valgi.by, valgi.smin, valgi.smax, 2);
                        intelsence(cx, cy, &inte, val, tabc.index);
                        }
                }
        }
void keycheck(mainv *val, tabm *tabc, tabm *lsm)
        {
        char ch = getch();
        //     clrscr();
        // printf(" ppass %c ", ch);
        if (kbhit() == 1)
                {
                // printf("  specail");
                speckey(val, &tabc->index, &tabc->totin, ch);
                }
        else
                {
                //      printf("normal");
                normkey(val, &tabc->index, &tabc->totin, ch, lsm, &*tabc);
                }
        change(&valg.lmin, &valg.lmax, valg.tlinec);
        calmx(&valg.lmin, &valg.lmax, &valg.linec, &valg.tlinec, &valg.umin, &valg.umax, valg.cn);
        chtab(&*tabc);
        }
int normkey(mainv *val, int *index, int *totin, char ch, tabm *lsm, tabm *tabc)
        {
        int in = ch;
        int flag = 1;
        if (in == 127)
                {
                int i = vald.cn - 1;
                if (vald.cn > 0)
                        {
                        if (bkstab(vald.data[vald.linec], &vald.cn, &vald.linec, temp) == 0)
                                bks(vald.data[vald.linec], &vald.cn, &vald.linec, temp);
                        }
                else
                        {
                        if (vald.linec > 0)
                                bksline(&vald.cn, &vald.umin, &vald.umax, &vald.linec, &vald.tlinec, vald.data);
                        else
                                beep();
                        }
                flag = 0;
                nstatus = 1;
                }

        else if (in == 14)
                {
                create(val, index, totin);
                }
        else if (in == 1)
                {
                char temp[1000];
                int rindex = *index;
                int dumax = vald.umax - vald.umin;
                int dmax = vald.lmax - vald.lmin;
                nstatus = 1;
                lsmove(lsm);
                lsindata("ls.txt", temp, lsm->index);
                createmade(val, index, totin);
                strcpy(vald.filename, temp);
                // valprov(val, *index, temp, dmax, val[rindex].dx, val[rindex].dy, dumax);
                fdataloader(vald.filename, val, *index);
                }
        else if (in == 23)
                {
                errtabbox(vald.bx, 1, val, *tabc);
                terminate(val, index, totin);
                }
        else if (in == 126)
                {
                gccrun(temp);
                flag = 0;
                }

        else if (in == 9)
                {
                tab(vald.data[vald.linec], &vald.cn);
                flag = 0;
                nstatus = 1;
                }
        else if (in == '\n')
                {
                if (istatus(0, 0))
                        {
                        filemid("clip.txt", 0, *index, val);
                        istatus(0, 1);
                        }
                else
                        newline(&vald.cn, &vald.umin, &vald.umax, &vald.linec, &vald.tlinec, vald.data);
                nstatus = 1;
                flag = 0;
                }
        else if (strchr(kybd, ch) != NULL)
                {
                dch(vald.data[vald.linec], ch, &vald.cn);
                flag = 0;
                nstatus = 1;
                }
        dfwrite(vald.data, temp, vald.tlinec);
        errorsaver();
        if (flag == 1)
                delwhile(50000);
        return 0;
        }
int speckey(mainv *val, int *index, int *totin, char ch)
        {
        // clrscr();
        int flag = 1;
        while (kbhit())
                ch = getch();
        // printf("%d",ch);
        // getch();
        switch (ch)
                {
        case 126:
                dfwrite(vald.data, temp, vald.tlinec);
                // printf("done");
                gccrun(temp);
                flag = 0;
                break;

        case 90:
                if (*index > 0)
                        *index -= 1;
                else
                        *index = *totin;
                //
                dfwrite(vald.data, temp, vald.tlinec);
                errorsaver();
                break;
        case 9:

                if (*index < *totin)
                        *index += 1;
                else
                        *index = 0;
                dfwrite(vald.data, temp, vald.tlinec);
                errorsaver();
                break;
        case 'A':
                if (istatus(0, 0))
                        {
                        int i;
                        int in;
                        int len;
                        char temp[1999];
                        ungetc('A', stdin);
                        in = inmove(cx, cy, 4, "inte.txt");
                        if (in >= 0)
                                {
                                filemid("clip.txt", in, *index, val);
                                }
                        istatus(0, 1);
                        }
                else
                        {
                        up(val, *index);
                        }
                flag = 0;
                break;
                //        return 1;
        case 'B':
                if (istatus(0, 0))
                        {
                        int i;
                        int in;
                        int len;
                        char temp[1999];
                        ungetc('B', stdin);
                        in = inmove(cx, cy, 4, "inte.txt");
                        if (in >= 0)
                                {
                                filemid("clip.txt", in, *index, val);
                                istatus(0, 1);
                                }
                        }
                else
                        {
                        down(val, *index);
                        }
                flag = 0;
                break;
                //      return 2;
        case 'C':
                if (istatus(0, 0))
                        {
                        filemid("clip.txt", 0, *index, val);
                        istatus(0, 1);
                        }
                else
                        right(val, *index);
                flag = 0;
                break;
                ///    return 3;
        case 'D':
                left(val, *index);
                flag = 0;
                break;
                // retur
                }
        if (flag)
                delwhile(50000);
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
                        nstatus = 1;
                        }
                else if (*linec > *umax)
                        {
                        *umax += 1;
                        *umin += 1;
                        nstatus = 1;
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
                        nstatus = 1;
                        }
                else if (cn > *lmax)
                        {
                        *lmax += 1;
                        *lmin += 1;

                        nstatus = 1;
                        }
                else
                        break;
                }
        }
void chtab(tabm *tabc)
        {
        while (1)
                {
                if (tabc->index < tabc->min && tabc->min > 0)
                        {
                        tabc->min -= 1;
                        tabc->max -= 1;
                        }
                else if (tabc->index >= tabc->max)
                        {
                        tabc->max += 1;
                        tabc->min += 1;
                        }
                else
                        break;
                }
        }
void up(mainv *val, int index)
        {
        if (vali.linec > 0)
                {
                if (vali.linec > 0)
                        {
                        int len;
                        vali.linec -= 1;
                        len = strlen(vali.data[vali.linec]);
                        if (vali.cn > len)
                                vali.cn = len;
                        }
                }
        else
                beep();
        }
void down(mainv *val, int index)
        {
        if (vali.linec < vali.tlinec - 1)
                {
                int len;
                vali.linec += 1;
                len = strlen(vali.data[vali.linec]);
                if (vali.cn > len)
                        vali.cn = len;
                }
        else
                beep();
        }
void right(mainv *val, int index)
        {
        int tl = vali.tlinec - 1;
        if (vali.cn < strlen(vali.data[vali.linec]))
                {
                vali.cn += 1;
                }
        else if (vali.linec < tl)
                {
                vali.cn = 0;
                down(val, index);
                }
        else
                beep();
        }
void left(mainv *val, int index)
        {
        if (vali.cn > 0)
                {
                vali.cn -= 1;
                }

        else if (vali.linec > 0)
                {
                int line = vali.linec - 1;
                if (line < 0)
                        line = 0;
                vali.cn = strlen(vali.data[line]);
                up(val, index);
                }
        else
                beep();
        }
void dch(char *token, char ch, int *cn)
        {
        // printf(" passs dch");
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
        char temp[2000];
        char *ptr = temp;
        char tt[1000];
        char *cptr = tt;
        int i, j;
        j = *tlinec + 1;
        i = *tlinec;
        strcpy(temp, token[*linec]);
        ptr[*cn] = '\0';
        strcpy(tt, token[*linec]);
        cptr += *cn;
        for (; i > *linec; i--, j--)
                {
                strcpy(token[j], token[i]);
                }
        token[*linec][0] = '\0';
        strcpy(token[*linec], temp);
        *linec += 1;
        strcpy(token[*linec], cptr);
        *tlinec += 1;
        *lmax = *lmax - *lmin;
        *lmin = 0;
        *cn = 0;
        brach(token, &*cn, *linec);
        }
void bksline(int *cn, int *lmin, int *lmax, int *linec, int *tlinec, char **token)
        {
        int i, j;
        if (*linec > 0 && *tlinec > 0)
                {
                j = *linec - 1;
                i = *linec;
                *cn = strlen(token[j]);
                strcat(token[j], token[i]);

                i += 1;
                j += 1;
                for (; i < *tlinec; i++, j++)
                        {
                        strcpy(token[j], token[i]);
                        }
                *tlinec -= 1;
                *linec -= 1;
                *lmax = *lmax - *lmin;
                *lmin = 0;
                }
        else
                beep();
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
void cat(char *file1, char *file2) // clone same file
        {
        FILE *fp;
        int i;
        char data[1000000];
        fp = fopen(file1, "r");
        if (fp == NULL)
                {
                printf("\nunable to open clone file");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                fappend(file2, data);
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
void ebox(int dx, int dy, int sx, int sy, int col)
        {
        int x = dx, y = dy;
        int i;
        int parx, pary;
        // tk(col);
        //  stand
        for (i = y + 1; i <= y + sy - 1; i++)
                {
                parx = x + sx;
                gotoxy(dx, i);
                printf(" ");
                gotoxy(parx, i);
                printf(" ");
                }
        // flat
        for (i = x + 1; i <= x + sx - 1; i++)
                {
                pary = y + sy;
                gotoxy(i, dy);
                printf(" ");
                gotoxy(i, pary);
                printf(" ");
                }
        // up left corner
        gotoxy(dx, dy);
        printf(" ");
        // up right corner
        parx = dx + sx;
        gotoxy(parx, dy);
        printf(" ");
        // down left corner
        pary = dy + sy;
        gotoxy(dx, pary);
        printf(" ");
        // down right corner
        pary = dy + sy;
        parx = dx + sx;
        gotoxy(parx, pary);
        printf(" ");
        tk(15);
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
        printf("╭");
        // up right corner
        parx = dx + sx;
        gotoxy(parx, dy);
        printf("╮");
        // down left corner
        pary = dy + sy;
        gotoxy(dx, pary);
        printf("╰");
        // down right corner
        pary = dy + sy;
        parx = dx + sx;
        gotoxy(parx, pary);
        printf("╯");
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

        if (array2d == NULL)
                {
                printf("calloc memory allocation failed");
                exit(0);
                }
        for (i = 0; i < row; i++)
                {
                array2d[i] = (char *)calloc(colum, sizeof(char));

                if (array2d[i] == NULL)
                        {
                        printf("calloc memory allocation failed");
                        exit(0);
                        }
                }
        return array2d;
        }
void flush()
        {
        fflush(stdin);
        fflush(stdout);
        fflush(stderr);
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
        // beep();
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
        //
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
int errorLoad(err *e, char *command)
        {
        FILE *fp;
        char data[1000];
        char com[1100];
        int status;
        int in = 0;
        // system(command);
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
                        strcpy(e->derr[in], data);
                        in += 1;
                        }
                }
        strcpy(e->derr[in], "-1");
        status = fclose(fp);
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
        strcpy(temp, token);
        ptr += llre(temp, ':', 3);
        // ptr += llre(temp, ':', 1);
        strcpy(token, ptr);
        }
int errwork(err *e, int *in, int *tot)
        {
        int i, st, end;
        // cclrscr();
        flush();
        *tot = errorLoad(e, "gcc ___temp.c -o ___temp.out 1>ein.t 2>error.txt&");
        for (i = 0; i < *tot; i++)
                {
                el(e->derr[i], in, i);
                elw(e->derr[i]);
                }
        flush();
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
        system(" gcc -Wall -Wextra  ___temp.c 0>input.txt 1>e.txt 2>error.txt &");
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
         while (1) {
                 int line=llre(ptr, ' ', 1);
                 ptr[line] = '\0';
         * * printf("%s", ptr);
                 ptr+=line; }*/
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
                if (strchr(token, '(') != NULL && strchr(token, ')') != NULL)
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
void funcload(char *filename, int index, char *dname)
        {
        FILE *fp;
        int i;
        char data[100000];
        char temp[100000];
        char *token = temp;
        char in = 0;
        // int flag = 0;
        int con = 0;
        int flag = 0;

        fclear("___funcpara.txt");
        fclear("___tvar.txt");
        fclear("global.txt");
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open function file");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (funcheck(data))
                        {
                        if (flag)
                                break;
                        fclear("___tvar.txt");
                        fappend("___funcpara.txt", data);
                        // cat("global.txt", "___tvar.txt");
                        funcscan(data, token);
                        strcat(token, "()\n");
                        fappend(dname, token);
                        in++;
                        }
                if (in == 0)
                        {
                        fappend("global.txt", data);
                        }

                else
                        fappend("___tvar.txt", data);
                if (con == index)
                        break;
                con++;
                }
        if (in == 0)
                {
                fclear("___tvar.txt");
                fappend("___funcpara.txt", data);
                cat("global.txt", "___tvar.txt");
                }
        fclear("fun.txt");
        // readf("___tvar.txt");
        duprem(dname, "fun.txt");
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
                // printf("%d|%s\n", con, temp);
                //                d(temp, "___func.txt");
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
                if (strchr(token, '{') != NULL)
                        {
                        return 2;
                        }
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
                if (varcheck(data) == 1)
                        {
                        tk(RED);
                        // printf("%s", data);
                        tk(WHITE);
                        varscan(name, data);
                        continue;
                        }
                if (varcheck(data) == 2)
                        {
                        char *ptr = data;
                        ptr += llre(data, '{', 1) + 1;
                        tk(RED);
                        // printf("%s", data);
                        tk(WHITE);
                        varscan(name, ptr);
                        continue;
                        }
                // printf("%s", data);
                }
        fclose(fp);
        duprem(name, "varc.txt");
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
void fpar(char *source, int index, char *dest)
        {
        FILE *fp;
        char data[190000];
        char temp[10000];
        int i = 0;
        fp = fopen(source, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file parameter ");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (funcheck(data))
                        {
                        fclear(dest);
                        parex(data, dest);
                        }
                if (i == index)
                        break;
                i++;
                }
        fclose(fp);
        }
void parex(char *source, char *dest)
        {
        int max = cns(source, ',');
        char temp[1000];
        int i, in, flag = 0;
        char *ptr = temp;
        strcpy(temp, source);
        for (i = 1; i <= max; i++)
                {
                flag = 0;
                ptr = temp;
                strcpy(temp, source);
                ptr += llre(source, ',', i);
                *ptr = '\n';
                ptr += 1;
                *ptr = '\0';
                ptr -= 2;
                for (; *ptr != ' ' && flag == 1 || flag == 0; ptr--)
                        {
                        if (*ptr != ' ')
                                {
                                flag = 1;
                                }
                        }
                ptr += 1;
                //       printf("noting %s", ptr);
                fappend(dest, ptr);
                }
        flag = 0;
        strcpy(temp, source);
        ptr = temp;
        ptr += llre(source, ')', 1);
        *ptr = '\n';
        ptr += 1;
        *ptr = '\0';
        ptr -= 2;
        for (; *ptr != ' ' && flag == 1 || flag == 0; ptr--)
                {
                if (*ptr != ' ')
                        {
                        flag = 1;
                        }
                }
        ptr += 1;
        //       printf("noting %s", ptr);
        fappend(dest, ptr);
        }
void rev(char *source)
        {
        int status = 1;
        int flag = 0;
        char *sdef = source + strlen(source) - 1;
        char temp[1000];
        char *ddef = temp;
        int len, i;
        // printf("sdef=%s %c\n", source, *sdef);
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
void stabbox(int x, int y, char *token, int col)
        {
        int dy = y + 1;
        int len = 0;
        box(x, y, 20, 2, col);
        gotoxy(x + 1, dy);
        len = printf("%s", token);
        for (; len < 19; len++)
                printf(" ");
        }
void tabbox(int x, int y, mainv val[], tabm tabc)
        {
        tabm tabi;
        int dy = y + 1;
        int i;
        tabi.min = tabc.min;
        tabi.max = tabc.max;
        for (i = 0; i <= tabc.totin; i++)
                {
                if (i >= tabc.min && i <= tabc.max)
                        {
                        tabi.index = i;
                        errtabbox(x, y, val, tabi);
                        if (i == tabc.index)
                                box(x, y, 20, 2, 2);
                        gotoxy(x + 1, dy);
                        tk(15);
                        printf("%s", val[i].filename);
                        x += 21;
                        }
                }
        }

void errtabbox(int x, int y, mainv val[], tabm tabc)
        {
        int dy = y + 1;
        int i;
        for (i = 0; i <= tabc.totin; i++)
                {
                if (i >= tabc.min && i <= tabc.max)
                        {
                        ebox(x, y, 20, 2, 15);
                        gotoxy(x + 1, dy);
                        tk(0);
                        printf("                   ");

                        x += 21;
                        }
                }
        tk(15);
        }
void lsdata(char *command, char *filename)
        {
        char temp[1999];
        sprintf(temp, "ls *.c 1>%s", command, filename);
        modifyls(filename);
        system(temp);
        }
void lsmove(tabm *tabc)
        {
        int flag = 0;
        char temp[1000];
        lsdata("ls", "ls.txt");
        lspr("ls.txt", tabc->index, tabc->min, tabc->max);
        while (1)
                {
                if (kbhit())
                        {
                        char ch;
                        while (kbhit())
                                {
                                ch = getch();
                                }
                        switch (ch)
                                {
                        case 'A':
                                if (tabc->index > 0)
                                        tabc->index--;
                                break;
                        case 'B':
                                if (tabc->index < tabc->totin)
                                        tabc->index++;
                                break;
                        case '\n':
                                flag = 1;
                                break;
                        case 4:
                                flag = 1;
                                break;
                                }
                        chtab(tabc);
                        lspr("ls.txt", tabc->index, tabc->min, tabc->max);
                        }
                if (flag)
                        break;
                }
        }
void lspr(char *filename, int index, int min, int max)
        {
        FILE *fp;
        int x = 2, y = 5;
        int i, r, c;
        int cl = 0;
        int len = 0;
        int coun = 0;
        char data[1000];
        char store[1000][1000];
        fp = fopen(filename, "r");
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (coun >= min && coun < max && strstr(data, ".c") != NULL)
                        {
                        gotoxy(x, y);
                        if (cl)
                                {
                                cl = 0;
                                bk(DARKGRAY);
                                tk(0);
                                }
                        else
                                {
                                cl = 1;
                                tk(15);
                                bk(0);
                                }
                        if (index == coun)
                                {
                                tk(15);
                                bk(4);
                                }
                        len = strlen(data) - 1;
                        data[len] = '\0';
                        len = printf("%s", data);
                        for (; len < 19; len++)
                                printf(" ");
                        y += 1;
                        }
                coun += 1;
                }
        bk(0);
        tk(15);
        }
void fdataloader(char *filename, mainv *val, int index)
        {
        FILE *fp;
        char data[10000];
        int i = 0;
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                fclear(filename);
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                data[strlen(data) - 1] = '\0';
                strcpy(vali.data[i], data);
                i++;
                vali.tlinec++;
                }
        vali.tlinec -= 1;
        fclose(fp);
        }
int totallc(char *filename)
        {
        FILE *fp;
        int line = 0;
        char data[10000];
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("unable to open ls file");
                return -1;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                line++;
        return line;
        }
void lsindata(char *filename, char *token, int index)
        {
        FILE *fp;
        char data[1000];
        int coun = 0;
        fp = fopen(filename, "r");
        if (fp == NULL)
                return;
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (coun == index)
                        strcpy(token, data);
                coun++;
                }
        token[strlen(token) - 1] = '\0';
        fclose(fp);
        }

void erindata(char *filename, char *token, int index)
        {
        FILE *fp;
        char data[10000];
        long coun = 0;
        fp = fopen(filename, "r");
        if (fp == NULL)
                return;
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (coun == index)
                        {
                        strcpy(token, data);
                        break;
                        }
                coun++;
                }
        token[strlen(token) - 1] = '\0';
        fclose(fp);
        }
void modifyls(char *filename)
        {
        }
void create(mainv *val, int *index, int *totin)
        {
        static int n = 1;
        char temp[1000];
        char i = *index;
        char j = *index;
        int rindex = *index;
        int dumax = vald.umax - vald.umin;
        int dmax = vald.lmax - vald.lmin;
        *index += 1;
        copyval(val, val, *index, *totin);
        sprintf(temp, "Untilted %d", n);
        n++;
        valprov(val, *index, temp, dmax, val[rindex].dx, val[rindex].dy, dumax);
        *totin += 1;
        }
void createmade(mainv *val, int *index, int *totin)
        {
        static int n = 1;
        char temp[1000];
        char i = *index;
        char j = *index;
        int rindex = *index;
        int dumax = vald.umax - vald.umin;
        int dmax = vald.lmax - vald.lmin;
        *index += 1;
        copyval(val, val, *index, *totin);
        sprintf(temp, "Untilted %d", n);
        n++;
        valprov(val, *index, temp, dmax, val[rindex].dx, val[rindex].dy, dumax);
        *totin += 1;
        }

void terminate(mainv *val, int *index, int *totin)
        {
        if (*totin > 0)
                {
                remval(val, val, *index, *totin);
                *totin -= 1;
                *index -= 1;
                }
        }
void copyval(mainv *val, mainv *vals, int index, int totin)
        {
        int i, j;
        int count = 0;
        j = totin;
        i = totin + 1;
        for (; j >= index && i > 0; i--, j--)
                {
                val[i] = val[j];
                }
        }
void remval(mainv *val, mainv *vals, int index, int totin)
        {
        int i, j;
        int count = 0;
        j = index + 1;
        i = index;
        for (; j <= totin; i++, j++)
                {
                val[i] = val[j];
                }
        }

void delwhile(long long int del)
        {
        del = 0;
        while (del > 0)
                {
                del -= 1;
                while (kbhit())
                        getch();
                }
        while (kbhit())
                getch();
        }

int finder(char *sname, char *dname)
        {
        FILE *fp;
        int con = 0;
        char data[1000];
        fp = fopen(sname, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file");
                return -1;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (strcmp(data, dname) == 0)
                        con++;
                }
        return con;
        }
void duprem(char *sname, char *dname)
        {
        FILE *fp;
        char data[1000];
        fclear(dname);
        fp = fopen(sname, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (finder(dname, data) < 1)
                        {
                        fappend(dname, data);
                        }
                }
        }

void gccrun(char *filename)
        {
        char temp[1000];
        char name[1900];
        clrscr();
        tk(15);
        strcpy(name, filename);
        name[strlen(name) - 2] = '\0';
        flush();
        while (kbhit())
                getch();
        sprintf(temp, "gcc ___temp.c -o ___temp.out && ./___temp.out");
        system(temp);
        flush();
        while (kbhit())
                getch();
        }
int mfs(intle *intles, char *filename, char *token)
        {
        FILE *fp;
        char data[1000];
        int len = strlen(token);
        int mlen = len;
        char *ptr;
        int index = 0;
        int coun = 0;
        int flag = 0;
        int i;
        //  strcat(token,"\n");
        // printf("%s", token);
        fp = fopen(filename, "r");
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                coun = 0;
                for (i = 0; i < len; i++)
                        {
                        if (data[i] == token[i])
                                {
                                int j = i + 1;
                                coun++;
                                if (coun == mlen && data[j] != '\n')
                                        {
                                        if (token[j] == ' ' || token[j] == '\0')
                                                {
                                                int clen = 0;
                                                fappend("inte.txt", data);
                                                strcpy(intles->data[index], data);

                                                intles->data[index][strlen(intles->data[index]) - 1] = '\0';
                                                ptr = data;
                                                ptr += len;
                                                flag = 1;
                                                // len=strlen(ptr);
                                                // ptr[len]='\0';
                                                strcpy(intles->clip[index], ptr);
                                                fappend("clip.txt", intles->clip[index]);
                                                index += 1;
                                                break;
                                                }
                                        }
                                continue;
                                }

                        break;
                        }
                }
        if (flag)
                {
                char filename[] = "inte.txt";
                oipr(cx, cy, filename);
                istatus(1, 1);
                }
        else
                istatus(0, 1);
        fclose(fp);
        return index;
        }

void beep()
        {
        system("play -n synth 0.10  sine 1000 0>null.txt 1>null.txt 2>null.txt &");
        }
void ipr(int x, int y, tabm *tabc, char *filename)
        {
        FILE *fp;
        char data[1000];
        char fn[] = "user.txt";
        int len = 0;
        int i;
        int con = 0;
        int maxc = 0;
        int cur = 0;
        int dx, dy;
        fclear(fn);
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("Unable to open file ipr");
                return;
                }
        con = 0;
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (con >= tabc->min && con < tabc->max)
                        {
                        fappend(fn, data);
                        // strcpy(strc[maxc], data);
                        if (con == tabc->index)
                                {
                                cur = maxc;
                                }
                        //      printf("\npass1 :%s", strc[maxc]);
                        maxc++;
                        }
                con += 1;
                }

        fclose(fp);
        fp = fopen(fn, "r");
        if (fp == NULL)
                {
                printf("Unable to open file ipr");
                return;
                }
        i = 0;
        if (x > 60)
                {
                x -= 32;
                }
        if (y < 22)
                {
                y += 1;

                // printf("pass");
                while (fgets(data, sizeof(data), fp) != NULL)
                        {
                        //               strcpy(data, strc[i]);
                        len = 0;
                        dx = x;
                        dy = y;
                        bk(DARKGRAY);
                        tk(0);
                        if (i == cur)
                                {
                                bk(4);
                                tk(15);
                                }
                        flush();
                        data[strlen(data) - 1] = '\0';
                        for (; len < 2 && dx < 118; len++, dx++)
                                {
                                gotoxy(dx, dy);
                                printf(" ");
                                }
                        // 92
                        for (len = 0; len < strlen(data) && dx < 118; len++, dx++)
                                {
                                gotoxy(dx, dy);
                                printf("%c", data[len]);
                                }
                        for (; len < 30 && dx < 118; len++, dx++)
                                printf(" ");
                        y += 1;
                        i++;
                        }
                }
        else
                {
                y -= 1;
                while (fgets(data, sizeof(data), fp) != NULL)
                        {
                        len = 0;
                        dx = x;
                        dy = y;
                        bk(DARKGRAY);
                        tk(0);
                        if (i == cur)
                                {
                                bk(4);
                                tk(15);
                                }
                        flush();
                        data[strlen(data) - 1] = '\0';
                        for (; len < 2 && dx < 118; len++, dx++)
                                {
                                gotoxy(dx, dy);
                                printf(" ");
                                }
                        // 92
                        for (len = 0; len < strlen(data) && dx < 118; len++, dx++)
                                {
                                gotoxy(dx, dy);
                                printf("%c", data[len]);
                                }
                        for (; len < 30 && dx < 118; len++, dx++)
                                printf(" ");

                        y -= 1;
                        i++;
                        }
                }
        fclose(fp);
        bk(0);
        tk(15);
        }
int inmove(int x, int y, int max, char *filename)
        {
        tabm tab;
        tabm *tabc = &tab;
        int flag = 0;
        char temp[1000];
        tabc->index = 0; //"inte.txt"
        tabc->totin = totallc(filename) - 1;
        tabc->min = 0;
        tabc->max = max;
        ipr(x, y, tabc, "inte.txt");
        if (y < 22)
                while (1)
                        {
                        if (kbhit())
                                {
                                char ch;
                                while (kbhit())
                                        {
                                        ch = getch();
                                        }
                                switch (ch)
                                        {
                                case 'A':
                                        if (tabc->index > 0)
                                                tabc->index--;
                                        else
                                                tabc->index = tabc->totin;
                                        break;
                                case 'B':
                                        if (tabc->index < tabc->totin)
                                                tabc->index++;
                                        else
                                                tabc->index = 0;
                                        break;

                                case '\n':
                                        flag = 1;
                                        break;
                                case 4:
                                        flag = 1;
                                        break;
                                default:
                                        return -1;
                                        }
                                chtab(tabc);
                                ipr(x, y, tabc, "inte.txt");
                                }
                        if (flag)
                                break;
                        }
        else
                while (1)
                        {
                        if (kbhit())
                                {
                                char ch;
                                while (kbhit())
                                        {
                                        ch = getch();
                                        }
                                switch (ch)
                                        {
                                case 'B':
                                        if (tabc->index > 0)
                                                tabc->index--;
                                        else
                                                tabc->index = tabc->totin;
                                        break;
                                case 'A':
                                        if (tabc->index < tabc->totin)
                                                tabc->index++;
                                        else
                                                tabc->index = 0;
                                        break;

                                case '\n':
                                        flag = 1;
                                        break;
                                case 4:
                                        flag = 1;
                                        break;
                                default:
                                        return -1;
                                        }
                                chtab(tabc);
                                ipr(x, y, tabc, "inte.txt");
                                }
                        if (flag)
                                break;
                        }
        return tabc->index;
        }
void oipr(int x, int y, char *filename)
        {
        tabm tab;
        tabm *tabc = &tab;
        int flag = 0;
        char temp[1000];
        tabc->index = 0; //"inte.txt"
        tabc->totin = totallc(filename) - 1;
        tabc->min = 0;
        tabc->max = 4;
        ipr(x, y, tabc, "inte.txt");
        }
int istatus(int i, int flag)
        {
        static int st = 0;
        if (flag)
                st = i;
        return st;
        }

int intlex(char *token, int cn, intle *intles)
        {
        char temp[100];
        char *ptr = temp;
        int i = cn - 1;
        int j = 0;
        int flag = 0;
        strcpy(temp, token);
        fclear("clip.txt");
        fclear("inte.txt");
        if (token[cn] != ' ' && token[cn] != '\0')
                return 0;
        if (token[i] == ' ' && i > 0)
                return 0;
        ptr += strlen(temp);
        for (i = cn; *ptr != ' ' && i > 0; i--, ptr--)
                ;
        if (i > 0)
                {
                ptr += 1;
                }
        strcpy(temp, ptr);
        mfs(intles, "___keyword.txt", ptr);
        return 1;
        }
void purivar(char *filename, char *name)
        {
        FILE *fp;
        char not [100] = "{[()]}";
        char data[100000];
        char *ptr = data;
        fclear(name);
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file purivar");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                ptr = data;
                for (; *ptr != '\0'; ptr++)
                        {
                        if (strchr(not, *ptr) != NULL)
                                {
                                *ptr = '\n';
                                ptr++;
                                *ptr = '\0';
                                }
                        }
                fappend(name, data);
                }
        fclose(fp);
        }
int checkst(char *token, int cn)
        {
        int i = cn + 1;
        int j = cn - 1;
        if (j < 0)
                j = 0;
        if (cn == 0)
                return 0;
        if (token[cn] == ' ' || token[cn] == '\0')
                {
                if (token[j] != ' ')
                        {
                        return 1;
                        }
                }
        return 0;
        }
void filemid(char *filename, int in, int index, mainv *val)
        {
        FILE *fp;
        int i;
        int con = 0;
        int flag = 0;
        char data[10000];
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("file unable open filemid");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (con == in)
                        {
                        data[strlen(data) - 1] = '\0';
                        for (i = 0; i < strlen(data); i++)
                                {
                                if (data[i] == '(')
                                        flag = 1;
                                midputc(vali.data[vali.linec], data[i], &vali.cn);
                                }
                        if (flag)
                                vali.cn -= 1;
                        }
                con += 1;
                }
        fclose(fp);
        }
void clean()
        {
        fclear("clip.txt");
        fclear("inte.txt");
        fclear("___keyword.txt");
        fclear("var.txt");
        fclear("varc.txt");
        fclear("func.txt");
        fclear("___tvar.txt");
        fclear("fun.txt");
        fclear("para.txt");
        fclear("golobal.txt");
        }
int intelsence(int x, int y, intle *intles, mainv *val, int index)
        {
        clean();
        // cat("___keyword.txt","kw.txt");
        if (checkst(vali.data[vali.linec], vali.cn) == 1)
                {
                char td[10000];
                // parameter
                        {
                    //     fpar(temp, vali.linec, "para.txt");
                    //   purivar("para.txt", "var.txt");
                    //   cat("var.txt", "___keyword.txt");
                    // readf("var.txt");
                        } // global""
                        {
                        varload("___tvar.txt", "var.txt");
                        purivar("global.txt", "var.txt");
                        cat("global.txt", "___keyword.txt");
                        } // function
                        {
                        funcload("___temp.c", vali.linec, "func.txt");
                        cat("fun.txt", "___keyword.txt");
                        }
                // variable
                        {
                        varload("___tvar.txt", "var.txt");
                        purivar("varc.txt", "var.txt");
                        cat("var.txt", "___keyword.txt");
                        }
                // keywords
                        {
                        cat("kw.txt", "___keyword.txt");
                        }
                strcpy(td, vali.data[vali.linec]);
                td[vali.cn] = '\0';
                intlex(td, vali.cn, intles);
                oipr(x, y, "inte.txt");
                return 1;
                }
        else
                {
                istatus(0, 1);
                return 0;
                }
        }
int structcheck(char *data)
        {
        if (strstr(data, "struct") != NULL && strstr(data, "=") == NULL)
                {
                if (strstr(data, ";") != NULL)
                        {
                        if (strstr(data, "}") != NULL)
                                return 1;
                        else
                                return 0;
                        }
                return 1;
                }
        return 0;
        }

int structvar(char *data)
        {
        if (strstr(data, "struct") != NULL && strstr(data, "=") == NULL)
                {
                if (strstr(data, ";") != NULL)
                        {
                        if (strstr(data, "}") != NULL)
                                return 1;
                        else
                                return 0;
                        }
                return 1;
                }
        return 0;
        }
void structmain(char *sname, char *stemp, char *dname)
        {
        FILE *fp;
        char upname[1990];
        char lastname[1000];
        char *ptr;
        char data[10000];
        int i = 0;
        fclear(dname);
        fp = fopen(stemp, "r");
        if (fp == NULL)
                {
                printf("\nUnable to open file");
                return 1;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                if (i == 0)
                        strcpy(upname, data);
                strcpy(lastname, data);
                i++;
                }
        if (strstr(upname, "typedef") != NULL)
                {
                ptr = lastname;
                ptr += llre(lastname, '}', 1) + 1;
                for (; *ptr == ' '; ptr++)
                        ;
                for (i = 0; *ptr != ' ' && *ptr != ';' && *ptr != '\0'; ptr++, i++)
                        ;
                *ptr = '\0';
                ptr -= i;
                }
        else
                {
                ptr = upname;
                if (strchr(upname, '{') != NULL)
                        ptr += llre(upname, '{', 1) - 1;
                else
                        ptr += strlen(data);
                for (; *ptr == ' ' && *ptr == '\n'; ptr--)
                        ;
                *ptr = '\0';
                for (i = 0; *ptr != ' '; ptr--, i++)
                        ;
                }
        fclose(fp);
        }
void structload(char *sname, char *dname)
        {
        FILE *fp;
        char stemp[1000] = "vtemp.txt";
        char stvar[1000] = "stvar.txt";
        char data[19000];
        char open = 0;
        char check[100];
        int flag = 0;
        int status = 0;
        fclear(stemp);
        fclear(stvar);
        clrscr();
        fp = fopen(sname, "r");
        if (fp == NULL)
                {
                printf("\n Unable to open file structload");
                return;
                }
        while (fgets(data, sizeof(data), fp) != NULL)
                {
                int endflag = 0;
                if (structcheck(data))
                        {
                        fclear(stemp);
                        flag = 1;
                        }
                if (flag)
                        {
                        if (strchr(data, '{') != NULL)
                                {
                                open += 1;
                                status = 1;
                                }
                        if (strchr(data, '}') != NULL)
                                {
                                open -= 1;
                                }
                        if (status || status == 0 && strstr(data, "}") != NULL && strstr(data, ";") != NULL)
                                {
                                if (open == 0)
                                        {
                                        flag = 0;
                                        status = 0;
                                        endflag = 1;
                                        }
                                }
                        // printf("%s",data);
                        fappend(stemp, data);
                        }
                if (endflag)
                        {
                        structmain(sname, stemp, dname);
                        endflag = 0;
                        }
                }
        fclose(fp);
        }
