#include <conio.h>
#include <stdio.h>
const int test(char *);
int main()
        {
        test("hello woorld");
        return 1;
        }
const int test(char *token)
        {
        int i=0;
        printf("%s", token);
        return i;
        } 
