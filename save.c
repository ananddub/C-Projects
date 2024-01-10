#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fileread(char *, const char);
int main(int arg, char *argc[])
        {
        int len = strlen(argc[1]) - 1;
        int len2 = len - 1;
        char save[] = {"mystyle.c"};
        char run[] = {"mystyle.out"};
        if (arg == 1)
                {
                printf("plese give a filename");
                return 1;
                }
        char data[10000];
        if (argc[1][len2] != '.' && argc[1][len] != 'c')
                {
                strcat(argc[1], ".c");
                }
        sprintf(
            data,
            "clang-format --style=\"{BasedOnStyle: Microsoft, IndentWidth: 8}\" %s >temp.txt &&gcc %s -o %s && ./%s %s",
            argc[1], save, run, run, argc[1]);
        printf("%s", data);
        system(data);
        // sprintf(data, "cat temp.txt>%s", argc[i]);
        //  system(data);
        return 1;
        }
