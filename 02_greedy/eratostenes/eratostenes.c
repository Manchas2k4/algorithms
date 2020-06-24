#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 10000000

void eratostenes(char *numbers) {
  int i, j;

  memset(numbers, 1, SIZE * sizeof(char));
  for (i = 2; i <= ((int) sqrt(SIZE)); i++) {
    if (numbers[i] == 1) { // j = (i + i)
      for (j = (i * 2); j <= SIZE; j = j + i) {
        numbers[j] = 0;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  char *numbers;
  int i;

  numbers = (char*) malloc( (SIZE + 1) * sizeof(char));
  eratostenes(numbers);
  for (i = 2; i < 1000; i++) {
    if (numbers[i] == 1) {
      printf("%4i", i);
    }
  }
  free(numbers);

  return 0;
}
