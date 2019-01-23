#include <stdio.h>
#include <stdlib.h>

void print_egyptian(int numerator, int denominator) {
	if (numerator == 0 || denominator == 0) {
		return;
	}
	
	if (denominator % numerator == 0) {
		printf("1/%i\n", (denominator / numerator));
		return;
	}
	
	if (numerator % denominator == 0) {
		printf("%i\n", (numerator / denominator));
		return;
	}
	
	if (numerator > denominator) {
		printf("%i + ", (numerator / denominator));
		print_egyptian(numerator % denominator, denominator);
		return;
	}
	
	int n = denominator / numerator + 1;
	printf("1/%i + ", n);
	print_egyptian((numerator * n) - denominator, denominator * n);
}

int main(int argc, char* argv[]) {
	int numerator, denominator;
	
	scanf("%i %i", &numerator, &denominator);
	print_egyptian(numerator, denominator);
	return 0;
}
