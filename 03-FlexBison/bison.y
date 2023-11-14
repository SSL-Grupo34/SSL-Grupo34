%{

/* fichero instrucciones.y */
#include <stdio.h>

extern FILE* yyin;
int analisisCorrecto = 1;
int yylex(void);

%}

%token INICIO FIN LEER ESCRIBIR ID ASIGNACION PUNTOYCOMA PARENIZQUIERDO PARENDERECHO COMA CONSTANTE SUMA RESTA

%%

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

int main (int argc, char *argv[])
{
        yyin=fopen(argv[1],"r");
        yyparse();
        fclose(yyin);

        if (analisisCorrecto){
        printf("\nAnalisis finalizado correctamente\n");
        }

        return 0;
}

int yyerror(const char *msg){
        printf("\nFallo el analisis: %s\n",msg);
        analisisCorrecto=0;
        return 0;
}