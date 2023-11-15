%option yylineno

%{

#include <stdio.h>
#include "y.tab.h"

int yyerror(const char *msg);
%}
letra           [a-zA-Z]
digito          [0-9]
identificador   {letra}({letra}|{digito})*
constEntera     {digito}({digito})*
%%

"inicio"            {return INICIO;}
"fin"               {return FIN;}
"leer"              {return LEER;}
"escribir"          {return ESCRIBIR;}
{constEntera}       {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno; yylval.entero=atoi(yytext); return CONSTANTE;}
{identificador}     {strcpy(yylval.INFO.cadena,yytext);yylval.INFO.linea = yylineno; strcpy(yylval.cadena,yytext); return ID;}
";"                 {return PUNTOYCOMA;}
","                 {return COMA;}    
":="                {return ASIGNACION;}
"+"                 {return SUMA;}
"-"                 {return RESTA;}
"("                 {return PARENIZQUIERDO;}
")"                 {return PARENDERECHO;}

[\s\t\n]            {;}  
.                   ECHO;

%%

int yywrap(void) {
    return 1;
}