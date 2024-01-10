#include<stdio.h>
#include<conio.h>
void main()
        {
        int farr[10]={1,2,3,5,67,8,87,33,45,32};
        int sarr[10];
        int *fptr,*sptr;
        int ctr;
        clrscr();
        fptr=farr;
        sptr=sarr;
        printf("\nPress any key to see the source  array...");
        getch();
        for(ctr=0;ctr<=9;ctr++)
                {
                printf("\nfptr[%d]=%d",ctr,*fptr);
                fptr++;
                }
        sptr=sarr;
        fptr=farr+9;
        getch();
        printf("\ndata copied to source array to another array.. ");
        getch();
        for(ctr=0;ctr<=9;ctr++)
                {
                *sptr=*fptr;
                fptr--;
                sptr++;
                }
        fptr=farr;
        sptr=sarr;
        printf("\nYour data is copied \nPress any key to see your copied data");
        getch();
        for(ctr=0;ctr<=9;ctr++)
                {
                printf("\nsarr[%d]=%d",ctr,*sptr);
                sptr++;
                }
        getch();  
        }
