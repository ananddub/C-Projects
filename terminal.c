#include <stdio.h>
#include <string.h>
#include <uconio.h>
int kbhit();
char getch();
void start();
void end();
void print(int);
void outp();
void CD();
int cd_check();
void keycheck(int);
int key();
int strcmp2();
char ndisp();
int nkey(char);
void cdir();
int bks();
int bin(int);
void keyword_in();
void ex();
int del();
int skey(char);
int _auto();
int blank();
#define data d[fn]._data
#define out d[fn]._output
#define keyword d[fn]._keyword
#define cn d[fn]._cn
#define cd d[fn]._cd
#define cdch d[fn]._cdch
#define clipboard d[fn]._clipboard
#define history d[fn]._history
struct __data
        {
        char _data[1000];
        char _output[10000];
        char _keyword[10000000];
        char _history[100][100000];
        char _clipboard[1000];
        int _cn;
        char _cd[1000];
        char _cdch[1000];
        };
struct __data d[100];
int fn = 0;
int hfn = 0, lhfn = 0;
const char inputkey[] = {
    " abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ123456789/*-+`~!@#$%^&*()_+{}|:\"<>?[];',./\\"};
int main()
        {
        clrscr();
        sprintf(cd, "/home/dubey");
        sprintf(data, "/home/dubey");
        keyword_in();
        data[0] = '\0';
        start();
        return 1;
        }
void ex()
        {
        char temp[1000];
        char *rest = temp;
        char *token;
        strcpy(temp, data);
        while ((token = strsep(&rest, " ")) != NULL)
                {
                if (strcmp(token, "exit") == 0)
                        exit(0);
                }
        }
void cdir()
        {
        FILE *fp;
        static char tmp[100000];
        char p[100000];
        char stemp[10000];
        char htemp[10000];
        char *rest = stemp;
        char *token;
        sprintf(stemp, "%s", cd);
        while ((token = strsep(&rest, " ")) != NULL)
                {
                strcpy(htemp, token);
                }
        sprintf(p, "ls -a  %s 2> /dev/null ", htemp);
        fp = popen(p, "r");
        cdch[0] = '\0';
        while (fgets(p, sizeof(p), fp) != NULL)
                {
                strcat(keyword, p);
                }
        if (pclose(fp) == 0)
                {
                tmp[0] = '\0';
                strcpy(tmp, keyword);
                //     printf("\t\t\t\t\t\tnot worked(%s)",keyword);
                }
        else
                {
                strcpy(keyword, tmp);
                //     printf("{%s}",keyword);
                }
        //   printf("%s",keyword);
        }
int cd_check()
        {
        FILE *fp;
        char dat[100000];
        char adata[1000];
        char ddata[1000];
        char p[1000000];
        int ct = 0;
        static char tmp[100000];
        char *rest = ddata;
        char *token;
        cdir();
        sprintf(ddata, "%s", data);
        while ((token = strsep(&rest, " ")) != NULL)
                {
                sprintf(adata, "%s", token);
                sprintf(p, "ls -a %s 2> /dev/null ", adata);
                }
        //     printf("%s",p);
        fp = popen(p, "r");
        cdch[0] = '\0';
        while (fgets(p, sizeof(p), fp) != NULL)
                {
                ct += 1;
                if (ct > 2)
                        {
                        sprintf(dat, "%s%s", adata, p);
                        strcat(keyword, dat);
                        strcat(keyword, p);
                        }
                }
        if (pclose(fp) == 0)
                {
                tmp[0] = '\0';
                strcpy(tmp, keyword);
                }
        else
                {
                strcpy(keyword, tmp);
                }
        //     printf("%s",keyword);
        }
int strcmp2()
        {
        char tdata[100000];
        char hdata[100000];
        char *rest = tdata;
        char *token;
        strcpy(tdata, data);
        while ((token = strsep(&rest, " ")) != NULL)
                {
                strcpy(hdata, token);
                }
        if (strcmp(hdata, "ls") == 0)
                return 1;
        else
                return 0;
        }
