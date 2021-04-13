#include <stdio.h>
#include <stdlib.h>

const char *filename = "pr54.dat";

int number_of_spaces(const char*);

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int num_lines;
	fscanf(fp, "%i", &num_lines);

	char *line;
	size_t len = 0;
	ssize_t nread;

	getline(&line, &len, fp); // flush newline
	for (int i=0; i<num_lines; i++) {
		nread = getline(&line, &len, fp); // note: \n is included. we did not remove it.
		int num_words = 1 + number_of_spaces(line);
		
		// increment the ascii value of each char by the number of words
		// in the line
		for (int j=0; j<nread; j++) {
			if ((line[j] >= 'A' && line[j] <= 'Z') || (line[j] >= 'a' && line[j] <= 'z')) {
				// line[j] is a letter
				line[j] = num_words + line[j];
				if ((line[j] > 'Z' && line[j] < 'a') || (line[j] > 'z')) {
					line[j] -= 26;
				}
			}
		}

		printf("%s", line);
	}

	return EXIT_SUCCESS;
}

int number_of_spaces(const char *str) {
	int count = 0;
	for (int i=0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			count++;
		}
	}
	return count;
}
