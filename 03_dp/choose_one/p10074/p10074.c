#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 105

int main(int argc, char* argv[]) {
  int matrix[SIZE][SIZE];
  int m, n, i, j, k, aux, max, count;

  while (scanf("%d %d", &m, &n) != EOF) {
    if (m == 0 && n == 0) {
      break;
    }

    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &aux);
        matrix[i][j] = 1 - aux;
      }
    }

    for (i = 1; i < m; i++) {
      for (j = 0; j < n; j++) {
        if (matrix[i][j] == 1) {
          matrix[i][j] = matrix[i - 1][j] + 1;
        }
      }
    }

    max = -1;
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        count = matrix[i][j];
        for (k = j + 1; k < n && matrix[i][j] <= matrix[i][k]; k++) {
          count += matrix[i][j];
        }
        for (k = j - 1; k >= 0 && matrix[i][j] <= matrix[i][k]; k--) {
          count += matrix[i][j];
        }
        if (count > max) {
          max = count;
        }
      }
      printf("%d\n", max);
    }
  }
  return 0;
}
