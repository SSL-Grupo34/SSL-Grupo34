%{

/* fichero instrucciones.y */
#include <stdio.h>

int yylex(void);

%}

%token FDT INICIO FIN LEER ESCRIBIR ID ASIGNACION PUNTOYCOMA PARENIZQUIERDO PARENDERECHO COMA CONSTANTE SUMA RESTA

%%

objetivo : programa FDT
;

programa : INICIO listaSentencias FIN
;

listaSentencias : sentencia 
                | sentencia sentencia
;

sentencia : ID ASIGNACION expresion PUNTOYCOMA  
            | LEER PARENIZQUIERDO listaIdentificadores PARENDERECHO PUNTOYCOMA
            | ESCRIBIR PARENIZQUIERDO listaExpresiones PARENDERECHO PUNTOYCOMA
;

listaIdentificadores : ID 
                    | ID COMA ID
;        

listaExpresiones : expresion 
                    | expresion COMA expresion
;

expresion : primaria 
            | primaria operadorAditivo primaria
;

primaria : ID 
        | CONSTANTE 
        | PARENIZQUIERDO expresion PARENDERECHO
;

operadorAditivo : SUMA 
                | RESTA
;

%%

yyerror (s) /* Llamada por yyparse ante un error */
char *s;
{
printf ("%s\n", s); /* Esta implementación por defecto nos valdrá */
/* Si no creamos esta función, habrá que enlazar con –ly en el
momento de compilar para usar una implementación por defecto */
}

main()
{
// Acciones a ejecutar antes del análisis
yyparse();
//Acciones a ejecutar después del análisis
}


