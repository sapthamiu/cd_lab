/*
S $\rarr$ a|>|(T)  
T $\rarr$ ST'
T' $\rarr$ ,ST'|$\epsilon$
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char str[100];
int cur = 0;

void invalid(){
	printf("---ERROR---\n");
	exit(0);
}
void valid(){
	printf("---SUCCESS---\n");
	exit(0);
}
void S();
void T();
void Tprime();
void S(){
	if(str[cur] == 'a'){
		cur++;
		return;
	}
	else if(str[cur] == '>'){
		cur++;
		return;
	}
	else if(str[cur] == '('){
		cur++;
		T();
		if(str[cur] == ')'){
			cur++;
			return;
		}
		else invalid();
	}
	else invalid();
}

void T(){
	S();
	Tprime();
}

void Tprime(){
	if(str[cur] == ','){
		cur++;
		S();
		Tprime();
	}
}

int main(){
	printf("Enter String: ");
	scanf("%s", str);
	S();
	if(str[cur] == '$') valid();
	else invalid();
}