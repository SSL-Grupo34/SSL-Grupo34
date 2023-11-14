%{

#include "y.tab.h"
#include <stdlib.h>
#ifndef yywrap
static int yywrap(void) {return 1;}
#endif

%}

espacio (" ")+
tabulacion (\t)+
letra           [a-zA-Z]
digito          [0-9]
identificador   {letra}({letra}|{digito})*
constEntera     {digito}({digito})*

%%

FDT                 {return FDT;}
inicio              {return INICIO;}
fin                 {return FIN;}
leer                {return LEER;}
escribir            {return ESCRIBIR;}
{constEntera}       {return CONSTANTE;}
";"                 {return PUNTOYCOMA;}
","                 {return COMA;}    
":="                {return ASIGNACION;}
"+"                 {return SUMA;}
"-"                 {return RESTA;}
{identificador}     {return ID;}
"("                 {return PARENIZQUIERDO;}
")"                 {return PARENDERECHO;}
{espacio}           {;}
{tabulacion}        {;}
.                   {;}

%%

int main() {
    yylex();
    printf("Analisis correcto");
}


/*

yyleng -> contiene el largo del token para el analisis de IDs
yylval = atoi( yytext ); -> se usa para obtener el numero entero asociado al token 

int yywrap(void) {
    return 1;
}
*/