%{
#include <stdlib.h>
#ifndef yywrap
static int yywrap(void) { return 1;}
#endif
%}
FINSENTENCIA ;{1}
PALABRARESERVADA inicio|fin|leer|escribir
CONSTANTE [1-9][0-9]*
IDENTIFICADOR [a-zA-Z][a-zA-Z0-9]*
OPERADOR \+|-
ASIGNACION :=
%%
{FINSENTENCIA}      printf("Esto es un fin de sentencia\n");
{PALABRARESERVADA}  printf("Esto es una palabra reservada\n");
{CONSTANTE}         printf("Esto es un dato entero\n");
{IDENTIFICADOR}     printf("Esto es un identificador\n");
{OPERADOR}          printf("Esto es un operador aditivo\n");
{ASIGNACION}        printf("Esto es una asignacion\n");
.                   printf("Error lexico\n");
%%
int main(){
yylex();
}