#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define K 100
#define N 100
#define SIZE 102
#define MOD 1000000LL


int main(int argc, char* argv[]) {
	int i, j, m, n, k, dp[SIZE][SIZE];
	
	memset(dp, 0, sizeof(dp));
	for (j = 0; j <= N; j++) {
		dp[1][j] = 1;
	}
	for (i = 2; i <= K; i++) {
		for (j = 0; j <= N; j++) {
			for (m = j; m >= 0; m--) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - m]) % MOD;
			}
		}
	}
	
	while (scanf("%i%i", &n, &k) != 0) {
		if (!n && !k) {
			break;
		}
		printf("%d\n", dp[k][n]);
	}
	return 0;
}
