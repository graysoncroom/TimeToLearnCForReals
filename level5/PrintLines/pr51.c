#include <stdio.h>
#include <stdlib.h>

const char *filename = "pr51.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int total_number_of_input_lines;
	fscanf(fp, "%i", &total_number_of_input_lines);

	int n;
	for (int i=0; i<total_number_of_input_lines; i++) {
		fscanf(fp, "%i", &n);
		printf("[");
		for (int j=0; j<n; j++) {
			printf("X");
		}
		printf("]\n");
	}
	return EXIT_SUCCESS;
}
