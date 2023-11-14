%{

/* fichero instrucciones.y */
#include <stdio.h>

extern int yyleng;
extern FILE* yyin;
int analisisCorrecto = 1;
int yylex(void);

%}

%union {
   char cadena[30];
   int entero;
   struct info{
       char cadena[40];
       int linea;
   }INFO;
}

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
        printf("\nAnalisis finalizado\n");
        }

        return 0;
}

int yyerror(const char *msg){
        printf("\nFallo el analisis en la linea: %d %s\n",yylval.INFO.linea,msg);
        analisisCorrecto=0;
        return 0;
}