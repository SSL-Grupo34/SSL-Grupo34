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

void leerInput(FILE *f, char cadena[]) { // Leo la cadena en el file y la guardo en la variable cadena
    fscanf(f, "%s", cadena);
}

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

int recorrerMatriz(char cadena[], int largoCadena){
	int contadorCadena, fila = 0, columna;
	char caracter;

  	for(contadorCadena=0; contadorCadena < largoCadena; contadorCadena++){
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

void resultadoCadena(char cadena[], int* numerosDecimales, int* numerosOctales, int* numerosHexadecimales){ // Analizo el resultado de recorrerMatriz y determino a que entero pertenece
    int largoCadena = strlen(cadena);
	int estadoFinal = recorrerMatriz (cadena, largoCadena);
	
    printf("Analisis de constantes:\n");
    switch(estadoFinal){
		case 1:
    		printf("\n %s OCTAL\n", cadena);
            (*numerosOctales)++;
    		break;
    	case 2:
    		printf("\n %s DECIMAL\n", cadena);
            (*numerosDecimales)++;
			break;
    	case 3:
    		printf("\n %s ERROR LEXICO\n", cadena);
    		break;
    	case 4:
    		printf("\n %s HEXADECIMAL\n", cadena);
            (*numerosHexadecimales)++;
    		break;
    	case 5:
    		printf("\n %s OCTAL\n", cadena);
            (*numerosOctales)++;
    		break;
    	case 6:
    		printf("\n %s ERROR LEXICO\n", cadena);
    		break;
    	default:
    		printf("\n %s ERROR LEXICO\n", cadena);
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
    //char centinela = '&'; // Determino el caracter de corte
    int numerosDecimales = 0, numerosOctales = 0, numerosHexadecimales = 0; // Declaracion de los contadores de Constantes Enteras

    leerInput(f, cadena);
    fclose(f);

    // TODO: implementar la lectura de todas las cadenas
    resultadoCadena(cadena, &numerosDecimales, &numerosOctales, &numerosHexadecimales);



    printf("\n Enteros decimales: %d\n Enteros octales: %d\n Enteros decimales: %d\n", numerosDecimales, numerosOctales, numerosHexadecimales);


    // Prueba de punto 2
    char caracter = '1';
    int valorNumerico;
    valorNumerico = conversionCaracterInt(caracter);
    printf("caracter = %c , valor numerico = %d", caracter, valorNumerico);

    return 0;
}