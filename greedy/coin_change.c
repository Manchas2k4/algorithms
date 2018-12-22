#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
  return ( *(int*)b - *(int*)a );
}

int coin_change(int n, int coins[], int amount) {
	int minimum = 0, i;
	
	qsort (coins, n, sizeof(int), compare);
	for (i = 0; i < n; i++) {
		minimum += amount / coins[i];
		amount %= coins[i];
	}
	return minimum;
}

int main(int argc, char* argv[]) {
	int *array = NULL;
	int i, n, amount, min;
	
	scanf("%i", &amount);
	scanf("%i", &n);
	
	array = (int*) malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%i", (array + i));
	}
	
	min = coin_change(n, array, amount);
	printf("%i\n", min);
	
	return 0;
}
