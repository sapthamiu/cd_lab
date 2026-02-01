//WAP that takes C program as input, recognizes all the keywords and prints them in upper case.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
    int c, k = 0;
    int incomm = 0, instring = 0;
    char word[100];
    char dict[][20] = {
        "break", "case", "char", "const", "continue", 
        "default", "do", "double", "else", "enum", 
        "float", "for", "if", "int", "long", 
        "return", "sizeof", "switch", "void", "while"};

    FILE* fin = fopen("sample.c", "r");
    if(fin == NULL){
        printf("Cannot open file\n");
        exit(1);
    }
    FILE* fout = fopen("ex3out.c", "w");

    while((c=getc(fin)) != EOF){
        //strings
        if(!incomm && c == '"'){
            instring = !instring;
            putc(c, fout);
            continue;
        }
        if(instring){
            putc(c, fout);
            continue;
        }
        //comments
        if(!incomm && c =='/'){
            int next = getc(fin);
            if(next == '*'){
                incomm = 1;
                putc(c, fout);
                putc(next, fout);
                continue;
            }
            else if(next == '/'){
                putc(c, fout);
                putc(next, fout);
                while((c=getc(fin)) != '\n' && c!= EOF)
                    putc(c, fout);
                if(c == '\n') putc('\n', fout);
                continue;
            }
            else{
                putc(c, fout);
                c = next;
            }
        }
        if(incomm){
            putc(c, fout);
            if(c == '*'){
                int next = getc(fin);
                if(next =='/'){
                    incomm = 0;
                    putc(next, fout);
                }
                else{
                    c = next;
                    if(c != EOF) continue;
                }
            }
            continue;
        }
        if(isalpha(c)){
            word[k++] = c;
            while((c=getc(fin)) != EOF && isalpha(c)) word[k++] = c;
            word[k] = '\0';
            int key=0;
            for(int i = 0; i < 20; i++){
                if(strcmp(word, dict[i]) == 0){
                    key = 1;
                    break;
                }
            }
            if(key){
                for(int i = 0; i < strlen(word); i++)
                    putc(toupper(word[i]), fout);
            }
            else {
                for(int i = 0; i < strlen(word); i++)
                    putc(word[i], fout);
            }
            if(c != EOF) putc(c, fout);
            k = 0;
        }
        else putc(c, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}