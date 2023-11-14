%{
#include <stdio.h>
#include "y.tab.h"
%}

espacio         (" ")+
tabulacion      (\t)+
letra           [a-zA-Z]
digito          [0-9]
identificador   {letra}({letra}|{digito})*
constEntera     {digito}({digito})*

%%

espacio             {;}
tabulacion          {;}            
"FDT"               {return FDT;}
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
.                   ECHO;

%%

int yywrap(void) {
    return 1;
}