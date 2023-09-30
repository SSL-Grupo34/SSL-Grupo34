#include "automataCalculadora.h"


int main(){

    /* AUTOMATA 1 */ 

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
    printf("\nResultados:\nEnteros Decimales = %d\nEnteros Octales = %d\nEnteros Hexadecimales = %d\n\n", decimales, octales, hexadecimales);

    /* AUTOMATA 2 */ 

    char stringHardcodeado[7] = "123456";
    for(int i=0; i < strlen(stringHardcodeado); i++){
        int numero = conversionCaracterInt(stringHardcodeado[i]);
        printf("Caracter convertido a numero: %d\n", numero);
    }

    /* AUTOMATA 3 */

    // INFIJO a POSTFIJO

	char infijo[TamanioMaximoOperacion]; // = "2*2/2+1";
	printf("\nIntroduzca una operacion aritmetica, sin parentesis:\n");
	scanf("%s", &infijo);

	char* postfijo = infijoConversionPostfijo(infijo);
	printf("%s\n", postfijo); // funciona bien
	
	// CALCULADORA

	int resultadoPostfijo = evaluarPostfijo(postfijo);  
	free(postfijo);
	printf("Resultado = %d\n", resultadoPostfijo); 

    return EXIT_SUCCESS;
}