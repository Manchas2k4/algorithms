#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100001

int main(int argc, char* argv[]) {
	int i, j, k, n, dropped[MAXSIZE];
	
	scanf("%i", &n);
	
	memset(dropped, 0, sizeof(int) * (n + 1));
	j = n;
	for (i = 1; i <= n; i++) {
		scanf("%i", &k);
		dropped[k]++;
		
		while (dropped[j] && j > 0) {
			printf("%i ", j);
			j--;
		}
		printf("\n");
	}
	return 0;
}