%{
#include<stdio.h>
	int chars = 0;
	int words = 0;
	int blanks = 0;
	int lines = 0;
%}

%%
[a-zA-Z]+ {words++; chars += yyleng;}
\n {chars++; lines++;}
[ \t] {chars++; blanks++;}
. {chars++;}
%%

int main(int argc, char** argv){
	printf("Enter a string: ");
	yylex();
	printf("\nCharacters: %d | Words: %d | Blanks: %d | Lines: %d\n", chars, words, blanks, lines);
	return 0;
}
int yywrap(){
	return 1;
}