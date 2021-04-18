#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE *fp = fopen("_pr56.dat", "r");

	int n = 0, m = 0;
	fscanf(fp, "%d = %d", &n, &m);
	printf("%d = %d\n", n, m);
	return EXIT_SUCCESS;
}
