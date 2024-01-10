// Write a function in C that takes an integer array and its size as parameters and returns the sum of all elements in the array using pointer arithmetic.
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void main()
        {
        int i=0,n,*ptr,*stptr;
        printf("Enter the no. of elements you want to store : ");
        scanf("%d",&n);
        ptr=(int*)malloc(n*sizeof(int));
        stptr=ptr;
        printf("Enter the elements : \n");
        for(i=0;i<n;i++)
                {
                scanf("%d",ptr++);
                 } 
        ptr=stptr;
        for(i=0;i<n;i++) printf("%d \n",*ptr++);

        for(i=0;i<n;i++) printf("\n%d ",*stptr++);
        getch();
        }
       
