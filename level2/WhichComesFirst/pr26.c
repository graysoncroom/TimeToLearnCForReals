#include <stdio.h>
#include <stdlib.h>

const char *filename = "pr26.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int number_of_input_lines;
	fscanf(fp, "%i", &number_of_input_lines);

	char *line;
	char word[100];
	size_t len = 0;

	for (int i=0; i<number_of_input_lines; i++) {
		fscanf(fp, "%s", &word);
		getline(&line, &len, fp); //discard remainder of line
		printf("%s\n", word);
	}

	return EXIT_SUCCESS;
}
