#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *filename = "pr55.dat";

void read_time(int *h, int *m, char *line) {
	int temp_hours, temp_mins;

	*h = *m = 0;

	line = 1 + strchr(line, ':');

	int n;
	while (sscanf(line, " %u:%u%n", &temp_hours, &temp_mins, &n) != EOF) {
		line += n;
		*h += temp_hours;
		*m += temp_mins;
	}

	// convert extra mins into proper amount of hours
	*h += *m / 60;
	*m = *m % 60;
}

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int num_line_groups;
	fscanf(fp, "%i", &num_line_groups);

	char *line1;
	size_t len1 = 0;
	ssize_t nread1;

	char *line2;
	size_t len2 = 0;
	ssize_t nread2;

	getline(&line1, &len1, fp); // flush newline
	// times start at index 8
	for (int i=0; i<num_line_groups; i++) {
		nread1 = getline(&line1, &len1, fp);
		nread2 = getline(&line2, &len2, fp);

		int team1_hours, team1_mins, team2_hours, team2_mins;
		read_time(&team1_hours, &team1_mins, line1);
		read_time(&team2_hours, &team2_mins, line2);

		// compare the two teams, print name of team that has lowest time
		if (team1_hours < team2_hours) {
			printf("TEAM 1\n");
		} else if (team2_hours < team1_hours) {
			printf("TEAM 2\n");
		} else {
			if (team1_mins < team2_mins) {
				printf("TEAM 1\n");
			} else if (team2_mins < team1_mins) {
				printf("TEAM 2\n");
			} else {
				fprintf(stderr, "WTF input. Can't do that shit bruh.\n");
				return EXIT_FAILURE;
			}
		}
	}

	return EXIT_SUCCESS;
}
