#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define SIZE 2001

int main(int argc, char* argv[]) {
	int input[SIZE], lis[SIZE], lds[SIZE];
	int n, t, i, j, s, ans;
	
	scanf("%i", &t);
	for (s = 0; s < t; s++) {
		scanf("%i", &n);
		for (i = 0; i < n; i++) {
			scanf("%i", &input[i]);
		}
		
		for (i = (n - 1); i >= 0; i--) {
			lis[i] = 1; lds[i] = 1;
			for (j = (i + 1); j < n; j++) {
				if (input[i] < input[j]) {
					lis[i] = MAX(lis[j] + 1, lis[i]);
				}
				
				if (input[i] > input[j]) {
					lds[i] = MAX(lds[j] + 1, lds[i]);
				}
			}
		}
		
		ans = 0;
		for (i = 0; i < n; i++) {
			ans = MAX(ans, lis[i] + lds[i] - 1);
		}
		printf("%i\n", ans);
	}
	return 0;
}