#include <stdio.h>

void pares() {
  printf("Pares:\n");
  for (int i = 1; i < 11; i++) {
    if (i%2 == 0) {
      printf("| %d \n", i);
    }
  }
}
