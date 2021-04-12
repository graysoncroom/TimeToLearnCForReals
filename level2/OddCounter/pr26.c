#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char *filename = "pr26.dat";

/* General Statement: Read in two numbers and print out how many odd
 * numbers exist between the two numbers. Include the starting number
 * and ending numbers when searching for odds.
 *
 * Input: The first line in the data file is an integer that represents
 * the number of data sets to follow. Each data set will contain two numbers
 */

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int number_of_input_lines;
	fscanf(fp, "%i", &number_of_input_lines);

	int starting_num;
	int ending_num;
	for (int i=0; i<number_of_input_lines; i++) {
		fscanf(fp, "%i", &starting_num);
		fscanf(fp, "%i", &ending_num);

		printf("%i\n", (int)(ceil(0.5+(ending_num-starting_num)/2.0)));
	}

	return EXIT_SUCCESS;
}
