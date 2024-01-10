#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tk textcolor
#define bk textbackground
typedef struct student
{
        char name[1000];
        char roll[1000];
        char sec[200];
        char phone[110];
} student;
typedef struct
{
        int index;
        int totin;
        int max;
        int min;
} tabm;
void box(int, int, int, int, int);
int nav();
void add();
void image(int);
void records();
void lspr(char *, int, int, int);
void lsmove(tabm *);
void slspr(char *, int, int, int);
void slsmove(tabm *);
void append(char *, char *);
void printimgcl();
student printimg(student);
int check(student);
long maxline(char *);
void scan(student);
void simage(int);
void chtab(tabm *);
void search();
void clear(char *);
void main()
{
        menu();
        gotoxy(20, 50);
}

int menuimg(int cn)
{
        char value[][100] = {"ADD", "RECORDS", "SEACRCH", "EXIT"};
        int i, j, x = 4, y = 4;
        bk(0);
        box(1, 2, 10, 40, 15);
        for (i = 0; i < 4; i++)
        {
                if (cn == i)
                {
                        int y;
                        bk(BLUE);
                        y = 3 + (i * 4);
                        // printf("y=%d", y);
                        for (j = 0; j < 3; j++)
                        {

                                gotoxy(1, y);
                                if (j == 1)
                                {
                                        int len = printf("  %s", value[i]);

                                        for (; len < 11; len++)
                                                printf(" ");
                                }
                                else
                                        printf("           ");

                                y += 1;
                        }
                        bk(0);
                        box(1, 2, 10, 40, 15);
                }
                else
                {
                        int y;
                        bk(0);
                        y = 3 + (i * 4);
                        // printf("y=%d", y);
                        for (j = 0; j < 3; j++)
                        {

                                gotoxy(1, y);
                                if (j == 1)
                                {
                                        printf(" %s", value[i]);
                                }
                                y += 1;
                        }
                        bk(0);
                        box(1, 2, 10, 40, 15);
                }
        }
}
void menu()
{
        int cn = 2;
        while (1)
        {
                bk(0);
                clrscr();
                menuimg(cn);

                bk(0);
                tk(15);
                switch (cn)
                {
                case 0:
                        image(1);
                        break;

                case 1:
                        tabm tab;

                        tab.index = 0;
                        tab.min = 0;
                        tab.max = 26;
                        tab.totin = maxline("std.txt");
                        lspr("std.txt", tab.index, tab.min, tab.max);
                        bk(0);
                        tk(15);
                        break;

                case 2:
                        tabm tabc;
                        student std = {"", "", "", ""};
                        simage(1);
                        scan(std);
                        tabc.index = 0;
                        tabc.min = 0;
                        tabc.max = 19;
                        tabc.totin = maxline("std.txt");
                        // lsdata("ls", "ls.txt");
                        slspr("std.txt", tabc.index, tabc.min, tabc.max);
                        bk(0);
                        tk(15);
                        break;

                case 3:

                        break;
                }

                bk(0);
                tk(15);
                switch (getch())
                {
                case 'B':
                        if (cn < 3)
                                cn++;
                        break;
                case 'A':
                        if (cn > 0)
                                cn--;
                        break;
                case '\n':
                        switch (cn)
                        {
                        case 0:

                                add();
                                break;

                        case 1:
                                records();
                                break;

                        case 2:
                                bk(0);
                                tk(15);
                                search();

                                menuimg(cn);
                                break;

                        case 3:
                                exit(0);
                                break;
                        }
                }
        }
}
int sflagcheck(int flag)
{
        char ch;
        while (1)
        {
                ch = getch();

                if (ch == 9)
                {
                        if (flag < 4)
                                flag += 1;
                        else
                                flag = 1;
                        simage(flag);
                }
                if (ch == '\n')
                {
                        simage(flag);
                        return flag;
                }
                if (ch == 27)
                {
                        return -1;
                }
        }
        return -1;
}

