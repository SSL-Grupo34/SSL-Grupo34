#include "automataCalculadora.c"

int esUnOperador(char caracter);

int precedencia(char operador);

char* infijoConversionPostfijo(char* infijo);

void push(int item);

int pop();

int evaluarPostfijo(char* cadena);