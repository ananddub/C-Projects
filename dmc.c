#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **dcaloc(int, int);
char **drealoc(char **, int, int);
void dfree(char **, int);
void dcat(char **dest, int, char **, int);
void dcpy(char **, char **, int);
int main()
        {
        char **data = dcaloc(6, 1024);
        int i, j;
        char **dest = dcaloc(6, 1024);
        char **ptr = dest;
        strcpy(data[0], "hello world");
        strcpy(data[1], "hi kase ho tum");
        dcpy(dest, data, 6);
        dcat(dest, 1, data, 1); 
        ptr += 2;    
        printf("print:%s", *ptr);
        return 1;
        }
void dcat(char **dest, int drow, char **source, int max)
        {
        int i;
        for (i = 0; i <=max; i++, drow++)
                {
                strcpy(dest[drow], source[i]);
                }
        } 
void dcpy(char **dest, char **source, int max)
        {
        int i;
        int row = 1;
        for (i = 0; i <= max; i++)
                {
                strcpy(dest[i], source[i]);
                }
        }
char **drealoc(char **resize, int row, int colum)
        {
        char **doublea = (char **)realloc(resize, row + sizeof(char *));
        int i;
        for (i = 0; i <= row; i++)
                {
                doublea[i] = (char *)realloc(resize[i], colum + sizeof(char));
                }
        return doublea;
        }
char **dcaloc(int row, int colum)
        {
        char **array2d = (char **)calloc(row, sizeof(char *));
        int i;
        for (i = 0; i <= row; i++)
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