void search()
{
        student std = {"", "", "", ""};
        int i, j = 1;
        int flag = 1;
        char ch;
        simage(1);
        while (1)
        {
                flag = sflagcheck(flag);
                if (flag == -1)
                        return;
                flush();
                gotoxy(22, 4);
                if (flag == 1)
                {
                        for (int i = 0; i < strlen(std.name); i++)
                                printf(" ");
                        gotoxy(22, 4);

                        gets(std.name);
                }
                else
                        printf(std.name);
                flush();
                gotoxy(58, 4);
                if (flag == 2)
                {
                        for (int i = 0; i < strlen(std.roll); i++)
                                printf(" ");
                        gotoxy(58, 4);

                        gets(std.roll);
                }
                else
                        printf(std.roll);
                flush();
                gotoxy(74, 4);
                if (flag == 3)
                {
                        printf("  ");
                        gets(std.sec);
                }
                else
                        printf(std.sec);
                flush();
                gotoxy(27, 7);
                if (flag == 4)
                {
                        for (int i = 0; i < strlen(std.phone); i++)
                                printf(" ");
                        gotoxy(27, 7);

                        gets(std.phone);
                }
                else
                        printf(std.phone);
                simage(flag);
                scan(std);
                tabm tabc;
                slsmove(&tabc);
        }
}
student stdnull(student std)
{
        std.name[0] = '\0';
        std.sec[0] = '\0';
        std.roll[0] = '\0';
        std.phone[0] = '\0';
        return std;
}
void add()
{
        student std = {"", "", "", ""};
        image(1);
        std = printimg(std);
        while (1)
        {
                char ch = getch();
                if (ch == '\n')
                {
                        printimgcl();
                        std = printimg(std);
                        std = stdnull(std);
                }
                else if (ch == 27)
                {
                        break;
                }
        }
}
void records()
{
        tabm tab;

        tab.index = 0;
        tab.min = 0;
        tab.max = 26;
        tab.totin = maxline("std.txt");
        lspr("std.txt", tab.index, tab.min, tab.max);

        lsmove(&tab);

        bk(0);
        tk(15);
        clrscr();
}
void simage(int flag)
{
        int blue = 15;
        // box(28, 2, 38, 11, 10);

        if (flag == 1)
                blue = BLUE;
        else
                blue = 15;

        gotoxy(15, 4);
        printf("Name");
        box(20, 3, 25, 2, blue);

        if (flag == 2)
                blue = BLUE;
        else
                blue = 15;

        gotoxy(48, 4);
        printf("Roll No");
        box(56, 3, 10, 2, blue);

        if (flag == 3)
                blue = BLUE;
        else
                blue = 15;

        gotoxy(68, 4);
        printf("Sec");
        box(72, 3, 10, 2, blue);

        if (flag == 4)
                blue = BLUE;
        else
                blue = 15;

        gotoxy(15, 7);
        printf("Phone No.");
        box(25, 6, 24, 2, blue);

        box(12, 2, 110, 8, 15);
        //
}
void image(int flag)
{
        box(28, 2, 38, 11, 10);

        gotoxy(30, 4);
        printf("Name");
        box(35, 3, 28, 2, 15);

        gotoxy(30, 7);
        printf("Roll No");
        box(38, 6, 10, 2, 15);

        gotoxy(49, 7);
        printf("Sec");
        box(53, 6, 10, 2, 15);

        gotoxy(30, 10);
        printf("Phone No.");
        box(39, 9, 24, 2, 15);

        if (flag == 1)
        {
                box(28, 14, 38, 2, BLUE);
                gotoxy(45, 15);
                printf("Save");
        }
        else if (flag == 2)
        {
                box(28, 14, 38, 2, GREEN);
                gotoxy(45, 15);
                printf("Saved");
        }
}

