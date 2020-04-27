#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define SIZE 10001

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char* argv[]) {
	int bags[SIZE], n, i, j;
	int max_size, current;
	int first_number, first_line;
	
	first_line = 1;
	while (scanf("%i", &n) != 0) {
		if (n == 0) {
			break;
		}
		
		if (first_line) {
			first_line = 0;
		} else {
			printf("\n");
		}
		
		memset(bags, 0, sizeof(int) * SIZE);
		for (i = 0; i < n; i++) {
			scanf("%i", &bags[i]);
		}
		
		qsort(bags, n, sizeof(int), compare);
		
		// FIND THE MAXIMUM NUMBER OF SAME SIZED BAGS
		max_size = INT_MIN;
		current = 1;
		for (i = 0; i < n; i++) {
			if (bags[i] == bags[i + 1]) {
				current++;
			} else {
				max_size = MAX(current, max_size);
				current = 1;
			}
		}
		
		// OUTPUT WITH THE MAX NUM OF SAME SIZED BAGS INTERVAL
		printf("%i\n", max_size);
		for (i = 0; i < max_size; i++) {
			first_number = 1;
			for (j = i; j < n; j+= max_size) {
				if (first_number) {
					first_number = 0;
				} else {
					printf(" ");
				}
				printf("%d", bags[j]);
			}
			printf("\n");
		}
	}
	return 0;
}