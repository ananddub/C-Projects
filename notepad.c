#include <ncurses.h>
#include<stdio.h>  
int kbhit();

int main() {
    int cn = 0;
    char arr[1000];
    int ch;

    initscr();
    
      
       arr[0] = '\0';
 
    while (1) {
         if (kbhit()) {
            keypad(stdscr,TRUE);
            ch = getch();
            refresh();

            if (ch == KEY_F(12)||ch==7) {
                if (cn>=0) { 
                    arr[cn] = '\0';
                    cn -= 1;
                }
            } else if (ch == KEY_F(12)) {
                // F12 key detected
                clear();
                move(20, 50);
                printw("F12 key pressed");
                refresh();
            } else {
                arr[cn] = ch;
                cn++;
                arr[cn] = '\0';
            
            }

            clear();
            move(20, 50);
            printw("%s", arr);
            refresh();
         keypad(stdscr,FALSE);

         }
    }

    endwin();
}

int kbhit() {
    char ch;
    nodelay(stdscr, TRUE);
    ch = getch(); 
    nodelay(stdscr,FALSE); 
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    }
    return 0;
}
