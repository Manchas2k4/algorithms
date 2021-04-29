#include <stdio.h>
#include <stdlib.h>

#define MAX 101

int main(int argc, char* argv[]) {
	int i, j, n, m, acum;
	char cadena[MAX], aux;

	scanf("%i", &n);
	for (i = 1; i <= n; i++) {
		scanf("%i\n", &m);
		fgets(cadena, MAX, stdin);
		acum = 0;
		for (j = 0; j < m; ) {
			if(cadena[j] == '#') {
				j++;
      } else {
				acum++;
				j += 3;
      }
		}
		printf("Case %i: %i\n", i, acum);
	}
	return 0;
}
