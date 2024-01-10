#include <stdio.h>
void readf(const char*);
int main()
        {
        FILE *file;
        char *filename = "example.txt";
        // Open the file in write mode to clear its contents
        file = fopen(filename, "w");
        // Check if the file was opened successfully
        if (file == NULL)
                {
                printf("Unable to open the file.\n");
                return 1;
                }
        // Close the file to clear its contents
        fclose(file);
        // Open the file in append mode
        file = fopen(filename, "a");
        // Check if the file was opened successfully in append mode
        if (file == NULL)
                {
                printf("Unable to open the file.\n");
                return 1;
                }
        // Write to the file
        fprintf(file, "This is new content appended to the file.");
        // Close the file
        fclose(file);
        printf("File '%s' cleared and new content written successfully.\n\n\n", filename);
        readf(filename); 
        return 0;
        }
void readf(const char *filename)
        {
        FILE *fp;
        char string[100000];
        fp = fopen(filename, "r");
        if (fp == NULL)
                {
                printf("\n Unable to open file");
                return;
                }
        while (fgets(string, sizeof(string), fp) != NULL)
                {
                printf("%s", string);
                }
        }
