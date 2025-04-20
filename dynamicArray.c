#include <stdio.h>
#include <stdlib.h>

int main() {
  int *num;
  int size = 0;
  int op;
  int j = 0;
  int *id = num;

  num = (int*)calloc(size, sizeof(int));
  if (num == NULL) {
    printf("NOP\n");
  } else {
    printf("YEP\n");
  }

  while (op != 2) {
    printf("Add new: ");
    scanf("%d", &op);

    switch (op) {
      case 1:
        size += 1;
        num = realloc(num, size * sizeof(int));

        if (num == NULL) {
          printf("NOP\n");
        } else {
          printf("YEP\n");
        }

        printf("Number: ");
        scanf("%d", &num[j]);
        j++;
        break;

      default:
        break;
    }
  }

  printf("\n===\n");
  for (int i=0; i < size; i++) {
    printf("%d\n", num[i]);
  }

  return 0;
}
