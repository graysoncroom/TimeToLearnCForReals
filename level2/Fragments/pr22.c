#include <stdio.h>

const char *filename = "pr22.dat";

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");
	
	int number_of_input_lines;
	fscanf(fp, "%i", &number_of_input_lines);

	char animal_name[100];
	int index1;
	int index2;
	for (int i=0; i<number_of_input_lines; i++) {
		fscanf(fp, "%s %i %i", animal_name, &index1, &index2);
		if (index2 == -1) {
			for (int j=index1; animal_name[j] != '\0'; j++) {
				printf("%c", animal_name[j]);
			}
		} else {
			for (int j=index1; j < index2; j++) {
				printf("%c", animal_name[j]);
			}
		}
		printf("\n");
	}
}
