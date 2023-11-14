%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE* yyin;
extern int yylineno;
int yylex(void);
int yyerror(const char *s);

%}

%token FDT INICIO FIN LEER ESCRIBIR ID ASIGNACION PUNTOYCOMA PARENIZQUIERDO PARENDERECHO COMA CONSTANTE SUMA RESTA

%%

objetivo : programa FDT

programa : INICIO listaSentencias FIN

listaSentencias : sentencia | sentencia sentencia

sentencia : ID ASIGNACION expresion PUNTOYCOMA  |   
            LEER PARENIZQUIERDO listaIdentificadores PARENDERECHO PUNTOYCOMA  |   
            ESCRIBIR PARENIZQUIERDO listaExpresiones PARENDERECHO PUNTOYCOMA

listaIdentificadores : ID | ID COMA ID        

listaExpresiones : expresion | expresion COMA expresion

expresion : primaria | primaria operadorAditivo primaria

primaria : ID | CONSTANTE | PARENIZQUIERDO expresion PARENDERECHO

operadorAditivo : SUMA | RESTA

%%

int main (int argc, char *argv[])
{
        yyin=fopen(argv[1],"r"); // el primer argumento debe ser el codigo en micro a analizar
        yyparse();
        fclose(yyin);

        return 0;
}


int yyerror(const char *msg){
        printf("\nFallo el analisis en la linea: %d %s\n",yylineno,msg);
        return 0;
}