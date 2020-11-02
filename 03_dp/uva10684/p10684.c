#include <stdio.h>
#include <stdlib.h>

#define N 10001

void max1d_sum(int *arr, int n) {
	int max_so_far = 0;
	int max_ending_here = 0;
	int i;
	
	for(i = 0; i < n; i++) {
		max_ending_here = max_ending_here + arr[i];
		if (max_ending_here < 0) {
			max_ending_here = 0;
		}
		if (max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
		}
	}
	if (max_so_far > 0) {
		printf("The maximum winning streak is %i.\n", max_so_far);
	} else {
		printf("Losing streak.\n");
	}
}

int main (int argc, char* argv[]) {
	int n, i;
	int array[N];
	
	while (1) {
		scanf("%i", &n);
		if (n == 0) {
			break;
		}
		for (i = 0; i < n; i++) {
			scanf("%i", &array[i]);
		}
		max1d_sum(array, n);
	}
	return 0;
}