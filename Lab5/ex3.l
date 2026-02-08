%{
#include<stdio.h>
	int posi = 0;
	int negi = 0;
	int posf = 0;
	int negf = 0;
%}

%%
[+]?([0-9]+)\.[0-9]+ {posf++;}
[-][0-9]+\.[0-9]+ {negf++;}
[+]?[0-9]+ {posi++;}
[-][0-9]+ {negi++;}
. ;
[ \t\n]+ ;
%%

int main(int argc, char** argv){
	printf("Enter some numbers: ");
	yylex();
	printf("\n+ve Ints: %d | -ve Ints: %d | +ve Floats: %d | -ve Floats: %d\n", posi, negi, posf, negf);
	return 0;
}
int yywrap(){
	return 1;
}