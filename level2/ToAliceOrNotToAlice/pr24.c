#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *filename = "pr24.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int number_of_input_lines;
	fscanf(fp, "%i", &number_of_input_lines);
	
	char *line;
	size_t len = 0;
	ssize_t nread;

	getline(&line, &len, fp); //flush newline

	for (int i=0; i<number_of_input_lines; i++) {
		nread = getline(&line, &len, fp);

		char alice_str[] = "ALICE";
		char *substr = (char*)malloc(5*sizeof(char));

		int result;
		int alice_count = 0;
		for (int j=0; j<nread-4; j++) {
			strncpy(substr, &line[j], 5);
			result = strcmp(substr, alice_str);
			if (result == 0) {
				alice_count++;
			}
		}
		printf("%i\n", alice_count);

		free(substr);
	}
}
