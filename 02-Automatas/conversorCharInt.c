/* PUNTO 2 */ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int conversionCaracterInt(char caracter) {
    char aux[2];  
    aux[0] = caracter;   
    aux[1] = '\0'; 
    
    int num = atoi(aux); // Convertir la cadena a un número entero
    return num;
}