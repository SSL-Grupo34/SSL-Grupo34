#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* PUNTO 1 */ 

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