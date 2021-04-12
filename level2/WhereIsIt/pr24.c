#include <stdio.h>

const char *filename = "pr24.dat";

int find_index_of_char_in_string(char*, char);

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int number_of_input_groups;
	fscanf(fp, "%i", &number_of_input_groups);

	char *line;
	size_t len = 0;
	ssize_t nread;
	char *char_to_find_line;
	size_t char_len = 0;
	char char_to_find;
	
	// fix this garbage :(
	getline(&line, &len, fp); // move past first newline
	for (int i=0; i<number_of_input_groups; i++) {
		nread = getline(&line, &len, fp);
		line[nread - 1] = '\0'; //remove newline grabbed by getline
		nread--;

		getline(&char_to_find_line, &char_len, fp);
		char_to_find = char_to_find_line[0];

		int found_index = find_index_of_char_in_string(line, char_to_find);
		if (found_index == -1) {
			printf("NOT THERE\n");
		} else {
			printf("%i\n", found_index);
		}

		//printf("[%s] and [%c]\n", line, char_to_find);
	}
}

int find_index_of_char_in_string(char* str, char c) {
	for (int i=0; str[i] != '\0'; i++) {
		if (str[i] == c) {
			return i;
		}
	}
	return -1;
}
