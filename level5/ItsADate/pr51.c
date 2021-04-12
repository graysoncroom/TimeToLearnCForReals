#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *filename = "pr51.dat";

const char * date_string_lookup[] = {
	"JANUARY",
	"FEBRUARY",
	"MARCH",
	"APRIL",
	"MAY",
	"JUNE",
	"JULY",
	"AUGUST",
	"SEPTEMBER",
	"OCTOBER",
	"NOVEMBER",
	"DECEMBER"
};

void get_date_string(char**, int);

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int num_input_lines;
	fscanf(fp, "%i", &num_input_lines);

	int month;
	int day;
	int year;
	char *month_str;
	for (int i=0; i<num_input_lines; i++) {
		fscanf(fp, "%i %i %i", &month, &day, &year);

		get_date_string(&month_str, month);

		printf("%s %i, %i\n", month_str, day, year);
		
		free(month_str);
	}
	return EXIT_SUCCESS;
}

void get_date_string(char** buf, int n) {
	*buf = (char*)malloc(10*sizeof(char));
	strncpy(*buf, date_string_lookup[n-1], 10);
}
