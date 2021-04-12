#include <stdio.h>
#include <stdlib.h>

const char *filename = "pr52.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int num_input_lines;
	fscanf(fp, "%i", &num_input_lines);

	int starting_num;
	int ending_num;

	for (int i=0; i<num_input_lines; i++) {
		fscanf(fp, "%i %i", &starting_num, &ending_num);
		if (starting_num % 2 == 1) {
			starting_num++;
		}
		for (int j=starting_num; j<=ending_num; j+=2) {
			printf("%i ", j);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
