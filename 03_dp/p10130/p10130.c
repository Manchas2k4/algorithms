#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1001
#define MW 31

int p[N], w[N];
long table[N][MW];

long max(long a, long b) {
	return (a > b)? a : b;
}

long knapsack(int n, int mw) {
	int i, j;
	
	memset(table, 0, N * MW * sizeof(int));
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= mw; j++) {
			if (j < w[i]) {
				table[i][j] = table[i - 1][j];
			} else {
				table[i][j] = max( table[i - 1][j], 
								   (table[i - 1][j - w[i]] + p[i]));
			}
		}
	}
	return table[n][mw];
}

int main(int argc, char* argv[]) {
	int t, n, g, mw;
	int i, j;
	long acum;
	
	scanf("%i", &t);
	for (i = 1; i <= t; i++) {
		scanf("%i", &n);
		for (j = 1; j <= n; j++) {
			scanf("%i %i", &p[j], &w[j]);
		}
		
		scanf("%i", &g);
		acum = 0;
		for (j = 1; j <= g; j++) {
			scanf("%i", &mw);
			acum += knapsack(n, mw);
		}
		printf("%li\n", acum);
	}
	return 0;
}