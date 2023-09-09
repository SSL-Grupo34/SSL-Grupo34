#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

/* PUNTO 2 */ 

int conversionCaracterInt(char caracter){
    char buffer[0];
    char* caracterConvertir = buffer;
    *caracterConvertir = caracter;
    return atoi(caracterConvertir);
}

/* PUNTO 1 */

int matriz [7][6] = {
//   0   [1-7]   [8,9]   [a-f]    [xX]  [ERROR]
    {1,      2,      2,      6,      6,      6}, // q0 Estado inicial
    {5,      5,      6,      6,      3,      6}, // q1 Estado final de DECIMAL con 0
    {2,      2,      2,      6,      6,      6}, // q2 Estado final de DECIMAL
    {4,      4,      4,      4,      6,      6}, // q3
    {4,      4,      4,      4,      6,      6}, // q4 Estado final de HEXADECIMAL
    {5,      5,      6,      6,      6,      6}, // q5 Estado final de OCTAL
    {6,      6,      6,      6,      6,      6}  // q6 Estado de ERROR
};


int columnaQuePertenece(char caracter){ 
	if(caracter =='0'){ 
    	return 0;
    }
    else if(caracter == '1' || caracter == '2' ||caracter == '3' ||caracter == '4' ||caracter == '5' ||caracter == '6' ||caracter == '7'){
    	return 1;
    }
    else if(caracter== '8' || caracter == '9'){
       	return 2;
    }
    else if(caracter== 'a' ||caracter == 'A' ||caracter == 'b' ||caracter == 'B' ||caracter =='c' ||caracter == 'C'||caracter == 'd' ||caracter == 'D' ||caracter == 'e' ||caracter == 'E' ||caracter == 'f' ||caracter == 'F'){
    	return 3;
    }
    else if(caracter =='x' || caracter == 'X'){
    	return 4;
    }
	return 5;
}


int recorrerMatriz(char cadena[], int matriz[7][6]){
	int cont_cadena, fila, columna, largoCadena;
	char caracter;
  	fila = 0;
    largoCadena = strlen(cadena);

  	for(cont_cadena=0; cont_cadena < largoCadena; cont_cadena++){
    	caracter = cadena[cont_cadena];
		columna=columnaQuePertenece(caracter);	
			
    	if(matriz[fila][columna] == 6)
		{
			return 6;
		}
		else
		{
			fila=matriz[fila][columna];
    	}	
  	}
  	return fila;	
}


void definirConstante(char cadena[], int matriz[7][6]){

	int estadoFinal= recorrerMatriz (cadena,matriz);

	switch(estadoFinal){
		case 1:
    		printf("%s DECIMAL\n", cadena);
    		break;
    	case 2:
    		printf("%s DECIMAL\n", cadena);
			break;
    	case 3:
    		printf("%s ERORR LEXICO\n", cadena);
    		break;
    	case 4:
    		printf("%s HEXADECIMAL\n", cadena);
    		break;
    	case 5:
    		printf("%s OCTAL\n", cadena);
    		break;
    	case 6:
    		printf("%s ERORR LEXICO\n", cadena);
    		break;
    	default:
    		printf("%s ERROR\n", cadena);
    	break;
	}
}





int main(){
    char input[20] = "input.txt";
    char cadena[100];       // Numero maximo de caracteres que puede leer = 100
    char* centinela= "&";   // Caracter centinela que divide cadenas

    FILE* entrada;
    entrada = fopen(input,"rt");
    if(entrada == NULL){
        printf("Error de lectura del archivo de entrada: %s", input);
        return 1;
    }
    fscanf(entrada,"%s",cadena); // Lectura de la cadena contenida en "input.txt"
    fclose(entrada);
    printf("Cadena leida: %s \n", cadena); // Print de la cadena completa

    char* token = strtok(cadena, centinela); // Guardado de la primera cadena

    printf("\nProcesamiento de enteros:\n\n");
	if(token!=NULL){
		while(token!=NULL){
			definirConstante(token, matriz);
			token = strtok(NULL, centinela);
		}
	}

	return 0;
}