#include <stdio.h>
#include <stdlib.h>

const char *filename = "pr53.dat";

int apply_operation(int x, int y, char op);

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int num_of_input_lines;
	fscanf(fp, "%i", &num_of_input_lines);

	char *line;
	size_t len = 0;
	ssize_t nread;

	getline(&line, &len, fp);

	int nums[4];
	char ops[2];
	for (int i=0; i<num_of_input_lines; i++) {
		fscanf(fp, "%i %c %i == %i %c %i", &nums[0], &ops[0], &nums[1], &nums[2], &ops[1], &nums[3]);
		//nread = getline(&line, &len, fp);
		int result1 = apply_operation(nums[0], nums[1], ops[0]);
		int result2 = apply_operation(nums[2], nums[3], ops[1]);
		printf("%s\n", (result1 == result2) ? "EQUAL" : "NOT EQUAL");
	}

	return EXIT_SUCCESS;
}

int apply_operation(int x, int y, char op) {
	switch (op) {
		case '+':
			return x + y;
			break;
		case '-':
			return x - y;
			break;
		default:
			exit(EXIT_FAILURE);
			break;
	}
}
