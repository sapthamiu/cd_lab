//Write a ‘C’ program to reverse the file contents and store in another file. 
//Also display the size of file using file handling function.
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fptr1, *fptr2;
    char filename[100];
    long size;
    char c;
    printf("Enter the filename to open for reading: ");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    printf("Enter the filename to open for writing reversed contents: ");
    scanf("%s", filename);
    fptr2 = fopen(filename, "w+");
    fseek(fptr1, 0, SEEK_END);
    size = ftell(fptr1);
    printf("\nFile size: %ld bytes\n", size);
    fseek(fptr1, -1, SEEK_END);
    while (1) {
        c = fgetc(fptr1);
        fputc(c, fptr2);
        if (ftell(fptr1) == 1)
            break;
        fseek(fptr1, -2, SEEK_CUR);
    }
    printf("\nContents copied to %s\n", filename);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
