%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

%}

%token FDT INICIO FIN LEER ESCRIBIR ID ASIGNACION PUNTOYCOMA PARENIZQUIERDO PARENDERECHO COMA CONSTANTE SUMA RESTA

%%

<objetivo> : <programa> FDT

<programa> : INICIO <listaSentencias> FIN

<listaSentencias> : <sentencia> {<sentencia>}

<sentencia> : ID ASIGNACION <expresión> PUNTOYCOMA  |   
            LEER PARENIZQUIERDO <listaIdentificadores> PARENDERECHO PUNTOYCOMA  |   
            ESCRIBIR PARENIZQUIERDO <listaExpresiones> PARENDERECHO PUNTOYCOMA

<listaIdentificadores> : ID {COMA ID}       

<listaExpresiones> : <expresión> {COMA <expresión>}

<expresión> : <primaria> {<operadorAditivo> <primaria>}

<primaria> : ID |
            CONSTANTE |
            PARENIZQUIERDO <expresión> PARENDERECHO

<operadorAditivo> : SUMA | RESTA

%%

int main(void) {
    yyparse();
    return 0;
}