void keyword_in()
        {
        FILE *fp;
        int i = 0, len;
        int min = 10000;
        int ad = 0;
        int j = 0;
        fp = popen("ls -a /usr/bin", "r");
        keyword[0] = '\0';
        strcat(keyword, out);
        cd_check();
        //   printf("%s",keyword);
        //  printf("{%d}{%s}",strlen(keyword));
        strcat(keyword, "\ncd\nmkdir\nrm\nrm -r\ncp\ncp -r");
        strcat(keyword, "\nvim\nkill\nman\ngcc\npython\nls\nls -a\nsudo\nsu\npacman\n-S\n-Sy\n-Syu\n");
        strcat(keyword, "\nexit\n");
        while (fgets(out, sizeof(out), fp) != NULL)
                {
                strcat(keyword, out);
                }
        pclose(fp);
        //      printf("%s",keyword);
        }
void start()
        {
        clrscr();
        data[0] = '\0';
        cn = 0;
        cd[0] = '\0';
        strcpy(cd, "cd /home/dubey");
        print(1);
        while (1)
                {
                if (kbhit())
                        {
                        key();
                        print(1);
                        }
                }
        }
int _auto(char **token)
        {
        int rt = 0;
        char teakey[100000];
        char tkey[100000];
        char *keyrest = teakey;
        char *kytoken;
        char *keytoken = tkey;
        int count = 0;
        int len = 0;
        //  printf("%d",strlen(keyword));
        sprintf(teakey, "%s", keyword);
        // sprintf(tkey,"can\ntouch",keyword);
        // printf("%s",*token);/*
        clipboard[0] = '\0';
        // cd_check();
        while ((kytoken = strsep(&keyrest, "\n")) != NULL)
                {
                char ch;
                sprintf(tkey, "%s", kytoken);
                len = strlen(*token);
                keytoken += len;
                ch = *keytoken;
                *keytoken = '\0';
                keytoken -= len;
                tk(9);
                count++;
                //  printf("%s count=%d,",kytoken,count);
                if (strcmp(keytoken, *token) == 0 && strlen(keytoken) > 0)
                        {
                        int i;
                        len = strlen(*token);
                        keytoken += len - 1;
                        *keytoken = '\0';
                        keytoken += 1;
                        *keytoken = ch;
                        tk(DARKGRAY);
                        printf("%s", keytoken, count);
                        sprintf(clipboard, "%s", keytoken);
                        return strlen(keytoken);
                        }
                }
        return 0;
        }
int bin(int gt)
        {
        char tdata[10000];
        char tkey[100000];
        char hdata[10000];
        char *hpdata = hdata;
        char *drest = tdata;
        char *dtoken;
        char *krest = tkey;
        char *ktoken;
        int count = 0;
        int flag = 0;
        int len = 0;
        int fl = 0;
        int lc = 0;
        int i = 0;
        int cc = 0;
        tdata[0] = '\0';
        strcpy(tdata, data);
        while ((dtoken = strsep(&drest, " ")) != NULL)
                {
                //      tk(RED);
                strcpy(tkey, keyword);
                sprintf(hdata, "%s", dtoken);
                while ((ktoken = strsep(&krest, "\n")) != NULL)
                        {
                        if (strcmp(ktoken, dtoken) == 0)
                                flag = 1;
                        }
                if (count == 0)
                        {
                        tk(YELLOW);
                        printf(":");
                        tk(RED);
                        }
                else
                        printf(" ");
                if (flag == 1)
                        {
                        tk(BLUE);
                        flag++;
                        }
                else if (flag == 2)
                        {
                        tk(CYAN);
                        }
                else
                        {
                        tk(RED);
                        }
                for (i = 0; i < strlen(dtoken); i++)
                        {
                        printf("%c", dtoken[i]);
                        }
                count += strlen(dtoken) + 1;
                if (count == cn && gt == 1)
                        {
                        len += _auto(&dtoken);
                        fl = 1;
                        printf("");
                        }
                cc++;
                }
        if (fl == 0 && blank() == 1 && gt == 1)
                {
                len += _auto(&hpdata);
                printf("");
                fl = 1;
                }
        return len;
        }
