#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

int main() {

	FILE *input = fopen("input.txt", "r");

	int max_length = 0;
	char read[MAX];

	// Allocate memory size
	while (fscanf(input, "%s ", read) != EOF) {
		if (max_length < strlen(read)) {
			max_length = strlen(read);
		}
	}
	// Get lengts
	fseek(input, 0, SEEK_SET);
	int *arr = (int *)malloc(sizeof(int)*(max_length + 1));

	for (int i = 0; i <= max_length; i++) {
		arr[i] = 0;
	}

	while (fscanf(input, "%s ", read) != EOF) {
		*(arr + strlen(read)) += 1;
	}
	// Print occurence
	for (int i = 1; i <= max_length; i++) {
		if (arr[i] != 0) {
			printf("%d ", i);
			printf("%d", arr[i]);
			printf("\n");
		}
	}

	fclose(input);
	system("PAUSE");
	return 0;
	


}
