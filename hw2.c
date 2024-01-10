#include <conio.h>
#include <stdio.h>
void input_i(int *, int);
void print_i(int *, int);
void rev(int *, int);
void swap(int *, int *);
void box(int, int, int, int, int);
#define tk textcolor
#define bk textbackground
int main()
        {
        int arr[11];
        clrscr();
        printf("\nInput data into array ");
        input_i(arr, 11);
        printf("\n Press any key to see data in a array"); getch();
        clrscr();
        printf("\n data in array ");
        print_i(arr, 11);
        printf("\n Press any key to see reverse data in a array"); getch();
        clrscr();
        rev(arr, 11);
        printf("\nReverse data in array ");
        print_i(arr, 11);
        getch();
        return 1;
        }
void rev(int *ptr, int size)
        {
        int *rptr = ptr + size - 1;
        int i;
        for (i = 0; i < size / 2; i++, rptr--, ptr++)
                {
                swap(&*ptr, &*rptr);
                }
        }
void input_i(int *ptr, int size)
        {
        int i;
        for (i = 0; i < size; i++)
                {
                printf("enter a data in  arr[%d] ;", i);
                scanf("%d", ptr);
                ptr++;
                }
        }
void print_i(int *ptr, int size)
        {
        int i;
        for (i = 0; i < size; i++)
                {
                printf("\ndata in arr[%d] ;%d", i, *ptr);
                ptr++;
                }
        }
void swap(int *a, int *b)
        {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
        }
