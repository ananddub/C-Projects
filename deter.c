#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pass printf("\npass");
typedef struct det
{
        char a[1000];
        char b[1000];
        char c[1000];
        int ans;
} det;

typedef struct indet
{
        int a[10];
        int b[10];
        int c[10];
        int max;
        int ans;
} indet;
int deterint(char *, int *);
int deter(det);
int main()
{
        det d = {"2,3,-5", "2,5,-14", "5,8,20", -1};
        deter(d);
        return 1;
}
int deter(det dc)
{
        indet di;
        int i;
        pass i = deterint(dc.a, di.a);
}
int deterint(char *token, int *a)
{
        char *temp = (char *)malloc(strlen(token) + 10);
        char *min;
        char *fix;
        char *max = temp;
        int i = 0;
        pass strcpy(temp, token);
        fix = &temp[strlen(temp)];
        fflush(stdout);
        printf("%s\n", max);
        fflush(stdout);
        while (max < fix)
        {
                char *th;
                min = max;
                th = strchr(max, ',');
                if (th == NULL)
                {
                        break;
                }
                max = th;
                *max = '\0';
                max += 1;
                a[i] = atoi(min);
                fflush(stdout);
                i++;
        }
        a[i] = atoi(min);
        free(temp);
        i++;
        return i;
}
