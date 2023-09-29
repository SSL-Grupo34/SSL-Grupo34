// C code to convert infix to postfix expression https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TamanioMaximoOperacion 100

// Function to return precedence of operators
int precedence(char operador){
	switch (operador) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}

// Function to check if the scanned character
// is an operator
int isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
			|| ch == '^');
}

// Main functio to convert infix expression
// to postfix expression
char* infixToPostfix(char* infix)
{
	int i, j;
	int len = strlen(infix);
	char* postfix = (char*)malloc(sizeof(char) * (len + 2));
	char stack[TamanioMaximoOperacion];
	int top = -1;

	for (i = 0, j = 0; i < len; i++) {
		if (infix[i] == ' ' || infix[i] == '\t')
			continue;
		
		// If the scanned character is operand
		// add it to the postfix expression
		if (isalnum(infix[i])) {
			postfix[j++] = infix[i];
		}
		
		// if the scanned character is '('
		// push it in the stack
		else if (infix[i] == '(') {
			stack[++top] = infix[i];
		}
		
		// if the scanned character is ')'
		// pop the stack and add it to the
		// output string until empty or '(' found
		else if (infix[i] == ')') {
			while (top > -1 && stack[top] != '(')
				postfix[j++] = stack[top--];
			if (top > -1 && stack[top] != '(')
				return "Invalid Expression";
			else
				top--;
		}
		
		// If the scanned character is an operator
		// push it in the stack
		else if (isOperator(infix[i])) {
			while (top > -1
				&& precedence(stack[top])
						>= precedence(infix[i]))
				postfix[j++] = stack[top--];
			stack[++top] = infix[i];
		}
	}

	// Pop all remaining elements from the stack
	while (top > -1) {
		if (stack[top] == '(') {
			return "Invalid Expression";
		}
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
	return postfix;
}


// Calculadora de postfijo a resultado final    https://www.javatpoint.com/postfix-evaluation-in-c
// Stack implementation
 
int stack[TamanioMaximoOperacion];  
int top = -1;  

void push(int item) {  
    if (top >= TamanioMaximoOperacion - 1) {  
		printf("Stack Overflow\n");  
        return;  
    }  
    top++;  
    stack[top] = item;  
}  

int pop() {  
    if (top < 0) {  
printf("Stack Underflow\n");  
        return -1;  
    }  
    int item = stack[top];  
    top--;  
    return item;  
}  
int esUnOperador(char caracter) {  
    if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') {  
        return 1;  
    }  
    return 0;  
}  
int evaluate(char* expression) {  
    int i = 0;  
    char symbol = expression[i];  
    int operand1, operand2, result;  
  
    while (symbol != '\0') {  
        if (symbol >= '0' && symbol <= '9') {  
            int num = symbol - '0';  
            push(num);  
        }  
        else if (esUnOperador(symbol)) {  
            operand2 = pop();  
            operand1 = pop();  
            switch(symbol) {  
                case '+': result = operand1 + operand2; break;  
                case '-': result = operand1 - operand2; break;  
                case '*': result = operand1 * operand2; break;  
                case '/': result = operand1 / operand2; break;  
            }  
            push(result);  
        }  
	i++;  
        symbol = expression[i];  
    }  
    result = pop();  
    return result;  
}  

int main()
{
	char infix[TamanioMaximoOperacion] = "3+4*8/2+3-5";
	
	// Function call
	char* postfijo = infixToPostfix(infix);
	printf("%s\n", postfijo); // funciona bien
	//free(postfix);


	// CALCULADORA

	int result = evaluate(postfijo);  
	printf("Resultado = %d\n", result);  



    return 0;
}
