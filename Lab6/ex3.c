/*
S $\rarr$ aAcBe 
A $\rarr$ bA'
A' $\rarr$ bA'|$\epsilon$
B $\rarr$ d
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
void A();
void Aprime();
void B();

void S(){
	if(str[cur] == 'a'){
		cur++;
		A();
		if(str[cur] == 'c'){
			cur++;
			B();
			if(str[cur] == 'e'){
				cur++;
				return;
			}
			else invalid();
		}
		else invalid();
	}
	else invalid();
}

void A(){
	if(str[cur] == 'b'){
		cur++;
		Aprime();
	}
	else invalid();
}

void Aprime(){
	if(str[cur] == 'b'){
		cur++;
		Aprime();
	}
}

void B(){
	if(str[cur] == 'd')
		cur++;
	else invalid();
}


int main(){
	printf("Enter String: ");
	scanf("%s", str);
	S();
	if(str[cur] == '$') valid();
	else invalid();
}