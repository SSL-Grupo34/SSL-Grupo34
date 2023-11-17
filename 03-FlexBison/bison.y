%{

/* fichero instrucciones.y */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylineno;
extern int yyleng;
extern FILE* yyin;
int yylex(void);

void procesarOperacionSuma(int valor1 ,int valor2);
void procesarOperacionResta(int valor1 ,int valor2);
void procesarID();
int yyerror(const char *msg);
%}

%union {
   char cadena[40];
   int entero;
   struct info{
       char cadena[40];
       int linea;
   }INFO;
}

%token INICIO FIN LEER ESCRIBIR ID ASIGNACION PUNTOYCOMA PARENIZQUIERDO PARENDERECHO COMA 
%token <entero> CONSTANTE
%token <cadena> SUMA RESTA

%%

programa : INICIO listaSentencias FIN
;

listaSentencias : sentencia 
                | listaSentencias sentencia
;

sentencia : identificador ASIGNACION expresion PUNTOYCOMA 
            | LEER PARENIZQUIERDO listaIdentificadores PARENDERECHO PUNTOYCOMA
            | ESCRIBIR PARENIZQUIERDO listaExpresiones PARENDERECHO PUNTOYCOMA
;

listaIdentificadores : identificador 
                    | listaIdentificadores COMA identificador
;        

listaExpresiones : expresion 
                    | listaExpresiones COMA expresion
;

expresion : primaria 
            | expresion SUMA primaria {procesarOperacionSuma($<entero>1 ,$<entero>3);}
            | expresion RESTA primaria {procesarOperacionResta($<entero>1 ,$<entero>3);}
;

primaria : identificador
        | CONSTANTE 
        | PARENIZQUIERDO expresion PARENDERECHO
;

identificador : ID {procesarID();}
;

%%

int main (int argc, char *argv[])
{
        yyin=fopen(argv[1],"r");
        yyparse();
        fclose(yyin);

        
        printf("\nAnalisis finalizado correctamente\n");
        

        return 0;
}

void procesarID()
{
    if(strlen(yylval.INFO.cadena) > 32)
    {   
        yyerror("Error Semantico, idenficador mayor a 32 caracteres");
    }
}

void procesarOperacionSuma(int valor1 ,int valor2)
{
    int resultado = valor1 + valor2;
    printf("\nResultado de asignacion: %d\n", resultado);
    
}
void procesarOperacionResta(int valor1 ,int valor2)
{
    int resultado = valor1 - valor2;
    printf("\nResultado de asignacion: %d\n", resultado);
    
}

int yyerror(const char *msg)
{
        printf("\nFallo en el analisis \n\t Linea: %d \n\t Error:%s\n", yylineno, msg);
        exit(1);
        return 0;
}