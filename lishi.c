#include <conio.h>
#include <stdio.h>
int factor(int *num)
        {               
        *num -= 1;      
        if (*num == 0)  
                {       
                *num=1; 
                return 1; 
                }       
        printf("%d\n", *num); 
        return factor(num )*(*num);
        }
void main()
        {
        int num, fac;
        clrscr();
        printf("Enter The num: ");
        scanf("%d", &num);
        fac = factor(&num);
        printf("\nFactorial: %d", fac);
        }
