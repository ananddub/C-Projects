#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    unsigned char buffer[100];
    size_t bytesRead;

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in binary mode
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read and display the contents of the file
    while ((bytesRead = fread(buffer, sizeof(unsigned char), sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            printf("%02X ", buffer[i]);
        }
    }

    printf("\n");

    // Close the file
    fclose(file);

    return 0;
}
