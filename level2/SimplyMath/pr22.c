#include <stdio.h>
#include <stdlib.h>

const char *filename = "pr22.dat";

int perform_operation(int, int, char);

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");
	
	int number_of_input_lines;
	fscanf(fp, "%i", &number_of_input_lines);

	int operand1;
	int operand2;
	char operation;
	for (int i=0; i<number_of_input_lines; i++) {
		fscanf(fp, "%i %i %c", &operand1, &operand2, &operation);
		int result = perform_operation(operand1, operand2, operation);
		printf("%i %c %i = %i\n", operand1, operation, operand2, result);
	}
}

int perform_operation(int op1, int op2, char operation) {
	int result;
	switch (operation) {
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
		case '*':
			result = op1 * op2;
			break;
		case '/':
			result = op1 / op2;
			break;
		default:
			fprintf(stderr, "User entred incorrect operation, namely, %c", operation);
			exit(EXIT_FAILURE);
	}
	return result;
}
