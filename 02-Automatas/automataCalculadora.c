#include "conversorCharInt.h"
#include <ctype.h>
#include <math.h>

#define TamanioMaximoOperacion 100

// Implemtacion de notacion Infija a Posftija para resolver problema de precedencia.

int esUnOperador(char caracter) {  // Funcion que determina si un caracter es un operador
    if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') {  
        return 1;  
    }  
    return 0;  
}  

// Funcion que determina la precedencia de los operadores
int precedencia(char operador){
	switch (operador) {
	case '+':
	case '-':
		return 1; // Segundo evaluo las operaciones de suma y resta
	case '*':
	case '/':
		return 2; // Primero evaluo las operaciones de multiplicacion y division
	default:
		return -1; // Error
	}
}

char* infijoConversionPostfijo(char* infijo) // Conversion de Infijo a Postfijo
{
	int i, j;
	int largoCadena = strlen(infijo); // Largo de la expresion a evaluar
	// Asigno el tamaño de char multiplicado por el largo de la cadena + 2 (inicio + \0)
	char* postfijo = (char*)malloc(sizeof(char) * (largoCadena + 2)); 
	char stack[TamanioMaximoOperacion];
	int top = -1;

	for (i = 0, j = 0; i < largoCadena; i++) {
		
		// Si el caracter es un operando, lo agrego a la expresion postfija final
		if (isalnum(infijo[i])) {
			postfijo[j++] = infijo[i];
		}
		
		// Si el caracter es un operador, entonces lo pusheo a la pila 
		else if (esUnOperador(infijo[i])) {
			while (top > -1 && precedencia(stack[top]) >= precedencia(infijo[i]))
				postfijo[j++] = stack[top--];
				stack[++top] = infijo[i];
		}
	}

	// Realizo un pop hasta vacias la pila
	while (top > -1) {
		postfijo[j++] = stack[top--];
	}

	postfijo[j] = '\0'; // Fin de cadena 
	return postfijo;
}



// Implementacion Calculadora

int stack[TamanioMaximoOperacion];  
int top = -1;  

void push(int numero) {  
    top++;  
    stack[top] = numero;  
}  

int pop() {  
    int numero = stack[top];  
    top--;  
    return numero;  
}

int evaluarPostfijo(char* cadena) {  
    int i = 0;  
    char caracter = cadena[i];  
    int operando1, operando2, resultado;  
  
    while (caracter != '\0') {
		int token = columnaQuePertenece(caracter);
        if (token == 1 || token == 2 || token == 3) {  
			int numero = conversionCaracterInt(caracter);
			push(numero); 
        } 
        else if (esUnOperador(caracter)) {  
            operando2 = pop();  
            operando1 = pop();  
            switch(caracter) {  
                case '+': resultado = operando1 + operando2; break;  
                case '-': resultado = operando1 - operando2; break;  
                case '*': resultado = operando1 * operando2; break;  
                case '/': resultado = operando1 / operando2; break;  
            }  
            push(resultado);  
        }
		else if (token == 6 || token == 5 || token == 4){
			printf("Error Lexico\n");
			return EXIT_FAILURE;
		}
		i++;  
        caracter = cadena[i];  
    }  
    resultado = pop();  
    return resultado;  
} 