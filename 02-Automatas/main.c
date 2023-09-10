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


int columnaQuePertenece(char caracter){ 
	if (caracter == '-' || caracter == '+'){
        return 0;
    }
    else if (caracter =='0'){ 
    	return 1;
    }
    else if(caracter == '1' || caracter == '2' ||caracter == '3' ||caracter == '4' ||caracter == '5' ||caracter == '6' ||caracter == '7'){
    	return 2;
    }
    else if(caracter== '8' || caracter == '9'){
       	return 3;
    }
    else if(caracter== 'a' ||caracter == 'A' ||caracter == 'b' ||caracter == 'B' ||caracter =='c' ||caracter == 'C'||caracter == 'd' ||caracter == 'D' ||caracter == 'e' ||caracter == 'E' ||caracter == 'f' ||caracter == 'F'){
    	return 4;
    }
    else if(caracter =='x' || caracter == 'X'){
    	return 5;
    }
	return 6;
}


int recorrerMatriz(char cadena[], int matriz[8][7]){
	int cont_cadena, fila, columna, largoCadena;
	char caracter;

    if(cadena[0] == '-' || cadena[0] == '+'){ // Asigno la primera fila por donde voy a empezar a analizar
        fila = 0;
    } else {
        fila = 1;
    }

    largoCadena = strlen(cadena);   //Obtengo el largo de la cadena a evaluar

  	for(cont_cadena=0; cont_cadena < largoCadena; cont_cadena++){
    	caracter = cadena[cont_cadena]; 
		columna = columnaQuePertenece(caracter); // Analizo a que columna pertenece el caracter de la cadena
			
    	if(matriz[fila][columna] == 7) // Si la columna es la 7 devuelvo directamente el estado ERROR
		{
			return 7;
		}
		else
		{
			fila=matriz[fila][columna];
    	}	
  	}
  	return fila;	
}


void contadorConstantes(char cadena[], int matriz[8][7], int* decimales, int* octales, int* hexadecimales){

	int estadoFinal= recorrerMatriz (cadena, matriz);

	switch(estadoFinal){
		case 2:
    		printf("%s DECIMAL\n", cadena);
            (*decimales)++;
    		break;
    	case 3:
    		printf("%s DECIMAL\n", cadena);
            (*decimales)++;
			break;
    	case 4:
    		printf("%s ERORR LEXICO\n", cadena);
    		break;
    	case 5:
    		printf("%s HEXADECIMAL\n", cadena);
            (*hexadecimales)++;
    		break;
    	case 6:
    		printf("%s OCTAL\n", cadena);
            (*octales)++;
    		break;
    	case 7:
    		printf("%s ERORR LEXICO\n", cadena);
    		break;
    	default:
    		printf("%s ERROR\n", cadena);
    	break;
	}
}


int main(){
    char input[20] = "input.txt"; // Archivo de lectura de entrada
    char cadena[100];       // Numero maximo de caracteres que puede leer = 100
    char* centinela= "$";   // Caracter centinela que divide cadenas
    int decimales = 0, octales = 0, hexadecimales = 0;

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
			contadorConstantes(token, matrizEnteros, &decimales, &octales, &hexadecimales); // Analizo la primera cadena y repito hasta que no queden cadenas por evaluar
			token = strtok(NULL, centinela);
		}
	}
    printf("\nResultados:\nEnteros Decimales = %d\nEnteros Octales = %d\nEnteros Hexadecimales = %d\n", decimales, octales, hexadecimales);

	return 0;
}