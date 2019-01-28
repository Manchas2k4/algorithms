#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef long long int lli;

int main(int argc, char* argv[]) {
	int i, n;
	lli a, b, p, tokens[MAX];
	
	scanf("%i %lli %lli", &n, &a, &b);
	
	for (i = 0; i < n; i++) {
		scanf("%lli", &tokens[i]);
	}
	
	for (i = 0; i < n; i++) {
		p = tokens[i] * a / b;
		printf("%lli ", tokens[i] - (p * b / a) - ((p * b % a) != 0));
	}
	printf("\n");
	return 0;
}
