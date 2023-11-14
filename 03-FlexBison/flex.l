%option yylineno

%{

#include <stdio.h>
#include "y.tab.h"

void imprimirErrorLexico();

%}

separador       ([ \t””])+
espacio         (" ")+
tabulacion      (\t)+
letra           [a-zA-Z]
digito          [0-9]
identificador   {letra}({letra}|{digito})*
constEntera     {digito}({digito})*

%%

separador           {/* omitir */}
espacio             {;}
tabulacion          {;}   
[\n]                {;}   
"inicio"            {return INICIO;}
"fin"               {return FIN;}
"leer"              {return LEER;}
"escribir"          {return ESCRIBIR;}
{constEntera}       {return CONSTANTE;}
{identificador}     {return ID;}
";"                 {return PUNTOYCOMA;}
","                 {return COMA;}    
":="                {return ASIGNACION;}
"+"                 {return SUMA;}
"-"                 {return RESTA;}
"("                 {return PARENIZQUIERDO;}
")"                 {return PARENDERECHO;}
.                   {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno;}

%%

int yywrap(void) {
    return 1;
}