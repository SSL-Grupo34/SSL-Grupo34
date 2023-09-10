#include "automataEnteros.c"

int matrizEnteros [8][7] = {
//   +-     0   [1-7]   [8,9]   [a-f]    [xX]  [ERROR]
    {1,     7,      7,      7,      7,      7,      7}, // q0 Estado inicial con signo
    {7,     2,      3,      3,      7,      7,      7}, // q1 Estado inicial sin signo
    {7,     6,      6,      7,      7,      4,      7}, // q2 Estado final de DECIMAL con 0
    {7,     3,      3,      3,      7,      7,      7}, // q3 Estado final de DECIMAL
    {7,     5,      5,      5,      5,      7,      7}, // q4
    {7,     5,      5,      5,      5,      7,      7}, // q5 Estado final de HEXADECIMAL
    {7,     6,      6,      7,      7,      7,      7}, // q6 Estado final de OCTAL                                                                 
    {7,     7,      7,      7,      7,      7,      7}  // q7 Estado de ERROR
};

// Analiza a que columna de la matriz pertenece un caracter dado
int columnaQuePertenece(char caracter);

// Algoritmo que recorre la matriz consumiendo caracteres de una cadena dada
int recorrerMatriz(char cadena[], int matriz[8][7]);

// Analizador de resultado de recorrer la matriz, incrementa los contadores de enteros segun los resultados
void contadorConstantes(char cadena[], int matriz[8][7], int* decimales, int* octales, int* hexadecimales);