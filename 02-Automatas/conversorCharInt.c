/* PUNTO 2 */ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int conversionCaracterInt(char caracter) {
    char aux[2];  // Creo manualmente la cadena
    aux[0] = caracter;   
    aux[1] = '\0'; 
    
    int num = atoi(aux); // COnvierto la cadena a un número entero
    return num;
}