#include <stdio.h>
#include <stdlib.h>

double fast_pow(double x, int n) {
	if (n < 0) {
		return fast_pow(1/x, -n);
	} else if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x;
	} else if (n % 2 == 0) {
		return fast_pow(x * x, n / 2);
	} else if (n % 2 != 0) {
		return x * fast_pow(x * x, (n - 1) / 2);
	}
}

int main(int argc, char* argv[]) {
	double x;
	int n;

	scanf("%lf %i", &x, &n);
	printf("result = %lf\n", fast_pow(x, n));
	return 0;
}
