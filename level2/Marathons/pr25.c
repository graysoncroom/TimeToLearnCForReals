#include <stdio.h>
#include <stdlib.h>

/* Read in a distance and determine how many marathons exist.
 * A marathon is 26.2 miles.
 *
 * The first line in the data file is an integer that represents
 * the number of data sets to follow. Each data set will contain
 * one number.
 */

const char *filename = "pr25.dat";
const float miles_per_marathon = 26.2;

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int number_of_input_lines;
	fscanf(fp, "%i", &number_of_input_lines);

	float distance;
	for (int i=0; i<number_of_input_lines; i++) {
		fscanf(fp, "%f", &distance);
		printf("%.2f\n", distance / miles_per_marathon);
	}
	
	return EXIT_SUCCESS;
}
