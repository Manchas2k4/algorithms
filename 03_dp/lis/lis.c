#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int lis(int *A, int size) {
	int *aux, i, j, count;
	
	aux = (int*) malloc(sizeof(int) + size);
	
	aux[0] = 1;
	for (i = 1; i < size; i++) {
		count = 0;
		for (j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				count = MAX(count, aux[j]);
			}
		}
		aux[i] = count + 1;
	}
	
	count = 0;
	for (i = 0; i < size; i++) {
		count = MAX(count, aux[i]);
	}
	
	free(aux);
	
	return count;
}

int main(int argc, char* argv[]) {
	int i, n, *array;
	
	scanf("%i", &n);

	array = (int*) malloc(sizeof(int) * n);	
	
	for (i = 0; i < n; i++) {
		scanf("%i", &array[i]);
	}
	printf("LIS = %i\n", lis(array, n));
	
	free(array);
	
	return 0;
}
