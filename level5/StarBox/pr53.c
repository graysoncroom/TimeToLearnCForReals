#include <stdio.h>
#include <stdlib.h>

const char *filename = "pr53.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int num_input_lines;
	fscanf(fp, "%i", &num_input_lines);

	int r,c;
	for (int i=0; i<num_input_lines; i++) {
		fscanf(fp, "%i %i", &r, &c);
		for (int j=0; j<r; j++) {
			for (int k=0; k<c; k++) {
				printf("*");
			}
			printf("\n");
		}
		printf("\n");
	}


	return EXIT_SUCCESS;
}
