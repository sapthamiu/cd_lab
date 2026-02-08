%{
#include<stdio.h>
FILE *fout, *fin;
extern FILE *yyin;
%}

%%
printf {fputs("WRITE", fout);}
scanf {fputs("READ", fout);}
\n {fputs("\n", fout);}
[ \t]+ {fputs(yytext, fout);}
. {fputs(yytext, fout);}
%%

int main(){
	fin = fopen("sample.c", "r");
	fout = fopen("sampleout.c", "w");
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