#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
        FILE *fp;
        char data[1024];
        fp = fopen("/home/dubey/Documents/Cproject/std.txt", "r");
        if (fp == NULL)
        {
                printf("Unable to open file\n");
                exit(1);
        }
        while (fgets(data, sizeof(data), fp) != NULL)
        {
                printf("0%s", data);
                fgets(data, sizeof(data), fp);
                printf("1%s", data);
                fgets(data, sizeof(data), fp);
                printf("2%s", data);
                fgets(data, sizeof(data), fp);
                printf("3%s", data);
        }

        fclose(fp);
}
