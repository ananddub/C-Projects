#include <conio.h>
#include <stdio.h>
int main()
        {
        int flag = 1;
        while (1)
                {
                if (kbhit())
                        {
                        if (flag)
                                clrscr();
                        printf("\n[%d]", getch());
                        flag = 0;
                        continue;
                        }
                flag = 1;
                }
        return 0;
        }
