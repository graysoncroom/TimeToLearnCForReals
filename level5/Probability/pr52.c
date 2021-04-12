#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *filename = "pr52.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int num_input_lines;
	fscanf(fp, "%i", &num_input_lines);

	int n;
	srand(time(NULL));

	for (int i=0; i<num_input_lines; i++) {
		fscanf(fp, "%i", &n);
		int x=0;
		for (int j=0; j<n; j++) {
			if (rand() % 2 == 0) {
				x++;
			}
		}
		printf("%.3lf\n", ((double)x)/n);
	}

	return EXIT_SUCCESS;
}
