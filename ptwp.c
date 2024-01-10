#include <conio.h>
#include <stdio.h>
void cpystr(char *, char *);
void main()
        {
        char *ptr=0; 
        char arr1[1000] = "hello world";
        char arr2[1000];
        clrscr(); 
        cpystr(arr1,arr2);
        printf("\narr1=%s", arr1);
        printf("\narr2=%s", arr2);
        }
void cpystr(char *source, char *dest)
        {   
        for (; *source != '\0'; dest++, source++)
                *dest = *source;
        *dest = '\0';
        }
