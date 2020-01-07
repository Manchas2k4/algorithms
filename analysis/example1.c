#include <stdio.h>
#include <stdlib.h>

/* SIZE = 1e8*/
#define SIZE 100000000

int main(int argc, char* argv[]) {
	int* array, i;
	
	array = (int*) malloc(sizeof(int) * SIZE);
	for (i = 0; i < SIZE; i++) {
		array[i] = (i + 1);
	}
	for (i = 0; i < 100; i++) {
		printf("%4i", array[i]);
	}
	printf("\n");
	free(array); 
	
	return 0;
}
