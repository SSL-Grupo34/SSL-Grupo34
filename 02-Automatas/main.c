#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Punto 2
int conversionCaracterInt(char caracter){
    char buffer[0];
    char* caracterConvertir = buffer;
    *caracterConvertir = caracter;
    return atoi(caracterConvertir);
}

// Punto 1

const int matriz[7][6] = {
//  0   [1-7]   [8-9]   [a-f]   [xX]    [error]  
    {1,     2,      2,      6,      6,      6}, // q0 estado inicial
    {5,     5,      6,      6,      3,      6}, // q1 final OCTAL en 0
    {2,     2,      2,      6,      6,      6}, // q2 final DECIMAL
    {4,     4,      4,      4,      6,      6}, // q3
    {4,     4,      4,      4,      6,      6}, // q4 final HEX
    {5,     5,      6,      6,      6,      6}, // q5 final OCTAL
    {6,     6,      6,      6,      6,      6}  // q6 ERROR
};

//void contadorConstantesEnteras(FILE* f, int decimal, int octal, int hexadecimal){

//}

int main(){
    printf("Hello World \n");

    FILE *f = fopen("input.txt", "r");

    // Prueba de punto 2
    char caracter = '1';
    int valorNumerico;
    valorNumerico = conversionCaracterInt(caracter);
    printf("caracter = %c , valor numerico = %d", caracter, valorNumerico);

    return 0;
}