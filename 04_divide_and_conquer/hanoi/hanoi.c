#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char start, char aux, char end) {
	if (n > 0) {
		hanoi(n - 1, start, end, aux);
		printf("Move disk %i, from %c to %c\n", n, start, end);
		hanoi(n - 1, aux, start, end);
	}
}

int main(int argc, char* argv[]) {
	int disks;
	
	scanf("%i", &disks);
	hanoi(disks, 'A', 'B', 'C');
	return 0;
}
