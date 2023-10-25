%{
#include <stdlib.h>
#ifndef yywrap
static int yywrap(void) { return 1;}
#endif
%}
FINSENTENCIA ;
PALABRARESERVADA inicio|fin|leer|escribir
DATO [1-9][0-9]*
IDENTIFICADOR [a-zA-Z][a-zA-Z0-9]*
%%
{FINSENTENCIA}      printf("Esto es un fin de sentencia\n");
{PALABRARESERVADA}  printf("Esto es una palabra reservada\n");
{DATO}              printf("Esto es un dato entero\n");
{IDENTIFICADOR}     printf("Esto es un identificador\n");
.                   printf("Error lexico\n");
%%
int main(){
yylex();
}