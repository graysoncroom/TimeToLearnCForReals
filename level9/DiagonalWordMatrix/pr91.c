#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const char *filename = "pr91.dat";


// TODO: figure out how to write portable c99 vararg macros
// with the intended functionality of __VA_OPT__(,) __VA_ARGS__
// sorry future grayson...

#define eprintf(format, ...)                                               \
	do {                                                                   \
		fprintf(stderr, "Error %s:%s:%d\n", __FILE__, __func__, __LINE__); \
		fprintf(stderr, format __VA_OPT__(,) __VA_ARGS__);                 \
	} while (false)

#define debug(format, ...) \
	do { \
		fprintf(stderr, format, ##__VA_ARGS__); \
	} while (false)

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");
	
	int number_of_input_lines;
	if (fscanf(fp, "%i", &number_of_input_lines) == EOF) {
		eprintf("fscanf failed\n");
	}

	char *line;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, fp);
	if (nread == -1) { // flush newline
		eprintf("getline failed\n");
	}

	free(line);
	len = 0;

	for (int i=0; i<number_of_input_lines; i++) {
		nread = getline(&line, &len, fp);
		if (nread == -1) {
			eprintf("getline failed (in for loop)\n");
		}

		line[nread-1] = '\0'; // replace newline with additional null terminator
		nread--;

		// This gives us a matrix of size n x n where n is the
		// smallest "square number" that can fit nread characters.
		int side = (int)(sqrt(nread) + 1);
		if (nread == 1) {
			side = 1;
		}
		printf("side:%d\n", side);
		//char **word_matrix = malloc(side*sizeof(char*));
		//for (int j=0; j<size; j++) {
		//	word_matrix[j] = malloc(side*sizeof(char));
		//}
		char *word_matrix = malloc(side*side*sizeof(char));



		// TODO: fix terrible gross code ewwwwwwwwwwwwwwwww
		// this def the issue
		// there may be a permutation orbit that corresponds to these
		// look into it tmr
		int jump_by = side + 1;
		int line_idx = 0;
		for (int idx=side-1; idx != (side*side-3); idx = (idx+jump_by)%(side*side)) {
			if (line_idx < nread) {
				word_matrix[idx] = line[line_idx];
				line_idx++;
			} else {
				word_matrix[idx] = '*';
			}
		}

		// NOTE: last matrix is in an infinite loop for some reason.
		// TODO: fix that bs

		//Remark: only prints out one character? wtf.
		for (int j=0; j<side*side; j++) {
			printf("%c", word_matrix[j]);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
