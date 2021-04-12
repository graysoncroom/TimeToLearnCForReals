#include <stdio.h>
#include <stdlib.h>

/* OK so the bandwidth saving program in 2.6 was not such a
 * success. So to make it up to its customers the internet
 * provider has determined correct data is better data. Write
 * a program that will find the sum of a binary number's digit
 * to be transmitted. If it is odd then output a 1 followed by the
 * number or if it is even output a 0 followed by the number.
 *
 * The first line in the data file is an integer that represents
 * the number of data sets to follow. Each data set will contain
 * a binary number.
 */

const char *filename = "pr52.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int number_of_input_lines;
	fscanf(fp, "%i", &number_of_input_lines);

	char *line;
	size_t len = 0;
	ssize_t nread;

	getline(&line, &len, fp);
	for (int i=0; i<number_of_input_lines; i++) {
		nread = getline(&line, &len, fp);

		line[--nread] = '\0';

		int sum = 0;
		for (int j=0; j<nread; j++) {
			sum += (line[j] - '0');
		}
		
		printf("%i%s\n", (sum % 2), line);
	}
	return EXIT_SUCCESS;
}
