#include <conio.h>
#include <stdio.h>

typedef struct
        {
        int dd, mm, yy;
        } date;
typedef struct
        {
        unsigned long roll;
        char name[100];
        char course[20];
        unsigned long long mob;
        date dob;
        } student;
void main()
        {
        studen std;
        clrscr();
        printf("\nEnter roll no :");
        fflus(stdin);
        scanf("%lu", &std.roll);
        printf("\nEnter your name :");
        fflus(stdin);
        gets(std.name);
        printf("\nEnter your course :");
        fflus(stdin);
        gets(std.course);
        printf("\nEnter  your dd mm yy:");
        fflus(stdin);
        scanf("%d %d %d", &std.dob.dd, &std.dob.mm, , &std.dob.yy);
        printf("\nroll no\tname\tcourse\tmobile\tdate");
        printf("%lu\t%s\t%s\t%llu\t%d %d %d",std.roll,std.name,std.course,std.   );
        }
