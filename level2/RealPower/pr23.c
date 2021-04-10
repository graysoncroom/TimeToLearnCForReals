#include <stdio.h>
#include <math.h>

const char *filename = "pr23.dat";


/* Given a real number and an integer, output
 * all of the powers of the real number from zero to the integer,
 * formmated to two decimal places, each separated by a 
 * single space all on one line.
 */

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int number_of_input_lines;
	fscanf(fp, "%i", &number_of_input_lines);

	double base;
	int exponent;
	for (int i=0; i<number_of_input_lines; i++) {
		fscanf(fp, "%lf", &base);
		fscanf(fp, "%i", &exponent);
		for (int j=0; j<=exponent; j++) {
			double result = pow(base, j);
			printf("%.2lf ", result);
		}
		printf("\n");
	}
	return 0;
}
