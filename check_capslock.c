#include <fcntl.h>       // File control operations
#include <linux/input.h> // Input device definitions
#include <stdio.h>       // Standard I/O functions
#include <unistd.h>      // UNIX standard function definitions

int main()
{
        int fd = open("/dev/input/eventX",
                      O_RDONLY); // Keyboard device file ko open karein. 'X' ko sahi number se replace karein.
        if (fd == -1)
        {
                perror("Cannot open device"); // Agar device open nahi hota toh error message print karein.
                return 1;
        }

        struct input_event ev; // 'input_event' structure ka instance 'ev' banate hain.

        while (1)
        {                                  // Infinite loop
                read(fd, &ev, sizeof(ev)); // Device se event read karein.
                if (ev.type == EV_KEY)
                { // Agar event type keypress ya key release hai.
                        if (ev.code == KEY_LEFTSHIFT || ev.code == KEY_RIGHTSHIFT)
                        { // Agar key code left ya right Shift key ka hai.
                                if (ev.value == 1)
                                { // Agar key press hua hai.
                                        printf("Shift key pressed\n");
                                }
                                else if (ev.value == 0)
                                { // Agar key release hua hai.
                                        printf("Shift key released\n");
                                }
                        }
                }
        }

        close(fd); // Device file ko close karein.
        return 0;
}
