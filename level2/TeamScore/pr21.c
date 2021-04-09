#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "pr21.dat"

int main(int argc, char ** argv) {
	FILE *fp = fopen(FILE_NAME, "r");
	
	int number_of_teams;
	fscanf(fp, "%i", &number_of_teams);

	char name[100];
	// currently only reading in first names
	// need to figure out how to read names until endline
	// or read in line, remove spaces, and strlen
	for (int i=0; i<number_of_teams; i++) {
		int total_character_count = 0;
		for (int j=0; j<3; j++) {
			fscanf(fp, "%s", &name);
			printf(name);
			total_character_count += strlen(name);
		}
		printf("%i\n", total_character_count);
	}
}
