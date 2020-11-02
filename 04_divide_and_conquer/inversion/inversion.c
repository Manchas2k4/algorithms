#include <stdio.h>
#include <stdlib.h>

void copy(int *A, int *B, int low, int high) {
	int i;
	
	for (i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

int merge_and_count(int *A, int *B, int low, int mid, int high) {
	int left, right, i, count;
	
	left = i = low;
	right = mid + 1;
	count = 0;
	while (left <= mid && right <= high) {
		if (A[left] < A[right]) {
			B[i] = A[left++];
		} else {
			B[i] = A[right++];
			count = count + (mid - left + 1);
		}
		i++;
	}
	while (left <= mid) {
		B[i] = A[left++];
		i++;
	}
	while (right <= high) {
		B[i] = A[right++];
		i++;
	}
	return count;
}

int sort_and_count(int *A, int *B, int low, int high) {
	int r, mid, left, right;
	
	r = left = right = 0;
	if ( (high - low + 1) == 1 ) {
		return 0;
	} else {
		mid = low + ((high - low) / 2);
		left = sort_and_count(A, B, low, mid);
		right = sort_and_count(A, B, mid + 1, high);
		r = merge_and_count(A, B, low, mid, high);
		return (r + left + right);
	}
}

int main(int argc, char* argv[]) {
	int i, n, result;
	int *array, *temp;
	
	scanf("%i", &n);
	array = (int*) malloc(sizeof(int) * n);
	temp = (int*) malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%i", &array[i]);
	}
	
	printf("result = %i\n",  sort_and_count(array, temp, 0, n - 1));
	
	free(temp);
	free(array);
	return 0;
}
