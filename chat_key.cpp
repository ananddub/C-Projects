#include <stdio.h>
#include <time.h>

int main() {
    char c;
    int start_time, end_time, total_time;
    int word_count = 0;
    int in_word = 0;

    printf("Enter some text: ");

    start_time = clock();

    while ((c = getche) != '\r') {
        if (c == ' ' || c == '\n') {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    if (in_word) {
        word_count++;
    }

    end_time = clock();
    total_time = (end_time - start_time) / CLOCKS_PER_SEC;

    printf("WPM: %d\n", (word_count / total_time) * 60);

    return 0;
}

