#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int binary_search(int A[], int low, int high, int key) {
	if (low > high) {
		return -1;
	} 
	
	int mid = low + (high - low) / 2;
	if (key == A[mid]) {
		return mid;
	} else if (key < A[mid]) {
		return binary_search(A, low, mid - 1, key);
	} else if (key > A[mid]) {
		return binary_search(A, mid + 1, high, key);
	}
}

int main(int argc, char* argv[]) {
	int *array, i, num;
	unsigned int size;
	
	scanf("%u %i", &size, &num);
	array = (int*) malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		scanf("%i", &array[i]);
	}
	
	printf("size = %u - num = %i\n", size, num);
	
	qsort(array, size, sizeof(int), compare);
	printf("found = %i\n", binary_search(array, 0, size - 1, num));
	
	free(array);
	
	return 0;
}
