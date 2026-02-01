//WAP that takes a file as input and replaces blank spaces and tabs by single space and writes the output to a file.
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fin, *fout;
    int c, instring = 0;
    fin = fopen("sample.c", "r");
    if(fin == NULL){
        printf("Cannot open file\n");
        exit(1);
    }
    fout = fopen("ex1out.c", "w");
    while((c = getc(fin)) != EOF){
        if(c == '"'){
            instring = !instring; 
            putc(c, fout);
            continue;
        }
        if(instring){
            putc(c, fout);
            continue;
        }
        if(c == ' ' || c == '\t'){
            putc(' ', fout);
            while((c = getc(fin)) == ' ' || c == '\t');
            if(c != EOF){
                if(c == '"'){
                    instring = !instring;
                    putc(c, fout);
                } else {
                    putc(c, fout);
                }
            }
        }
        else{
            putc(c, fout);
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}