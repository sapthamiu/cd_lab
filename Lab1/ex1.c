//Write a ‘C’ program to count the number of lines and characters in a file.
#include <stdio.h>
#include <stdlib.h>
int main(){
FILE *fptr;
char filename[100], c;
int lines = 0, chars = 0;
printf("Enter the filename to open for reading: ");
scanf("%s", filename);
fptr = fopen(filename, "r");
if(fptr == NULL){
printf("Cannot open file %s\n", filename);
exit(0);
}
c = fgetc(fptr);
if(c == '\n') lines++;
if(c != EOF) chars++;
while(c != EOF){
c = fgetc(fptr);
if(c == '\n') lines++;
if(c != EOF) chars++;
}
printf("\nContents read from %s\nTotal characters: %d\nTotal lines: %d\n", filename, chars, 
lines);
fclose(fptr);
return 0;
}