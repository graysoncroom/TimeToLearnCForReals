#include <stdio.h>

const char *filename = "pr23.dat";

// Area = bh
int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int number_of_input_lines;
	fscanf(fp, "%i", &number_of_input_lines);

	float base;
	float height;

	for (int i=0; i<number_of_input_lines; i++) {
		fscanf(fp, "%f", &base);
		fscanf(fp, "%f", &height);
		printf("%.2f\n", base*height);
	}
}