void flush()
{
        fflush(stdin);
        fflush(stdout);
        fflush(stderr);
}
void input(student std, char *filename)
{
        char data[10000];
        sprintf(data, "name: %s", std.name);
        append(filename, data);

        sprintf(data, "\nroll no: %s", std.roll);
        append(filename, data);

        sprintf(data, "\nsec: %s", std.sec);
        append(filename, data);

        sprintf(data, "\nphone no: %s", std.phone);
        append(filename, data);

        sprintf(data, "\n-----------------------------------------------------------------\n");
        append(filename, data);
}
void inputauto(student std, char *filename)
{
        char data[10000];
        sprintf(data, "%s", std.name);
        append(filename, data);

        sprintf(data, "%s", std.roll);
        append(filename, data);

        sprintf(data, "%s", std.sec);
        append(filename, data);

        sprintf(data, "%s", std.phone);
        append(filename, data);

        sprintf(data, "-----------------------------------------------------------------\n");
        append(filename, data);
}
student printimg(student std)
{
        int i, j = 1;
        image(1);
        flush();
        gotoxy(36, 4);
        gets(std.name);
        flush();
        gotoxy(39, 7);
        gets(std.roll);
        flush();
        gotoxy(55, 7);
        gets(std.sec);
        flush();
        gotoxy(40, 10);
        gets(std.phone);
        image(2); /*
         name: Ravi
         roll no: 822111
         sec: B
         phone no: 789456124
         -----------------------------------------------------------------*/
        input(std, "std.txt");
}
void printimgcl()
{
        image(1);
        flush();
        gotoxy(36, 4);
        printf("                                 ");
        flush();
        gotoxy(39, 7);
        printf("       ");
        flush();
        gotoxy(55, 7);
        printf("       ");
        flush();
        gotoxy(40, 10);
        printf("                                 ");
        // image(2);
}
void append(char *filename, char *token)
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
void box(int dx, int dy, int sx, int sy, int col)
{
        int x = dx, y = dy;
        int i;
        int parx, pary;
        textcolor(col);
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

        textcolor(15);
}
long maxline(char *filename)
{
        FILE *fp;
        long line = -1;
        char data[1000];
        fp = fopen(filename, "r");
        if (fp == NULL)
        {
                printf("\nUnable to open maxline");
                return 0;
        }
        while (fgets(data, sizeof(data), fp) != NULL)
        {
                if (fgets(data, sizeof(data), fp) == NULL)
                        return line;
                else if (fgets(data, sizeof(data), fp) == NULL)
                        return line;
                else if (fgets(data, sizeof(data), fp) == NULL)
                        return line;
                else if (fgets(data, sizeof(data), fp) == NULL)
                        return line;
                line += 1;
        }
        fclose(fp);
        return line;
}
void slsmove(tabm *tabc)
{
        int flag = 0;
        char temp[1000];
        tabc->index = 0;
        tabc->min = 0;
        tabc->max = 19;
        tabc->totin = maxline("temp.txt");
        // lsdata("ls", "ls.txt");
        slspr("temp.txt", tabc->index, tabc->min, tabc->max);
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
                                bk(0);
                                printf(" ");
                                tk(15);
                                break;
                        case 4:
                                flag = 1;
                                break;
                        }

                        menuimg(2);
                        chtab(tabc);
                        slspr("temp.txt", tabc->index, tabc->min, tabc->max);
                }
                if (flag)
                        break;
        }
}
void slspr(char *filename, int index, int min, int max)
{
        FILE *fp;
        int x = 15, y = 13;
        int i, r, c;
        int cl = 0;
        int len = 0;
        int coun = 0;
        int indexs = 0;

        char data[1000];
        int lenname[5] = {6, 8, 4, 10};
        char store[1000][1000];
        char *ptr = data;
        static int ic = 0;
        gotoxy(15, 11);
        bk(0);
        tk(15);
        printf(" Name\t\t\tRollno\t\t\tSec\t\t\t PhoneNo");
        fp = fopen(filename, "r");
        // printf("pass %d",ic++);
        while (fgets(data, sizeof(data), fp) != NULL)
        {
                if (coun >= min && coun < max)
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
                        fgets(data, sizeof(data), fp);
                        if (data[4] == '-')
                                break;
                        data[strlen(data) - 1] = '\0';
                        ptr = data;
                        ptr += lenname[0];
                        len = printf("%s", ptr);
                        for (; len < 25; len++)
                                printf(" ");
                        fgets(data, sizeof(data), fp);
                        data[strlen(data) - 1] = '\0';
                        ptr = data;
                        ptr += lenname[1];
                        len = printf("%s", ptr);
                        for (; len < 25; len++)
                                printf(" ");
                        fgets(data, sizeof(data), fp);
                        data[strlen(data) - 1] = '\0';
                        ptr = data;
                        ptr += lenname[2];
                        len = printf("%s", ptr);
                        for (; len < 25; len++)
                                printf(" ");
                        fgets(data, sizeof(data), fp);
                        data[strlen(data) - 1] = '\0';
                        ptr = data;
                        ptr += lenname[3];
                        len = printf("%s", ptr);
                        for (; len < 25; len++)
                                printf(" ");
                        y += 1;
                        indexs += 1;
                }
                else
                {
                        if (fgets(data, sizeof(data), fp) == NULL)
                                break;
                        else if (fgets(data, sizeof(data), fp) == NULL)
                                break;
                        else if (fgets(data, sizeof(data), fp) == NULL)
                                break;
                        else if (fgets(data, sizeof(data), fp) == NULL)
                                break;
                }
                coun += 1;
        }
        bk(0);
        tk(15);
        for (; indexs < max - min; indexs++)
        {
                gotoxy(x, y);
                for (len = 0; len < 100; len++)
                        printf(" ");

                y += 1;
        }
}
void scan(student std)
{
        FILE *fp;
        char data[1000];
        student stdch;
        int flag = 0;
        char *ptr = data;
        int len[5] = {5, 8, 4, 10};
        int list[4] = {0, 0, 0, 0};
        if (strlen(std.name) > 0)
                list[0] = 1;
        if (strlen(std.roll) > 0)
                list[1] = 1;
        if (strlen(std.sec) > 0)
                list[2] = 1;
        if (strlen(std.phone) > 0)
                list[3] = 1;
        fp = fopen("std.txt", "r");

        // getch();
        if (fp == NULL)
        {
                printf("\nUnable to open file");
                return;
        }
        clear("temp.txt");
        append("temp.txt", "-------------------------------------------------------------\n");
        while (fgets(data, sizeof(data), fp) != NULL)
        {
                int clist[4] = {0, 0, 0, 0};

                flag = 0;
                if (fgets(data, sizeof(data), fp) != NULL)
                {
                        ptr = data;
                        ptr += len[0];
                        data[strlen(data) - 1] = '\0';

                        strcpy(stdch.name, ptr);

                        if (strstr(data, std.name) != NULL && strlen(std.name) > 0)
                        {
                                // printf("[%s]",strstr(data, std.name) );
                                clist[0] = 1;
                                // printf("%s", ptr);
                        }
                }
                if (fgets(data, sizeof(data), fp) != NULL)
                {
                        ptr = data;
                        ptr += len[1];

                        data[strlen(data) - 1] = '\0';
                        strcpy(stdch.roll, ptr);
                        // printf("(%d)",strlen(std.roll));
                        if (strstr(data, std.roll) != NULL && strlen(std.roll) > 0)
                                clist[1] = 1;
                }
                if (fgets(data, sizeof(data), fp) != NULL)
                {
                        ptr = data;
                        ptr += len[2];

                        data[strlen(data) - 1] = '\0';
                        strcpy(stdch.sec, ptr);

                        if (strstr(data, std.sec) != NULL && strlen(std.sec) > 0)
                                clist[2] = 1;
                }
                if (fgets(data, sizeof(data), fp) != NULL)
                {
                        ptr = data;
                        ptr += len[3];
                        data[strlen(data) - 1] = '\0';
                        strcpy(stdch.phone, ptr);
                        if (strstr(data, std.phone) != NULL && strlen(std.phone) > 0)
                        {
                                clist[3] = 1;
                        }
                }

                if (clist[0] == list[0] && clist[1] == list[1] && clist[2] == list[2] && clist[3] == list[3])
                {
                        input(stdch, "temp.txt");
                }
        }
        fclose(fp);
}
void lsmove(tabm *tabc)
{
        int flag = 0;
        char temp[1000];
        tabc->index = 0;
        tabc->min = 0;
        tabc->max = 26;
        tabc->totin = maxline("std.txt");
        // lsdata("ls", "ls.txt");
        lspr("std.txt", tabc->index, tabc->min, tabc->max);
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
                        lspr("std.txt", tabc->index, tabc->min, tabc->max);
                }
                if (flag)
                        break;
        }
}
void clear(char *filename)
{
        FILE *fp;
        fp = fopen(filename, "w");
        if (fp == NULL)
        {
                printf("\nUnable to open file");
                return;
        }
        fclose(fp);
}
void lspr(char *filename, int index, int min, int max)
{
        FILE *fp;
        int x = 15, y = 5;
        int i, r, c;
        int cl = 0;
        int len = 0;
        int coun = 0;
        char data[1000];
        int lenname[5] = {5, 8, 4, 10};
        char store[1000][1000];
        char *ptr = data;
        gotoxy(15, 3);
        bk(0);
        tk(15);
        printf("Name\t\t\tRollno\t\t\tSec\t\t\t PhoneNo");
        fp = fopen(filename, "r");
        while (fgets(data, sizeof(data), fp) != NULL)
        {
                if (coun >= min && coun < max)
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

                        fgets(data, sizeof(data), fp);
                        if (data[4] == '-')
                                return;
                        data[strlen(data) - 1] = '\0';
                        ptr = data;
                        ptr += lenname[0];
                        len = printf("%s", ptr);
                        for (; len < 25; len++)
                                printf(" ");
                        fgets(data, sizeof(data), fp);
                        data[strlen(data) - 1] = '\0';
                        ptr = data;
                        ptr += lenname[1];
                        len = printf("%s", ptr);
                        for (; len < 25; len++)
                                printf(" ");
                        fgets(data, sizeof(data), fp);
                        data[strlen(data) - 1] = '\0';
                        ptr = data;
                        ptr += lenname[2];
                        len = printf("%s", ptr);
                        for (; len < 25; len++)
                                printf(" ");
                        fgets(data, sizeof(data), fp);
                        data[strlen(data) - 1] = '\0';
                        ptr = data;
                        ptr += lenname[3];
                        len = printf("%s", ptr);
                        for (; len < 25; len++)
                                printf(" ");
                        y += 1;
                }
                else
                {
                        if (fgets(data, sizeof(data), fp) == NULL)
                                return;
                        else if (fgets(data, sizeof(data), fp) == NULL)
                                return;
                        else if (fgets(data, sizeof(data), fp) == NULL)
                                return;
                        else if (fgets(data, sizeof(data), fp) == NULL)
                                return;
                }
                coun += 1;
        }
        bk(0);
        tk(15);
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
