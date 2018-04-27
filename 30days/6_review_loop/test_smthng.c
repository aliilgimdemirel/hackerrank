#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	char *hasan = NULL;

	hasan = "maho";
	printf("DEBUG\n");

	hasan[0] = 'm';
	printf("DEBUG\n");
	hasan[1] = 'a';
	printf("DEBUG\n");
	hasan[2] = 'h';
	printf("DEBUG\n");
	hasan[3] = '\0';
	printf("DEBUG\n");
	hasan[4] = '\0';

	printf("%s\n", hasan);

	free(hasan);

	return 0;
}