void print(int flagcc)
        {
        int len = strlen(data), i;
        int bk1 = 0, flag = 0;
        char dtemp[1000];
        char *ptemp = dtemp;
        tk(WHITE);
        printf("\r");
        strcpy(dtemp, cd);
        ptemp += 2;
        *ptemp = '\0';
        ptemp += 1;
        keyword_in();
        tk(WHITE);
        printf("Dubey@");
        tk(9);
        printf("terminal");
        tk(6);
        printf("[%s]", ptemp);
        tk(15);
        for (i = 0; i <= len; i++)
                {
                if (cn == i)
                        flag = 1;
                if (flag == 1)
                        bk1++;
                }
        bk1 += bin(flagcc);
        for (i = 0; i < 20; i++)
                {
                printf(" ");
                }
        //    printf("   ");
        // 3
        bk1 += 19;
        for (i = 0; i < bk1; i++)
                {
                printf("\b");
                }
        }
void CD()
        {
        FILE *fp;
        char temp1[1000];
        char hcd[1000];
        int flag = 0, len;
        if (strstr(data, "cd") != NULL)
                {
                strcpy(hcd, cd);
                sprintf(temp1, "%s && %s && pwd ", cd, data);
                cd[0] = '\0';
                fp = popen(temp1, "r");
                while (fgets(out, sizeof(out), fp) != NULL)
                        {
                        sprintf(cd, "cd %s", out);
                        flag = 1;
                        }
                pclose(fp);
                if (flag)
                        {
                        len = strlen(cd) - 1;
                        cd[len] = '\0';
                        }
                }
        if (strlen(cd) == 0)
                {
                strcpy(cd, hcd);
                }
        }
int blank()
        {
        int i;
        char _inputkey[] = {
            "abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ123456789/*-+`~!@#$%^&*()_+{}|:\"<>?[];',\\./"};
        for (i = 0; i < strlen(_inputkey); i++)
                {
                if (strchr(data, _inputkey[i]) != NULL)
                        {
                        return 1;
                        }
                }
        return 0;
        }
void outp()
        {
        FILE *fp;
        char temp1[1000];
        char p[10000];
        char tp[10000];
        char hp[10000];
        char *rest = tp;
        char *token;
        int flag = 0;
        strcpy(history[lhfn], data);
        lhfn++;
        hfn++;
        if (blank())
                sprintf(temp1, "%s && %s  ", cd, data);
        else
                {
                temp1[0] = '\0';
                }
        system(temp1);
        /*    if(blank())
                            {
                    if(strstr(data,"ls")!=NULL)
                                      {
                              //if(strstr(data,"-l")==NULL)
                                            {
                                    sprintf(temp1,"%s && %s -l",cd,data);
                                    flag=1;
                                  //  printf("\t\t\\t\t\t\t\t\t%s flag=1 " ,temp1);
                                            }
                            //  else
                              //       sprintf(temp1,"%s && %s 2> /dev/null",cd,data);
                                      }
                            }
           else
                            {
                    temp1[0]='\0';
                            }
            fp=popen(temp1,"r");
            while(fgets(p,sizeof(p),fp))
                            {
                    if(strstr(p,"drwx")!=NULL)tk(BLUE);
                    else if(strstr(p,".rw")!=NULL)tk(WHITE);
                    else tk(GREEN);
                 /*   if(flag==1)
                                    {
                            int i,j=0;
                            int cnn=0;
                            for(i=strlen(p),j=0;;i--,j++)
                                            {
                                    tp[j]=p[i];
                                    printf("%c",p[i]);
                                    if(cnn>1)
                                                    {
                                            if(p[i]!=' ')
                                                    break;
                                                    }
                                    cnn++;
                                            }
                            j++;
                            tp[j]='\0';
                            for(i=strlen(tp)-1,j=0;i>1 ;i--,j++)
                                            {
                                    hp[j]=tp[i];
                            j++;
                            hp[j]='\0';
                            strcpy(p,hp);
                            printf("%s\n",hp);
                                    }
                    else*/
        //                 printf("%s",p);
                //        }
        //   pclose(fp);
        }
