#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000001

int main(int argc, char* argv[]) {
	int i, n, a[MAXSIZE], count, pos;
	
	scanf("%i", &n);
	
	count = 0; 
	pos = 0;
	for (i = 0; i < n; i++) {
		scanf("%i", &a[i]);
		if (a[i - 1] >= a[i]) {
			count++;
			pos = i;
		}
	}
	
	if (count == 0) {
		printf("0\n");
	} else if (count == 1 && a[n - 1] > a[0]) {
		printf("%i\n", (n - pos));
	} else {
		printf("-1\n");
	}
	return 0;
}