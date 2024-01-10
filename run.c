#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tk textcolor
#define bk textbackground
void seprator(char *, char *, char *);
void python(char);
void C(char);
void anim(int, int, int, int, char[]);
void error(int, int, char[]);
void delayc()
{
        long i;
        char anim[100] = {"   press any key to exit"};
        static int cn = 4;
        char ch;
        tk(15);
        ch = toupper(anim[cn]);
        for (i = 0; i < cn; i++)
                printf("%c", anim[i]);
        tk(cn / 2);
        printf("%c\r", ch);
        cn += 1;
        if (strlen(anim) == cn)
                cn = 4;
        else if (anim[cn] == ' ')
                cn += 1;
        for (i = 0; i <= 300000; i++)
                if (kbhit())
                        exit(0);
        tk(15);
}
int main(int argc, char *argv[])
{
        FILE *fp;
        char exec[10000] = {'\0'};
        char *filename;
        char data[1000] = {'\0'};
        char cd[10000] = {'\0'};
        char tempc[1000] = {'\0'};
        char animation[] = "press any key to continue";
        int len;
        if (argc != 2)
        {
                printf("Please provide a single file name as an argument.\n");
                return 1;
        }
        filename = argv[1];
        system("clear");
        bk(0);
        tk(15);
        fp = fopen("tempp.txt", "w");
        fputs(argv[1], fp);
        fclose(fp);
        // printf("filename=%s\n", filename);
        // getch();
        strcpy(tempc, filename);
        strcpy(data, filename);
        if (strstr(data, ".c") != NULL)
        {
                len = strlen(data) - 2;
                tempc[len] = '\0';
        }
        if (strchr(filename, '/') != NULL)
        {
                seprator(cd, data, tempc);
                strcpy(data, tempc);
                if (strstr(tempc, ".py") != NULL)
                {
                        sprintf(exec, " cd %s && xdotool type '1' && xdotool key return &&  sudo python3 %s", cd, tempc);
                        // system(exec);
                        // sprintf(exec,"xdotool type '1' && xdotool key return")
                }
                if (strstr(tempc, ".js") != NULL)
                {
                        sprintf(exec, " cd %s && xdotool type '1' && xdotool key return &&  sudo node %s", cd, tempc);
                        // system(exec);
                        // sprintf(exec,"xdotool type '1' && xdotool key return")
                }
                else if (strstr(tempc, ".c") != NULL)
                {
                        len = strlen(data) - 2;
                        tempc[len] = '\0';
                        sprintf(exec, "cd %s && gcc %s.c -lcurl -o %s.out  && ./%s.out ", cd, tempc, tempc, tempc);
                }

                system(exec);
        }
        else
        {
                sprintf(data, "gcc %s.c -o -lcurl %s.out   && ./%s.out", tempc, tempc, tempc);
                system(data);
        }

        printf("\n");
        while (1)
        {
                // delayc();
                printf("   press any key to exit   \r");
                delayc();
                printf("   press any key to exit.  \r");
                delayc();
                printf("   press any key to exit.. \r");
                delayc();
                printf("   press any key to exit...\r");
                delayc();
        }
        return 0;
}
void C(char filename)
{
        printf("hello world ");
}
void seprator(char *cd, char *data, char *temp)
{
        char tempc[1000];
        char *ptr = tempc;
        char cc[10000];
        char *token = cc;
        char len;
        int cn = 0;
        int tlen = 0;
        int i;
        len = 0;
        strcpy(tempc, data);
        cd[0] = '\0';
        temp[0] = '\0';
        strcpy(cc, tempc);
        for (i = strlen(tempc); ptr[i] != '/'; i--)
        {
                ptr[i] = '\0';
        }
        sprintf(cd, "%s", ptr);
        token[i] = '\0';
        token += i + 1;
        strcpy(temp, token);
        //  printf("lates=%s\n", temp);
        // getch();
}
void anim(int x, int y, int bkl, int clk, char data[])
{
        long i, j;
        char ch;
        int cl = 0;
        while (1)
        {
                bk(bkl);
                tk(clk);
                if (kbhit())
                        break;
                gotoxy(x, y);
                printf("%s", data);
                for (i = 0; i < strlen(data); i++)
                {
                        bk(bkl);
                        tk(clk);
                        if (kbhit())
                                break;
                        ch = toupper(data[i]);
                        if (ch == ' ')
                                continue;
                        else
                        {
                                gotoxy(x, y);
                                for (j = 0; j < i; j++)
                                        printf("%c", data[j]);
                                tk(cl);
                                cl++;
                                if (cl == 16)
                                        cl = 0;
                                printf("%c", ch);
                        }
                        gotoxy(100, 50);
                        for (j = 0; j <= 300000 && kbhit() != 1; j++)
                                ;
                }
                if (kbhit())
                        break;
        }
        bk(0);
        tk(15);
}
void error(int x, int y, char data[])
{
        long i, j;
        char ch;
        int cl = 0;
        int count = 0;
        while (1)
        {
                bk(0);
                tk(15);
                if (kbhit())
                        break;
                gotoxy(x, y);
                printf("%s", data);
                for (i = 0; i < 3; i++)
                {
                        if (i < count)
                                printf(".");
                        else
                                printf(" ");
                }
                for (i = 0; i < strlen(data); i++)
                {
                        bk(0);
                        tk(15);
                        if (kbhit())
                                break;
                        ch = toupper(data[i]);
                        if (ch == ' ')
                                continue;
                        else
                        {
                                gotoxy(x, y);
                                for (j = 0; j < i; j++)
                                        printf("%c", data[j]);
                                tk(cl);
                                cl++;
                                if (cl == 16)
                                        cl = 0;
                                printf("%c", ch);
                        }
                        gotoxy(100, 50);
                        for (j = 0; j <= 100000 && kbhit() != 1; j++)
                                ;
                }
                count += 1;
                if (count == 4)
                        count = 0;
                if (kbhit())
                        break;
        }
        gotoxy(x, y);
        for (i = 0; i <= strlen(data) + 2; i++)
                printf(" ");
        bk(0);
        tk(15);
}
