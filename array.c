// write a program to print the data of an array of size 10 using pointer
//  modify the above program and take the data in array using pointer by user
#include <conio.h>
#include <stdio.h>
void main()
        {
        int arr[10];
        int *ptr = arr;
        int i;
        clrscr();
        for (i = 0; i < 10; i++)
                {
                printf("enter a value in arr[%d] : ", i);
                scanf("%d", ptr);
                ptr += 1;
                }
        ptr = arr;
        for (i = 0; i < 10; i++)
                {
                printf("\n value in arr[%d] :%d", i, *ptr);
                ptr += 1;
                }
        getch();
        }
