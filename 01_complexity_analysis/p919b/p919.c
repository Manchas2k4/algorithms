#include <stdio.h>
#include <stdlib.h>

int sum_digits(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(int argc, char* argv[]) {
	int i, k, count;
	
	scanf("%i", &k);
	count = 0;
	for (i = 19; i < 11000000; i++) { 
		if (sum_digits(i) == 10) {
			count++;
			if (count == k) {
				break;
			}
		}
	}
	printf("%d\n", i);
	return 0;
}