#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *filename = "pr91.dat";

#define eprintf(fmt, ...) \
	fprintf(stderr, "Error on %s:%s on line %d\n", __FILE__, __func__, __LINE__); \
	fprintf(stderr, fmt __VA_OPT__(,) __VA_ARGS__)

void myprint(float x) {
	printf("%.3f ", x);
}

void swap(char *str, int idx1, int idx2) {
	char temp = str[idx2];
	str[idx2] = str[idx1];
	str[idx1] = temp;
}

// 1.23456 ==> 65432.1
float float_flipper(float x) {
	char *str = malloc(10000 * sizeof(char));
	int str_size = sprintf(str, "%.3f", x);

	if (str_size < 0) {
		fprintf(stderr, "sprintf fucked up. go check it out.\n");
		eprintf("sprintf fucked up. go fix it!\n");
		exit(EXIT_FAILURE);
	}

	//printf("before_flip: %s\n", str);
	//

	for (int i = str_size - 1; i >= 0 && str[i] == '0'; i--) {
		str[i] = '\0';
		str_size--;
	}

	int s_idx = 0;
	int e_idx = str_size - 1;
	while (s_idx < e_idx) {
		swap(str, s_idx, e_idx);
		s_idx++;
		e_idx--;
	}

	//for (int i=0; i<(str_size/2); i++) {
	//	swap(str, i, str_size-i);
	//}


	float result;
	if (sscanf(str, "%f", &result) == EOF) {
		eprintf("You fucked up in sscanf buddy! Go %s!\n", "fix");
	}
	free(str);
	return result;
}

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	char *line;
	size_t len = 0;
	ssize_t nread;

	while ((nread = getline(&line, &len, fp)) != -1) {
		float xs[nread];
		memset(xs, '\0', nread);
		float avg = 0;

		int i;
		int n;
		for (i = 0; i < nread && sscanf(line, "%f%n", &xs[i], &n) != EOF; i++) {
			line += n;
			avg += xs[i];
			myprint(xs[i]);
		}
		printf("\n");

		int xs_size = i;
		avg /= xs_size;
		myprint(avg);
		printf("\n");
		
		avg = 0;
		float flipped_xs;
		for (i = 0; i < xs_size; i++) {
			flipped_xs = float_flipper(xs[i]);
			avg += flipped_xs;
			myprint(flipped_xs);
		}
		printf("\n");
		avg /= xs_size;
		myprint(avg); 
		printf("\n");
	}
	return EXIT_SUCCESS;
}
