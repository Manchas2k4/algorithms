#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sieve(int n) {
	char* result;
	int i, j;
	
	result = (char*) malloc(sizeof(char) * (n + 1));
	memset(result, 1, (n + 1));
	
	for (i = 2; i <= n; i++) {
		if (result[i]) {
			for (j = 2*i; j <= n; j = j + i) {
				result[j] = 0;
			}
		}
	}
	return result;
}

int main(int argc, char* argv[]) {
	int i, n;
	char* result;
	
	scanf("%i", &n);
	result = sieve(n);
	for (i = 2; i <= n; i++) {
		if (result[i]) {
			printf("%i ", i);
		}
	}
	printf("\n");
}