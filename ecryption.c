#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void readb(char *);
void writedb();
void main()
{
        char filename[] = "hello.zip"; // giving file name to perform binary operation
        readb(filename);
}

void readb(char *filename) {
        FILE *fp;
        unsigned char data[1000]; // Buffer to store binary content
        size_t bytesRead;

        fp = fopen(filename, "rb");
        if (fp == NULL) {
                printf("\nUnable to open file");
                return;
        }

        while ((bytesRead = fread(data, 1, sizeof(data), fp)) > 0) {
                for (size_t i = 0; i < bytesRead; i++) {
                        printf("%d ", data[i]); // Print the binary value in hexadecimal
                }
                printf("\n");
        }

        fclose(fp);
}
