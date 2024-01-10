#include <conio.h>
#include <stdio.h>
int fact(int);
void main()
        {
        printf("%d", fact(10));
        }
int fact(int n)
        {
        if (n > 1)
                return fact(n - 1) * n;
        }
