%{

#include <stdio.h>
#include “y.tab.h” /* GENERADO AUTOMÁTICAMENTE POR BISON */

%}

letra           [a-zA-Z]
digito          [0-9]
identificador   {letra}({letra}|{digito})*
constEntera     {digito}({digito})*
separador       [ \t]

%%

FDT

{separador}         {/* omitir */}
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
.                   ECHO;

%%

int yywrap(void) {
    return 1;
}