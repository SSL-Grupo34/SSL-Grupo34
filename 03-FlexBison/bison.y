%{

/* fichero instrucciones.y */
#include <stdio.h>

extern int yyleng;
extern FILE* yyin;
int analisisCorrecto = 1;
int yylex(void);

void procesarOperacion(int valor1, int valor2);
void procesarID();
%}

%union {
   char cadena[40];
   int entero;
   struct info{
       char cadena[40];
       int linea;
   }INFO;
}

%token INICIO FIN LEER ESCRIBIR ID ASIGNACION PUNTOYCOMA PARENIZQUIERDO PARENDERECHO COMA SUMA RESTA
%token <entero> CONSTANTE

%%

programa : INICIO listaSentencias FIN
;

listaSentencias : sentencia 
                | sentencia sentencia
;

sentencia : identificador ASIGNACION expresion PUNTOYCOMA  
            | LEER PARENIZQUIERDO listaIdentificadores PARENDERECHO PUNTOYCOMA
            | ESCRIBIR PARENIZQUIERDO listaExpresiones PARENDERECHO PUNTOYCOMA
;

listaIdentificadores : identificador 
                    | identificador COMA identificador
;        

listaExpresiones : expresion 
                    | expresion COMA expresion
;

expresion : primaria 
            | primaria operadorAditivo primaria {procesarOperacion($<entero>1, $<entero>3);}
;

primaria : identificador 
        | CONSTANTE 
        | PARENIZQUIERDO expresion PARENDERECHO
;

operadorAditivo : SUMA 
                | RESTA
;

identificador : ID {procesarID();}
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

void procesarID()
{
    if(yyleng > 32)
    {
        yyerror("Error Semantico, idenficador mayor a 32 caracteres");
    }
}

void procesarOperacion(int valor1, int valor2)
{
    int resultado = valor1 + valor2;
    printf("\nResultado de asignacion: %d\n", resultado);
}

int yyerror(const char *msg)
{
        printf("\nFallo en el analisis \n\t Linea: %d \n\t Error:%s\n",yylval.INFO.linea,msg);
        analisisCorrecto=0;
        return 0;
}