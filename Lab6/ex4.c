/*
S $\rarr$ (L)|a  
L $\rarr$ SL'  
L' $\rarr$ ,SL'|$\epsilon$
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
void L();
void Lprime();

void S(){
	if(str[cur] == '('){
        cur++;
        L();
        if(str[cur] == ')'){
            cur++;
            return;
        }
        else invalid();
    }
    else if(str[cur] == 'a'){
        cur++;
        return;
    }
    else invalid();
}

void L(){
    S();
    Lprime();
	
}

void Lprime(){
	if(str[cur] == ','){
        cur++;
        S();
        Lprime();
    }
}


int main(){
	printf("Enter String: ");
	scanf("%s", str);
	S();
	if(str[cur] == '$') valid();
	else invalid();
}