#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "pr21.dat"

int main(int argc, char ** argv) {
	FILE *fp = fopen(FILE_NAME, "r");
	
	int number_of_teams;
	fscanf(fp, "%i", &number_of_teams);

	char *name = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	// currently only reading in first names
	// need to figure out how to read names until endline
	// or read in line, remove spaces, and strlen
	getline(&name, &len, fp);
	for (unsigned int i=0; i<number_of_teams; i++) {
		int total_character_count = 0;
		for (unsigned int j=0; j<3; j++) {
			nread = getline(&name, &len, fp);
			name[nread - 1] = '\0'; // remove newline character grabbed by getline
			nread--;
			int nspaces = 0;
			for (unsigned int k=0; name[k] != '\0'; k++) {
				//printf("%c\n", name[k]);
				if (name[k] == ' ') {
					nspaces++;
				}
			}
			int current_character_count = nread - nspaces;
			total_character_count += current_character_count;
		}
		printf("%i\n", total_character_count);
	}
}
