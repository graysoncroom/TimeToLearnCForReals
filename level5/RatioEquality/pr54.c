#include <stdio.h>
#include <stdlib.h>

const char *filename = "pr54.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	char *line;
	size_t len = 0;
	ssize_t nread;

	float a,b,c,d;
	while (fscanf(fp, "%f %f %f %f", &a, &b, &c, &d) != EOF) {
		float ratio1 = a / b;
		float ratio2 = c / d;
		float result = ratio1 - ratio2;
		if (result < 0) {
			result = -result;
		}
		printf("%.6f %s\n", result, result < 0.00001 ? "EQUAL RATIOS" : "NOT EQUAL");
	}

	return EXIT_SUCCESS;
}
