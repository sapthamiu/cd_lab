%{
#include<stdio.h>
#include<ctype.h>
FILE *fout, *fin;
extern FILE *yyin;
%}

%%
\/\/.* {fputs(yytext, fout);}
\/\*([^*]|\*[^/])*\*\/ {fputs(yytext, fout);}
[A-Z] {putc(tolower(yytext[0]), fout);}
\n {fputs("\n", fout);}
[ \t]+ {fputs(yytext, fout);}
. {fputs(yytext, fout);}
%%

int main(){
	fin = fopen("samplecom.c", "r");
	fout = fopen("samplecomout.c", "w");
	if(!fin || !fout) {
		printf("File error\n");
		return 1;
	}
	yyin = fin;
	yylex();
	fclose(fin);
	fclose(fout);
	return 0;
}
int yywrap(){
	return 1;
}