#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char *filename = "pr91.dat";

#define eprintf(format, ...) \
	fprintf(stderr, "Error %s:%s:%d\n", __FILE__, __func__, __LINE__); \
	fprintf(stderr, format __VA_OPT__(,) __VA_ARGS__))

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");
	
	int number_of_input_lines;
	if (fscanf(fp, "%i", &number_of_input_lines) == EOF) {
		eprintf("fscanf failed\n");
	}

	char *line;
	size_t len = 0;
	ssize_t nread;

	if (nread = getline(&line, &len, fp) == -1) {
		eprintf("getline failed\n");
	}

	for (int i=0; i<number_of_input_lines; i++) {
		if (nread = getline(&line, &len, fp) == -1) {
			eprintf("getline failed (in for loop)\n");
		}
		nread--;
		line[nread] = '\0'; // replace newline with additional null terminator

		// This gives us a matrix of size n x n where n is the
		// smallest "square number" that can fit nread characters.
		int side = (int)(sqrt(nread) + 1);
		char *word_matrix = malloc(side*side*sizeof(char));

	}

	return EXIT_SUCCESS;
}
