#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

void swap(char *number, int i, int j) {
	char aux = number[i];
	number[i] = number[j];
	number[j] = aux;
}

void permutation(char *number, int pos) {
	int i;
	
	if (pos > 0) {
		for (i = 0; i <= pos; i++) {
			swap(number, i, pos);
			permutation(number, pos - 1);
			swap(number, i, pos);
		}
	} else {
		printf("%s\n", number);
	}
}

int main(int argc, char* argv[]) {
	char number[SIZE];
	int length;
	
	scanf("%s", number);
	
	length = strlen(number);
	permutation(number, length - 1);
	
	return 0;
}
