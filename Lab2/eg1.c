//WAP to remove single and multiline comments from a given C file
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fin, *fout;
    int c, next;
    fin = fopen("sample.c", "r");
    if(fin == NULL){
        printf("cannot open file\n");
        exit(0);
    }
    fout = fopen("eg1out.c", "w");

    c = getc(fin);
    while(c != EOF){
        if(c == '/'){
            next = getc(fin);
            //single-line 
            if(next == '/'){
                while(c != '\n' && c != EOF)
                    c = getc(fin);
                if(c == '\n')
                    fputc('\n', fout);
            }
            //multi-line
            else if(next == '*'){
                do{
                    while(c != '*')
                        c = getc(fin);
                    c = getc(fin);
                }while(c != '/');
            }
            else{
                putc(c, fout);
                putc(next, fout);
            }
        }
        else putc(c, fout);
        c = getc(fin);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}