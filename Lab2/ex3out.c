//This is a        single line comment
/* ***his is a
***Multiline Comment
** */
/*
#include<stdio.h>
*/
//#include<stdio.h>
#include <stdio.h>
VOID main()
{
    FILE *fopen(), *fp;
    INT c ;
    fp = fopen(".         prog.c", "r"); //Comment
    c = getc( fp ) ;
    //if do switch
    WHILE ( c != EOF )
    {
        putchar( c );
        c = getc ( fp );
    } /*multiline
    comment */
    fclose( fp );
}