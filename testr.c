#include <stdio.h>

int main() {
    FILE *fileIn, *fileOut;
    char ch;

    // Open the input file in read mode
    fileIn = fopen("temp.txt", "r");
    if (fileIn == NULL) {
        printf("Unable to open the input file.\n");
        return 1;
    }
 
    // Open a temporary output file in write mode
    fileOut = fopen("temporary.txt", "w");
    if (fileOut == NULL) {
        printf("Unable to create the output file.\n");
        fclose(fileIn);
        return 1;
    }

    // Copy non-blank lines from input file to output file
    while ((ch = fgetc(fileIn)) != EOF) {
        if (ch != '\n') {
            fputc(ch, fileOut);
        } else {
            // Check if the line is blank (contains only newline character)
            int isBlank = 1;
            while ((ch = fgetc(fileIn)) != EOF) {
                 {
                    isBlank = 0;
                    break;
                }
            }
            if (!isBlank) {
                fputc('\n', fileOut);
                fseek(fileIn, -1, SEEK_CUR); // Rewind by one character
            }
        }
    }

    // Close the input and output files
    fclose(fileIn);
    fclose(fileOut);

    printf("Blank lines removed successfully.\n");

    return 0;
}
