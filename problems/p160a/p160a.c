#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int compare(const void *a, const void *b) {
	return ( *(int*)b - *(int*)a );
}

int main(int argc, char* argv[]) {
	int coins[MAX], i, n;
	int total, sum, val;
	
	total = 0;
	scanf("%i", &n);
	for (i = 0; i < n; i++) {
		scanf("%i", &val);
		coins[i] = val;
		total += val;
	}
	
	qsort(coins, n, sizeof(int), compare);
	
	i = 0;
	sum = 0;
	total /= 2;
	while (sum <= total) {
		sum += coins[i++];
	}
	
	printf("%i\n", i);
	
	return 0;
}
	
	
	