int key()
        {
        char ch;
        ch = getch();
        if (strchr(inputkey, ch) != NULL)
                {
                nkey(ch);
                }
        else
                {
                skey(ch);
                }
        }
int skey(char ch)
        {
        int len = 0;
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
        case 'A':
                int i, len;
                len = strlen(data);
                if (hfn > 0)
                        {
                        hfn -= 1;
                        strcpy(data, history[hfn]);
                        cn = strlen(data);
                        i = cn;
                        for (i = len; i >= cn; i--)
                                {
                                printf("\b");
                                }
                        for (i = cn; i <= len; i++)
                                {
                                printf(" ");
                                }
                        }
                break;
        case 'B':
                len = strlen(data);
                if (hfn < lhfn)
                        {
                        hfn += 1;
                        strcpy(data, history[hfn]);
                        cn = strlen(data);
                        i = cn;
                        for (i = len; i >= cn; i--)
                                {
                                printf("\b");
                                }
                        for (i = cn; i <= len; i++)
                                {
                                printf(" ");
                                }
                        break;
                        }
        case 9:
                if (clipboard[0] != '\0')
                        {
                        for (i = 0; i < strlen(clipboard); i++)
                                {
                                nkey(clipboard[i]);
                                }
                        clipboard[0] = '\0';
                        break;
                        }
                break;
        case 12:
                sprintf(data, "clear");
                ungetc('\n', stdin);
                break;
        case 'C':
                if (clipboard[0] != '\0')
                        {
                        for (i = 0; i < strlen(clipboard); i++)
                                {
                                nkey(clipboard[i]);
                                }
                        clipboard[0] = '\0';
                        break;
                        }
                len = strlen(data);
                if (cn < len)
                        cn++;
                break;
        case 'D':
                if (cn > 0)
                        cn--;
                break;
        case 127:
                if (cn > 0)
                        bks();
                break;
        case '~':
                del();
                break;
        case '\n':
                print(0);
                tk(GREEN);
                printf("\n");
                ex();
                blank();
                outp();
                CD();
                data[0] = '\0';
                cn = 0;
                break;
                }
        }
int del()
        {
        int len;
        len = strlen(data);
        cn++;
        if (cn < len)
                bks();
        else
                cn--;
        }
int bks()
        {
        char temp[1000];
        int i, j, len;
        len = strlen(data);
        j = cn;
        temp[0] = '\0';
        for (i = 0; i < len; i++)
                {
                temp[i] = data[j];
                j++;
                }
        temp[i] = '\0';
        cn--;
        len = strlen(temp);
        j = cn;
        for (i = 0; i < len; i++)
                {
                data[j] = temp[i];
                j++;
                }
        data[j] = '\0';
        }
int nkey(char ch)
        {
        char temp[1000];
        int i, j, len;
        len = strlen(data);
        j = cn;
        temp[0] = '\0';
        for (i = 0; i < len; i++)
                {
                temp[i] = data[j];
                j++;
                }
        temp[i] = '\0';
        data[cn] = ch;
        len = strlen(temp);
        cn++;
        j = cn;
        for (i = 0; i < len; i++)
                {
                data[j] = temp[i];
                j++;
                }
        data[j] = '\0';
        }
int kbhit()
        {
        struct termios old, new;
        int ch;
        int oldf;
        tcgetattr(STDIN_FILENO, &old);
        new = old;
        new.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        if (ch != EOF)
                {
                ungetc(ch, stdin);
                return 1;
                }
        return 0;
        }
char getch()
        {
        char ch;
        struct termios old, new;
        tcgetattr(STDIN_FILENO, &old);
        new = old;
        new.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
        return ch;
        }
