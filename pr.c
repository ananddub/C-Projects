#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    // Allocate memory for 5 integers
    ptr = (int *)malloc(5 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Resize memory to hold 3 integers
    ptr = (int *)realloc(ptr, 3 * sizeof(int));

    free(ptr);

    return 0;
}

