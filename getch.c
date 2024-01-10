#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include<fcntl.h> 
char  getch()
        { 
        struct termios old,new;
        char ch;
        tcgetattr(STDIN_FILENO,&old);
        new=old; 
        new.c_lflag&=~(ICANON|ECHO);
        tcsetattr(STDIN_FILENO,TCSANOW,&new);
        ch=getchar(); 
        tcsetattr(STDIN_FILENO,TCSANOW,&old);
        return ch;  
        } 
int main()
        {
        printf("enter a data %c ",getch()); 
        return 1;  
        } 
