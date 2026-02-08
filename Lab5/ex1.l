%{
	#include<stdio.h>
	int vowels = 0;
	int consos = 0;
%}
%%
a|e|i|o|u|A|E|I|O|U {vowels++;}
[a-zA-Z] {consos++;}
[\t\n]+ ;
. ;
%%
int main(){
	printf("Enter a string (Ctrl+D to stop): ");
	yylex();
	printf("Vowels: %d | Consonants = %d\n", vowels, consos);
	return 0;
}
int yywrap(){
	return 1;
}
