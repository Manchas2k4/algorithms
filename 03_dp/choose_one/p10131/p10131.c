#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1001

void lis(int w[], int s[], int n) {
	int i, j, max;
	int l[N], p[N];
	
	for (i = 0; i < n; i++) {
		l[i] = 1;
		p[i] = 0;
		for (j = 0; j < i; j++) {
			if ( (w[j] < w[i] && s[j] > s[i]) && (l[j] + 1) > l[i]) {
				p[i] = j;
				l[i] = l[j] + 1;
			}
		}
	}
	max = 0;
	for (i = 0; i < n; i++) {
		if (l[i] > l[max]) {
			max = i;
		}
	}
	printf("%i\n", l[max]);
	i = max;
	while (i > 0) {
		printf("%i\n", p[i]);
		i = p[i];
	}
}

int main(int argc, char* argv[]) {
	int n, max;
	int w[N], s[N];
	
	n = 0;
	while (scanf("%i %i", &w[n], &s[n]) != EOF) {
		n++;
	}
	lis(w, s, n);
	return 0;
}