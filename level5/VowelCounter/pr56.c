#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char *filename = "pr56.dat";

#define ulcase(x) case x:\
	case (x ^ 32)

int main(int argc, char **argv) {
	FILE *fd = fopen(filename, "r");

	int number_of_input_lines;
	fscanf(fd, "%i", &number_of_input_lines);

	char *line;
	size_t len = 0;
	ssize_t nread;

	getline(&line, &len, fd); //flush newline from first line

	for (int cl = 0; cl < number_of_input_lines; cl++) {
		nread = getline(&line, &len, fd);

		int a_counter = 0, e_counter = 0, i_counter = 0, o_counter = 0, u_counter = 0; 

		for (int i = 0; i < nread; i++) {
			switch (line[i]) {
				ulcase('a'):
					a_counter++;
					break;
				ulcase('e'):
					e_counter++;
					break;
				ulcase('i'):
					i_counter++;
					break;
				ulcase('o'):
					o_counter++;
					break;
				ulcase('u'):
					u_counter++;
					break;
			}
		}

		printf("A - %d E - %d I - %d O - %d U - %d\n", a_counter, e_counter, i_counter, o_counter, u_counter);
	}
	return EXIT_SUCCESS;
}
