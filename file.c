#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 1000000

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    char file_buffer[MAX_FILE_SIZE];
    int choice;
    FILE *fp;

    while (1)
    {
        printf("\nFile Manager\n");
        printf("1. Create a new file\n");
        printf("2. Open an existing file\n");
        printf("3. Read from a file\n");
        printf("4. Write to a file\n");
        printf("5. Close the file\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);
                fp = fopen(filename, "w");
                if (fp == NULL)
                {
                    printf("Error: Unable to create the file.\n");
                }
                else
                {
                    printf("File created successfully.\n");
                    fclose(fp);
                }
                break;
            case 2:
                printf("Enter the filename: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                if (fp == NULL)
                {
                    printf("Error: Unable to open the file.\n");
                }
                else
                {
                    printf("File opened successfully.\n");
                }
                break;
            case 3:
                if (fp == NULL)
                {
                    printf("Error: No file is open.\n");
                }
                else
                {
                    fread(file_buffer, sizeof(char), MAX_FILE_SIZE, fp);
                    printf("File contents: %s\n", file_buffer);
                }
                break;
            case 4:
                if (fp == NULL)
                {
                    printf("Error: No file is open.\n");
                }
                else
                {
                    printf("Enter the text to write to the file: ");
                    scanf("%s", file_buffer);
                    fwrite(file_buffer, sizeof(char), strlen(file_buffer), fp);
                    printf("Text written to the file.\n");
                }
                break;
            case 5:
                if (fp == NULL)
                {
                    printf("Error: No file is open.\n");
                }
                else
                {
                    fclose(fp);
                    printf("File closed successfully.\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

