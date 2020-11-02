#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[21][201];
int weight[21];
int n;
int sum;

int max(int a, int b) {
	return (a > b)? a : b;
}

int solve(int n, int size) {
	int i, j;
	
	memset(table, 0, sizeof(table));
    for (i = 1; i < n; i++) {
        for (j = 1; j <= size; j++) {
            if (j < weight[i]) {
                table[i][j] = table[i - 1][j];
            } else {
                table[i][j] = max(table[i - 1][j], (table[i - 1][j - weight[i]] + weight[i]));
            }
        }
    }
    return (table[n - 1][size] == size);
}

void fill_weight(char* input) {
	char *data;
	
	sum = 0;
	n = 1;
  	data = strtok (input," ");
  	while (data != NULL) {
  		weight[n] = atoi(data);
  		sum += weight[n];
  		n++;
    	data = strtok (NULL, " ");
  	}
}

int main(int argc, char* argv[]) {
	int cases, i;
	char ws[100];
	
	scanf("%i%*[ \n\t]", &cases);
	for (i = 1; i <= cases; i++) {
		fgets(ws, 100, stdin);
		fill_weight(ws);
		
		if (sum % 2 == 1) {
			printf("NO\n");
		} else if (solve(n, sum/2)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
