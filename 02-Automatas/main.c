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

typedef struct contador
{
    int decimales,octales,hexadecimales;
}contador;

int leerInput(FILE *f, char cadena[]) { // Leo la cadena en el file y la guardo en la variable cadena
    int i = 0;
    while(feof(f) == 0){
        cadena[i] = fgetc(f);
        i++;
    }
    return i;
}

const int matriz[6][5] = {
//  0   [1-7]   [8-9]   [a-f]   [xX]    [error]  
    {1,     2,      2,      6,      6,      6}, // q0 estado inicial
    {5,     5,      6,      6,      3,      6}, // q1 final OCTAL en 0
    {2,     2,      2,      6,      6,      6}, // q2 final DECIMAL
    {4,     4,      4,      4,      6,      6}, // q3
    {4,     4,      4,      4,      6,      6}, // q4 final HEX
    {5,     5,      6,      6,      6,      6}, // q5 final OCTAL
    {6,     6,      6,      6,      6,      6}  // q6 ERROR
};

int columnaQuePertenece(char caracter){ // Analizo a que columna pertenece el caracter
	if(caracter =='0'){ 
        	return 0;
        }
        else if(caracter =='1' || caracter == '2' ||caracter == '3' ||caracter == '4' ||caracter == '5' ||caracter == '6' ||caracter == '7'){
        	return 1;
        }
        else if(caracter=='8' || caracter == '9'){
           	return 2;
       	}
        else if(caracter== 'a' ||caracter == 'A' ||caracter == 'b' ||caracter == 'B' ||caracter =='c' ||caracter == 'C'||caracter == 'd' ||caracter == 'D' ||caracter == 'e' ||caracter == 'E' ||caracter == 'f' ||caracter == 'F'){
        	return 3;
        }
        else if(caracter =='x' || caracter == 'X'){
        	return 4;
        }

	return 5; // Si no pertenece a ninguno, retorno la columna [Error]
}

int recorrerMatriz(char cadena[]){

	int contadorCadena, fila = 0, columna;
	char caracter;

  	for(contadorCadena=0; contadorCadena<strlen(cadena); contadorCadena++){
    	caracter = cadena[contadorCadena];
		columna = columnaQuePertenece(caracter);	
			
    	if(matriz[fila][columna] == 6) // Consulta por estado de error
		{
			return 6;
		}
		else // Si no se encuentra en el estado de error continua evaluando
		{
			fila=matriz[fila][columna]; 
    	}	

  	}

  	return fila; // Una vez recorrida toda la matriz devuelvo la fila final donde se encuentra correspondiente al estado final
}

void resultadoCadena(char cadena[], contador numeros){ // Analizo el resultado de recorrerMatriz y determino a que entero pertenece
	int estadoFinal = recorrerMatriz (cadena);
	switch(estadoFinal){
		case 1:
    		printf("\n %s OCTAL", cadena);
            numeros.octales++;
    		break;
    	case 2:
    		printf("\n %s DECIMAL", cadena);
            numeros.decimales++;
			break;
    	case 3:
    		printf("\n %s ERROR LEXICO ", cadena);
    		break;
    	case 4:
    		printf("\n %s HEXADECIMAL", cadena);
            numeros.hexadecimales++;
    		break;
    	case 5:
    		printf("\n %s OCTAL", cadena);
            numeros.octales++;
    		break;
    	case 6:
    		printf("\n %s ERROR LEXICO", cadena);
    		break;
    	default:
    		printf("\n %s ERROR LEXICO", cadena);
    	break;
	}
}


int main(){

    FILE *f = fopen("input.txt", "r");

    if(f == NULL){
        printf("Error al abrir el archivo de input.txt");
        return 1;
    } else {
        printf("Archivo de input.txt leido exitosamente\n");

    }

    char cadena[50]; // Se elige 50 arbitrariamente como tamanio maximo de la cadena de entrada
    char* centinela="&"; // Determino el caracter de corte
    contador numeros; // Se setea en 0 los contadores de las constantes
    numeros.decimales = 0;
    numeros.octales = 0;
    numeros.hexadecimales = 0;
 
    int cantidadCaracteres = leerInput(f, cadena);
    fclose(f);

    for(int i=0 ; i < cantidadCaracteres; i++){ // Para verificar correcta lectura de caracteres
        printf("%c \n", cadena[i]);
    }

    // TODO: implementar la lectura de todas las cadenas

    // Prueba de punto 2
    char caracter = '1';
    int valorNumerico;
    valorNumerico = conversionCaracterInt(caracter);
    printf("caracter = %c , valor numerico = %d", caracter, valorNumerico);

    return 0;
}