%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
[0-9]+ {
	int num = atoi(yytext); 
	printf("Hexadecimal representation: %x\n", num);
}
[ \t\n]+ ;
. ; 
%%

int main(){
	printf("Enter a decimal number: ");
	yylex();
	return 0;
}
int yywrap(){
	return 1;
}