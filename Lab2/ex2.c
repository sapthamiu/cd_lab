//WAP to discard preprocessor directives from the given input C file.
#include<stdio.h>
#include<stdlib.h>
int main(){
    int c, next, incomm = 0, instart = 1;
    FILE* fin = fopen("sample.c", "r");
    if(fin == NULL){
        printf("Cannot open file\n");
        exit(1);
    }
    FILE* fout = fopen("ex2out.c", "w");
    c = getc(fin);
    while(c != EOF){
        next = getc(fin);
        //comments
        if(!incomm && c == '/' && next == '*'){
            //only handle block comms coz single line comms are not newline anyways
            incomm = 1;
            putc(c, fout);
            putc(next, fout);
            c = getc(fin);
            continue;
        }
        if(incomm){
            putc(c, fout);
            if(c == '*' && next == '/'){
                incomm = 0;
                putc(next, fout);
                c = getc(fin);
                continue;
            }
            c = next;
            continue;
        }
        //string
        if(c == '"'){
            putc(c, fout);
            c = next;
            while(c != '"' && c != EOF){
                putc(c, fout);
                c = getc(fin);
            }
            if(c == '"') putc(c, fout);
            instart = 0;
            c = getc(fin);
            continue;
        }
        if(instart && c == '#'){
            while(c != '\n' && c != EOF)
                c = getc(fin);
            instart = 1; //new line after skipping directives
            continue;
        }
        putc(c, fout);
        if(c == '\n')
            instart = 1;
        else if(c != ' ' && c != '\t') instart = 0; //treat leading spaces as newline itself
        c = next;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}