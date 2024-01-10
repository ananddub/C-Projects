#include <conio.h>
#include <stdio.h>
#include <string.h>
#define ABOLD "\033[1m"
#define RBOLD "\033[0m"
int main()
{
        long del;
        char data[100] = "printing 1000 times a sorry for krishnavi";
        int col = 1;
        int i;
        int j;
        getch();
        printf("\t\t\t\t");
        for (i = 0; i < strlen(data); i++)
        {
                // if(i%10==0)
                {
                        col++;
                        if (col == 16)
                                col = 1;
                }
                textcolor(col);
                fflush(stdout);
                printf("%s%c", ABOLD, data[i]);
                for (del = 0; del < 100000000; del++)
                        ;
        }
        for (i = 0; i < 1000; i++)
        {
                if (i % 10 == 0)
                {
                        col++;
                        if (col == 16)
                                col = 1;
                }
                textcolor(col);
                fflush(stdout);
                for (j = 0; j < 1; j++)
                        printf("\n________________________________________________");
                printf("Sorry krishnavi_______________________________________________________");
                for (del = 0; del < 10000000; del++)
                        ;
        }
        printf("\n1000 times completed");
        return 1;
}
5
