#include <stdio.h>
#include <stdlib.h>

int get_closest(int val1, int val2, int target) {
	if (target - val1 > val2 - target) {
		return val2;
	} else {
		return val1;
	}
}

int find_closest(int *arr, int n, int target) {
	int low, high, mid;
	
	if (target < arr[0]) {
		return arr[0];
	}
	
	if (target >= arr[n - 1]) {
		return arr[n - 1];
	}
	
	low = 0;
	high = n - 1;
	mid = 0;
	while (low < high) {
		mid = low + ( (high - low) / 2 );
		if (target == arr[mid]) {
			return arr[mid];
		} else if (target < arr[mid]) {
			if (mid > 0 && target > arr[mid - 1]) {
				return get_closest(arr[mid - 1], arr[mid], target);
			}
			high = mid;
		} else {
			if (mid < (n - 1) && target < arr[mid + 1]) {
				return get_closest(arr[mid], arr[mid + 1], target);
			}
			low = mid;
		}
	}
}

int main(int argc, char* argv[]) {
	int i, n, target, *arr;
	
	scanf("%i %i", &n, &target);
	
	arr = (int*) malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%i", &arr[i]);
	}
	
	printf("closest of %i = %i\n", target, find_closest(arr, 8, target));
	
	free(arr);
	return 0;
}