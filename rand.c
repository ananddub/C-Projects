#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
        srand(time(NULL));
        int flag = rand() % 2;
        printf("Question :Colleage jana chaiye ?\n");
        printf("Ans ->");
        if (flag == 1)
                printf("NO");
        else
                printf("Yes");

        printf("\n\n\n\n");
        return 0;
}
