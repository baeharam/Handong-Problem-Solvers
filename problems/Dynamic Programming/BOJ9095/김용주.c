#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int data[11];
	int T;
	int *input = NULL;

	scanf("%d", &T);
	input = (int*)malloc(T * sizeof(int));

	data[0] = 1;
	data[1] = 2;
	data[2] = 4;

	for (int i = 0; i < T; i++) {
		scanf("%d", &input[i]);
	}

	for (int i = 3; i < 11; i++) {
		data[i] = data[i - 1] + data[i - 2] + data[i - 3];
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", data[input[i] - 1]);
	}

	free(input);
	return 0;
}