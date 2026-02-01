//without using intermediate file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
    char type[100];
    int row, col;
}TOKEN;
char* keywords[] = {"int", "float", "char", "void", "if", "else", "while", "for", "return", "main"};
int keycount = 10;
int row, col;
FILE* fp;
int isKeyword(char* str){
    for(int i = 0; i < keycount; i++)
        if(strcmp(str, keywords[i]) == 0) return 1;
    return 0;
}
void skipIgnored(){
    char c;
    while((c = getc(fp)) != EOF){
        col++;
        if(c == ' ' || c == '\t') continue;
        if(c == '\n'){
            row++;
            col = 0; 
            continue;
        }
        //preprocessor
        if(c == '#'){
            while( c != '\n' && c != EOF)
                c = getc(fp);
            row++;
            col = 0;
            continue;
        }
        //comment
        if(c == '/'){
            char next = getc(fp);
            col++;
            if(next == '/'){
                while(c != '\n' && c != EOF)
                    c = getc(fp);
                row++;
                col = 0;
                continue;
            }
            else if(next == '*'){
                while(1){
                    c = getc(fp);
                    if(c == '\n'){
                        row++;
                        col = 0;
                    }
                    if(c == '*'){
                        char end = getc(fp);
                        if(end == '/') break;
                    }
                }
                continue;
            }
            else{
                fseek(fp, -1, SEEK_CUR);
                col--;
            }
        }
        fseek(fp, -1, SEEK_CUR);
        col--;
        break;
    }
}
TOKEN readString(){
    TOKEN token;
    int startrow = row;
    int startcol = col;
    int i = 0;
    char c;
    token.type[i++] = '"';
    while((c = fgetc(fp)) != EOF){
        col++;
        token.type[i++] = c;
        if(c == '"') break;
        if(c == '\n'){
            row++;
            col = 0;
        }
    }
    token.type[i] = '\0';
    token.row = startrow;
    token.col = startcol;
    return token;
}
TOKEN readId(){
    TOKEN token;
    int startrow = row;
    int startcol = col;
    char buf[100];
    int i = 0;
    char c = getc(fp);
    col++;
    buf[i++] = c;
    while(1){
        char next = getc(fp);
        if(isalnum(next) || next == '_'){
            col++;
            buf[i++] = next;
        }
        else{
            // ungetc(next, fp);
            fseek(fp, -1, SEEK_CUR);
            col--;
            break;
        }
    }
    buf[i] = '\0';
    token.row = startrow;
    token.col = startcol;
    if(isKeyword(buf)) strcpy(token.type, buf);
    else strcpy(token.type, "id");
    return token;
}
TOKEN readNum(){
    TOKEN token;
    int startrow = row;
    int startcol = col;
    char buf[100];
    int i = 0;
    int decimal = 0;
    char c = getc(fp);
    col++;
    buf[i++] = c;
    while(1){
        char next = getc(fp);
        if(isdigit(next)){
            col++;
            buf[i++] = next;
        }
        else if(next == '.' && !decimal){
            col++;
            decimal = 1;
            buf[i++] = next;
        }
        else{
            fseek(fp, -1, SEEK_CUR);
            col--;
            break;
        }
    }
    buf[i] = '\0';
    token.row = startrow;
    token.col = startcol;
    strcpy(token.type, buf);
    return token;
}
TOKEN readOp(){
    TOKEN token;
    int startrow = row;
    int startcol = col;
    char buf[10];
    int i = 0;
    char c = getc(fp);
    col++;
    buf[i++] = c;
    char next = getc(fp);
    if((c=='=' && next=='=') || (c=='<' && next=='=') || (c=='>' && next=='=') || (c=='!' && next=='=') || (c=='&' && next=='&') || (c=='|' && next=='|')){
        col++;
        buf[i++] = next;
    }
    else {
        fseek(fp, -1, SEEK_CUR);
        col--;
    }
    buf[i] = '\0';
    token.row = startrow;
    token.col = startcol;
    strcpy(token.type, buf);
    return token;
}
TOKEN readSymbol(){
    TOKEN token;
    char c = getc(fp);
    col++;
    token.row = row;
    token.col = col;
    token.type[0] = c;
    token.type[1] = '\0';
    return token;
}
TOKEN getNextToken(){
    TOKEN token;
    char c;
    skipIgnored();
    c = getc(fp);
    if(c == EOF){
        strcpy(token.type, "EOF");
        return token;
    }
    fseek(fp, -1, SEEK_CUR);
    if(c == '"') return readString();
    if(isalpha(c) || c == '_') return readId();
    if(isdigit(c)) return readNum();
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='<' 
    || c=='>' || c=='=' || c=='!' || c=='&' || c=='|') return readOp();
    if(c==';' || c==',' || c=='(' || c==')' 
    || c=='{' || c=='}' || c=='[' || c==']') return readSymbol();
    getc(fp);
    col++;
    return getNextToken();
}
int main(){
    TOKEN token;
    fp = fopen("samplela.c", "r");
    if(!fp){
        printf("Cannot open file\n");
        return 0;
    }
    row = 1;
    col = 0;
    do{
        token = getNextToken();
        if(strcmp(token.type, "EOF") != 0)
            printf("<%s, %d, %d>\n", token.type, token.row, token.col);
    } while(strcmp(token.type, "EOF") != 0);
    fclose(fp);
}