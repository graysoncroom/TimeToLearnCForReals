#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "pr21.dat"

int main(int argc, char **argv) {
	FILE *fp = fopen(FILE_NAME, "r");

	int number_of_lines;
	fscanf(fp, "%i", &number_of_lines);
	
	int current_num;
	for (int i=0; i<number_of_lines; i++) {
		fscanf(fp, "%i", &current_num);
		printf("%s\n", current_num < 10 ? "Not bigger than ten" : "Bigger than ten.");
	}
}
