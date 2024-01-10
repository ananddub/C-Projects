#include <conio.h>
#include <stdio.h>
int find(const char[], const char);
int main()
        {
        const char vowel[] = "aeiouAEIOU";
        char data[100];
        int i, vol = 0, con = 0, cnum = 0;
        clrscr();
        printf("enter your name :");
        gets(data);
        for (i = 0; data[i] != '\0'; i++)
                {
                if (find(vowel, data[i]))
                        vol += 1;
                }
        printf("\ntotal vowel :%d", vol);
        return 1;
        }
int find(const char data[], const char ch)
        {
        int i;
        for (i = 0; data[i] != '\0'; i++)
                {
                if (data[i] == ch)
                        return 1;
                }
        return 0;
        }
