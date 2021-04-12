#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *filename = "pr24.dat";

/* The first line in the data file is an integer that represents
 * the number of data sets to follow. Each data set will contain a value
 * to be raised followed by a list of item values that could be sold.
 */

int greaterThan(const void *, const void *);

int main(int argc, char **argv) {
	FILE *fp = fopen(filename, "r");

	int number_of_input_groups;
	fscanf(fp, "%i", &number_of_input_groups);

	int amount_to_sell_total;

	for (int i=0; i<number_of_input_groups; i++) {
		fscanf(fp, "%i", &amount_to_sell_total);
		
		char *item_amounts;
		ssize_t nread;
		size_t len = 0;
		getline(&item_amounts, &len, fp); // flush newline
		nread = getline(&item_amounts, &len, fp);
		
		int current_item_amount;
		int n; // offset 
		char *copy_item_amounts = item_amounts;
		
		int nspaces = 0;
		for (int j=0; item_amounts[j] != '\0'; j++) {
			if (item_amounts[j] == ' ') {
				nspaces++;
			}
		}
		int number_of_ints = nspaces + 1;
		int item_amounts_int[number_of_ints];

		int j=0;
		while(sscanf(item_amounts, "%i %n", &current_item_amount, &n) != EOF) {
			item_amounts_int[j] = current_item_amount;
			item_amounts += n;
			j++;
		}
		qsort(item_amounts_int, number_of_ints, sizeof(int), greaterThan);

		for (j=0; j<number_of_ints; j++) {
			//printf("total: %i ; curr: %i\n", amount_to_sell_total, item_amounts_int[j]);
			if (amount_to_sell_total > 0) {
				amount_to_sell_total -= item_amounts_int[j];
				printf("%i ", item_amounts_int[j]);
			}
		}
		printf("\n");

		//for (j=0; j<number_of_ints; j++)
		//	if (items_amounts_sold[j] != -1)
		//		printf("%i ", items_amounts_sold[j]);

		free(copy_item_amounts);
	}

	return EXIT_SUCCESS;
}

// return value meaning:
// <0 loperand goes before roperand
// 0  order doesn't matter
// >0 roperand goes before loperand
int greaterThan(const void *loperand, const void *roperand) {
	int *l = (int*)loperand;
	int *r = (int*)roperand;

	if (*l > *r) {
		return -1;
	} else if (*r > *l) {
		return 1;
	} else {
		return 0;
	}
}
