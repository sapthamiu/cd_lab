//Write a ‘C’ program that merges lines alternatively from 2 files and stores it in a resultant file.
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fptr1, *fptr2, *fptr3;
    char filename[100], line1[256], line2[256];
    char *r1, *r2;
    printf("Enter the first filename to open for reading: ");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    printf("Enter the second filename to open for reading: ");
    scanf("%s", filename);
    fptr2 = fopen(filename, "r");
    if (fptr2 == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    printf("Enter the filename to open for writing: ");
    scanf("%s", filename);
    fptr3 = fopen(filename, "w+");
    while (1) {
        r1 = fgets(line1, sizeof(line1), fptr1);
        r2 = fgets(line2, sizeof(line2), fptr2);
        if (r1 == NULL && r2 == NULL)
            break;
        if (r1 != NULL)
            fputs(line1, fptr3);
        if (r2 != NULL)
            fputs(line2, fptr3);
    }
    printf("Files merged into %s\n", filename);
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    return 0;
}