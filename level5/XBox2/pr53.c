#include <stdio.h>
#include <stdlib.h>

const char *filename = "pr53.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int num_input_lines;
	fscanf(fp, "%i", &num_input_lines);

	int n;
	for (int i=0; i<num_input_lines; i++) {
		fscanf(fp, "%i", &n);
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				printf("X");
			}
			printf("\n");
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
