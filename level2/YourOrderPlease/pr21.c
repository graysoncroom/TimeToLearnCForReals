#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "pr21.dat"

void swap(int*, int*);
int lessThan(const void *, const void *);

int main(int argc, char **argv) {
	FILE *fp = fopen(FILE_NAME, "r");
	
	int number_of_lines;
	fscanf(fp, "%i", &number_of_lines);


	for (int i = 0; i < number_of_lines; i++) {
		int numbers[3];
		fscanf(fp, "%i %i %i", &numbers[0], &numbers[1], &numbers[2]);

		//if (numbers[1] < numbers[0])
		//	swap(&numbers[0], &numbers[1]);
		//if (numbers[2] < numbers[0])
		//	swap(&numbers[0], &numbers[2]);
		//if (numbers[2] < numbers[1])
		//	swap(&numbers[1], &numbers[2]);
		
		qsort(numbers, 3, sizeof(*numbers), lessThan);

		for (int j = 0; j < 3; j++) {
			printf("%i ", numbers[j]);
		}
		printf("\n");
	}
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int lessThan(const void *x, const void *y) {
	int *xInt = (int*)x;
	int *yInt = (int*)y;

	return *xInt < *yInt ? -1 : 1;
}
