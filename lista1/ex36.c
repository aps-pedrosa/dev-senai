#include <stdio.h>

void ex36() {
  printf("Pares:\n");
  for (int i = 1; i < 11; i++) {
    if (i%2 == 0) {
      printf("| %d \n", i);
    }
  }
}
