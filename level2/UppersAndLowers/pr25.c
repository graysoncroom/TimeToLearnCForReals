#include <stdio.h>
#include <stdlib.h>

/* General Statement: Input a string and output the uppercase version 
 * of it if the length of the string is even, otherwise output the
 * string in lowercase.
 *
 * Input: The first number in the data file represents the number
 * of data sets to follow. Each data set contains a single word.
 */

const char *filename = "pr25.dat";


void make_char_lowercase(char *);
void make_char_uppercase(char *);

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int input_line_count;
	fscanf(fp, "%i", &input_line_count);

	char *word;
	size_t len = 0;
	ssize_t nread;

	getline(&word, &len, fp); // discard newline
	for (int i=0; i<input_line_count; i++) {
		nread = getline(&word, &len, fp);
		word[nread-1] = '\0';
		nread--;

		// note: nread is the length of word
		if (nread % 2 == 0) { // if nread is even
			// then output uppercase version of word
			for (int j=0; j<nread; j++) {
				make_char_uppercase(&word[j]);
			}
		} else { // if nread is odd
			// then output lowercase version of word
			for (int j=0; j<nread; j++) {
				make_char_lowercase(&word[j]);
			}
		}
		printf("%s\n", word);
	}
	
	return EXIT_SUCCESS;
}

void make_char_lowercase(char *c) {
	if (*c <= 'Z' && *c >= 'A') {
		*c ^= 32;
	}
}

void make_char_uppercase(char *c) {
	if (*c <= 'z' && *c >= 'a') {
		*c ^= 32;
	}
}
